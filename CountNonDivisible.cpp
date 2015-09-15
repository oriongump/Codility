// you can use includes, for example:
// #include <algorithm>

#include <string>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>
#include <memory>
#include <set>
#include <climits>
#include <stack>

using namespace std;

#define rep(i,m) for(int i=0;i<(int) (m);i++)
#define rep2(i,n,m) for(int i=n;i<(int) (m);i++)
#define pb push_back

typedef stringstream ss;
typedef long long ll;
typedef pair<long,long> PLL;
typedef multimap <ll, ll> sparse_map;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A) {
    // write your code in C++11
    
    int N = A.size();
    int max=*max_element(A.begin(), A.end()) + 1;
    vector<int> counts(max,0),nonDiv(max,0);

    // Calculate occurences of each number in the array
    for (int i = 0; i < N; ++i)
    {
        counts[A[i]] += 1;
    }

    std::vector<int> answer(N,N);

    // For each element of the array
    for (int i = 0; i < N; ++i)
    {
        // If a variable of the same value has been calculated, just take the value
        if(nonDiv[A[i]]){
            answer[i]=nonDiv[A[i]];
        }else{
            //Subtract the number of occurences of A[i]'s divisors
            for (int j = 1; j * j <= A[i]; ++j)
            {
                if (A[i] % j == 0)
                {
                    answer[i] -= counts[j];
                    if (A[i] / j != j)
                    {
                        answer[i] -= counts[A[i] / j];
                    }
                }
            }
        }
    }
    return answer;
}
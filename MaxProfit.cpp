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

int solution(vector<int> &A) {
    // write your code in C++11
    int min=INT_MAX, max=0,N=A.size();
    ll maxProf=0,curProf=0;
    rep(i,N){
        if(A[i]<min){
            min=A[i];
            max=0;
        }else{
            if(A[i]>max){
                max=A[i];
                curProf=max-min;
                if(curProf>maxProf){
                    maxProf=curProf;
                }
            }
        }
    }
    return maxProf;   
}
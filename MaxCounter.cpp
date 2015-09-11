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

using namespace std;

#define rep(i,m) for(int i=0;i<(int) (m);i++)
#define rep2(i,n,m) for(int i=n;i<(int) (m);i++)
#define pb push_back

typedef stringstream ss;
typedef long long ll;
typedef pair<long,long> PLL;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++11
    int max=0,prevMax=0;
    bool reset=false;
    vector<int> counter(N,0);
    rep(i,A.size()){
        if(A[i]<=N){
            int idx=A[i]-1;
            if(reset&&counter[idx]<prevMax){
                counter[idx]=prevMax+1;
            }else{
                counter[idx]++;
            }
            if(counter[idx]>max) max=counter[idx];
        }else{
            prevMax=max;
            reset=true;
        }
    }
    if(reset){
        rep(i,N){
            if(counter[i]<prevMax) counter[i]=prevMax;
        }
    }
    return counter;
}
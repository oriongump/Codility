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
    int N=A.size(),sum=0;
    if(N<3) return 0;
    vector<int> peaks,factors;
    bool isCandi=false;
    rep(i,N-1){
        if(isCandi&&A[i]>A[i+1]){
            peaks.pb(i);
        }
        isCandi=A[i]<A[i+1];
    }
    int max=peaks.size();
    if(max<2) return max;
    sum=1;
    int upbound=sqrt(N);
    rep2(i,2,upbound+1){
        if(N%i==0) factors.pb(i);
    }
    int n=factors.size();
    if(n==0) return 1;
    if(N/factors[n-1]!=factors[n-1]) factors.pb(N/factors[n-1]);
    rep2(i,1,n){
        int idx=n-i-1;
        factors.pb(N/factors[idx]);
    }
    n=factors.size();
    rep(i,factors.size()){
        int slices=N/factors[i];
        if(slices<=max){
            int step=factors[i];
            int idx=0;
            int avail=max;
            rep(j,max){
                if(peaks[j]>=idx){
                    if(peaks[j]<idx+step){
                        idx+=step;
                        if(idx==N){
                            sum=slices;
                            return sum;
                        }
                    }else{
                        break;
                    }
                }else{
                    avail--;
                    if(avail<slices){
                        break;
                    }
                }
            }
        }
    }
    return sum;
}
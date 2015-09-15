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
    if(N<3) return sum;
    vector<int> peaks;
    bool isCandi=false;
    rep(i,N-1){
        if(isCandi&&A[i]>A[i+1]){
            peaks.pb(i);
        }
        isCandi=A[i]<A[i+1];
    }
    int max=peaks.size();
    if(max<2) return max;
    int length=peaks[max-1]-peaks[0];
    for(int i=int(floor(sqrt(length)))+1;i>0;i--){
        int idx=peaks[0];
        int count=1;
        int avail=max;
        rep2(j,1,max){
            if(peaks[j]-idx>=i){
                idx=peaks[j];
                count++;
                if(count==i) return i;
            }else{
                avail--;
                if(avail<i){
                    break;
                }
            }
        }
    }
    return sum;
}
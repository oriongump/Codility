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
typedef multimap <ll, ll> sparse_map;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// int solution(vector<int> &A) {
//     // write your code in C++11
//     int count=0,N=A.size();
//     sparse_map loc;
//     vector<ll> disc;
//     rep(i,N){
//         ll left=i-A[i],right=i+A[i];
//         loc.emplace(left,i);
//         disc.pb(right);
//     }
//     //pair<sparse_map::iterator, sparse_map::iterator> ppp;
//     for (sparse_map::iterator it = loc.begin();it != loc.end();){
//         ll right=disc[it->second];
//         sparse_map::iterator nit=++it;
//         for (;nit != loc.end();nit++){
//             if(nit->first<=right){
//                 count++;
//                 if(count>10000000)
//                     return -1;
//             }else{
//                 break;
//             }
//         }
//     }
//     return count;
// }

int solution(vector<int> &A) {
    // write your code in C++11
    int count=0,N=A.size();
    vector<int> diss(N,0),dise(N,0);
    rep(i,N){
        diss[int(max(ll(0),i-ll(A[i])))]++;
        dise[int(min(ll(N-1),i+ll(A[i])))]++;
    }
    int actDisc=0;
    rep(i,N){
        if(diss[i]>0){
            count+=actDisc*diss[i];
            count+=diss[i]*(diss[i]-1)/2;
            actDisc+=diss[i];
        }
        actDisc-=dise[i];
        if(count>10000000)
            return -1;
    }
    return count;
}
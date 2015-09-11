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
    int sum=0,N=A.size(),leadNum,count=0,lcount=0;
    if(!N) return 0;
    stack<int> cache;
    rep(i,N){
        if(cache.empty()){
            cache.push(A[i]);
        }else{
            if(cache.top()==A[i]){
                cache.push(A[i]);
            }else{
                cache.pop();
            }
        }
    }
    if(cache.empty()){
        return 0;
    }else{
        int candi=cache.top();
        rep(i,N){
            if(A[i]==candi) count++;
        }
        if(count>N/2){
            leadNum=candi;
        }else{
            return 0;
        }
    }
    rep(i,N-1){
        if(A[i]==leadNum) lcount++;
        if(lcount>(i+1)/2&&(count-lcount)>(N-i-1)/2) sum++;
        //cout << i << " " << lcount<< " " << count<<" "<<sum<<endl;
    }
    return sum;
}
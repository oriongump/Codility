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

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
    ll N=A.size();
    ll n=N;
    stack<int> down;
    rep(i,N){
      if(!down.empty()){
        if(B[i]){
            down.push(A[i]);
        }else{
            while(!down.empty()&&down.top()<A[i]){
                down.pop();
                n--;
            }
            if(!down.empty()&&down.top()>A[i]){
                n--;
            }
        }
      }else{
        if(B[i]){
          down.push(A[i]);
        }
      }
    }
    return n;
}
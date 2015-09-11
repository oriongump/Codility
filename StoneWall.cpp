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

int solution(vector<int> &H) {
    // write your code in C++11
    ll N=H.size();
    if(!N) return 0;
    stack<int> h;
    ll sum=0;
    rep(i,N){
        if(h.empty()){
            sum++;
            h.push(H[i]);
        }else{
            if(H[i]>h.top()){
                sum++;
                h.push(H[i]);
            }else{
                while(!h.empty()&&H[i]<h.top()){
                    h.pop();
                }
                if(!h.empty()&&H[i]==h.top()){
                }else{
                    sum++;
                    h.push(H[i]);
                }
            }
        }
    }
    return sum;
}
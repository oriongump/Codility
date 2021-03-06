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

int solution(vector<int> &A) {
    // write your code in C++11
    ll ssum=A[0],esum=0,min=LLONG_MAX;
    rep2(i,1,A.size()) esum+=A[i];
    rep2(i,1,A.size()){
        ll diff=abs(ssum-esum);
        if(diff<min) min=diff;
        ssum+=A[i];
        esum-=A[i];
    }
    return min;
}
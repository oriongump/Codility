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
  int M=P.size(),N=S.size();
  vector<int> result(M);
  vector<vector<int> > count;
  vector<int> placeholder={0,0,0,0};
  count.pb(placeholder);
  switch(S.at(0)){
      case 'A': count[0][0]++;break;
      case 'C': count[0][1]++;break;
      case 'G': count[0][2]++;break;
      default: count[0][3]++;break;
  }
  rep2(i,1,N){
      count.pb(count[i-1]);
      switch(S.at(i)){
          case 'A': count[i][0]++;break;
          case 'C': count[i][1]++;break;
          case 'G': count[i][2]++;break;
          default: count[i][3]++;break;
      }
      // for(auto j:count[i]){
      //     cout<< j << "\t";
      // }
      // cout<<endl;
  }
  rep(i,M){
      int start=P[i],end=Q[i];
      if(start==end){
          switch(S.at(start)){
              case 'A': result[i]=1;break;
              case 'C': result[i]=2;break;
              case 'G': result[i]=3;break;
              default: result[i]=4;break;
          }
      }else{
          rep(j,4){
              if(count[end][j]-count[start][j]>0){
                  result[i]=j+1;
                  break;
              }
          }
      }
  }
  return result;
}
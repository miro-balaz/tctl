#line 5 "KingdomAndDice.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>
#include<cstdio>
#include<bitset>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
int  abs(int x) {
  if(x<0) return -x;
  return x;
}
class KingdomAndDice {
  public:

    double newFairness(vector <int> firstDie, vector <int> secondDie, int X); 
};

double KingdomAndDice::newFairness(vector <int> f, vector <int> s, int X) {
  int score = 0 ;
  int n=f.size();
  int count_free = 0;
  REP(i, n) {
    REP(j,n) if(f[i]>s[j]) score++;
    if(f[i]==0) count_free++;
  }
  sort(s.begin(), s.end());
  set<int> used;
  REP(i,n)  {
    used.insert(f[i]);
    used.insert(s[i]);
  }
  vector<int> A;
  s.push_back(X);
  REP(i,s.size())if(i) {
    REP(j,n+3) {
      int x=s[i]-j;
      if(x<=s[i-1]) break;
      if(!used.count(x)){
        A.push_back(i);
      }
    }
  }
  int m=n*n;
  unsigned long long M[3000];
  REP(i,m+1) M[i]=0;
  M[score]=1;
  REP(i,A.size()) {
    for(int x=m;x>=0;--x) {
      if(x+A[i]<=m) M[x+A[i]]|= M[x]<<1LL;
    }
  }
  int rval=score;

  REP(i,m+1) if(M[i] & ((1LL<<count_free+1LL)-1LL) ) {
    if(abs(m-rval*2)>abs(m-i*2)) rval= i;
  }
  return (double)rval/(double)m;

}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

#line 5 "XorLife.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include <cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class XorLife {
	public:


	long long countAliveCells(vector <string> field, int K) ;
};
typedef unsigned long long int bt;
class Entry{
  public:
  vector<bt> b;
  int k;
  public:
  Entry(vector<bt> bb, int kk):b(bb),k(kk){}
  //bool operator<(const Entry &x) {
  //  if(b.size()!=x.b.size()) return b.size()<x.b.size();
  //  if(k!=x.k) return k<x.k;
  //  REP(i,b.size()) if(b[i]!=x.b[i]) return b[i]<x.b[i];
  //}
};
  bool operator<(const Entry &a,const Entry &x) {
    if(a.b.size()!=x.b.size()) return a.b.size()<x.b.size();
    if(a.k!=x.k) return a.k<x.k;
    REP(i,a.b.size()) if(a.b[i]!=x.b[i]) return a.b[i]<x.b[i];
    return false;
  }
vector<bt> next(vector<bt> b, int n) {  
  vector<bt> rval = vector<bt>(n+2,0);
  REP(i,n) {
    rval[i] ^= b[i]<<1LL;
    rval[i+1] ^= b[i]<<1LL;
    rval[i+1] ^= b[i];
    rval[i+1] ^= b[i]<<2LL;
    rval[i+2] ^= b[i]<<1LL;
  }
  return rval;
}
int bit_count(bt a) {
  int rval=0;
  while(a) {
    rval++;
    a&=a-1LL;
  }
  return rval;
}
typedef map<Entry, long long> M_t;
M_t M;
long long rec(vector<bt> b, int n, int k) {
//  printf("%d\n",n);
  Entry entry(b,k);
  int bc=0;
  REP(i,b.size()) bc+=bit_count(b[i]);
  if(k==0) return bc;
  if(bc==0) return 0;
  M_t::iterator it = M.find(entry);
  if(it != M.end()) {
    return it->second;
  }
      
//  if(n==1) return 1;
  long long rval=0;
  if(k%2==0) {
    int m=(n+1)/2;
    if(n==1) {
      rval = rec(b, n, k/2);
    } else {
      REP(dx,2) REP(dy,2) {
        vector<bt> c = vector<bt>(m);
        for(long long int i=dy;i<n;i+=2) {
          for(long long int j=dx;j<n;j+=2) {
            c[i/2] |= ((b[i]>> j) &1)<<(j/2);
          }
        }
        rval+=rec(c, m , k/2);
      }
    }
  } else {
    rval = rec(next(b,n), n+2, k-1);
  }
  M[entry]=rval;
  return rval;

}
//{{
long long XorLife::countAliveCells(vector <string> field, int K){
  int n=field.size();
  M.clear();
  if((int)field[0].size()>n) n= field[0].size();
  vector<bt> bits(n,0);

  REP(i,field.size())  {
    REP(j,field[i].size()) if(field[i][j]=='o'){
      bits[i] |= 1LL<<j;
    }
  }
  return rec(bits, n, K);

}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

#line 5 "BallRemoval.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>
#include<cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class BallRemoval {
	public:

	string canLeave(string label); 
};
string s;
int n;
typedef long long int num;
num h[50][50];
num go(num a, num b) {
  if(a>b) return 1;
  num &rval = h[a][b];
  if(rval>=0) return rval;
  rval=0;
  for(int i=a;i<b;++i) {
    for(int j=i+1;j<=b;++j) {
      if( ( (i>0 && s[i]=='>') || (j<n-1 && s[j]=='<') ) && go(a,i-1) && go(i+1,j-1)    && go(j+1,b) ) {
        rval=1;
      }
    }
  }
  return rval;
}



string BallRemoval::canLeave(string label) {
  s=label;
  n=s.size();
  memset(h,-1, sizeof(h));
  string rval;//bug: here was=0
  REP(i,n) {
    if(go(0,i-1) && go(i+1,n-1) )rval.push_back('o');else rval.push_back('.');
  }
  return rval;
}

int main() {
  string a="<<<>><<<<<>>>>><<<<<>>>>><<<<<>>>>><<<<<>>>>><<>>";
  string b="o.o...o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o";
  BallRemoval x;
  if(x.canLeave(a)==b) cout<<"PASSES"<<endl;
  cout<<x.canLeave(a)<<endl;
}

//bug: failed test case
//<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"}

//Expected:
//"o.o.o.o.o.o.o.o.................................."

//Received:
//"............o.o.................................."



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

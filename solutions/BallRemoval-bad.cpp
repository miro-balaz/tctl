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
  num &r=h[a][b];
  if(r!=-1) return r;
  if(a+1==b) {
    return r=(1LL<<a);
  }
  num rval=0;
  for(int i=a+1; i<b; i+=2) {
    num l=go(a,i);
    num r=go(i+1,b);
    if(s[i]=='<') {
      rval|=r;
    } else {
      rval|=l;
    }
  }
  if(a!=0 && a+2<b && s[a]=='>') rval|=go(a+2,b);
  if(b!=n && b-2>a && s[b-1]=='<' ) rval|=go(a, b-2);
  return r=rval; 
}

string BallRemoval::canLeave(string label) {
  s=label;
  n=s.size();
  memset(h,-1, sizeof(h));
  num x= go(0,n);
  string rval;//bug: here was=0
  REP(i,n) {
    if(x&(1LL<<i))rval.push_back('o');else rval.push_back('.');
  }
  return rval;
}

int main() {
  string a="<<<>><<<<<>>>>><<<<<>>>>><<<<<>>>>><<<<<>>>>><<>>";
  string b="o.o...o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o";
  BallRemoval x;
  if(x.canLeave(a)==b) cout<<"PASSES"<<endl;
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

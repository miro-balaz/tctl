#line 5 "EelAndRabbit.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class EelAndRabbit {
  public:

    int getmax(vector <int> l, vector <int> t); 
};
int EelAndRabbit::getmax(vector <int> l, vector <int> t) {
  vector<int> s;
  int n=l.size();
  REP(i, n) {
    s.push_back(t[i]);
    s.push_back(t[i]+l[i]);
  }
  int rval=0;
  REP(i,s.size()) REP(j,i+1) {
    int now=0;
    int t1=s[i];
    int t2=s[j];
    REP(k, n) {
      int left=t[k];
      int right=t[k]+l[k];
      if( (left<=t1 && right>=t1) || (left<=t2 && right>=t2)) now++;//bug: t2 was t1
    }
    rval=max(now, rval);

  }
  return rval;
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

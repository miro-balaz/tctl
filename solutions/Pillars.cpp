//{{{b

//}}}e
#line 5 "Pillars.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class Pillars {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; double Arg3 = 1.0; verify_case(0, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; double Arg3 = 2.387132965131785; verify_case(1, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 15; double Arg3 = 6.737191281760445; verify_case(2, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 15; int Arg2 = 23; double Arg3 = 12.988608956320535; verify_case(3, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	double getExpectedLength(int w, int x, int y) ;
};

double Pillars::getExpectedLength(int w, int x, int y){
  // x,y sum w2 +(x-y)2
  double rval=0;
  double all=(double)(x)*(y);
  int m=y;
  if(x>m) m=x;
  REP(i,m) {
    
    double f=max(0,min(x,y-i))+max(0,min(y,x-i));
    if(i==0) {
      f=min(x,y);
    }
    rval+=f*sqrt((double)w*w + (double)i*i);

  }
  return rval/all;
}
//{{{b
int main() {
  Pillars ___test;
  ___test.run_test(-1);
}
//}}}e

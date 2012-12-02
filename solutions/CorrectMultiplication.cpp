//{{{b

//}}}e
#line 5 "CorrectMultiplication.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class CorrectMultiplication {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 19; int Arg1 = 28; int Arg2 = 522; long long Arg3 = 2LL; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 30; int Arg2 = 500; long long Arg3 = 11LL; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11111; int Arg1 = 11111; int Arg2 = 123454321; long long Arg3 = 0LL; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 100; int Arg2 = 10; long long Arg3 = 1089LL; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 399; int Arg1 = 522; int Arg2 = 199999; long long Arg3 = 24LL; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	long long getMinimum(int a, int b, int c) ;
};
long long A(long long a) {
 if(a<0) return -a;
 return a;

}
long long min(long long a, long long b) {
  if(a<b) return a;
  return b;
}
long long go(long long a, long long b, long long c) {
  long long result=A(c-a*b);
  for(long long x=1;x<=100000;++x) {
    long long y=c/x;
    long long value= A(a-x)+A(b-y)+A(x*y-c);
    if(y) result=min(result, value);
    
    y=c/x + 1;
    value= A(a-x)+A(b-y)+A(x*y-c);
    result=min(result, value);
    
  }
  return result;
}
long long CorrectMultiplication::getMinimum(int a_, int b_, int c_){
  long long a=a_;
  long long b=b_;
  long long c=c_; 
  return min(go(a,b,c),go(b,a,c));
}
//{{{b
int main() {
  CorrectMultiplication ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "Suminator.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include<complex>
#include<stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class Suminator {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 200, 300, 0, 100, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 600; int Arg2 = 0; verify_case(1, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 7, 3, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 0; verify_case(2, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 8, 4, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = -1; verify_case(3, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = -1; verify_case(4, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {7, -1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(5, Arg2, findMissing(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int findMissing(vector <int> program, int wantedResult) ;
};
typedef long long int num;
complex<num> eval(vector<int> program) {
  stack<complex<num> > s;
  REP(i,51) s.push(complex<num>(0,0));
  REP(i,program.size()) {
    if(program[i]==0) {
      complex<num> a=s.top();
      s.pop();
      complex<num> b=s.top();
      s.pop();
      s.push(a+b);
    } else if(program[i]==-1){
      s.push(complex<num>(0,-1));
    } else {
      s.push(complex<num>(program[i],0));
    }
  }
  complex<num> x=s.top();
  return x;
}
int Suminator::findMissing(vector <int> program, int wantedResult){
  complex<num> x=eval(program);
  REP(i,program.size()) if(program[i]==-1) program[i]=0;
complex<num>  y = eval(program);
  if(real(y)==wantedResult) return 0;
  if(imag(x)==0) {
    if(real(x)==wantedResult) {
      return 1;
    } else {
      return -1;
    }
  } else {
    num rval=wantedResult-real(x);
    if(rval<=0) return -1;
    return rval;
  }


}
//{{{b
int main() {
  Suminator ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "EllysFractions.cpp"
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

class EllysFractions {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 0LL; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 1LL; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 3LL; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { int Arg0 = 5; long long Arg1 = 9LL; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { int Arg0 = 100; long long Arg1 = 177431885LL; verify_case(4, Arg1, getCount(Arg0)); }

// END CUT HERE

//}}}e


	long long getCount(int N) ;
};
long long is_prime(long long x) {
  if(x==1) return 0;
  for(int i=2;i*i<=x;++i) {
    if(x%i==0) return 0;
  }
  return 1;
}
long long EllysFractions::getCount(int N){
  long long rval=0;
  long long sum=0;
  for(int i=2;i<=N;++i) {
    sum+=is_prime(i);
    rval+=1ll<<(sum-1ll);
  }
 return rval; 
}
//{{{b
int main() {
  EllysFractions ___test;
  ___test.run_test(-1);
}
//}}}e

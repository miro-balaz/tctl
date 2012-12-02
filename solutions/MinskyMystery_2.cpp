//{{{b

//}}}e
#line 5 "MinskyMystery.cpp"
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

class MinskyMystery {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 79418294653; int Arg1 = 188092387; verify_case(0, Arg1, computeAnswer(Arg0)); }
	void test_case_1() { long long Arg0 = 3LL; int Arg1 = 27; verify_case(1, Arg1, computeAnswer(Arg0)); }
	void test_case_2() { long long Arg0 = 4LL; int Arg1 = 16; verify_case(2, Arg1, computeAnswer(Arg0)); }
	void test_case_3() { long long Arg0 = 2401LL; int Arg1 = 59058; verify_case(3, Arg1, computeAnswer(Arg0)); }
	void test_case_4() { long long Arg0 = 24LL; int Arg1 = 86; verify_case(4, Arg1, computeAnswer(Arg0)); }

// END CUT HERE

//}}}e


	int computeAnswer(long long N) ;
};
//{79418294653}
//188092387
typedef long long num;
num go(num to, num n) {
  num rval=0;
  //printf("n=%lld to=%lld\n",n,to);
  num i=2;
  num one=1;
  num four=4;
  num p=1000000009;
  for(;i<=to-one;) {
    num start = i;
    num podiel = n/i;
    num end = n/podiel;
    if(end>to-one) end=to-one;
    num pocet=(end-start+one)%p;
    num inc =  (n%p*pocet)%p*four%p+(podiel%p+one)*pocet;
    rval=(rval+inc)%p;
    i=end+one;
  }
  return (rval+n*(num)3+n/to+to) % p;
}
int MinskyMystery::computeAnswer(long long N){
  if(N<=1) {
    return -1;
  }
  for(num i=2;i*i<=N;++i) {
    if(N%i==0) return go(i,N);
  }
  return go(N,N);

}

//{{{b
int main() {
  MinskyMystery ___test;
  ___test.run_test(0);
}
//}}}e

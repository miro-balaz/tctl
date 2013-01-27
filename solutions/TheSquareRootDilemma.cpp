//{{{b

//}}}e
#line 5 "TheSquareRootDilemma.cpp"
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

class TheSquareRootDilemma {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 3; verify_case(1, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 8; int Arg2 = 5; verify_case(2, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 310; verify_case(3, Arg2, countPairs(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int countPairs(int N, int M) ;
};

int TheSquareRootDilemma::countPairs(int N, int M){
  int rval=0;
for(int i=1;i<=N;++i) {
  int faktor=1;
  int cislo=i;
  for(int j=2;j*j<=cislo;++j) if(cislo%j==0){
    int cnt=0;
    while(cislo%j==0) {
      cnt++;
      cislo/=j;
    }
    if(cnt&1) faktor*=j;
    
  }
  faktor*=cislo;
  rval+=(int)sqrt(M/faktor);
}  
return rval;
}
//{{{b
int main() {
  TheSquareRootDilemma ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "AlienAndSetDiv1.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class AlienAndSetDiv1 {
	public:
//{{{b

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 20; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 14; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 40; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

//}}}e

	int getNumber(int N, int K); 
};
#define MOD 1000000007
int h[100][50][50];
int k;
int n;
typedef long long int ll;
ll go(int cislo, int dlz1, int dlz2) {
  if(dlz1>n || dlz2>n) return 0;
  if(dlz1==n && dlz2==n) return 1;
  if(cislo>=n+n) return 0;
  if(h[cislo][dlz1][dlz2]!=-1) return h[cislo][dlz1][dlz2];
  long long int rval=0;
  if(dlz1==dlz2) {
    ll a=0;
    for(int i=cislo+k;i<n+n;++i) {
      a+=go(i+1, dlz1+i-cislo, dlz2+1);
    }
    rval=(a+a)%MOD;
  } else {
    rval=(go(cislo+1,dlz1+1,dlz2)+go(cislo+1,dlz1,dlz2+1))%MOD;
  }

  h[cislo][dlz1][dlz2]=rval;
  return rval;
}
int AlienAndSetDiv1::getNumber(int N, int K) {
  k=K;
  n=N;
  REP(i,n*2) REP(j,n) REP(k,n) h[i][j][k]=-1;
  return go(0,0,0);
}
//{{{b
int main() {
  AlienAndSetDiv1  ___test;
  ___test.run_test(-1);
}
//}}}e

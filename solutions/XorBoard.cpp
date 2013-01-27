//{{{b

//}}}e
#line 5 "XorBoard.cpp"
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

class XorBoard {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; int Arg5 = 4; verify_case(0, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 0; verify_case(1, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 50; int Arg3 = 40; int Arg4 = 200; int Arg5 = 333759825; verify_case(2, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1200; int Arg1 = 1000; int Arg2 = 800; int Arg3 = 600; int Arg4 = 4000; int Arg5 = 96859710; verify_case(3, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 555; int Arg1 = 555; int Arg2 = 555; int Arg3 = 555; int Arg4 = 5550; int Arg5 = 549361755; verify_case(4, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

//}}}e


	int count(int H, int W, int Rcount, int Ccount, int S) ;
};
typedef long long num;
int C[3200][3200];
num mod = 555555555;
int f(num k, num n, num m) {
  num res = n-k;
  if (res%2) return 0;
  // pocet rozdeleni res/2, medzi 
  //if(res==0) return C[k][m];
 // cout<<k<<n<<m<<":"<<m+res/2-1<<" "<<m-1<<endl;
  return C[m + res/2 - 1][m - 1]%mod * C[m][k]%mod;
}
int XorBoard::count(int H, int W, int Rcount, int Ccount, int S){
num rval=0;
REP(i,3200) C[i][0] = C[i][i] = 1;
REP(i, 3200 ) REP(j, i) if(j){
  C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
}
REP(r, Rcount+1) {
  REP(c, Ccount+1) {
    if(r>H || c>W) continue;
    if(W*r + H*c - 2*r*c ==S) {
      num x=(f(r,Rcount, H)%mod)*(f(c,Ccount, W)%mod);
//if (x)      cout<< r<<c << x<<endl;
      rval=(rval+x)%mod;
    }
  }
}  
return rval;
}
//{{{b
int main() {
  XorBoard ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "KingXNewCurrency.cpp"
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

class KingXNewCurrency {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 8; int Arg2 = 5; int Arg3 = 5; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 4; int Arg2 = 2; int Arg3 = -1; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 13; int Arg3 = 1; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 44; int Arg3 = 2; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 128; int Arg1 = 96; int Arg2 = 3; int Arg3 = 65; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	int howMany(int A, int B, int X) ;
};
int p[333*333];
int p2[333*333];

int can(int A, int B, int X, int Y) {
 if(__gcd(A,B) % __gcd(X,Y)) return 0;
 REP(i,A*B) p[i]=0;
 p[0]=1;
 REP(i,A*B) if(i-A>=0) p[i]|=p[i-A];
 REP(i,A*B) if(i-B>=0) p[i]|=p[i-B];


 REP(i,A*B) p2[i]=0;
 p2[0]=1;
 REP(i,A*B) if(i-X>=0) p2[i]|=p2[i-X];
 REP(i,A*B) if(i-Y>=0) p2[i]|=p2[i-Y];

 REP(i,A*B) if(p[i] && !p2[i]) return 0;
 return 1;


}
int KingXNewCurrency::howMany(int A, int B, int X){
  if(__gcd(A,B) %X==0) return -1;
  int count=0;
  for(int i=1;i<202;++i) count+=can(A,B,X,i);
  return count;  
}
//{{{b
int main() {
  KingXNewCurrency ___test;
  ___test.run_test(-1);
}
//}}}e

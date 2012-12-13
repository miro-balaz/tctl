//{{{b

//}}}e
#line 5 "AlternateColors2.cpp"
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

class AlternateColors2 {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 1LL; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 3LL; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 4; long long Arg2 = 9LL; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; long long Arg2 = 21LL; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 2; long long Arg2 = 1LL; verify_case(4, Arg2, countWays(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100000; int Arg1 = 100000; long long Arg2 = 1666700000LL; verify_case(5, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	long long countWays(int n, int k) ;
};
typedef long long num;
long long AlternateColors2::countWays(int n_, int k_){
   num rval=0;
   num k=k_;
   num n=n_;
   if(k%3==1) {
     num m=n-k/3-k/3-(k+2)/3;
     REP(i,m+1) {
       rval+=(m-i+1);
     }
   }
   REP(i, (k+2)/3){  //3*i<k
     num m=n-3*i;
     num new_k = k-3*i;
     if(new_k>1) {  //excludes first case
       if(new_k%2==1 ) {  //necessery condition
         m -= (new_k+1)/2 + (new_k+1)/2; // for 3 we need at least 2 of each color
         if(m>=0) {  // trivial condition
           rval+=(m+1)*2;  
         }         
     }
     num x= (new_k-1)/2+1;//  new_k; //*2-1
     x=x*2-1;
     rval+=x;
     }
   }
   return rval;
}
//{{{b
int main() {
  AlternateColors2 ___test;
  ___test.run_test(-1);
}
//}}}e

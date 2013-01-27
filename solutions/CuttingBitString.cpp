//{{{b

//}}}e
#line 5 "CuttingBitString.cpp"
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

class CuttingBitString {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "101101101"; int Arg1 = 3; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "1111101"; int Arg1 = 1; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "00000"; int Arg1 = -1; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "110011011"; int Arg1 = 3; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "1000101011"; int Arg1 = -1; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arg0 = "111011100110101100101110111"; int Arg1 = 5; verify_case(5, Arg1, getmin(Arg0)); }

// END CUT HERE

//}}}e


	int getmin(string S) ;
};
typedef long long int num;
vector<num> m5;
int is_pow(num a) {
  if (a==1) return 1;
  if (a%5) return 0;
  return is_pow(a/5);
}
int CuttingBitString::getmin(string S){
   int n=S.size();
   int f[51];
   REP(i,n) f[i]=-1;
   f[n]=0;
   for(int i=n-1; i>=0; --i) if(S[i]=='1') {
     num x=0;
     for(int j=i;j<n;++j) {
       x = x*2+(S[j]-'0');
       int a=f[j+1];
       if( j+1 < n && S[j+1]=='0') continue; 
       if(a != -1 && is_pow(x)) {
         if ( 1+a< f[i]|| f[i]==-1) f[i]=1+a;
       }

     }
   }
   return f[0];
   
}
//{{{b
int main() {
  CuttingBitString ___test;
  ___test.run_test(-1);
}
//}}}e

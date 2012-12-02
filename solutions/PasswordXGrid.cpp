//{{{b

//}}}e
#line 5 "PasswordXGrid.cpp"
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

class PasswordXGrid {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1","4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"32"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(0, Arg2, minSum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"47", "59"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"361"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 19; verify_case(1, Arg2, minSum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"36", "23", "49"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"890", "176"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 28; verify_case(2, Arg2, minSum(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"8888585","5888585"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"58585858"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 58; verify_case(3, Arg2, minSum(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"7777777","7777777","7777777","7777777"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"44444444","44444444","44444444"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 61; verify_case(4, Arg2, minSum(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int minSum(vector <string> horizontal, vector <string> vertical) ;
};

int PasswordXGrid::minSum(vector <string> horizontal, vector <string> vertical){
int h[51][51];
int n = horizontal.size();
int m = horizontal[0].size()+1;

REP(i, n) {
  REP(j,m) {
    int p=0;
    if(i>0) {
      int a=h[i-1][j]+vertical[i-1][j]-'0';
      if(a>p) p = a;
    }
    if(j>0) {
      int a = h[i][j-1]+horizontal[i][j-1]-'0';
      if(a>p) p = a;
    }
    h[i][j]=p;
  }
}
return h[n-1][m-1];
}
//{{{b
int main() {
  PasswordXGrid ___test;
  ___test.run_test(-1);
}
//}}}e

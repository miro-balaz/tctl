//{{{b

//}}}e
#line 5 "ScotlandYard.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class ScotlandYard {
	public:
//{{{b

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "NNY",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "NNN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNN",
 "NNN",
 "NNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, maxMoves(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"NYY",
 "NNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "NNN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNN",
 "NNN",
 "NNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, maxMoves(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"NYYY",
 "YNYY",
 "YYNY",
 "YYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(2, Arg3, maxMoves(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"NNY",
 "NNY",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "NNY",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNN",
 "NNN",
 "YNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, maxMoves(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"NNN",
 "YNY",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "YNN",
 "YNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNN",
 "NNN",
 "YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(4, Arg3, maxMoves(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"NNNNYNNNYY",
 "NNYNNYYYYY",
 "NNNNNNNNNN",
 "YYNNYYNNNY",
 "NNYNNNNNNN",
 "YNYNYNNNYN",
 "NNYNYNNNYN",
 "NNNNNNYNNN",
 "NNNNNNNNNN",
 "NNNNNNYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYNNNYNNY",
 "YNYNNYYNYY",
 "NNNNNNNNNN",
 "YNYNNYNYNY",
 "NNYNNNNNYN",
 "YNYNYNYNYN",
 "NNYNNNNNNY",
 "YNYNNNNNNN",
 "NNNNNNNNNN",
 "NNYNYNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNNNNNNYNN",
 "YNYNNNNNYN",
 "NNNNNNNNNN",
 "NYNNYNNNYY",
 "NNYNNNNNNN",
 "YNYNNNNNYY",
 "NNNNYNNNYN",
 "NNYNNNYNNN",
 "NNNNNNNNNY",
 "NNYNYNNNNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21; verify_case(5, Arg3, maxMoves(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e

	int maxMoves(vector <string> taxi, vector <string> bus, vector <string> metro); 
};
vector<set<int> > h;
int n;
int vertex_id(int a, int b) {
if(a<b) swap(a,b);
//n+, n-1, n-2, n-a+b;
}
int vertex_id(int a) {
  return a;
}
int ScotlandYard::maxMoves(vector <string> taxi, vector <string> bus, vector <string> metro) {
  
}
//{{{b
int main() {
  ScotlandYard  ___test;
  ___test.run_test(-1);
}
//}}}e

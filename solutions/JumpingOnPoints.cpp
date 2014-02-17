//{{{b

//}}}e
#line 5 "JumpingOnPoints.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class JumpingOnPoints {
	public:
//{{{b

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arr2[] = {0, 0, 5, 100, 0, 0, 5, 100, 0, 0, 10, 100, 1, 1, 0, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 150000000000000LL; verify_case(0, Arg3, sumOfDistances(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 18LL; verify_case(1, Arg3, sumOfDistances(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 0; int Arr2[] = {0, 1, 1, 100, 0, 1, 1, 100, 1, 1, 0, 100, 0, 0, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 6LL; verify_case(2, Arg3, sumOfDistances(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 60000; int Arg1 = 0; int Arr2[] = {0, 1, 1, 1000000000, 0, 1, 1, 1000000000, 1, 1, 0, 1000000000, 999999999, 1, 0, 1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1799969998200030000LL; verify_case(3, Arg3, sumOfDistances(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 0; int Arr2[] = {0, 1, 5, 15, 0, 1, 5, 10, 0, 0, 0, 1,1,1,1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 8LL; verify_case(4, Arg3, sumOfDistances(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 286; int Arr2[] = {11111, 11111, 111111, 11111111, 12121, 12111, 13131, 11111111, 13, 14444, 44312, 222211, 13131, 328655, 11373, 999999993}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 738940004832LL; verify_case(5, Arg3, sumOfDistances(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e

	long long sumOfDistances(int N, int S, vector <int> params); 
};
long long JumpingOnPoints::sumOfDistances(int N, int S, vector <int> params) {
  
}
//{{{b
int main() {
  JumpingOnPoints  ___test;
  ___test.run_test(-1);
}
//}}}e

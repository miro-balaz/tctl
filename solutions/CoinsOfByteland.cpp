//{{{b

//}}}e
#line 5 "CoinsOfByteland.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class CoinsOfByteland {
	public:
//{{{b

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7, 11, 15, 18, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, countCoinSystems(Arg0)); }
	void test_case_1() { int Arr0[] = {10, 19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 45; verify_case(1, Arg1, countCoinSystems(Arg0)); }
	void test_case_2() { int Arr0[] = {10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10000; verify_case(2, Arg1, countCoinSystems(Arg0)); }
	void test_case_3() { int Arr0[] = {1326549, 3212423, 6546565, 8785456}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 546494632; verify_case(3, Arg1, countCoinSystems(Arg0)); }

// END CUT HERE

//}}}e

	int countCoinSystems(vector <int> maxSum); 
};
int CoinsOfByteland::countCoinSystems(vector <int> maxSum) {
  
}
//{{{b
int main() {
  CoinsOfByteland  ___test;
  ___test.run_test(-1);
}
//}}}e

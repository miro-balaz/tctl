//{{{b

//}}}e
#line 5 "MergersDivOne.cpp"
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

class MergersDivOne {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, -7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.5; verify_case(0, Arg1, findMaximum(Arg0)); }
	void test_case_1() { int Arr0[] = {10, -17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -3.5; verify_case(1, Arg1, findMaximum(Arg0)); }
	void test_case_2() { int Arr0[] = {12, 12, 12, 12, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 12.0; verify_case(2, Arg1, findMaximum(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 0, 0, 0, 0, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 50.0; verify_case(3, Arg1, findMaximum(Arg0)); }
	void test_case_4() { int Arr0[] = {10, -10, 100, -100, 1000, -1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 491.25; verify_case(4, Arg1, findMaximum(Arg0)); }

// END CUT HERE

//}}}e


	double findMaximum(vector <int> revenues) ;
};
double MergersDivOne::findMaximum(vector <int> revenues){
   int n=revenues.size();
   sort(revenues.begin(),revenues.end());
   double avg=revenues[0];
   for(int i=1;i<n;++i) {
     avg = ((double)revenues[i]+avg)/2;
   }
   return avg;
   
}
//{{{b
int main() {
  MergersDivOne ___test;
  ___test.run_test(-1);
}
//}}}e

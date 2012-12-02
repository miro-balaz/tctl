//{{{b

//}}}e
#line 5 "GogoXMarisaKirisima.cpp"
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

class GogoXMarisaKirisima {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN"
,"YNY"
,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNY"
,"YNY"
,"YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYY"
,"NNNY"
,"NNNY"
,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE

//}}}e


	int solve(vector <string> choices) ;
};


int GogoXMarisaKirisima::solve(vector <string> choices){
  int n=choices.size();
  vector<int> reachable(n,0);  //from 0
  vector<int> reaches(n,0);  // n-1 
  reachable[0]=1;
  reaches[n-1]=1;
  REP(x,n+3) {
    REP(i,n) REP(j,n) {
      reachable[j] |= reachable[i] & (choices[i][j]=='Y');
      reaches[i] |= reaches[j] & (choices[i][j]=='Y');
    }
  }
  int nodes=0;
  int edges=0;
  REP(i,n) nodes += reachable[i] && reaches[i];
  REP(i,n) REP(j,n) edges += reachable[i] && reaches[j] && (choices[i][j] == 'Y');
  if(nodes==0) return 0;
  return edges-nodes+2;
}
//{{{b
int main() {
  GogoXMarisaKirisima ___test;
  ___test.run_test(-1);
}
//}}}e

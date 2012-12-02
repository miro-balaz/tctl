//{{{b

//}}}e
#line 5 "GogoXBallsAndBins.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class GogoXBallsAndBins {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; int Arg2 = 625702391; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int solve(vector <int> T, int moves) ;
};
typedef long long int number_t;
#define MOD 1000000009ll
typedef long long int state_t[51][10001];
state_t states[2];
int GogoXBallsAndBins::solve(vector <int> T, int moves){
   state_t *now = states;
   state_t *then = &states[1];
   REP(i,51) REP(j,10001) (*now)[i][j]=0;
   (*now)[0][5000]=1;
   int n=T.size();
   REP(pos,n) {
     REP(i,51) REP(j,10001) (*then)[i][j]=0;
     REP(wait,51) REP(score,10001) {
       long long int &s = (*now)[wait][score];
       long long int *t;
       if(s) {
         //printf("%d %d %d->%lld\n",pos,wait,score-5000, (*now)[wait][score]);
         t = &(*then)[wait][score]; *t= (*t +  (wait*2+1)*s) % MOD;
         if(wait>0) {
           t = &(*then)[wait-1][score+2*T[pos]]; *t = (*t +  wait * wait * s) % MOD;
         }
         t = &(*then)[wait+1][score-2*T[pos]]; *t = (*t +  s) % MOD;
       }
     }


     swap(now, then);
   }
   return (*now)[0][5000+moves*2];




}
//{{{b
int main() {
  GogoXBallsAndBins ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "NoRepeatPlaylist.cpp"
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

class NoRepeatPlaylist {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 100; int Arg3 = 956927880; verify_case(0, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 3; int Arg3 = 0; verify_case(1, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 3; int Arg3 = 6; verify_case(2, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 0; int Arg2 = 4; int Arg3 = 24; verify_case(3, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; int Arg3 = 2; verify_case(4, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 5; int Arg2 = 100; int Arg3 = 222288991; verify_case(5, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	int numPlaylists(int N, int M, int P) ;
};
#define MOD 1000000007
long long int comb[101][101];

int NoRepeatPlaylist::numPlaylists(int N, int M, int P){
   long long int q=0;
   REP(i,101) REP(j,101) comb[i][j]=0;
   comb[0][0]=1;
   //comb[i][j]=comb[i-1][j-1] + comb[i-1][j]
   REP(i,101) if(i) REP(j,101){
     comb[i][j]=(comb[i-1][j] + (j?comb[i-1][j-1]:0))% MOD ;
   }

  REP(missing, N) {
   long long int n = N-missing, m = M;
   long long int r=1;
    REP(i,P)  {
      long long int j=i;
      if(j>m) j=m;
      r=r*(n-j) % MOD;
    }
    long long int coef=comb[N][missing];
    if(missing & 1) {
      q-=(r*coef)%MOD;

    } else {
      q+=(r*coef)%MOD;
    }
    printf("%lld\n",q);
    q=(MOD+q)%MOD;
  }
   
   return q;
}
//{{{b
int main() {
  NoRepeatPlaylist ___test;
  ___test.run_test(0);
}
//}}}e

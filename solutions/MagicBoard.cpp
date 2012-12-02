//{{{b

//}}}e
#line 5 "MagicBoard.cpp"
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


//##
//.#
//0011
//0001
//1000
//1100
#define REP(i,n) for(int i=0;i<(int)n;++i)

class MagicBoard {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"##",
 ".#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, ableToUnlock(Arg0)); }
	void test_case_1() { string Arr0[] = {"#.",
 ".#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, ableToUnlock(Arg0)); }
	void test_case_2() { string Arr0[] = {"##",
 "##",
 "##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, ableToUnlock(Arg0)); }
	void test_case_3() { string Arr0[] = {"###",
 "###",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, ableToUnlock(Arg0)); }
	void test_case_4() { string Arr0[] = {"###",
 "..#",
 "###",
 "#..",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, ableToUnlock(Arg0)); }
	void test_case_5() { string Arr0[] = {"................",
 ".######..######.",
 ".######..######.",
 ".##......##..##.",
 ".##......##..##.",
 ".######..######.",
 ".######..######.",
 ".....##..##..##.",
 ".....##..##..##.",
 ".######..######.",
 ".######..######.",
 "................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(5, Arg1, ableToUnlock(Arg0)); }
	void test_case_6() { string Arr0[] = {"#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(6, Arg1, ableToUnlock(Arg0)); }

// END CUT HERE

//}}}e


	string ableToUnlock(vector <string> board) ;
};

string MagicBoard::ableToUnlock(vector <string> board){
  int n = board.size();
  int m = board[0].size();
  vector<int> cnt(m+n);

  vector<vector<int> > M(cnt.size(), vector<int>(cnt.size()));
  REP(i,n) REP(j,m) {
    if(board[i][j]=='#') {
       cnt[i]++;
       cnt[n+j]++;
       M[i][n+j]=1;
       M[n+j][i]=1;
    }
  }
  int N=m+n;  
  REP(k,N) REP(i,N) REP(j,N) M[i][j]|=M[i][k] & M[k][j];
  REP(i,N) if(cnt[i]) {
    REP(j,N) if(j!=i && cnt[j] && !M[i][j]) return "NO";
    break;
  }
  int cunpair=0;
  REP(i,N) cunpair +=cnt[i]&1;
  int cunpair2=0;
  REP(i,N) if(i>=n)cunpair2 +=cnt[i]&1;
  printf("%d %d\n",cunpair, cunpair2);
  if((cunpair ==2 && cunpair2==0) || cunpair>2 ) return "NO";
  return "YES";
}
//{{{b
int main() {
  MagicBoard ___test;
  ___test.run_test(-1);
}
//}}}e

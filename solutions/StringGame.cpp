//{{{b

//}}}e
#line 5 "StringGame.cpp"
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

class StringGame {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"a", "b", "c", "d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getWinningStrings(Arg0)); }
	void test_case_1() { string Arr0[] = {"aabbcc", "aaabbb", "aaaccc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getWinningStrings(Arg0)); }
	void test_case_2() { string Arr0[] = {"ab", "ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getWinningStrings(Arg0)); }
	void test_case_3() { string Arr0[] = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getWinningStrings(Arg0)); }

// END CUT HERE

//}}}e


	vector <int> getWinningStrings(vector <string> S) ;
};

vector <int> StringGame::getWinningStrings(vector <string> S){
  int H[50][26];
 REP(i,50) REP(j,26) H[i][j]=0;
int n=S.size();
  REP(i,n) REP(j,S[i].size()) H[i][S[i][j]-'a']++;
  vector<int> rval;
  REP(start, n) {
    vector<int> killed(n,0);
    killed[start]=1;
    vector<int> used(26,0);
    REP(t,26) {
      REP(l,26) if(!used[l]){
        int ok=1;
        REP(i,n) if(!killed[i]&& H[start][l]<H[i][l]) {
          ok=0;
          break;
        }
        if(ok) {
          used[l]=1;
          REP(i,n) if(H[start][l]>H[i][l]) killed[i]=1;
          break;
        }
      }
    }
    int ka=1;
    REP(i,n) if(!killed[i]) ka=0;
    if(ka) rval.push_back(start);
  }
  return rval;
}
//{{{b
int main() {
  StringGame ___test;
  ___test.run_test(-1);
}
//}}}e

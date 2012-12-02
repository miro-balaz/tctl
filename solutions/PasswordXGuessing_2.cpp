//{{{b

//}}}e
#line 5 "PasswordXGuessing.cpp"
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

class PasswordXGuessing {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"58", "47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"539", "540", "541"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"12", "34", "56", "78"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"2", "3", "5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"4747", "4747", "4747", "4747"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 36LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

//}}}e


	long long howMany(vector <string> guesses) ;
};

long long PasswordXGuessing::howMany(vector <string> guesses){
int cnt = 0;
int n = guesses[0].size();
REP(c,10) {
  REP(j,n) {
    string  ps = guesses[0];  
    ps[j]='0'+c;
    int ok=1;
    REP(i,guesses.size()) {
      int cnt=0;
      REP(x,n) if (guesses[i][x]!=ps[x]) cnt++;
      if (cnt!=1) ok=0;
    }
    cnt+=ok;
  }
}
return cnt;
}
//{{{b
int main() {
  PasswordXGuessing ___test;
  ___test.run_test(-1);
}
//}}}e

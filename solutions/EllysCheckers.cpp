//{{{b

//}}}e
#line 5 "EllysCheckers.cpp"
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

class EllysCheckers {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".o..."; string Arg1 = "YES"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "..o..o"; string Arg1 = "YES"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = ".o...ooo..oo.."; string Arg1 = "NO"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "......o.ooo.o......"; string Arg1 = "YES"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = ".o..o...o....o.....o"; string Arg1 = "NO"; verify_case(4, Arg1, getWinner(Arg0)); }

// END CUT HERE

//}}}e


	string getWinner(string board) ;
};
map<int, int> can_win;
int n;
    bitset<20> x;
    int depth=0;
int go(int state) {
  if(can_win.find(state)!=can_win.end()) {
    return can_win[state];
  }
  depth++;
  //printf("%d %d\n",depth,state);
  int result=0; // NO MOVES = lose
  REP(i,n-1)  {
    x=state;
    if(x[i]) {
      if(x[i+1]) {
        if(i+2<n && x[i+2] && i+3<n && !x[i+3]) {
          x[i]=0;
          x[i+3]=1;
          
        }
      } else {
        x[i]=0;
        x[i+1]=1;
      }
      if(x[i]) continue;
      x[n-1]=0;
    
      if(!go(x.to_ulong())) {
        result=1;
        break;
      } 
    }
  }
  depth--;
  return can_win[state]=result;
}

string EllysCheckers::getWinner(string board){
     can_win.clear();
     int state=0;
     n =board.size();
     board[n-1]='.';
     REP(i,n) {
       state*=2;
       state+=board[n-i-1]=='o';
     }
     return go(state)?"YES":"NO";

}
//{{{b
int main() {
  EllysCheckers ___test;
  ___test.run_test(-1);
}
//}}}e

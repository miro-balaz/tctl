//{{{b

//}}}e
#line 5 "RowAndCoins.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class RowAndCoins {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABBB"; string Arg1 = "Alice"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "BBBB"; string Arg1 = "Bob"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = "BA"; string Arg1 = "Alice"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "BABBABBB"; string Arg1 = "Bob"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = "ABABBBABAABBAA"; string Arg1 = "Alice"; verify_case(4, Arg1, getWinner(Arg0)); }
	void test_case_5() { string Arg0 = "BBBAAABBAAABBB"; string Arg1 = "Bob"; verify_case(5, Arg1, getWinner(Arg0)); }

// END CUT HERE

//}}}e


	string getWinner(string cells) ;
};
string cells;
typedef bitset<15> stav;
int position[65536];

int go(stav s,int n) {
  if(position[s.to_ulong()]!=-1) {
    return position[s.to_ulong()];
  }
  if((int)s.count()-s[n]==n-1) {
    for(int i=0;i<n;++i) if(!s[i]){
      if(s[n]==(cells[i]=='B' )) return 1;
      return 0;
    }
  }
  int result=0;  //losing position
  for(int i=0;i<n;++i) {
    if(result) break;
    if(!s[i]) {
      for(int j=i+1;j<=n;++j) {
        stav novy(s);
        novy.flip(n);
        bool good=1;
        for(int k=i;k<j;++k) {
          if(s[k]) {
            good=0;
            break;
          }
          novy.set(k);
        }
        if(!good) break;
        if((int)novy.count()-novy[n]!=n) {
          if(!go(novy,n)) {
            result=1;
            break;
          }
        }
      }
    }
  }


  return position[s.to_ulong()]=result;
}
string RowAndCoins::getWinner(string cells){
  ::cells=cells;
  int n=cells.size();
  REP(i,1<<(n+1)) position[i]=-1;
  if(go(0,n)) {
    return "Alice";
  } else {
    return "Bob";
  }
   
}
//{{{b
int main() {
  RowAndCoins ___test;
  ___test.run_test(-1);
}
//}}}e

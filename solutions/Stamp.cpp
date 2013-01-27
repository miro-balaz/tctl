//{{{b

//}}}e
#line 5 "Stamp.cpp"
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

class Stamp {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRGGBB"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(0, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "R**GB*"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(1, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "BRRB"; int Arg1 = 2; int Arg2 = 7; int Arg3 = 30; verify_case(2, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "R*RR*GG"; int Arg1 = 10; int Arg2 = 58; int Arg3 = 204; verify_case(3, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "*B**B**B*BB*G*BBB**B**B*"; int Arg1 = 5; int Arg2 = 2; int Arg3 = 33; verify_case(4, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG"; int Arg1 = 7; int Arg2 = 1; int Arg3 = 30; verify_case(5, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	int getMinimumCost(string desiredColor, int stampCost, int pushCost) ;
};
int n;
vector<int> s;
int get_pu(int L) {
  int MAX=1000;
  int h[50][3];
  REP(i,n) REP(j,3) h[i][j]=MAX;
  int rval=MAX;
  REP(i,n) if(i>=L-1)REP(c,3) {
    int r=MAX;
    int ok=1;
    REP(j,L) {
      if(s[i-j] != 3 && s[i-j] != c) {
        ok=0;
        break;
      }
    }
    if (!ok) continue;
    if(i==L-1) {
      r=0;
    } else {
      REP(f,3) {
        r=min(r, h[i-L][f]);
      }
    
      REP(j,L-1) {
        int x=i-j-1;
        if(x<0) break;
        r=min(r, h[x][c]);
      }
    }
    if(r==MAX) continue;
    h[i][c]=min(h[i][c],1+r);
  }
  

  REP(i,3) rval=min(rval, h[n-1][i]);
  if(rval==MAX) return -1;
  return rval;

  //a[colored][3]
}
int Stamp::getMinimumCost(string desiredColor, int stampCost, int pushCost){
    string c = desiredColor;
    s.clear();
    n = c.size();
    REP(i,n) {
      s.push_back(string("RGB*").find(c[i]));
    }
    int rval=-1;
    REP(i,n) {
      int pu = get_pu(i+1);
      if(pu!=-1) {
        int cost = pu*pushCost+(i+1)*stampCost;
        if(rval==-1 || cost<rval) rval=cost;
      }
    }
    return rval;
}
//{{{b
int main() {
  Stamp ___test;
  ___test.run_test(-1);
}
//}}}e

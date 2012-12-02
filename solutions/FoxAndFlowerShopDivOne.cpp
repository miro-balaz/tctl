//{{{b

//}}}e
#line 5 "FoxAndFlowerShopDivOne.cpp"
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
template<typename T>
class RMQ_c{
  public:
  vector<vector<T> > v;
  RMQ_c(vector<T> v) {
    this->v=vector<vector<T > >(1,v);
    initialize();
  }
  void initialize() {
    int n =v[0].size();
    int is = 2;
    int level=1;
    while(is <= n ) {
      v.push_back(vector<T>(n,0));
      for(int i=is-1; i < n; ++i) {
        v[level][i]=max(v[level-1][i],v[level-1][i-is/2]);
      }
      level++;
      is *= 2;
    }
  }
  T get_minimum(int start, int end) {
    if (start >= end) {
      return 0;
    }
    int sz = end-start;
    int is=1;
    int level=0;
    while(is*2 <= sz) {
      is*=2;
      level++;
    }
    return max(v[level][start+is-1],v[level][end-1]);
  }

};
class FoxAndFlowerShopDivOne {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"LLL",
 "PPP",
 "LLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 7; verify_case(0, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"LLL",
 "PPP",
 "LLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 6; verify_case(1, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"LLPL.LPP",
 "PLPPPPLL",
 "L.P.PLLL",
 "LPL.PP.L",
 ".LLL.P.L",
 "PPLP..PL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 38; verify_case(3, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = -1; verify_case(4, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"LLLP..LLP.PLL.LL..LP",
 "L.PL.L.LLLL.LPLLPLP.",
 "PLL.LL.LLL..PL...L..",
 ".LPPP.PPPLLLLPLP..PP",
 "LP.P.PPL.L...P.L.LLL",
 "L..LPLPP.PP...PPPL..",
 "PP.PLLL.LL...LP..LP.",
 "PL...P.PPPL..PLP.L..",
 "P.PPPLPLP.LL.L.LLLPL",
 "PLLPLLP.LLL.P..P.LPL",
 "..LLLPLPPPLP.P.LP.LL",
 "..LP..L..LLPPP.LL.LP",
 "LPLL.PLLPPLP...LL..P",
 "LL.....PLL.PLL.P....",
 "LLL...LPPPPL.PL...PP",
 ".PLPLLLLP.LPP...L...",
 "LL...L.LL.LLLPLPPPP.",
 "PLPLLLL..LP.LLPLLLL.",
 "PP.PLL..L..LLLPPL..P",
 ".LLPL.P.PP.P.L.PLPLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 208; verify_case(5, Arg2, theMaxFlowers(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int theMaxFlowers(vector <string> flowers, int maxDiff) ;
};

int FoxAndFlowerShopDivOne::theMaxFlowers(vector <string> flowers, int maxDiff){
  int sx=flowers[0].size();
  int sy=flowers.size();
  int sD[31][31],sS[31][31];
  // Here forgot +1
  REP(i,sy+1) sD[i][0] = sS[i][0] = 0;
  REP(j,sx+1) sD[0][j] = sS[0][j] = 0;
  REP(i,sy) REP(j,sx) {
    if (flowers[i][j]=='.') {
      sD[i+1][j+1] = sS[i+1][j+1] = 0;
    } else {
      sS[i+1][j+1] = 1;
      sD[i+1][j+1] = flowers[i][j] == 'P' ? 1:-1;
    }
  }
  // subset sum
  REP(i,sy+1) REP(j,sx+1) if(i&&j){
    // here forgot +=
    sS[i][j]+=sS[i-1][j]+sS[i][j-1]-sS[i-1][j-1];
    sD[i][j]+=sD[i-1][j]+sD[i][j-1]-sD[i-1][j-1];
//    cout<<i<<" "<<j<<" "<<sS[i][j]<<endl;
  }
  vector<vector<int> > left(sx,vector<int>(2000,-1)),right(sx,vector<int>(2000,-1)), top(sy,vector<int>(2000,-1)),bottom(sy,vector<int>(2000,-1));

  REP(y0,sy) REP(y1,sy) if (y1>=y0 ) {
    REP(x0,sx) REP(x1,sx) if(x1>=x0) {
      int dif = sD[y1+1][x1+1] - sD[y0][x1+1]-sD[y1+1][x0]+sD[y0][x0]+900;
      int sum = sS[y1+1][x1+1] - sS[y0][x1+1]-sS[y1+1][x0]+sS[y0][x0];

      for(int i=x1;i<sx;++i) {
        left[i][dif]=max(left[i][dif],sum);
      }
      for(int i=0;i<=x0;++i) {
        right[i][dif]=max(right[i][dif],sum);
      }
      for(int i=y1;i<sy;++i) {
        bottom[i][dif]=max(bottom[i][dif],sum);
      }
      for(int i=0;i<=y0;++i) {
        top[i][dif]=max(top[i][dif], sum);
      }
    }
  }

  vector<RMQ_c<int> > r_left,r_right,r_top,r_bottom;
  REP(i,sy) {
    r_top.push_back(RMQ_c<int>   ( top[i]));
    r_bottom.push_back(RMQ_c<int>( bottom[i]));
  }
  REP(i,sx) {
    r_left.push_back(RMQ_c<int>(left[i]));
    r_right.push_back(RMQ_c<int>(right[i]));
  }
  REP(i,sx) {
    for(int j=-9; j<=9;++j) {
      //cout<<"right"<<i<<" "<<j<<"= "<<right[i][j+900]<<endl;
    }
  }
  // forgot to read about the each rectangle must contain at least one cell
  int rval=-1;
  REP(y0,sy) REP(y1,sy) if (y1>=y0 ) {
    REP(x0,sx) REP(x1,sx) if(x1>=x0) {
      int dif = sD[y1+1][x1+1] - sD[y0][x1+1]-sD[y1+1][x0]+sD[y0][x0];
      int sum = sS[y1+1][x1+1] - sS[y0][x1+1]-sS[y1+1][x0]+sS[y0][x0];
    //  cout<<dif<<" "<<sum<<endl;
      // -D<=dif +x<=D
      //added offset too early, before doing calculations with actual value
      int a = -maxDiff-dif+900;
      int b = maxDiff-dif+1+900;
      if(a<0) a = 0;
      if(b>1801) b = 1801;
      int cc=-1;
      if(x0>0) {
        int c = r_left[x0-1].get_minimum(a,b);
        if(c > cc) {
          cc = c;
        }
      }
      if(x1+1<sx) {
        int c = r_right[x1+1].get_minimum(a,b);
        if(c > cc) {
       //   cout<<"fail "<<c<<endl;
          cc = c;
        }
      }
      if(y0>0) {
        int c =r_bottom[y0-1].get_minimum(a,b);
        if(c > cc) {
          cc=c;
        }
      }
      if(y1+1 < sy) {
        int c =r_top[y1+1].get_minimum(a,b);
        if(c>cc) {
          cc=c;
        }
      }
      // logical bug
      if(cc!=-1) {
        if(cc+sum>rval) {
//          cout << x0<<x1<<y0<<y1<<"cc="<<cc<<"dif="<<dif<<"sum="<<sum<<" "<<a<<" "<<b<<endl;
          rval = cc+sum;
        }
      }
    }
  }
  
  return rval; 
}
//{{{b
int main() {
  FoxAndFlowerShopDivOne ___test;
  ___test.run_test(-1);
}
//}}}e

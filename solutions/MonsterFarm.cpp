//{{{b

//}}}e
#line 5 "MonsterFarm.cpp"
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

class MonsterFarm {
  public:
    //{{{b

    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numMonsters(Arg0)); }
    void test_case_1() { string Arr0[] = {"1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, numMonsters(Arg0)); }
    void test_case_2() { string Arr0[] = {"2", "3", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, numMonsters(Arg0)); }
    void test_case_3() { string Arr0[] = {"1", "3 4", "2", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, numMonsters(Arg0)); }
    void test_case_4() { string Arr0[] = {"2 2", "3", "4 4 4", "5", "6", "7 7 7 7", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(4, Arg1, numMonsters(Arg0)); }
    void test_case_5() { string Arr0[] = {"2 3","5 7","2 4","5","6","4","7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(5, Arg1, numMonsters(Arg0)); }

    // END CUT HERE

    //}}}e


    int numMonsters(vector <string> transforms) ;
};
#define MOD1 1000000007
#define MOD2 1000000009
typedef vector<long long int> stav_t;
int MonsterFarm::numMonsters(vector <string> transforms){
  long long int p[50][50];
  int n = transforms.size();
  REP(i,n) REP(j,n) p[i][j]=0;
  REP(i,n) {
    istringstream is(transforms[i]);
    int s;
    while(is>>s) {
      p[i][s-1]++;
    }
  }
  int q[50][50];
  REP(i,n) REP(j,n) q[i][j]=!!p[i][j];
  REP(k,n) REP(i,n)REP(j,n) q[i][j]|=q[i][k]&q[k][j];
  REP(i,n) if(q[i][i] && q[0][i]) {
    int deg=0;
    REP(j,n) deg+=p[i][j];
    if(deg>1) return -1;
  }
  if(p[0][0]>1) return -1;
  stav_t a(n);
  a[0]=1;
  set<stav_t> stavy;
  stavy.insert(a);
  REP(x , n+3) {
    stav_t novy=stav_t(n,0);
    for(int i=0;i<n;++i) {
      for(int j=0;j<n;++j) {
        novy[i]=(novy[i] + a[j]*p[j][i] % MOD1)%MOD1;
      }
    }
    a=novy;
  }
      long long int x=0;
      for(int i=0;i<n;++i) {
        x+=a[i];
      }
      return x%MOD1;
}
//{{{b
int main() {
  MonsterFarm ___test;
  ___test.run_test(-1);
}
//}}}e

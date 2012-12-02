//{{{b

//}}}e
#line 5 "DengklekMakingChains.cpp"
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

class DengklekMakingChains {
  public:
    //{{{b

    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {".15", "7..", "402", "..3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
    void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
    void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
    void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
    void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
    void test_case_5() { string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(5, Arg1, maxBeauty(Arg0)); }

    // END CUT HERE

    //}}}e


    int maxBeauty(vector <string> chains) ;
};
int g(char x) {
  return x - '0';
}
int f(char x) {
  return x != '.';
}
int DengklekMakingChains::maxBeauty(vector <string> c){
  int rval=0;
  c.push_back("...");
  c.push_back("...");
  int n=c.size();
  REP(i,n) REP(j,n) if(i!=j) {
    int sum=0;
    string a;
    a=c[i];

    for(int x=2;x>=0 && f(a[x]);--x) sum+=g(a[x]);
    a=c[j];
    for(int x=0;x<3 && f(a[x]);++x) sum+=g(a[x]);

    REP(k,n) if(i!=k && j!=k) {
      a=c[k];
      if(f(a[0])&&f(a[1]) && f(a[2])) sum+=g(a[0])+g(a[1])+g(a[2]);
    }
    
    if(sum>rval) {
      rval = sum;
    }
  }
  REP(i,n) {
    rval=max(rval, g(c[i][1]));
  }
  return rval;
}

//{{{b
int main() {
  DengklekMakingChains ___test;
  ___test.run_test(-1);
}
//}}}e

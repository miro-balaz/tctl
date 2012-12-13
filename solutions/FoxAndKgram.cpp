//{{{b

//}}}e
#line 5 "FoxAndKgram.cpp"
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

class FoxAndKgram {
  public:
    //{{{b

    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,1,1,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maxK(Arg0)); }
    void test_case_1() { int Arr0[] = {2,2,1,3,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, maxK(Arg0)); }
    void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, maxK(Arg0)); }
    void test_case_3() { int Arr0[] = {2,2,2,2,2,2,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maxK(Arg0)); }
    void test_case_4() { int Arr0[] = {1,2,3,1,2,4,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, maxK(Arg0)); }
    void test_case_5() { int Arr0[] = {2,3,5,7,11,13,17,19,23,29}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, maxK(Arg0)); }

    // END CUT HERE

    //}}}e


    int maxK(vector <int> len) ;
};

int FoxAndKgram::maxK(vector <int> len){
  int rval=0;
  int h[101];
  REP(i,101) h[i]=0;
  REP(i,len.size()) {
    h[len[i]]++;      
  }
  REP(l, 101) {
    int cnt = h[l];
    REP(i,101) if(i && i<l-1-i) cnt+=min(h[i],h[l-1-i]);
    if(l%2) {
      cnt+=h[l/2]/2;
    }
    if(cnt>=l) rval=l;
  }
  return rval;

}
//{{{b
int main() {
  FoxAndKgram ___test;
  ___test.run_test(-1);
}
//}}}e

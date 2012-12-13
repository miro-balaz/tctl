//{{{b

//}}}e
#line 5 "FoxAndDoraemon.cpp"
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

class FoxAndDoraemon {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 1002; verify_case(0, Arg2, minTime(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,6,9,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 2012; verify_case(1, Arg2, minTime(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000,100,10,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1001; verify_case(2, Arg2, minTime(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1712,1911,1703,1610,1697,1612}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 2012; verify_case(3, Arg2, minTime(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3000; int Arg2 = 15000; verify_case(4, Arg2, minTime(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {58}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3600; int Arg2 = 58; verify_case(5, Arg2, minTime(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int minTime(vector <int> workCost, int splitCost) ;
};

int FoxAndDoraemon::minTime(vector <int> w, int splitCost){
  sort(w.begin(), w.end(), greater<int>());
  int rval=w[0]+splitCost*w.size();
  int l=0;
  int r=rval;
  int n=w.size();
  while(l+1<r) {
    int c=(l+r+1)/2;
    int ok=1;

    int x=1;
    int critical=0;
    int time=0;
    
    while(ok && x<n-critical) {
      while(critical<n && time + splitCost + w[critical] >c) {
        x--;
        critical++;
        if(x<0) {
          ok=0;
          break;
        }
      }
      if(x==0 && critical<n) {
        ok=0;
        break;
      }
      x+=x;
      time+=splitCost;
      

    }

    if(critical<n && time+w[critical]>c){
      ok=0;
    }

    if(ok) {
      r=c;
    } else {
      l=c;
    }
  }
  return r;
}
//{{{b
int main() {
  FoxAndDoraemon ___test;
  ___test.run_test(-1);
}
//}}}e

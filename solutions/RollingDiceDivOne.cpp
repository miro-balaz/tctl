//{{{b

//}}}e
#line 5 "RollingDiceDivOne.cpp"
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

class RollingDiceDivOne {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); 
          if ((Case == -1) || (Case == 4)) test_case_4(); 
          if ((Case == -1) || (Case == 5)) test_case_5(); 
        }
        private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6, 6, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 11LL; verify_case(0, Arg1, mostLikely(Arg0)); }
	void test_case_1() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, mostLikely(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(2, Arg1, mostLikely(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 10, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(3, Arg1, mostLikely(Arg0)); }
	void test_case_4() { int Arr0[] = {382828264, 942663792, 291832707, 887961277, 546603677, 545185615, 146267547, 6938117, 167567032, 84232402,
700781193, 452172304, 816532384, 951089120, 448136091, 280899512, 256093435, 39595226, 631504901, 154772240}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4366828428LL; verify_case(4, Arg1, mostLikely(Arg0)); }

	void test_case_5() { int Arr0[] ={1, 1, 3, 7, 8, 5, 8, 8, 3, 8, 5, 4, 5, 7, 1, 7, 2, 1, 6, 1, 1, 1, 3, 3, 1} ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 62LL; verify_case(5, Arg1, mostLikely(Arg0)); }
// END CUT HERE

//}}}e


	long long mostLikely(vector <int> dice) ;
};

long long RollingDiceDivOne::mostLikely(vector <int> dice){
long long l,r;
  sort(dice.begin(),dice.end());
  reverse(dice.begin(), dice.end());
  REP(i,dice.size()) dice[i]--;
  if(dice.size()==1) {
    l=0;
  } else {
    l = dice[1];
    r = dice[0];
    for(int i=2;i < (int)dice.size();++i) {
      long long k=dice[i];
      long long len=r-l+1;
      printf("Processing k=%lld len=%lld l=%lld r=%lld\n",k,len,l,r);
      if(k<len) {
        l+=k;
      } else {
        if(len%2!=k%2) {
          if(len%2) {
            l=r=l+len/2+(k+1)/2;
          } else {
            l=r=l+len/2-1+(k+1)/2;
          }
        } else {
          if(len%2) {
            l=l+ len/2+k/2;
          } else {
            l=l+ len/2-1+k/2;
          }
          r=l+1;

        }
      }
      printf("Result = l=%lld r=%lld\n",l,r);
    }
    /*static long long int f[300][300];
    int m=150;
    REP(i,m) REP(j,m) f[i][j]=0;
    f[0][0]=1;
    printf("i=0---");
    REP(i,dice.size()) {
      REP(j,m) {
        REP(x,dice[i])if(x<=j) {
          f[i+1][j]+=f[i][j-x];
        }
        printf("(%d)%02lld ",j,f[i+1][j]);
      }
      printf("\n i=%d---",i+1);
    }*/

  }
  return l + dice.size();
}
//{{{b
int main() {
  RollingDiceDivOne ___test;
  ___test.run_test(5);
}
//}}}e

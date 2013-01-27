//{{{b

//}}}e
#line 5 "TheDivisionGame.cpp"
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

class TheDivisionGame {
  public:
    //{{{b

    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 999805519; int Arg1 = 1000072678; long long Arg2 = 34556370200LL; verify_case(0, Arg2, countWinningIntervals(Arg0, Arg1)); }
    //999805519, 1000072678
    void test_case_1() { int Arg0 = 2; int Arg1 = 5; long long Arg2 = 9LL; verify_case(1, Arg2, countWinningIntervals(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 2; int Arg1 = 6; long long Arg2 = 13LL; verify_case(2, Arg2, countWinningIntervals(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 2; int Arg1 = 100; long long Arg2 = 4345LL; verify_case(3, Arg2, countWinningIntervals(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 12566125; int Arg1 = 12567777; long long Arg2 = 1313432LL; verify_case(4, Arg2, countWinningIntervals(Arg0, Arg1)); }

    // END CUT HERE

    //}}}e


    long long countWinningIntervals(int L, int R) ;
};
// prvocisla do 32000
int D[1000002];
int C[1000002];
long long TheDivisionGame::countWinningIntervals(int L, int R){
  int x=0;
  long long xc=0;
  vector<int> primes;
  for(int i=2;i*i<=R;++i) {
    bool is_prime = 1;
    for(int j=2;j*j<=i;++j) if(i%j==0) is_prime=false;
    if(is_prime) primes.push_back(i);
  }
  cout<<"pici"<<endl;
  for(long long i=L;i<=R;++i) {
    D[i-L]=0;    
    C[i-L]=i;

  }
  REP(i, primes.size()) {
long    long c=primes[i];  //bug: given long instead of long long
    int ok=1;
    while(ok) {
      ok=0;
      //cout<<c<<endl;
      for(long long j=(c-L%c)%c; j<=R-L; j+=c) {

        D[j]++;
        C[j]/=primes[i];
        ok=1;
      }
      c=c*primes[i];
    }
  }
  cout<<"kokot"<<endl;
  for(int i=0;i<=R-L;++i) {
    if (C[i]!=1) D[i]++;
  }
  int M=32;
  long long H[32];
  REP(i,M) H[i]=0;
  H[0]=1;
  for(int i=0;i<=R-L;++i) {
    x^=D[i];
    if(x>=M) return 0;
    xc+=H[x];
    H[x]++;
  }
  long long n=R-L+1;
  return  (n*(n+1)/2)-xc; //bug: forgot to return complement, so reviewed correct solution

//you must not get scared when you see too hard statement, 

}
//{{{b
int main() {
  TheDivisionGame ___test;
  ___test.run_test(-1);
}
//}}}e

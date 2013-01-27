//{{{b

//}}}e
#line 5 "PenguinEmperor.cpp"
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

class PenguinEmperor {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 2LL; int Arg2 = 2; verify_case(0, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 3LL; int Arg2 = 2; verify_case(1, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 36LL; int Arg2 = 107374182; verify_case(2, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 300; long long Arg1 = 751LL; int Arg2 = 413521250; verify_case(3, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 300; long long Arg1 = 750LL; int Arg2 = 0; verify_case(4, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 350; long long Arg1 = 1000000000000000000LL; int Arg2 = 667009739; verify_case(5, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 5; long long Arg1 = 7LL; int Arg2 = 12; verify_case(6, Arg2, countJourneys(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int countJourneys(int numCities, long long daysPassed) ;
};
#define MOD 1000000007
typedef long long int num;
vector<num> mul(vector<num> a, vector<num> b) {
  vector<num> rval(a.size()*2,0);
  REP(i,a.size()) if(b[i]){
    REP(j,a.size()) {
      rval[i+j]+=(b[i]*a[j])%MOD;

    }
  }
  REP(i,a.size()) {
    rval[i]=(rval[i]+rval[i+a.size()])%MOD;
  }
  rval.resize(a.size());
  
  return rval;
}
vector<num> modexp(vector<num> a,num exp) { //bug: int exp
  if(exp==0) {
    vector<num> X(a.size(), 0);
    X[0]=1;
    return X;
  }
  vector<num> Y = modexp(a,exp/2);
  Y=mul(Y,Y);
  if(exp&1) {
    Y=mul(Y,a);
  }
  return Y;
}
int PenguinEmperor::countJourneys(int n, long long k){
  vector<vector<num> > D;
  D.push_back(vector<num>(n,0)) ;
  D[0][0]=1;
  REP(i,n-1) {
    vector<num> x(n,0);
    x[i+1]=1;
    x[n-i-1]=1;
    D.push_back(mul(D[i], x));
  }
  vector<num> X=modexp(D[n-1], k/n); //bug: n/k
  X=mul(X, D[k%n]);
  return X[0];

   
}
//{{{b
int main() {
  PenguinEmperor ___test;
  ___test.run_test(-1);
}
//}}}e

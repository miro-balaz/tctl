//{{{b

//}}}e
#line 5 "RectangularSum.cpp"
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

class RectangularSum {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	//65, 42, 10441
        void test_case_0() { int Arg0 = 65; int Arg1 = 42; long long Arg2 = 10441LL; long long Arg3 = -1LL; verify_case(0, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 10LL; long long Arg3 = -1LL; verify_case(1, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 36LL; long long Arg3 = 9LL; verify_case(2, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 25; int Arg1 = 25; long long Arg2 = 16000LL; long long Arg3 = 32LL; verify_case(3, Arg3, minimalArea(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 1000000; long long Arg2 = 1000000000000LL; long long Arg3 = 2LL; verify_case(4, Arg3, minimalArea(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	long long minimalArea(int height, int width, long long S) ;
};
void skus(long long W, long long H, long long width, long long height, long long S, long long &rval) {
  //cout<<W<<" "<<H<<endl;
  if(W > width || H>height) return;
  long long product = 2*S/W/H-W+1+width-width*H;
  //cout<<product<<endl;
  if(product % 2 || product<0) return;
  product/=2;
  long long x=product%width;
  long long y=product/width;
  if(y+H<=height && x+W<=width) {
    if(rval==-1 || rval>W*H){
      //cout<<"solution "<<x<<" "<<y<<"W="<<W<<"H= "<<H <<endl;
      rval=W*H;
    }
  }

}
long long RectangularSum::minimalArea(int height, int width, long long S){
  //sum =(x+x+W-1)*W/2*H + width*(y+y+H-1)*H  /2*W
  //2sum = W*H*(2x+W-1+(2y+H-1)*width   ) 
  vector<long long> divisors;
  long long x=2*S;
  for(long long u=1;u*u<=x;++u) {
    if(x%u==0) {
      divisors.push_back(u);
      divisors.push_back(x/u);
    }
  }
  sort(divisors.begin(), divisors.end());
  long long rval=-1;
  REP(i, divisors.size()) {
    REP(j,i+1) if(divisors[i]%divisors[j]==0){
      long long W1 = divisors[j];
      long long W2= divisors[i]/divisors[j];
      if(W1>W2) {
        break;
      }
      skus(W1,W2,width, height,S, rval);
      skus(W2,W1,width, height,S, rval);
    }
  }
  return rval;
}
//{{{b
int main() {
  RectangularSum ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "CheckerExpansion.cpp"
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

class CheckerExpansion {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 0LL; long long Arg2 = 0LL; int Arg3 = 4; int Arg4 = 4; string Arr5[] = {"....", "....", "....", "A..." }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, resultAfter(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 4LL; long long Arg2 = 1LL; int Arg3 = 3; int Arg4 = 4; string Arr5[] = {"A..", "...", "B..", ".B." }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, resultAfter(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 1024LL; long long Arg1 = 1525LL; long long Arg2 = 512LL; int Arg3 = 20; int Arg4 = 2; string Arr5[] = {"B...B...B...........", ".B.A.B.A.B.........." }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, resultAfter(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 53LL; long long Arg1 = 85LL; long long Arg2 = 6LL; int Arg3 = 5; int Arg4 = 14; string Arr5[] = {".....", ".....", "B....", ".B.A.", ".....", ".....", ".....", ".....", ".....", ".....", "B....", ".B...", "..B..", ".A.B." }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(3, Arg5, resultAfter(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

//}}}e


	vector <string> resultAfter(long long t, long long x0, long long y0, int w, int h) ;
};
typedef long long num;
string P[2]={"A.B.",".B.."};
char g(num t , num x, num y, num M){
  //cout <<t<<" "<<x<<" "<<y<<" "<<M<<endl;
  if(y<0 || x<0) return '.';
  if(y>=t) return '.';
  if((x+y)%2) return '.';
  if((x+y)/2>=t) return '.';
  if(y<2 && x<4) return P[y][x];
  if(x<M && y<M/2) return g(t,x,y,M/2);
  if(y<M/2) return g(t-M/2,x-M,y,M/2);
  if(x>=M+M/2) return '.';
  return g(t-M/2,x-M/2,y-M/2,M/2);


}
char f(num t, num x, num y) {
 num M=1;
while(M*2<=x) M*=2;
while(M<=y) M*=2;
return g(t,x,y,M);

}
vector <string> CheckerExpansion::resultAfter(long long t, long long x0, long long y0, int w, int h){
  vector<string> rval(h, string(w,'.'));
  REP(i,h)  {
    REP(j,w) {
      rval[i][j]=f(t,j+x0,h-i-1+y0);
    }
  }
return rval;  
}
//{{{b
int main() {
  CheckerExpansion ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "MagicCandy.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class MagicCandy {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; verify_case(0, Arg1, whichOne(Arg0)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 7; verify_case(1, Arg1, whichOne(Arg0)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 17; verify_case(2, Arg1, whichOne(Arg0)); }
	void test_case_3() { int Arg0 = 5265; int Arg1 = 5257; verify_case(3, Arg1, whichOne(Arg0)); }
	void test_case_4() { int Arg0 = 20111223; int Arg1 = 20110741; verify_case(4, Arg1, whichOne(Arg0)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; verify_case(5, Arg1, whichOne(Arg0)); }

// END CUT HERE

//}}}e


	int whichOne(int n) ;
};
int f(int a) { //floor square root of a
  return (int)sqrt(a);
}
int MagicCandy::whichOne(int n){
   vector<int> c;
   c.push_back(n);
   int a=n;
   while(a>1) {
     a=a-f(a);
     c.push_back(a);
   }
   int pos=1;
   for(int i=((int)c.size())-1;i>0;--i) { //y=x-f(x)   //x=y+f(x)
     int x=pos+f(pos);
     while(pos>x-f(x)) x++;
     pos=x;
   }
   return pos;
}
//{{{b
int main() {
  MagicCandy ___test;
  ___test.run_test(-1);
}
//}}}e

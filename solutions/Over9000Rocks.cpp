//{{{b

//}}}e
#line 5 "Over9000Rocks.cpp"
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

class Over9000Rocks {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {9000, 1, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9000, 2, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(1, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1001, 2001, 3001, 3001}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1003, 2003, 3003, 3003}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(2, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {9000,90000,1,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9000,90000,3,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 38; verify_case(3, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, countPossibilities(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int countPossibilities(vector <int> lowerBound, vector <int> upperBound) ;
};

int Over9000Rocks::countPossibilities(vector <int> lowerBound, vector <int> upperBound){
  int sum=1;  
 REP(i,upperBound.size()) sum+=upperBound[i];

 static char a[16000000];
 REP(i,sum) a[i]=0;
 a[0]=1;
 int is=0;
 REP(j,upperBound.size()) {
//  printf("%d\n",j);
   REP(i,sum) {
     int start=i-upperBound[j];
     int end=i-lowerBound[j];
     is +=(end>=0?a[end]&1:0)-(start>0?a[start-1]&1:0);
     if(is) a[i]|=2;    
   }
  REP(i,sum) a[i]=!!a[i];
 }
 int rval=0;
 REP(i,sum) if(i>9000)rval+=a[i];
 return rval;
}
//{{{b
int main() {
  Over9000Rocks ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "SwitchesAndLamps.cpp"
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

class SwitchesAndLamps {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNN", "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNY", "NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, theMin(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"YYN", "YNY", "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YNY", "NYY", "YNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, theMin(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, theMin(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"YYNNN", "NNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNY", "NNNYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, theMin(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, theMin(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int theMin(vector <string> switches, vector <string> lamps) ;
};

typedef long long int num;
int SwitchesAndLamps::theMin(vector <string> switches, vector <string> lamps){
   int n =switches[0].size();
   num a[50],b[50];
   REP(i,n) a[i]=b[i]=0;
   REP(i,switches.size()) {
     // bug index i , a zle uzatvorkovanie
     REP(j,n) a[j]=a[j]*2+(switches[i][j]=='Y');
     REP(j,n) b[j]=b[j]*2+(lamps[i][j]=='Y');
   }
   map<num, int> A,B;
   REP(i,n) A[a[i]]++;
   REP(i,n) B[b[i]]++;
   int m=0;

   REP(i, n) {
     num k=a[i];
     m=max(m,A[k]);
     if(A[k]!=B[k]) return -1;
   }
   int rval=0;
   while(m>1) {
     rval++;
     m=(m+1)/2;     
   }
   return rval;


}
//{{{b
int main() {
  SwitchesAndLamps ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "WolfInZooDivOne.cpp"
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

class WolfInZooDivOne {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 16; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {"0 4 2 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 9 5 9"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 225; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; string Arr1[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6419882; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	int count(int N, vector <string> L, vector <string> R) ;
};
vector<int> jo(vector<string> s) {
  string a;
  REP(i,s.size()) a.append(s[i]);
  istringstream is(a);
  vector<int> rval;
  int b;
  while(is>>b) rval.push_back(b);
  return rval;
}
typedef long long int num;
num q[300][300];
num MOD =1000000007;
int WolfInZooDivOne::count(int N, vector <string> L, vector <string> R){
   vector<int> l=jo(L);
   vector<int> r=jo(R);
   int m=l.size();
   int n=N;
   REP(i,n) REP(j,n) q[i][j]=0;
   REP(i,n) REP(j,i) q[i][j]=1;
//   REP(i,n) REP(j,n) q
   REP(i,n) {
     int lm=i;
     REP(j,m) if(r[j]>=i) lm=min(lm, l[j]); 
     REP(j,i)  {
       REP(k,j) if(k<lm){
        q[i][j]=(q[i][j]+q[j][k])%MOD;
       }

     }
   }
   num rval=1+n;
   REP(i,n) REP(j,i) rval=(rval+q[i][j])%MOD;
   return rval;
}
//{{{b
int main() {
  WolfInZooDivOne ___test;
  ___test.run_test(-1);
}
//}}}e

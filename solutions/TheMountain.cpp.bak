//{{{b

//}}}e
#line 5 "TheMountain.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(num i=0;i<(num)(n);++i)
class TheMountain {
	public:
//{{{b

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {0, 0, 0, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 2, 0, 1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4, 6, 9, 1, 3, 6}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 29; verify_case(0, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1, 0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 2, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 7, 6}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 40; verify_case(1, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {0, 0, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 2, 2, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 15; verify_case(2, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0, 0, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 8, 5, 8}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(3, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 3; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(4, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 123; int Arg1 = 45; int Arr2[] = {2, 3, 5, 7, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {13, 17, 19, 23, 29}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {100, 200, 300, 400, 500}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 367047; verify_case(5, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 200; int Arg1 = 200; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {666}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5737554; verify_case(6, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {0, 8, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 1, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 4, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 593; verify_case(7, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

//}}}e

	int minSum(int n, int m, vector <int> rowIndex, vector <int> columnIndex, vector <int> element); 
};
typedef long long int num;
void swX(vector<vector<num> > &v) {
  REP(i,v.size()) reverse(v[i].begin(), v[i].end());
}
void swY(vector<vector<num> > &v) {
  reverse(v.begin(), v.end());
}
#define INF 90000000000000LL
vector<vector<num > > compute(vector<vector<num> > &x) {
num n=x.size();num m=x[0].size();
vector<vector<num > > rval(n, vector<num>(m));
REP(i,n) REP(j,m) {
  num y=max(i?rval[i-1][j]:0, j?rval[i][j-1]:0 )+1;
  if(x[i][j]==-1) {
    rval[i][j]=y;
  } else {
    if(x[i][j]<y) {
      rval[i][j]=INF;
    } else {
      rval[i][j]=x[i][j];
    }
  }
}
return rval;
}
vector<vector<num > > prefix_sum(vector<vector<num> > x) {
num n=x.size();num m=x[0].size();
vector<vector<num > >rval(n, vector<num>(m));
REP(i,n) REP(j,m) {
  rval[i][j]=min( (i?rval[i-1][j]:0)+ (j?rval[i][j-1]:0) +x[i][j]-(i&&j?rval[i-1][j-1]:0), INF);
}
return rval;

}
int TheMountain::minSum(int n, int m, vector <int> rowIndex, vector <int> columnIndex, vector <int> element) {
  vector<vector<num> > M0,M1,M2,M3, S0,S1,S2,S3,X(n, vector<num>(m,-1));
  REP(i,rowIndex.size()) X[rowIndex[i]][columnIndex[i]]= element[i];
  M0=compute(X);
  S0=prefix_sum(M0);
  swX(X);
  M1=compute(X);
  S1=prefix_sum(M1);
  swX(M1);swX(S1);
  swY(X);
  M3=compute(X);
  S3=prefix_sum(M3);
  swX(M3);swY(M3);swX(S3); swY(S3);
  swX(X);
  M2=compute(X);
  S2=prefix_sum(M2);
  swY(M2);swY(S2);
  num rval=INF;
  REP(a,n)REP(b,m) {
    if(M0[a][b]==INF || M1[a][b]==INF || M2[a][b]==INF || M3[a][b]==INF) continue;
    num can=max(max(M0[a][b],M1[a][b]),max(M2[a][b], M3[a][b]));
    if(a && b)can+=S0[a-1][b-1];
    if(a && b+1<m)can+=S1[a-1][b+1];
    if(a+1<n && b)can+=S2[a+1][b-1];
    if(a+1<n && b+1<m)can+=S3[a+1][b+1];
    REP(i,a) can+=max(M0[i][b],M1[i][b]);
    for(int i=n-1;i>a;--i) can+=max(M2[i][b],M3[i][b]);
    REP(i,b) can+=max(M0[a][i],M2[a][i]);
    for(int i=m-1;i>b;--i) can+=max(M1[a][i],M3[a][i]);




    rval=min(rval, can);
  }
  if(rval>=INF) rval=-1;
  return rval;
  
}
//{{{b
int main() {
  TheMountain  ___test;
  ___test.run_test(-1);
  //01
  //23

}
//}}}e

//{{{b

//}}}e
#line 5 "MagicBlizzard.cpp"
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

class MagicBlizzard {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.2222222222222223; verify_case(0, Arg2, expectation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.666666666666667; verify_case(1, Arg2, expectation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,2,6,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.46525111252384; verify_case(2, Arg2, expectation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7,11,2,13,3,19,5,17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16,8,4,15,12,9,10,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 98.55659436211914; verify_case(3, Arg2, expectation(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0E10; verify_case(4, Arg2, expectation(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	double expectation(vector <int> range, vector <int> amount) ;
};
double f(int a) {
  return (2*a+1)*(2*a+1);
}
double MagicBlizzard::expectation(vector <int> range, vector <int> amount){
  vector<pair<int, int> > p;
  REP(i,range.size()) p.push_back(make_pair(range[i],amount[i]) );
  int ptr=0;
  sort(p.begin(),p.end());
  /*REP(i,p.size()) if(i) {
    if(p[i].first==p[ptr].first) {
      p[ptr].second+=p[i].second;
    } else {
      p[++ptr]=p[i];
    }
  }
  p.resize(ptr+1);*/
  double result=0;
  double cumulative_E=0;
  double cumulative_Esq=0;
  //E(x^2) = D(x)+E^2(x);
  //D(x) = p*(1-p)*k
  for(int i=p.size()-1;i>=0;--i) {
    double pr = 1.0/f(p[i].first);
    double E=pr*(double)p[i].second;
    double D=(1.0-pr)*E;
    double Esq = D+E*E;
    double area=f(p[i].first);
    if(i) {
      area-=f(p[i-1].first);
    }
    printf("area = %.5lf Esq=%.5lf E=%.5lf pr=%.5lf\n",area,Esq,E,pr);
    cumulative_Esq+=Esq+cumulative_E*E*2.0;
    cumulative_E += E;
    result+=area*cumulative_Esq;
    printf("cumE = %.5lf cum_Esq=%.5lf\n",cumulative_E,cumulative_Esq);
  }
return result;
}
//{{{b
int main() {
  MagicBlizzard ___test;
  ___test.run_test(-1);
}
//}}}e

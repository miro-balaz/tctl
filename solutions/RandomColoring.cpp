//{{{b

//}}}e
#line 5 "RandomColoring.cpp"
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
class Cube {
  public:
    double a[50][50][50];
    int max1,max2,max3;
    void init() {
      REP(i,max1)REP(j,max2)REP(k,max3) a[i][j][k]=0;

    }
    Cube(int a1,int a2,int a3):max1(a1),max2(a2),max3(a3){}
    void diff() {
      for(int i=max1-1;i>=1;--i) {
        REP(j,max2) REP(k,max3) a[i][j][k]-=a[i-1][j][k];
      }
      for(int i=max2-1;i>=1;--i) {
        REP(j,max1) REP(k,max3) a[j][i][k]-=a[j][i-1][k];
      }
      for(int i=max3-1;i>=1;--i) {
        REP(j,max1) REP(k,max2) a[j][k][i]-=a[j][k][i-1];
      }

    }
    void sum() {
      for(int i=1;i<max3;++i) {
        REP(j,max1) REP(k,max2) a[j][k][i]+=a[j][k][i-1];
      }
      for(int i=1;i<max2;++i) {
        REP(j,max1) REP(k,max3) a[j][i][k]+=a[j][i-1][k];
      }
      for(int i=1;i<max1;++i) {
        REP(j,max2) REP(k,max3) a[i][j][k]+=a[i-1][j][k];
      }

    }
   
    void cut_cube(int &s0,int &s1,int &s2, int &t1,int &t2,int &t3) {
      if(s0<0) s0=0;
      if(s1<0) s1=0;
      if(s2<0) s2=0;
      if(t1>max1) t1=max1;
      if(t2>max3) t2=max2;
      if(t3>max2) t3=max3;
    }
    void add_cube(int s0,int s1,int s2, int t0,int t1,int t2, double value) {
      cut_cube(s0,s1,s2,t0,t1,t2);
      int d[3]={t0-s0,t1-s1,t2-s2};
      int s[3]={s0-1,s1-1,s2-1};
      for(int i=0;i<8;++i) {
        bitset<3> bs(i);
        int x[3];
        REP(j,3) x[j]=s[j];
        REP(j,3) if(bs[j]) x[j]=d[j];
        if(x[0]<0) continue;
        if(x[1]<0) continue;
        if(x[2]<0) continue;
        if(bs.count%2) {
          a[x[0]][x[1]][x[2]]-=value;
        } else {
          a[x[0]][x[1]][x[2]]+=value;          
        }
      }

    }
    void add_cube(int s0,int s1,int s2, int t0,int t1,int t2, double value) {
     
    }
};
class RandomColoring {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 0; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; double Arg9 = 0.0; verify_case(0, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 0; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; double Arg9 = 0.22222222222222227; verify_case(1, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 2; int Arg3 = 2; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 3; int Arg8 = 3; double Arg9 = 1.0; verify_case(2, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 8; int Arg3 = 9; int Arg4 = 1; int Arg5 = 2; int Arg6 = 3; int Arg7 = 0; int Arg8 = 10; double Arg9 = 0.0; verify_case(3, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 8; int Arg3 = 9; int Arg4 = 1; int Arg5 = 2; int Arg6 = 3; int Arg7 = 4; int Arg8 = 10; double Arg9 = 0.37826245943967396; verify_case(4, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arg3 = 2; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 2; double Arg9 = 0.09090909090909148; verify_case(5, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE

//}}}e


	double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) ;
};

double RandomColoring::getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2){
   
}
//{{{b
int main() {
  RandomColoring ___test;
  ___test.run_test(-1);
}
//}}}e

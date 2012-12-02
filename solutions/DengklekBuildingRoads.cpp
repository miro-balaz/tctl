//{{{b

//}}}e
#line 5 "DengklekBuildingRoads.cpp"
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

class DengklekBuildingRoads {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; int Arg3 = 3; verify_case(0, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 3; int Arg3 = 4; verify_case(1, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(2, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 3; int Arg3 = 1; verify_case(3, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 5; int Arg3 = 26964424; verify_case(4, Arg3, numWays(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	int numWays(int N, int M, int K) ;
};
typedef long long int state[31][32][512];
state *p1;
state *p2;
state s1,s2;
#define MOD 1000000007
int DengklekBuildingRoads::numWays(int N, int M, int K){
   p1=&s1;
   p2=&s2;
   int max_par = 1<<(K+1);
   REP(i,M+1) REP(j,N+1) REP(x,max_par) s1[i][j][x]=0;
   s1[0][N][0] = 1;
   for(int n=N-2;n>=0;--n) {
    
     //printf("n=%d\n",n);
     state &NOW(*p1),&THEN(*p2);
     REP(i,M+1) REP(j,N+1) REP(p,max_par) {
        // printf("C)%d %d %x == %lld\n",i,j,p,p&1?0:NOW[i][n+2][p>>1]);
        if((p&1)==0 && (j+1>=N || j+1-n==K+1 )) {
          THEN[i][j][p]= NOW[i][n+2][p>>1];
        } else {
          THEN[i][j][p]=0;
        }
     }
     //printf("sub\n");
     REP(i, M+1) for(int j=min(n+K,N-1);j>n;--j) REP(p,max_par){
       if(j+1-n<=K && j+1<N) {
         //printf("A)%d %d %x += %lld\n",i,j,p,THEN[i][j+1][p]);
         THEN[i][j][p]+=THEN[i][j+1][p];         
         THEN[i][j][p]%=MOD;
       }
       if(i>0) {
         //printf("B)%d %d %x += %lld\n",i,j,p,THEN[i-1][j][p^1^(1<<(j-n))]);
         THEN[i][j][p]+=THEN[i-1][j][p^1^(1<<(j-n))];
         THEN[i][j][p]%=MOD;
       }
     }     
     swap(p1,p2);
   }

return (*p1)[M][1][0];
}
//{{{b
int main() {
  DengklekBuildingRoads ___test;
  ___test.run_test(-1);
}
//}}}e

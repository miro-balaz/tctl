//{{{b

//}}}e
#line 5 "SPartition.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include<cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class SPartition {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "oxox"; long long Arg1 = 2LL; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { string Arg0 = "oooxxx"; long long Arg1 = 0LL; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { string Arg0 = "xoxxox"; long long Arg1 = 4LL; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { string Arg0 = "xo"; long long Arg1 = 0LL; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { string Arg0 = "ooooxoox"; long long Arg1 = 8LL; verify_case(4, Arg1, getCount(Arg0)); }
	void test_case_5() { string Arg0 = "ooxxoxox"; long long Arg1 = 8LL; verify_case(5, Arg1, getCount(Arg0)); }

// END CUT HERE

//}}}e


	long long getCount(string s) ;
};
long long sw[40][20];
long long go2(int pos, int first);

int p[51];
int w[21];
int n;
int nd2;
inline long long go(int pos, int first) {
  if(sw[pos][first]!=-1) return sw[pos][first]; else
  return sw[pos][first]=go2(pos,first);
}
long long go2(int pos, int first) {
//  printf("pos=%d first=%d ",pos,first);
  //for(int i=0;i<nd2;++i) printf("%d",w[i]);
  //printf("==>");
  //for(int i=0;i<n;++i) printf("%d",p[i]);
  //printf("\n");
  int second =pos-first;
  //if(second<first) return go(pos, second);
  
  if( pos==n && first==nd2) return 1;
  if(pos==n) return 0;
  long long rv=0;
  if(first<nd2 && w[first]==p[pos]) {
   // printf("A\n");
    rv+=go(pos+1,first+1);
  }
  if(second <nd2 &&  w[second]==p[pos]) {
    //printf("B\n");
    rv+=go(pos+1,first);
  }
  return rv;
}
long long SPartition::getCount(string s){
  long long rv=0; 
  REP(i,s.size()) p[i]=s[i]=='x';
   n=s.size();
   nd2=n/2;
   REP(i,1<<nd2) {
     //printf("%d\n",i);
     REP(j,nd2) w[j]=  (i&(1<<j)) > 0;
     REP(j,n+1) REP(k,nd2+1) sw[j][k]=-1;
     rv+=go(0,0);
   }
   return rv;
}
//{{{b
int main() {
  SPartition ___test;
  ___test.run_test(-1);
}
//}}}e

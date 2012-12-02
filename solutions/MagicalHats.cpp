//{{{b

//}}}e
#line 5 "MagicalHats.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include<cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class MagicalHats {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"HHH",
 "H.H",
 "HH."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 9; verify_case(1, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"HH",
 "HH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(2, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"HHH",
 "HHH",
 "H.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13,13,13,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 13; verify_case(3, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"HHH",
 "HHH",
 "H.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13,13,13,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 26; verify_case(4, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"H.H.",
 ".H.H",
 "H.H."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = -1; verify_case(5, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"HHH",
 "H.H",
 "HHH",
 "H.H",
 "HHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33,337,1007,2403,5601,6003,9999}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 1377; verify_case(6, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arr0[] = {".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".....H.H.....",
 "......H......",
 ".....H.H.....",
 ".............",
 ".............",
 ".............",
 "............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 22; verify_case(7, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) ;
};
int moc[20];

int toTernary(int mask,int cnt) {
  int rval=0;
  REP(i,cnt) {
    if( mask &(1<<i)) rval+=moc[i]*2;else rval+=moc[i];
  }
  return rval;
}
int clearTernaryDigit(int t, int d) {
  int res=t%moc[d];
  int f=t/moc[d+1];
  return f*moc[d+1]+res;
}
int memo[2000000];
int possible[2000000];
int go(int t,int cnt, int ng) {
  int rval=-1;
  if(!possible[t]) return -1;
  if(memo[t]!=-2) {
    return memo[t];
  }
  vector<int> f;
  int k=t;
  REP(i, cnt) {
    f.push_back(k%3);
    k/=3;
  }
  if(ng==0) {
    rval=0;
    REP(i,cnt) if(f[i]==2) rval++;
  } else {
    REP(i,cnt) if(!f[i]) {
      int a=go(t+moc[i], cnt,ng-1);
      int b=go(t+2*moc[i], cnt,ng-1);
      if(a==-1 && b==-1) continue;
      if(b!=-1) if(a==-1 || a>b) a=b;
      if(rval==-1 || rval<a) rval=a;
    }
  }
  return memo[t] =rval;

}
typedef unsigned long long int num;
int MagicalHats::findMaximumReward(vector <string> board, vector <int> coins, int numGuesses){
 moc[0]=1;
 REP(i,14) if(i)moc[i]=moc[i-1]*3;
 memset(possible, 0, sizeof(possible));
 vector<int> x,y;
 num row_mask=0,col_mask = 0;
 REP(i,board.size()) {
   REP(j, board[0].size()) {
     if(board[i][j]=='H') {
       col_mask ^= 1LL<<(num)j;
       row_mask ^= 1LL<<(num)i;
       x.push_back(j);
       y.push_back(i);
     }
   }
 }
 int n=x.size();
 REP(mask, 1<<n) {
   num col=col_mask, row=row_mask;
   int cnt=0;
   REP(i, n) if(mask&(1<<i)) {
     col^=1LL<<(num)x[i];
     row^=1LL<<(num)y[i];
     cnt++;
   }
   if(!col && !row && cnt == (int)coins.size()) {
     cout<<mask<<endl;
     possible[toTernary(mask,n)]=1;
   }
 }
 for(int i=moc[n]-1;i>=0;--i) {
   if(possible[i]) {
     REP(j,n) {
       possible[clearTernaryDigit(i,j)]=1;
     }
   }
 }
 REP(i,moc[n]) memo[i]=-2; 
 int score = go(0,n, numGuesses);
 sort(coins.begin(), coins.end());
 int rval=0;
 if(score==-1) return -1;
 REP(i, score) rval+=coins[i];
 return rval;
}
//{{{b
int main() {
  MagicalHats ___test;
  ___test.run_test(-1);
}
//}}}e

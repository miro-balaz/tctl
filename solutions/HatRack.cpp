//{{{b

//}}}e
#line 5 "HatRack.cpp"
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

class HatRack {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {6,6,6,4,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,4,5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,2,2,11,11,8,8,3,3,4,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,11,8,12,13,9,10,4,5,7,6,14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 16LL; verify_case(4, Arg2, countWays(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(5, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	long long countWays(vector <int> knob1, vector <int> knob2) ;
};
// md=
int mc[50],p[50], dep[50], h[50][50];
vector<int> seen;
int n;
void go(int x, int l) {
  seen[x]=1;
  dep[x]=l;
  mc[x]=0;
  REP(i,n) if(h[x][i]) if(!seen[i]){
    mc[x]++;
    go(i,l+1);
    p[i]=x;
    
  }
}

int label[50];
void go2(int x) {
  REP(i,n) if(p[i]==x) {
    //bug: forgot recursive call
    go2(i);
    label[x]+=label[i];
  }
}
// je plny prave vtedy
long long HatRack::countWays(vector <int> knob1, vector <int> knob2){
   long long rval=0;
   n=knob1.size()+1;//bug: here was +1 forgotten
   if(n==2) return 2;
   
   REP(i,n) REP(j,n) h[i][j]=0;

   REP(i,n-1)  h[knob1[i]-1][knob2[i]-1]=h[knob2[i]-1][knob1[i]-1]=1;
   REP(root,n) {
     seen = vector<int>(n,0);
     p[root] = -1; //bug:forgot this
     go(root,0);
     int ok=1;
     int c1=0;
     REP(i,n) if(mc[i]==1) c1++;

     REP(i,n) if(mc[i]>2) ok=0;
     if(c1>1) ok=0;
     int md=0;
     REP(i,n) md = max(md, dep[i]);
     REP(i,n) if(mc[i]==1 && dep[i]!=md-1) ok=0;
     REP(i,n) label[i]=0;
     REP(i,n) if(mc[i]==0) {
       if (dep[i]==md) {
         if(mc[p[i]]==1) label[i]=1;
         else label[i]=0;
       } else if(dep[i]==md-1) {
         label[i]=2;
       } else ok=0;
     }
     if(!ok)continue;
     long x=1;
     go2( root );
     REP(i,n) REP(j,i) if(p[i]==p[j] && label[i]==label[j]) {
       x<<=1; //bug:here was rval instead of x
     }
     //cout<<root<< " " << x<<endl;
     rval += x;
     //can_swap[i]=1 iff it has 2children and thy ahve the same maximal height 2 depth and both can be swapper


   }
   return rval;
}
//{{{b
int main() {
  HatRack ___test;
  ___test.run_test(-1);
}
//}}}e

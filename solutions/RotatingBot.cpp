//{{{b

//}}}e
#line 5 "RotatingBot.cpp"
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

class RotatingBot {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, minArea(Arg0)); }
	void test_case_1() { int Arr0[] = {3,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(1, Arg1, minArea(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, minArea(Arg0)); }
	void test_case_3() { int Arr0[] = {9,5,11,10,11,4,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 132; verify_case(3, Arg1, minArea(Arg0)); }
	void test_case_4() { int Arr0[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420; verify_case(4, Arg1, minArea(Arg0)); }
	void test_case_5() { int Arr0[] = {8,6,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, minArea(Arg0)); }
	void test_case_6() { int Arr0[] = {8,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 63; verify_case(6, Arg1, minArea(Arg0)); }
	void test_case_7() { int Arr0[] = {5,4,5,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(7, Arg1, minArea(Arg0)); }

// END CUT HERE

//}}}e


	int minArea(vector <int> moves) ;
};
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
   set<pair<int,int> > S;
   int mx,my,mix,miy;
   void compute() {
     mx=-10000000;
     my=-1000000;
     mix=1000000;
     miy=1000000;
     for(set<pair<int, int> >::iterator it=S.begin();it!=S.end();++it) {
       int x=it->first;
       int y=it->second;
       mx=max(mx,x);
       my=max(y,my);
       mix=min(x,mix);
       miy=min(y,miy);
     }
   }
int RotatingBot::minArea(vector <int> moves){
   int x=0;
   int y=0;
   S.clear();
   S.insert(make_pair(0,0));
   int s=0;
   REP(m, moves.size()) {
     REP(i,moves[m]) {
       int nx=x+dx[s];
       int ny=y+dy[s];
       if(S.count(make_pair(nx,ny))) {
         return -1;
       }
       if(m>=4 && (nx<mix || ny<miy || ny>my || nx>mx) ) return -1;
       S.insert(make_pair(nx,ny));
       x=nx;
       y=ny;
     }
     int nx=x+dx[s];
     int ny=y+dy[s];
     bool ok=false;
     if(m<=4) compute();
     if(S.count(make_pair(nx,ny)) ) ok=1;
     if(ny<miy || ny>my || nx<mix || nx>mx) ok=1;
     if(m==(int)moves.size()-1) ok=1;
     if(!ok) return -1;
     s=(s+1)%4;
   }
   compute();
   int sx=mx-mix+1;
   int sy=my-miy+1;
   return sx*sy;
}
//{{{b
int main() {
  RotatingBot ___test;
  ___test.run_test(-1);
}
//}}}e

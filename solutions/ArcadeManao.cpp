//{{{b

//}}}e
#line 5 "ArcadeManao.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>
#include<queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class ArcadeManao {
	public:
//{{{b

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"XXXX",
 "...X",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; int Arg3 = 4; verify_case(2, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; verify_case(4, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e

	int shortestLadder(vector <string> level, int coinRow, int coinColumn); 
};
int ArcadeManao::shortestLadder(vector <string> level, int coinRow, int coinColumn) {
 int n=level.size();
 int m=level[0].size();
 REP(i,n+1) {
  vector<vector<int> > p(n, vector<int>(m));
  queue<int> Q;
  p[n-1][0]=1;
  
  Q.push(n-1);
  Q.push(0);

  while(!Q.empty()) {
    int y=Q.front();Q.pop();
    int x=Q.front();Q.pop();
    vector<int> Nx;
    vector<int> Ny;
    Nx.push_back(x-1);
    Ny.push_back(y);
    Nx.push_back(x+1);
    Ny.push_back(y);
    
    REP(j,i+1) {
      Nx.push_back(x);
      Ny.push_back(y-j);
      Nx.push_back(x);
      Ny.push_back(y+j);
    }

    REP(j,Nx.size()) {
      int nx = Nx[j];
      int ny = Ny[j];
      if ( ny<0 || nx<0 || ny>=n || nx>=m) continue;
      if ( level[ny][nx] != 'X') continue;
      if ( ny == coinRow-1 && nx == coinColumn-1 ) return i;
      if ( p[ny][nx] ) continue;
      p[ny][nx]=1;
      Q.push(ny);
      Q.push(nx);
    }
  }

 }
 return -1; 
}
//{{{b
int main() {
  ArcadeManao  ___test;
  ___test.run_test(-1);
}
//}}}e

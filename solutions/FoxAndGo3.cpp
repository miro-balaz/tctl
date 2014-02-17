//{{{b

//}}}e
#line 5 "FoxAndGo3.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class FoxAndGo3 {
	public:
//{{{b

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"o.o",
 ".o.",
 "o.o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxEmptyCells(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 ".o.",
 "..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, maxEmptyCells(Arg0)); }
	void test_case_2() { string Arr0[] = {"xxxxx",
 "xxoxx",
 "xo.ox",
 "xxoxx",
 "xxxxx"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, maxEmptyCells(Arg0)); }
	void test_case_3() { string Arr0[] = {".xox.",
 ".o.ox",
 "x.o.o",
 "ox.ox",
 ".ox.."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, maxEmptyCells(Arg0)); }
	void test_case_4() { string Arr0[] = {"o.o.o",
 ".ox..",
 "oxxxo",
 "..x..",
 "o.o.o"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maxEmptyCells(Arg0)); }
	void test_case_5() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(5, Arg1, maxEmptyCells(Arg0)); }

// END CUT HERE

//}}}e

	int maxEmptyCells(vector <string> board); 
};
vector<vector<int> > edges;
map<pair<int, int >,int > flow;
map<pair<int, int >,int > cap;

void addedge(int a, int b){
  edges[a].push_back(b);
  edges[b].push_back(a);
  cap[make_pair(a,b)]=1;
  cap[make_pair(b,a)]=0;
  flow[make_pair(a,b)]=0;
  flow[make_pair(b,a)]=0;

}
int res(int a,int b) {
  pair<int, int> p(a,b);
  return cap[p]-flow[p];
}
void push(int a, int b, int v) {
  pair<int, int> p(a,b);
  pair<int, int> r(b,a);
  flow[p]+=v;
  flow[r]-=v;
}
vector<int> seen;
int go(int x, int dest) {
  if(seen[x]) return 0;
  seen[x]=1;
  if(x==dest) return 1;
  REP(i,edges[x].size()) {
    int y=edges[x][i];
    if(res(x,y)>0) {
      if(go(y,dest)) {
        push(x,y,1);
        return 1;
      }
    }
  }
  return 0;
}
int maxflow(int source, int destination, int n) {
  int rval=0;
  while(1) {
    seen=vector<int>(n);
    int i=go(source,destination);
    if(!i) break;
    rval+=i;
  }
  return rval;
}
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int FoxAndGo3::maxEmptyCells(vector <string> board) {
  cap.clear();
  flow.clear();
  int n=board.size();
  int nodes=n*n+2;
  edges=vector<vector<int > >(nodes);
//flow
  int source=n*n;
  int sink=n*n+1;
  int rval=0;
  REP(i,n) REP(j,n) {
    if(board[i][j]!='x') rval++;
    if(board[i][j]=='o') {
      addedge( source,i*n+j);
      int c=0;
      REP(s,4) {
        int ny=i+dy[s];
        int nx=j+dx[s];
        if(ny>=0 && ny<n && nx>=0 && nx<n) {
          if(board[ny][nx]=='.') c++;
          addedge(i*n+j,ny*n+nx);
        }
      }
      if(c==0) rval--;
    } else if(board[i][j]=='.') {
      addedge(i*n+j, sink);
    }
  }
  int min_cut=maxflow(source, sink,nodes);
  return rval-min_cut;
}
//{{{b
int main() {
  FoxAndGo3  ___test;
  ___test.run_test(3);
}
//}}}e

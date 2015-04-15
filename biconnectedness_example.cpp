//{{{b

//}}}e
#line 5 "BigO.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class BigO {
  public:
    //{{{b

    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"NYY",
      "YNY",
      "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, minK(Arg0)); }
    void test_case_1() { string Arr0[] = {"NYNNN",
      "NNYNN",
      "NNNYN",
      "NNNNY",
      "NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minK(Arg0)); }
    void test_case_2() { string Arr0[] = {"NYNNN",
      "YNNNN",
      "NNNYN",
      "NNNNY",
      "NNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minK(Arg0)); }
    void test_case_3() { string Arr0[] = {"NYYYNYYYNNYYYYYYNYNN",
      "NNNNYNYYNNYYYNYYNYYN",
      "NYNNYYYNNNYYYYNYNYNN",
      "NYYNNYYYYNNNYYNNYNYY",
      "NYNYNNNNNNYYYYYNYYYN",
      "YNNNNNNYNNYNNYYYYYYY",
      "NNYYNNNNNYNYNYNNYNYY",
      "NNYNYYNNNNYNYNYYYYNN",
      "NYYNYYNNNYNNYYYNYNYN",
      "YYNNYNNYYNYNNNNNYNNN",
      "YYNYYNNYYYNYYNYNYYYY",
      "YYNNYYNYNYNNNNYNNNNY",
      "NNYYNYYYNNNNNYYYYYNY",
      "YNNNYNNNNYNNNNNYNNNY",
      "YYYYNYYNNYNNNNNYNNNN",
      "NYYYYNYNYYNNYNNNYNNY",
      "YYYYYNNNYYYYNYYYNNYN",
      "NNYNNYNYNYNNNNNNYNYN",
      "YYNYYNNNNNYNNYNYNNNY",
      "YYYYNYNYYNNYNYNYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minK(Arg0)); }
    void test_case_4() { string Arr0[] = {"NYNYYYNYYYNYYNYYNYYNYYNYNNYYYYNNNYYNNNYNYYNYNNNYNY",
      "NNNNNNNNNNNNNNNNYNNNYNNNNNYNYNYNNNNNNYNNNNNNNNNNNN",
      "NYNYYYYNYNYYNNYYYYYYYYYYNYYYNYYYYYYNNYYYYYYYNNYYYY",
      "NYNNYYNNNNNNNNNNNYNNNYNYNNYNYNYYNYYNNYYYNNNNNNNYYY",
      "NNNNNNNNNNNNYNNYYNNNYNNNNYNNYNNYNNYNNYNYNNNNNNNYYN",
      "NNNNNNNNNNNNNNNNYNNNYNNNNNNNNNYNNNNNNYNNNNNNNNNNNN",
      "YYNYNNNYNYYYYNYYYYYYYYYYNYYYYYYYNYYNNYNYYYYYNNYNYY",
      "NYNYYNNNYYNNYNNYYYNNYYNYNYYNYYYNNNYNNYYYNNNNNNNYYY",
      "NYNYYYNYNYNNNNNYYYNNNNNNNYYNYYYYNYYNNYYYNNNNNNNYYY",
      "NYNNNYNNNNNNNNNYYNNNYNNNNNYNYNYNNYYNNYNYNNNYNNNNYN",
      "NYNYYYNNYYNYYNYNYYNYYYNYNYYNYYYYNYNNNNYYYYNYNNNYNY",
      "NYNNYYNNNYNNYNNYYYNNYYNNNYYNYYNNNYYNNNNYNNNYNNNYYY",
      "NNNNNNNNNNNNNNNYYNNNYNNNNNNNYNNYNYNNNYYNNNNNNNNYNN",
      "YYYYNYYYYYYYYNYYYYNYYYYYYYYYYYNYYNYYYNYYYYYNNYYNYN",
      "NYNYYNNYYYNYYNNYYYNYNYNYNYYNYYYYNYYNNYYYYYNYNNNNNY",
      "NYNNNNNNNNNNNNNNYNNNYNNNNNYNYNYYNYNNNNNNNNNNNNNNNN",
      "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN",
      "NYNNNYNNNNNNNNNYYNNNNNNNNNNNYNYYNYYNNYNNNNNNNNNYYN",
      "NYNYYYNNYYNYNNYYYYNYYYNYNYYYYNNYNNYNNYNYYYYNNNYYYY",
      "NNNYYYNNNYNYYNNYYYNNYYNNNYYNYYYYNYYNNNYYNYNYNNNYYY",
      "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN",
      "NYNNNYNNNNNNNNNYNNNNNNNNNYYNYYYYNYYNNYNNNNNNNNNYYN",
      "YYNYYYNNYYNYYNYNYYNYNYNYNYYYYYYYNYNNNYYYYYNYNNYYYY",
      "NYNYYYNNNNNNYNNNYYNNYYNNNYYNYYYYNYYNNYYYNNNNNNNYNY",
      "YNNNYYYYYYYYYNYYYYYYYYYNNYYNYNYNYNNYYYYYYYNYNNYYYY",
      "NYNNNYNNNNNNNNNYYNNNYNNNNNYNYNYYNYYNNNNYNNNNNNNYNN",
      "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN",
      "NYNYYYNYYYNYNNNNYYNYYNNYNYYNYYYYNYYNNNNNYYNYNNYYNN",
      "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
      "NYNNNYNNNNNNNNNYYNNNYNNNNNNNNNYYNYYNNNNYNNNNNNNYYY",
      "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
      "NNNNNNNNNNNNNNNNYNNNYNNNNNYNNNYNNNNNNNNNNNNNNNNNNN",
      "NYNYYNNYYYNNNNNYYYNYYYNNNYYYYYYYNYYNNYYYYNNYNNNNYY",
      "NNNNNNNNNNNNNNNYYNNNYNNNNNYNYNYYNNNNNYNNNNNNNNNNNN",
      "NYNNNNNNNNNNNNNNYNNNYNNNNNYNNNYYNNNNNNNNNNNNNNNYNN",
      "NYNYYYYYNYYYYNYYYYYYNYYYNNNYYYYYNYYNYNYYYYYYNYYYNY",
      "YYNYYYNYYYNNNNNYNYYYYNYNNNYYYYYYNYYNNYYNYNNYNNYNNY",
      "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
      "NYNNNYNNNNNNNNNYYNNNNYNNNNYNYNNYNNNNNYNYNNNNNNNYNN",
      "NYNNNYNNNNNNNNNYYNNNNNNNNYYNYNYNNYYNNNNNNNNNNNNYNN",
      "NYNYYYNYYYNYNNNNNYNNYYNYNNYNNYYYNYYNNYYYNNNNNNNYYY",
      "NYNYYNNNNYNYYNNYYYNYYYNNNYYNYYYNNYYNNYYYNNNYNNNNYY",
      "NYNYNYNYYYNYYNYYNYNYNYYYNNYYYYYYNNNNNYYYNYNYNNYNYY",
      "NYNNNYNNNYNNNNNYYYNNYNNNNNYNYNNNNYYNNYNYNNNNNNNYYN",
      "YYYNNYNYYYNYNNYYYYYNYYNYNYYYYYNYYNYNYYYYYNNYNNYNYN",
      "YYNNYYYYYYYNYNYYNYYYYYYYYYYNYYYNYYYNNYYYYNYYNNYYYY",
      "NYNNYYNYYYNNYNNYYYNYNYNYNYYNNYYNNYNNNYYYNYNYNNNNYY",
      "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN",
      "NNNNNNNNNNNNNNNNNNNNYNNNNNYNYNYNNNNNNYNNNNNNNNNYNN",
      "NYNNYYNNNNNNNNNYYNNNNNNNNYYNYNNYNYYNNYNYNNNNNNNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minK(Arg0)); }

    // END CUT HERE

    //}}}e

    int minK(vector <string> graph); 
};
int h[50][50];
int h2[50][50];
int n2;
int n;
vector<int> ts;
vector<int> seen;
vector<int> component;
void toposort(int node) {
  if(seen[node]) return;
  seen[node]=1;
  REP(i,n) if(h[node][i]) toposort(i);
  ts.push_back(node);
//  cout<<node<<endl;
}

void toposort2(int node) {
  if(seen[node]) return;
  seen[node]=1;
  REP(i,n2) if(h2[node][i]) toposort2(i);
  ts.push_back(node);
}
void mark(int node, int num) {
  if(component[node]!=-1) return;
  component[node]=num;
  REP(i,n) if(h[i][node]) mark(i,num);
}
int BigO::minK(vector <string> graph) {
  n=graph.size();
  REP(i,n) REP(j,n) h[i][j]=graph[i][j]=='Y';
  ts.resize(0);
  seen = vector<int>(n);
  REP(i,n) if(!seen[i])  toposort(i);
  int comp=0;
  component=vector<int>(n,-1);
  for(int pos=n-1;pos>=0;--pos) {
    int node=ts[pos];
    if(component[node]==-1) {
      mark(node, comp);
      comp++;
    }
  }
  cout<<comp<<endl;

  n2=comp;
  vector<int> comp_nodes(n2), comp_edges(n2);
  REP(i,n) comp_nodes[component[i]]++;
  REP(i,n2)REP(j,n2) h2[i][j]=0;
  REP(i,n) REP(j,n) if(h[i][j]){
    if(component[i]==component[j]){
      comp_edges[component[i]]++;
    } else {
      h2[component[i]][component[j]]=1;
    }
  }

  REP(i,n2) if(comp_nodes[i]>1 && comp_nodes[i]!=comp_edges[i]) return -1;
  seen=vector<int>(n2);
  ts.resize(0);
  REP(i,n2) if(!seen[i]) toposort2(i);
  vector<int> dp(n2);
  REP(pos, n2) {
    int i=ts[pos];
    int x=0;
    if(comp_nodes[i]>1) x=1;
    dp[i]=x;
    REP(j,n) if(h2[i][j]) {
      dp[i]=max(dp[i], dp[j]+x);

    }

  }
  int md= *max_element(dp.begin(), dp.end());
  if(md>1) return md-1;else return 0;

}
//{{{b
int main() {
  BigO  ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "ChromaticNumber.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include<queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class ChromaticNumber {
  public:
    //{{{b

    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minColors(Arg0)); }
    void test_case_1() { string Arr0[] = {"NYY",
      "YNN",
      "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minColors(Arg0)); }
    void test_case_2() { string Arr0[] = {"NYNN",
      "YNNN",
      "NNNY",
      "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minColors(Arg0)); }
    void test_case_3() { string Arr0[] = {"NYNY",
      "YNYY",
      "NYNN",
      "YYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minColors(Arg0)); }
    void test_case_4() { string Arr0[] = {"NYYYYYYY",
      "YNYYYYYY",
      "YYNYYYYY",
      "YYYNYYYY",
      "YYYYNYYY",
      "YYYYYNYY",
      "YYYYYYNY",
      "YYYYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, minColors(Arg0)); }

    // END CUT HERE

    //}}}e


    int minColors(vector <string> graph) ;
};

int ChromaticNumber::minColors(vector <string> graph){
  // there are at most 2 vertices to which a vertex is not connected
  // each independent set is at most 3 vertices large
  // dual graph is linearo kvadratic lonsists o lines or circles
  //each line =n elements (n+1)/2, circle size n= n/2
  int n=graph.size();
  vector<int> p(n,0);
  int rval = 0;
  REP(i,n) if(!p[i]){
    int pv=0;
    int ph=0;
    queue<int> Q;
    Q.push(i);
    p[i]=1;
    while(!Q.empty()) {
      int x=Q.front();Q.pop();
      pv++;
      REP(j,n) if(graph[x][j]=='N' && j!=x){
        ph++;
        if(!p[j]) {
          Q.push(j);
          p[j]=1;
        }
      }
    }
    ph/=2;
    if(pv==1) {
      rval++;
    } else if(pv==ph){
      if(pv==3) rval+=1;
      else rval+=(pv+1)/2;
    } else {
      rval+=(pv+1)/2;
    }

    
  }
  return rval;
}
//{{{b
int main() {
  ChromaticNumber ___test;
  ___test.run_test(-1);
}
//}}}e

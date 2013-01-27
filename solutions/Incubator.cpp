//{{{b

//}}}e
#line 5 "Incubator.cpp"
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

class Incubator {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NY","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYN", "NNY", "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_5() { string Arr0[] = {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_6() { string Arr0[] = {"Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, maxMagicalGirls(Arg0)); }

// END CUT HERE

//}}}e


	int maxMagicalGirls(vector <string> love) ;
};
int h[50][50];
int n;
vector<int> to,seen;
void go(int x) {
  if(seen[x]) return;
  seen[x]=1;
  REP(i,n) if(h[x][i]) {
    go(i);
  }
  to.push_back(x);
}

vector<int> label;
void go2(int x, int lab) {
  if (seen[x]) return;
  seen[x]=1;
  label[x]=lab;
  REP(i,n) if(h[i][x]) {
    go2(i, lab);
  }
}
int Incubator::maxMagicalGirls(vector <string> love){
  n = love.size();
  REP(i,n) REP(j,n) h[i][j]=love[i][j]=='Y';
  seen=vector<int>(n,0);
  REP(i,n) go(i);
  seen = label=vector<int>(n,0);
  int ln=0;
  for(int i=n-1;i>=0;--i) if(!seen[to[i]]){
//    cout<<to[i]<<endl;
    go2(to[i], ln);
    ln++;
  }
//  cout<<ln<<endl;
  vector<int> kok(ln,1);
  REP(i,n) REP(j,n) if(h[i][j] && label[i] != label[j]) kok[label[i]]=0;
  int rval=0;
  REP(i,n) {
  //  cout<<label[i]<<endl;
  }
  REP(i,ln) {
    rval+=kok[i];
  }
  return rval;
   
}
//{{{b
int main() {
  Incubator ___test;
  ___test.run_test(2);
}
//}}}e

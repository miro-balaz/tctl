//{{{b

//}}}e
#line 5 "CirclesGame.cpp"
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

class CirclesGame {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(0, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(1, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(2, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0, 0, 0, 10, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 1, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(3, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {10,20,30,40,50,60,70,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,7,6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,2,2,2,2,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(4, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0, 3, 6, 9, 12, -4747, -4777}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-5858, -5858, -5858, -5858, -5858, 777, 777}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {58, 1, 1, 1, 1, 44, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(5, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(6, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e
	string whoCanWin(vector <int> x, vector <int> y, vector <int> r) ;
};

int h[50][50];
int n;
vector<int> seen;
vector<int> grundy;
int get_root(int x) {
  REP(i,n) if(h[i][x]) return get_root(i);
  return x;
}
int get_grundy(int x);
int dva=0;
void find_grundy(int x, int rest_grundy, set<int> &grundy_set) {
  REP(i,n) if(h[x][i]){
    rest_grundy ^= get_grundy(i); //bug
  }
  grundy_set.insert(rest_grundy);
  REP(i,n) if(h[x][i]) {
    find_grundy(i, rest_grundy ^ get_grundy(i), grundy_set);
  }



}
int get_grundy(int x) {
//  cout<<x<<endl;
  if (grundy[x]!=-1) {
    return grundy[x];
  }
  if(x==2) dva=1;
  set<int> gs;
  find_grundy(x, 0, gs);
  REP(i, n+n+1) if( gs.find(i) == gs.end() ) {
    if(x==2) dva=0;
    return grundy[x] = i;
  }
  exit(1);
  
}
string CirclesGame::whoCanWin(vector <int> x, vector <int> y, vector <int> r){
   n=x.size();
   vector<pair<int, int> > I;
   REP(i,n) I.push_back(make_pair(r[i],i));
   sort(I.begin(), I.end());
   REP(i,n) REP(j,n) h[i][j]=0;
   REP(i_,n) for(int j_=i_+1;j_<n;++j_){ //bug: self loops, nad that there might be cycles
     int i=I[i_].second;
     int j=I[j_].second;
     int dx=x[i]-x[j];
     int dy=y[i]-y[j];
     if(dx*dx+dy*dy <r[j]*r[j] ) {
       h[j][i]=1;
       break;} //bug: graph was poorly constructed, we want transitive reduction
   }
   seen = vector<int>(n,0);
   grundy = vector<int>(n,-1);
    int grundy=0;
    REP(i,n) {
      int root=get_root(i); //bug: this was totally wrong i used the root multiple times
      if(!seen[root])    grundy ^=get_grundy(root);
      seen[root]=1;
    }

   if(grundy==0) return "Bob"; else return "Alice";


}
//{{{b
int main() {
  CirclesGame ___test;
  ___test.run_test(-1);
}
/// o: 1
/// o-o := 2
/// o-o-o
//}}}e

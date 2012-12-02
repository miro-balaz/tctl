//{{{b

//}}}e
#line 5 "CrossingTheRiver.cpp"
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

class CrossingTheRiver {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {3,4,4,5,5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arg4 = "POSSIBLE"; verify_case(0, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {3,4,4,5,6, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arg4 = "IMPOSSIBLE"; verify_case(1, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {4,4,4,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; string Arg4 = "POSSIBLE"; verify_case(2, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {5,5,5,5,5,5, 2,3,4,4,6, 7, 3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arg4 = "POSSIBLE"; verify_case(3, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 7; int Arr2[] = {6,6,6,6,6,6,6, 6,6,6,6,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; string Arg4 = "POSSIBLE"; verify_case(4, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; int Arr2[] = {5,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arg4 = "IMPOSSIBLE"; verify_case(5, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

//}}}e


	string isItEvenPossible(int waterWidth, int landWidth, vector <int> blockHeight, int depth) ;
};
int cnt[200];
vector<int> v;
int depth;
int waterWidth;
int go(int pos, int land_r, int height) {
  if(land_r) {
    if(pos<0) return 0;
    int h=v[pos];
    if(height-h!=0 && height-h!=1 && height!=-1) return 0;
    REP(i,cnt[v[pos]]) if(i<land_r){
      int j=i+1;
      cnt[v[pos]]-=j;
      if(go(pos-1, land_r-j, h)) return 1;      
      cnt[v[pos]]+=j;
    }
    return 0;
  } else {
    // also 0 is optional
    int y=0;
    REP(i,height+1) {
      if(cnt[i+depth]==0) {
        if(i!=0 && i!=height) {
          return 0;
        }
      }
      //cout<<i+depth<<"="<<cnt[i+depth]<<endl;
      y+=cnt[i+depth];
    }
    int rval= y>=waterWidth;
    //cout<<rval<<" height="<<height<<endl;
    return rval;
  }
}
string CrossingTheRiver::isItEvenPossible(int waterWidth, int landWidth, vector <int> b, int depth){
  int n=b.size();
  ::depth=depth;
  ::waterWidth = waterWidth;
  int a=0;
  sort(b.begin(), b.end());
  REP(i,n) if(b[i]==depth) a++;
  if(a>=waterWidth) return "POSSIBLE";
  map<int, int> x;
  REP(i, n) x[b[i]]++;
  for(map<int,int>::iterator it=x.begin();it!=x.end();++it) {
    v.push_back(it->first);
  }
  int rval=0;
  REP(i,v.size()) {
    REP(j,200) cnt[j] = x[j];
    rval|=go(i, landWidth, -1);
  }
    return rval?"POSSIBLE":"IMPOSSIBLE";
  //

     
}
//{{{b
int main() {
  CrossingTheRiver ___test;
  ___test.run_test(-1);
}
//}}}e

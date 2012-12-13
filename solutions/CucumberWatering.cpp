//{{{b

//}}}e
#line 5 "CucumberWatering.cpp"
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

class CucumberWatering {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 6, 8, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 6LL; verify_case(0, Arg2, theMin(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1000000000, 1000000000, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 3000000000LL; verify_case(1, Arg2, theMin(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {58, 2012}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; long long Arg2 = 0LL; verify_case(2, Arg2, theMin(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {9, -3, 14, 6, 5, -9, 32, 7, -5, 26, 2, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 58LL; verify_case(3, Arg2, theMin(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	long long theMin(vector <int> x, int K) ;
};
typedef long long num;
long long CucumberWatering::theMin(vector <int> x, int K){
  vector<pair<int,int> > v;
  int n=x.size();
  REP(i,n) v.push_back(make_pair(x[i],i));
  sort(v.begin(),v.end());

  vector<int> perm(n,0);
  REP(i,n) perm[v[i].second]=i;

  num d[51][51];
  num rval = 0;
  REP(i,n-1)  {
    rval+=abs(x[i]-x[i+1]);
  }
  REP(i,n) REP(j,n) d[i][j]=0;
  REP(pocet, K+1) {
    REP(now,n) {
      d[pocet][now]=0;
      if(pocet>=2) {
        for(int i=0;i<=now;++i) {
          num value = d[pocet-1][i];
          int a = v[i].first;
          int b=v[now].first; 
          REP(j,n-1) {
            int start=x[j];
            int end=x[j+1];
            if(end<start) swap(start,end);
            if (end<=a || start>=b) continue; 
            if(end>=b && start<=a) {
              value+=abs(b-a);
            } else if(start <=a && end<=b) {
              value+=abs(a-end)- min(abs(a-end),abs(b-end));
            } else if(start>=a && end>=b) {
              value+=abs(start-b)-min(abs(start-a),abs(start-b));
            } else {
              value+=abs(start-end)-min(abs(start-end), min(abs(a-start),abs(a-end))+min(abs(b-start),abs(b-end)));
            }

          }

          d[pocet][now]=max(d[pocet][now], value);
        }

      }
    }

  }
  num best=0;
  REP(i,n) best=max(best, d[K][i]);
  return rval-best;
}
//{{{b
int main() {
  CucumberWatering ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "TravellingPurchasingMan.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include<cstdio>
#include<queue>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class TravellingPurchasingMan {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
        void test_case_0() { int Arg0 = 4; string Arr1[] ={"140 141 1", "20 21 10", "10 40 20", "0 10 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 70", "1 2 10", "2 3 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, maxStores(Arg0, Arg1, Arg2)); }

	void test_case_1() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 30", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = {"0 1000 17"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, maxStores(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	int maxStores(int N, vector <string> interestingStores, vector <string> roads) ;
};
int h[50][50];
int M=3000000;
int d[65536];
typedef pair<int, int> pi;
typedef pair<int, pi> ipi;
int TravellingPurchasingMan::maxStores(int n, vector <string> interestingStores, vector <string> roads){
  int m= interestingStores.size();
  REP(i,n) REP(j,n) h[i][j]=M;
  REP(i,roads.size()) {
    int a,b,l;
    sscanf(roads[i].c_str(), "%d %d %d",&a,&b,&l);
    h[a][b]=l;
    h[b][a]=l;
  }
  vector<int> open,close, duration;
  REP(i,m) {
    int a,b,c;
    sscanf(interestingStores[i].c_str(), "%d %d %d",&a,&b,&c);
    open.push_back(a);
    close.push_back(b);
    duration.push_back(c);

  }
  REP(i,n) h[i][i]=0;
  REP(k,n) REP(i,n) REP(j,n) h[i][j] = min(h[i][j],h[i][k]+h[k][j]);
  REP(i,1<<m) d[i] = M;
  priority_queue< ipi,vector<ipi >,greater<ipi >  >Q;
  REP(i,m) {
    int s = 1 << i;
    int t0 = max(h[n-1][i], open[i]);
    if(t0 <= close[i]) {
      t0 += duration[i];
      d[s] = t0;
      Q.push(make_pair(t0, make_pair(s,i)));
    }
  }
  while(!Q.empty()) {
    int s = Q.top().second.first;
    int x=Q.top().second.second;
    int t0 = d[s];
    Q.pop();
    REP(i,m) {
      int t1 = max(t0+h[x][i], open[i]);
      if(t1 <= close[i]) {
        t1 += duration[i];
        int t = s | (1<<i);
        if(d[t] > t1) {
          d[t] = t1;
          Q.push(make_pair(t1,make_pair(t, i)));
        }
      }
    }
  }
  int rval=0;
  REP(i,1<<m) if(d[i]<M){
    bitset<16> g(i);
    rval=max<int>(rval, g.count());
    
  }

return rval;
}
//{{{b
int main() {
  TravellingPurchasingMan ___test;
  ___test.run_test(-1);
}
//}}}e

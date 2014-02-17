//{{{b

//}}}e
#line 5 "TheExperiment.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class TheExperiment {
	public:
//{{{b

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"341156"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 6; int Arg4 = 10; int Arg5 = 2; verify_case(0, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"999112999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; int Arg3 = 21; int Arg4 = 30; int Arg5 = 2; verify_case(1, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 3; int Arg5 = 0; verify_case(2, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"59059", "110", "1132230231"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 5; int Arg3 = 10; int Arg4 = 20; int Arg5 = 6; verify_case(3, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 8; int Arg3 = 4; int Arg4 = 2700; int Arg5 = 418629948; verify_case(4, Arg5, countPlacements(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

//}}}e

	int countPlacements(vector <string> intensity, int M, int L, int A, int B); 
};
vector<int> v;
int A,B;
int ok(int start, int end) {
  int c= v[end]-(start?v[start-1]:0);
  return (c>=A && c<=B);
}
typedef long long num;
num h[301][301][2];
inline void ADD(num &a, num b) {
a=(a+b)%1000000009;
}

int TheExperiment::countPlacements(vector <string> intensity, int M, int L, int A, int B) {
  ::A=A;
  ::B=B;
  string s;
  REP(i,intensity.size()) s.append(intensity[i]);
  int n=s.size();
   v =vector<int>(n);REP(i,n) v[i]=s[i]-'0';
  REP(i,n) if(i) v[i]+=v[i-1];
  REP(i,n) REP(j,n) REP(k,2) h[i][j][k]=0;
  h[0][0][0]=1;
  REP(count,M) {
    REP(start,n) {
      for(int end=start;end<n;++end) {
        num cnt_closed=0;
        num cnt_open=0;
        int length = end-start+1;
    //    cout<<start<<" "<<end<<" "<<ok(end-min(L, length)+1,end)<<endl;
        if (!ok(end-min(L, length)+1,end)) continue;

        // I am making interval from start to end that is closed
        ADD(cnt_closed , h[count][start][1] );
        if(length==L) {
          ADD(cnt_closed, h[count][start][0]);
        }
        if(length<L) {
          ADD(cnt_open, h[count][start][0]);
        }
        ADD(h[count+1][end+1][0], cnt_open);
        ADD(h[count+1][end+1][1], cnt_closed);

      }

    }
  }
  //REP(i,M+1) {
  //  REP(j,n+1) { //BUG
  //    cout<<"("<<h[i][j][0]<<","<<h[i][j][1]<<")";
  //  }
  //  cout<<endl;
  //}
  
  num rval=0;
  REP(i,n+1) ADD(rval, h[M][i][1]);
  return rval;





}
//{{{b
int main() {
  TheExperiment  ___test;
  ___test.run_test(-1);
}
//}}}e

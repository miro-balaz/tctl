//{{{b

//}}}e
#line 5 "ShoutterDiv1.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class ShoutterDiv1 {
	public:
//{{{b

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"22", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"11", "1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"21", "4"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"22", "2"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"00", "0"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"11", "1"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"43", "6"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 2; verify_case(0, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { string Arr0[] = {"00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"00"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"13"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"00"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"00"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"00"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"24"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = -1; verify_case(1, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { string Arr0[] = {"0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1234"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"0000"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"0000"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"0000"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"2345"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 6; verify_case(2, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { string Arr0[] = {"0000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0000000000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"7626463146"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"0000000000"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"0000000000"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"0000000000"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"9927686479"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 18; verify_case(3, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { string Arr0[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"50353624751857130208544645495168271486083954769538"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"85748487990028258641117783760944852941545064635928"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"61465744851859252308555855596388482696094965779649"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"37620749792666153778227385275518278477865684777411"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 333; verify_case(4, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE

//}}}e

	int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1); 
};
string j(vector<string> a) {
  string r;
  REP(i,a.size()) r.append(a[i]);
  return r;
}
vector<int> ga(string s1,string s10, string s100, string s1000) {
  vector<int> r;
  REP(i,s1.size()) {
     int a=(s1000[i]-'0');
     a=a*10+(s100[i]-'0');
     a=a*10+(s10[i]-'0');
     a=a*10+(s1[i]-'0');
     r.push_back(a);
  }
  return r;
}
int LD[5000],RD[5000];
int ShoutterDiv1::count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1) {
  vector<int> starts=ga(j(s1),j(s10),j(s100),j(s1000));
  vector<int> ends=ga(j(t1),j(t10),j(t100),j(t1000));
  vector<int> all=starts;
  REP(i,ends.size()) all.push_back(ends[i]);
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  int m=starts.size();
  REP(i,m) starts[i]=lower_bound(all.begin(), all.end(), starts[i])-all.begin();
  REP(i,m) ends[i]=lower_bound(all.begin(), all.end(), ends[i])-all.begin();
  int n = all.size();
  int inf=10000;
  int last_start=0;
  REP(i,m) last_start=max(last_start, starts[i]);
  REP(i,n) RD[i]=0;
  for(int i=last_start-1;i>=0;--i) {
    RD[i]=inf;
    REP(j,m) if(starts[j]<=i && ends[j]>i) RD[i]=min(RD[i], RD[ends[j]]+1);
  }
  int first_end=n-1;
  REP(i,m) first_end=min(first_end, ends[i]);
  REP(i,n) LD[i]=0;
  for(int i=first_end+1; i<n; ++i) {
    LD[i]=inf;
    REP(j,m) if(starts[j]<i && ends[j]>=i) LD[i]=min(LD[i], LD[starts[j]]+1);
  }
  int rval=0;
  REP(i,m) {
    int left=starts[i], right=ends[i];
    int best=LD[starts[i]] + RD[ends[i]];
    REP(j,m) if(ends[j] >= right && starts[j] <= left){
      best=min(best, 1 + RD[ends[j]]+LD[starts[j]]);
    }

    rval+=best;
  }
  if (rval>=inf) return -1;
  return rval;
}
//{{{b
int main() {
  ShoutterDiv1  ___test;

  ___test.run_test(-1);

}
//}}}e

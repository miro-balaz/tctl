//{{{b

//}}}e
#line 5 "BlurredDartboard.cpp"
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

class BlurredDartboard {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1274; int Arg2 = 50; verify_case(0, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 5; verify_case(1, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 7, 8, 1, 3, 2, 6, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2012; int Arg2 = 252; verify_case(2, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2012; int Arg2 = 307; verify_case(3, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = 84656087; verify_case(4, Arg2, minThrows(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int minThrows(vector <int> points, int P) ;
};
typedef long long  num;
int BlurredDartboard::minThrows(vector <int> points, int P){
  int ub=P;
 int lb=0;
 int largest_known = 0;
 int n=points.size();
 vector<int> m(n+1,1);
 REP(i, n) {
   if(points[i]>largest_known) largest_known = points[i];
   m[points[i]]=0;
 } 
 vector<int> unk;
 REP(i,n+1) if (i  && m[i]) unk.push_back(i);
 int unk_sum=0;
 REP(i,unk.size()) unk_sum += unk[i];  //TODO learn STL sum
 sort(unk.begin(), unk.end());
 if (unk.size() ==0 || (int)unk.size()*largest_known > unk_sum) {
   return (P+largest_known-1)/largest_known;
 }
 while(lb+1<ub) {
   num c=(ub+lb+1)/2;
   num mam = 0;
   REP(i,unk.size()) {
     num val = 0;
     REP(j,i) val+=unk[j];
     int rest = c- i;     
     if(rest<0) continue;
     num full_times = rest/unk.size();
     val+=full_times*unk_sum;
     val+=(rest-full_times*unk.size())*largest_known;
     if (val > mam) mam=val;
   }
   if(mam >=P) {
     ub=c;
   } else {
     lb=c;
   }
 }
 return ub;
}
//{{{b
int main() {
  BlurredDartboard ___test;
  ___test.run_test(0);
}
//}}}e

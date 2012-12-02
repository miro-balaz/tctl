//{{{b

//}}}e
#line 5 "StrIIRec.cpp"
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

class StrIIRec {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arg2 = "ab"; string Arg3 = "ba"; verify_case(0, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 1; string Arg2 = "efcdgab"; string Arg3 = "efcdgabhi"; verify_case(1, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 55; string Arg2 = "debgikjfc"; string Arg3 = "kjihgfedcba"; verify_case(2, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 0; string Arg2 = "e"; string Arg3 = "eabcdfghijklmno"; verify_case(3, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 20; string Arg2 = "fcdebiha"; string Arg3 = "fcdehigba"; verify_case(4, Arg3, recovstr(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	string recovstr(int n, int minInv, string minStr) ;
};

string StrIIRec::recovstr(int n, int minInv, string minStr){
  bitset<20> used;
  string rval;
  int is_larger=false;
  int inv_so_far=0;
  REP(i,n)  {
    int start=0;
    if(!is_larger && i<(int)minStr.size()) {
      start = minStr[i]-'a';
    }
    for(int j=start;j<n;++j) if(!used[j]){
      char c='a'+j;
      int after=0;
      REP(k,j) if(!used[k] ) after++;
      int free=n-used.count()-1;
      int inv = inv_so_far+after+free*(free-1)/2;
//      cout<<i<<" c="<<c<<" after = " << after <<" free="<<free<<" inv so far="<<inv_so_far<<" inv="<<inv<<endl;
      if(inv>=minInv) {
        used[j]=1;
        inv_so_far += after;
        rval.push_back(c);
        if(i>=(int)minStr.size() || c>minStr[i]) {
          is_larger = 1;
        }
        break;
      }
    }



  }
if((int)rval.size() != n) return "";
return rval;
}
//{{{b
int main() {
  StrIIRec ___test;
___test.run_test(-1);
}
//}}}e

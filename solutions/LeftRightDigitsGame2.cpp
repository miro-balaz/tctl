//{{{b

//}}}e
#line 5 "LeftRightDigitsGame2.cpp"
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

class LeftRightDigitsGame2 {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "565"; string Arg1 = "556"; string Arg2 = "556"; verify_case(0, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "565"; string Arg1 = "566"; string Arg2 = "655"; verify_case(1, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "565"; string Arg1 = "656"; string Arg2 = ""; verify_case(2, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "9876543210"; string Arg1 = "5565565565"; string Arg2 = "5678943210"; verify_case(3, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "8016352"; string Arg1 = "1000000"; string Arg2 = "1086352"; verify_case(4, Arg2, minNumber(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	string minNumber(string digits, string lowerBound) ;
};
bool can_start(string digits, string start) { //50*50*50*50 // for each index we walk all substrings and for each we check if it is again substring

}

// if we use suffix array
string LeftRightDigitsGame2::minNumber(string digits, string lowerBound){
  map<string, int> A;
  vector<string> B;
  int n = digits.size();
  A[""]=0;
  B.push_back("");
  REP(i,n) {
    for(int j=1;j<=n-i;++j) {
      string s = lowerBound.substr(i,j);
      if (A.find(s)==A.end()) {
        A[s]=B.size();
        B.push_back(s);
      }
    }
  }

  set<int> pref;
  string rval;
  REP(i,n+1) pref.insert(A[lowerBound.substr(0,i)]);
//  map<pair<int,char>, string> M;
  int K=B.size();
  vector<string> M(K*10);
  // for each substring i have one smallest that is greater or equal than minimum, but if i consider only the prefix i cann not know if it will be bigger
  int em = A[""];
  M[em*10+digits[0]-'0'] = digits.substr(0,1);
  REP(i,n) if(i){ //50
//    map<pair<int,char> ,string> nM;
    vector<string> nM(K*10);
    string x = digits.substr(i,1);
//    for(map<pair<int,char>, string>::iterator it = M.begin(); it != M.end();++it) {
    REP(o,M.size())if(M[o].size()!=0) { //25000
      //string S[2] = {x+B[it->first.first]+string(1,it->first.second), B[it->first.first]+string(1, it->first.second) + x};
//      string S[2]={x+it->second,it->second+x};
      // momorize only for long-est prefix and then deduce for all smaller prefixes
      // for prefix size x> only update prefixes of equal or bigger size
      string S[2]={x+M[o],M[o]+x};
      for(int f = 0; f < 2; ++f) {
        string s = S[f];
        for(int j=B[o/10].size();j<(int)s.size();++j) { //50
          string z = s.substr(0,j);
          char c=s[j];
//          cout<<"producing:" <<z <<","<< c<<ndl;
          if(A.find(z) != A.end()) { //50 * log 2000
            int a = A[z];
//            pair<int, char> pa(a,c);
            int pa=a*10+c-'0';
            if(nM[pa] == "" || nM[pa] >s) nM[pa]=s;
          }
        }
      }
    }
    M.swap( nM);
  }
  rval="";
  for(set<int>::iterator it=pref.begin(); it!=pref.end();++it) {
  
    for(char c='0'; c<='9';++c) {
//      pair<int, char> pa(*it, c);
      int pa=*it*10+c-'0';
      if(M[pa]!= "") {
        string s= M[pa];
  //      cout<<s<<endl;
        if(s>=lowerBound) {
          if(rval=="" || rval>s)rval=s;
        }
      }
    }
  }
  return rval;
}
//{{{b
int main() {
  LeftRightDigitsGame2 ___test;
  ___test.run_test(-1);
}
//}}}e

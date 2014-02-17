//{{{b

//}}}e
#line 5 "TheLargestString.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class TheLargestString {
	public:
//{{{b

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "zy"; string Arg2 = "by"; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abacaba"; string Arg1 = "zzzaaaa"; string Arg2 = "cbaaaa"; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "x"; string Arg1 = "x"; string Arg2 = "xx"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abbabbabbababaaaabbababab"; string Arg1 = "bababbaabbbababbbbababaab"; string Arg2 = "bbbbbbbbbbbbbbbbbbaaab"; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

//}}}e

	string find(string s, string t); 
};
void longine(string &s, string &t) {
  int length=s.size();
  string s2=s,t2;
  string best_s=s;
  string best_t=t;
  int best_length=length;
  REP(i,s.size()) {
    if(t[i]==s[0]) {
      length++;    
      t2.push_back(t[i]);
    } else {
      s2.resize(s2.size()-1);
      length--;
    }
    string can_s=s2+t2+t.substr(i+1);
    if(length>=best_length && can_s>best_s+best_t) {
      best_length = length;
      best_s=s2;
      best_t=t2+t.substr(i+1);
    }
  }
  s=best_s;
  t=best_t;
}
string TheLargestString::find(string s, string t) {
  if(s.size()==0) return "";
  int n=s.size();
  char largest='a';
  REP(i,n) largest=max(largest, s[i]);
  char l2='a';
  REP(i,n) if(s[i]==largest) l2=max(l2, t[i]);
  if(l2>largest) {
    string S(2,' ');
    S[0]=largest;
    S[1]=l2;
    return S;
  }
  string s2,t2;
  int last=0;
  REP(i,n) {
    if(s[i]==largest) {
      s2.push_back(s[i]);
      t2.push_back(t[i]);
      last=i;
    }
  }
  string rval=s2+t2;
  rval=max(rval, s2+find(s.substr(last+1),t.substr(last+1))+t2);
  longine(s2,t2);
  rval=max(rval, s2+t2);


return rval;
}
//{{{b
int main() {
  TheLargestString  ___test;
  ___test.run_test(3);
}
//}}}e

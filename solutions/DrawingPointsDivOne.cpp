//{{{b

//}}}e
#line 5 "DrawingPointsDivOne.cpp"
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

class DrawingPointsDivOne {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, maxSteps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, maxSteps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, maxSteps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-41,-40,1,-11,-32,-7,24,-11,49,-15,-22,20,-8,54,54,69,16,-30,36,-6,-30,40,64,20,-66,
 -37,-33,-18,-35,36,9,61,-43,45,5,60,-8,-58,65,-66,41,12,34,-11,-57,-38,46,63,-55,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,-24,-2,-4,23,14,1,70,-26,45,15,48,32,-41,54,-47,-67,-46,-9,-53,54,28,-61,11,53,68,
 -33,62,37,-8,-17,-17,48,19,-49,56,-41,16,17,-50,28,59,10,50,23,-16,56,31,-70,-44}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(3, Arg2, maxSteps(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	int maxSteps(vector <int> x, vector <int> y) ;
};

typedef pair<int, int> P;
class Stav {
  public:
 // vector<int> x, vector<int> y
  set<P> b;
  Stav(vector<int> x, vector<int> y) {
    REP(i,x.size()) b.insert(P(x[i],y[i]));    
  }
  Stav(const set<P> &x){
    b=x;
  };
  inline bool in(const P &x) {
    return b.find(x)!=b.end();
  }
  Stav get_next(){
    set<P> c;
    for(set<P>::iterator it=b.begin();it!=b.end();++it) {
      P d=*it;
      d.first++;
      if (!in(d)) continue;
      d.second++;
      if (!in(d)) continue;
      d.first--;
      if (!in(d)) continue;
      c.insert(*it);
    }
    return Stav(c);
  }
  Stav get_previous() {
    set<P> c;
    for(set<P>::iterator it=b.begin();it!=b.end();++it) {
      P d=*it;
      c.insert(d);
      d.first++;
      c.insert(d);
      d.second++;
      c.insert(d);
      d.first--;
      c.insert(d);
    }
    return Stav(c);

  }
  bool operator==(const Stav &x) {
    return includes(b.begin(), b.end(), x.b.begin(), x.b.end());
    //return this->b==x.b;
  }
  void print() {
    return;
    int mx=0;
    int my=0;
    int min_x=1000,min_y=1000;
    for(set<P>::iterator it=b.begin();it!=b.end();++it) {
      mx=max(mx, it->first);
      my=max(my, it->second);
      min_x=min(min_x, it->first);
      min_y=min(min_y, it->second);
    }
    for(int j=min_y;j<=my;++j) {
      for(int i=min_x;i<=mx;++i) {
        if(in(P(i,j))) cout<<"X";
            else cout<<".";
      }
      cout<<endl;
    }
    cout<<endl;
    
  }
};
typedef unsigned long long int N;
int DrawingPointsDivOne::maxSteps(vector <int> x, vector <int> y){
Stav s(x,y);
int cnt=0;
while(true) {
  Stav prev = s.get_previous();
  Stav check = prev.get_next();
//  cout << "iteration "<<cnt<<endl;
  //s.print();
 // cout<<"prev"<<endl;
  prev.print();
  //cout<<"ceck"<<endl;
  check.print();
  if(! include(s==check)) {
    //cout<<s.b.size()<< " "<<check.b.size()<<endl;
    return cnt;
  }
  cnt++;
  s=check;
  if(cnt>=150) return -1;
}


}
//{{{b
int main() {
  DrawingPointsDivOne ___test;
  ___test.run_test(3);
}
//}}}e

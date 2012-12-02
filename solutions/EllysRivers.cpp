//{{{b

//}}}e
#line 5 "EllysRivers.cpp"
#include<string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class EllysRivers {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100000; int Arg1 = 1; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 1.00000000005; verify_case(0, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10000; int Arg1 = 211; int Arr2[] = {911}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {207}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 48.24623664712219; verify_case(1, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1337; int Arg1 = 2; int Arr2[] = {100, 200, 300, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {11, 12, 13, 14}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 128.57830549575695; verify_case(2, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 77; int Arg1 = 119; int Arr2[] = {11, 12, 13, 14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100, 200, 300, 400}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.3842077071089629; verify_case(3, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 7134; int Arg1 = 1525; int Arr2[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 214.6509731258811; verify_case(4, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

//}}}e


	double getMin(int length, int walk, vector <int> width, vector <int> speed) ;
};

double sqr(double x) {
 return x*x;
}
class Element{
  public:
    int i_;
    int x_;
    double cost_;
    Element(int i,int x, double cost):i_(i), x_(x), cost_(cost){}
    bool operator<(const Element &e) const{
      return e.cost_<cost_;
    }
};  
double EllysRivers::getMin(int length, int walk, vector <int> width, vector <int> speed){
double rval=0;
priority_queue<Element> Q;
REP(i,speed.size())  {
  Q.push(Element(i,0,(sqrt(sqr(width[i])+1) - (double)width[i]) /speed[i] ));
}
REP(i, length) {
  Element e= Q.top();
  Q.pop();
  if(e.cost_ >1.0/walk) {
    Q.push(e);
    break;
  }
  e.x_++;
  double W=width[e.i_];
  double S=speed[e.i_];
  e.cost_= (
      sqrt(sqr(W)+sqr(e.x_+1)) -
      sqrt(sqr(W)+sqr(e.x_))
      )/S;
    Q.push(e);
}
double only_walk=length;
while(!Q.empty()) {
  Element e=Q.top();
  Q.pop();
  only_walk-=e.x_;
  int i=e.i_;
  rval+=sqrt(sqr(width[i])+sqr(e.x_))/speed[i];
}
rval+=only_walk/walk;
return rval;
}
//{{{b
int main() {
  EllysRivers ___test;
  ___test.run_test(0);
}
//}}}e

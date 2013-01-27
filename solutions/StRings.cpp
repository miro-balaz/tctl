//{{{b

//}}}e
#line 5 "StRings.cpp"
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

class StRings {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 4, 1, 5, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getSmallest(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getSmallest(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {3, 8, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 8, 6, 1, 2, 5, 4, 9, 10, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getSmallest(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {34, 68, 97, 87, 47, 39, 50, 59, 4, 7, 29, 91, 1, 80, 90, 95,
 60, 40, 43, 73, 54, 69, 32, 31, 53, 11, 84, 3, 28, 77, 44, 86,
 2, 75, 85, 52, 93, 81, 70, 89, 19, 67, 98, 100, 41, 65, 57, 27, 33, 49}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 6, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 30, 35, 36, 37, 38, 42, 45, 46, 48, 51, 55, 56, 58, 61, 62, 63, 64, 71, 66, 72, 74, 76, 78, 79, 82, 88, 83, 94, 96, 92, 99 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getSmallest(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getSmallest(Arg0, Arg1)); }

// END CUT HERE

//}}}e


	vector <int> getSmallest(int N, vector <int> first) ;
};
int uf[100000];
int find_set(int x) {
  int z,y=x;
  while(uf[y]>=0) y=uf[y];
  while(uf[x]>=0) {
    z=uf[x];
    uf[x]=y;
    x=z;
  }
  return y;
}
void merge(int a, int b) {
  int A=find_set(a);
  int B = find_set(b);
  if(-A<-B) swap(A,B);
  uf[A]+=uf[B];
  uf[B]=A;
}

vector <int> StRings::getSmallest(int N, vector <int> first){
//bug: this was totally stupid ide, because it is not guaranteed
  //  if(N==(int)first.size()) return first; //bug: forgot this special case, generaly at the begining haven't realized that it forms cycle at the end
  if(N==1) return vector<int>(1,1);//bug: forgot about this special case
  REP(i,N) uf[i]=-1;
  int n=first.size();
  REP(i,n) first[i]--;
  vector<int> rval;
  vector<int> used(N,0);
  REP(i,n) {
    used[first[i]]=1;
    int a=find_set(i);
    int b=find_set(first[i]);
    if(a==b && i!=N-1) return rval; //bug:here forgot this
    merge(a,b);
  }
//  cout<<"here"<<endl;
  int  x=0;
  while(x<N && used[x])x++;
  int y=x+1;
  while(y<N && (used[y] || find_set(y)==find_set(x)) ) y++;
  rval=first;
  for(int i=first.size();i<N-1;++i) {
    if(x==N) return vector<int>();
    if(find_set(i)!=find_set(x)) {
      rval.push_back(x);
  //    cout<<x<<endl;
      used[x]=1;
      merge(i,x);
      while(x<y && used[x]) x++;
      if(x==y) {
        y=x+1;
        while(y<N && (used[y] || find_set(y)==find_set(x)) ) y++;
      }
    } else {
      if(y>=N) return vector<int>();
      rval.push_back(y);
    //  cout<<y<<endl;
      merge(i,y);
      used[y]=1;
      while(y<N && (used[y] || find_set(y)==find_set(x)) ) y++;
    }
  }
  REP(i,N) if(!used[i]) rval.push_back(i);

  if(N>50) {
    REP(i,50) rval[i]=rval[N-50+i];
    rval.resize(50);
  }
  REP(i,rval.size()) rval[i]++;
  return rval;
// sketch
  // join components , if there are cycles return empty array
  // a[i]!=i  
  // for each i, found smallest not used number that would not create cycle, if i does not have incomming edge, insert edge there/ what if at the end we only have n

  // i would solve it by having each component in heap, but it could be also by keeping of range to which is the first component and then value of next free of different
}
//{{{b
int main() {
  StRings ___test;
  ___test.run_test(-1);
}
//}}}e

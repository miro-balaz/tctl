//{{{b

//}}}e
#line 5 "BuildingReorganization.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include <cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class BuildingReorganization {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; int Arg3 = 10; long long Arg4 = 215LL; verify_case(0, Arg4, theMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; int Arg3 = 10; long long Arg4 = 190LL; verify_case(1, Arg4, theMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {5, 50, 1, 50, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 4; int Arg3 = 10; long long Arg4 = 275LL; verify_case(2, Arg4, theMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {5, 50, 1, 50, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 4; int Arg3 = 1000; long long Arg4 = 10540LL; verify_case(3, Arg4, theMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {5, 50, 1, 50, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; int Arg3 = 1000; long long Arg4 = 104428LL; verify_case(4, Arg4, theMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {4,1,1,1000,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 4; int Arg3 = 1; long long Arg4 = 20LL; verify_case(5, Arg4, theMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {157,10,157,979797,152152152,156,4,77,157,79}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; int Arg3 = 123; long long Arg4 = 13041277280686205LL; verify_case(6, Arg4, theMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arr0[] = {346455317,453638062,491871419,297060164,426458223,53746370,422461742,231053793,309679268,297959075,
 76653026,277375296,411684823,427164497,257399925,224643292,114988354,457289888,51199847,199807287,
 110648220,303379857,435712111,245040291,401790144,260999362,6953083,385721020,438059362,434000869,
 481788278,70215282,135651128,68577856,448298562,11191117,408997160,407134756,10781024,267655550,
 183460325,284786399,222774818,193425138,51658225,117130718,352764522,342521474,147243649,265160879}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 44; int Arg3 = 9986066; long long Arg4 = 234928185619577559LL; verify_case(7, Arg4, theMin(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

//}}}e


	long long theMin(vector <int> heights, int A, int B, int cost) ;
};
typedef long long int num;
vector<num> w;
int A,B;
num cost;
num abs(num a) {
  if(a<0) return -a;
  return a;
}
num GetReserve(num pos, num from, num limit) {
  if(pos == A || pos == B) return 0;
  num rval = (limit - abs(pos-from)*cost-w[pos])+1;
  if(rval<0) return 0;
  return rval;
}
num GetCost(num pos, num from, num increment) {
  num rval;
  if(increment<=0) return 0;
//  printf("jebem pos:%lld from:%lld increment:%lld cost:%lld w[pos]:%lld\n",pos,from,increment, cost,w[pos]);
  rval =abs(pos-from)*cost*increment +     ((w[pos] + increment + w[pos] - 1LL) * increment) / 2LL;
  return 0;//rval % 47;
}

long long BuildingReorganization::theMin(vector <int> heights, int A, int B, int cost){
   int n=heights.size();
   w.clear();
   REP(i,n) w.push_back(heights[i]);
   ::A = A;
   ::B = B;
   ::cost = cost;
   num rval=-1;
   
#define BIG 2000000000LL
   for(int j=0;j<n;++j) if(j!= A && j!= B) {
     num too_little = -1;
     num enough = BIG*BIG;
     num kokos=-1;
     while(too_little+1<enough) {
       num test = (too_little +enough+1)/2;
       num x = w[A];
       vector<num> w_bck = w;
       num cost = 0 ;
       for(int i=0;i<=j;++i) {
         num res = GetReserve(i,A,test);
         if(res>x) res=x;
         x-=res;
         cost+=GetCost(i,A,res);
         w[i]+=res;
    //     printf("A:%lld\n",cost);
         if(!x) break;
       }
       if(x>0) {
         too_little = test;
       w=w_bck;
         continue;
       }
       
       x = w[B];
       for(int i=n-1;i>=j;--i) {
         num res = GetReserve(i,B,test);
         if(res>x) res=x;
         x-=res;
         cost+=GetCost(i,B,res);
         w[i]+=res;
  //       printf("B:%lld\n",cost);
         if(!x) break;
       }
       if(x>0) {
         too_little = test;
       w=w_bck;
         continue;
       }

       enough = test;
       kokos=cost;
//      if(j==2) printf("cost = %lld enough%lld\n",cost,enough);
       w=w_bck;
     }
     if(kokos!=-1) {
       if(rval==-1 || kokos<rval) rval = kokos;
     }
   }

   return rval+(w[A]-1LL)*w[A]/2LL + (w[B]-1LL)*w[B]/2LL;

}
//{{{b
int main() {
  BuildingReorganization ___test;
  ___test.run_test(-1);
}
//}}}e

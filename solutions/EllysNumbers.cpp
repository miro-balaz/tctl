//{{{b

//}}}e
#line 5 "EllysNumbers.cpp"
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
#include <cassert>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class EllysNumbers {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
          long long Arg0 =81072583964372LL; string Arr1[] ={"61478053 386433476 68068 154176113 1008436 848003 ", "193732 65413348 884338147 44387629 10206781 321577", "508 25055756 383135324 47851804 252109 10909444 30", "932 693930412 4285853 63427 35130316 21164 2547953", "2 13657732 901337276 206303636 112986692 605073469", " 18259 920227 54131 32164 247 661779196 3116 29725", "652 323323 21559604 260924 39569761 7727401 148666", "7 703703 1318724 513893 722228 30909604 6068 29598", "8 18636673 93431303 85387379 4921 1571908 35634264", "4 451137596 6263939 139134541 13 5031796 13633279 ", "19393 1708993 25789 1729 13902889 308 186176452 13", "889 145673 86439067 1986127 332519 559967012 29971", " 7667 24783229 435461 310403 42484 6649159 8877484", " 748619 36244 208470691 10204859 15470884 4917437 ", "1741844 45939644 10951556 78884 467236 14389004 43", "3411 251636 57643663 73109036 160433 597215372 345", "756268 775569284 157604"};
          vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
          long long Arg2 = 12LL; 
          verify_case(0, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 42LL; string Arr1[] = {"1 2 3 4 5 6 7 13 14 21 42"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(1, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1337LL; string Arr1[] = {"1 13 42 666 2674"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1073741824LL; string Arr1[] = {"1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 1",
 "6384 32768 65536 131072 262144 524288 1048576 2097",
 "152 4194304 8388608 16777216 33554432 67108864 134",
 "217728 268435456 536870912"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 7420738134810LL; string Arr1[] = {"435 625199055 4199 33263 17 222870 284870433 72093",
 "2379 7 11 31 247110827 23 1771 81809 851968487 13 ", 
 "476379795 1001 5 435274114 38264554 7429 239906525",
 " 3 227183706 887045414 606786670 3795 797605175 29",
 " 30 747186719 19 2 562347843 74 2294 588002688 743",
 "6429 703 591740547 36657492 37 444178205 1002001 2",
 "17626404"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 110LL; verify_case(4, Arg2, getSubsets(Arg0, Arg1)); }

// END CUT HERE

//}}}e



	long long getSubsets(long long n, vector <string> special) ;
};
vector<int> numbers;
typedef pair<int, long long> entry_t; 
typedef map<entry_t, long long> map_t;
map_t M;

#define M 20
long long X1[1<<M],X2[1<<M];
long long EllysNumbers::getSubsets(long long n, vector <string> special){
  string s;
 REP(i,special.size()) {
   s.append(special[i]);
 } 
 istringstream iss(s);
 int number;
 numbers.clear();
 while(iss>>number) numbers.push_back(number);
 sort(numbers.begin(), numbers.end());
 int was_one=0;
 if(numbers[0]==1) {
   was_one=1;
   numbers.erase(numbers.begin());
 }
 vector<long long> primes;
 long long d=n;
 vector<long long> good;
 REP(i,numbers.size()) {
   long long number=numbers[i];
   if(n% number==0 && __gcd(n/number,number)==1) good.push_back(number);
 }
 //printf("good numbers = ");
 //REP(i,good.size()) printf("%lld ",good[i]);
 //printf("\n");
 REP(i, good.size()) {
   long long other = n/d;
   long long number =good[i];
   number/=__gcd(other,number);
   //printf("%lld %lld %lld\n",number,d,d%number);
   if(d % number==0 && number!=1) {
     //printf("pushing %lld\n",number);
     primes.push_back(number);
     d/=number;
   }
 }
 vector<long long> base;
 base.swap(primes);
 REP(i,base.size()) {
   for(long long p=2;p*p<=base[i];++p) {
     if(base[i]%p==0) {

       long long moc=p;
       base[i]/=p;
       while(base[i]%p==0) {
         moc*=p;
         base[i]/=p;
       }
       primes.push_back(moc);
     }     
   }
   if(base[i]!=1) {
     primes.push_back(base[i]);
   }
 }
 if(d>1) return 0;
 vector<long long> masks;
 REP(i,good.size()) {
   long long mask=0;
   REP(j,primes.size()) {
     long long prime=primes[j];
     if ( good[i] % prime ==0 ) mask |= 1ll << j;
   }
   masks.push_back(mask);
 }
 int k = primes.size();
 int bound = 1ll << k;
 //vector<vector<string> > sol(bound);
 //sol[0].push_back("");
 REP(i,bound) X1[i] = 0;
 X1[0] = 1;
 REP(i,good.size()) {
   long long f = masks[i];
   REP(j,bound) if((j&f) == f){
     X1[j] += X1[j^f];     
     //REP(u,sol[j^f].size()) {
       //char c[4444];
       //sprintf(c,"%lld*%s",good[i], sol[j^f][u].c_str());
   //    sol[j].push_back(c);
     //}
   //  assert(X1[j] == sol[j].size());
   }
 }
   
 long long rval = X1[bound-1];
 if(was_one) {
   rval = rval * 2;
 }
 //REP(i,sol[bound-1].size()) {
 //  printf("*%s\n",sol[bound-1][i].c_str());
 //}
 //printf("primes = %d ",(int)primes.size());
 //REP(i,primes.size()) printf(" %lld ",primes[i]);
 //printf("\n");
 //REP(i,good.size()) if(good[i]==386433476){
 // printf("%llx\n", masks[i]);
 //}
 return rval;
 
}
//{{{b
int main() {
  EllysNumbers ___test;
  ___test.run_test(0);
}
//}}}e

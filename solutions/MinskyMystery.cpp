#line 5 "MinskyMystery.cpp"
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

class MinskyMystery {
	public:


	int computeAnswer(long long N) ;
};
//{79418294653}
//188092387
typedef long long num;
num go(num to, num n) {
  num rval=0;
  //printf("n=%lld to=%lld\n",n,to);
  num i=2;
  num one=1;
  num four=4;
  num p=1000000009;
  for(;i<=to-one;) {
    num start = i;
    num podiel = n/i;
    num end = n/podiel;
    
    if(end>to-one) end=to-one;
    //num inc = ( (podiel*(start+end)%p)*(end-start+1)/2)*4+(podiel+1)*(end-start+1);+n%i
    num pocet=(end-start+one)%p;
    num inc =  (n%p*pocet)%p*four%p+(podiel%p+one)*pocet;
    //printf("start=%lld end=%lld inc=%lld\n",start,end,inc);
    rval=(rval+inc)%p;
    i=end+one;

  }
  //+5
  //suma 2,5=23
  //suma 3,5=22
  //suma 4,5=22
  //suma 5,5=16
  //            88   
  return (rval+n*(num)3+n/to+to) % p;
}
int MinskyMystery::computeAnswer(long long N){
  if(N<=1) {
    return -1;
  }
  for(num i=2;i*i<=N;++i) {
    if(N%i==0) return go(i,N);
  }
  return go(N,N);

}



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

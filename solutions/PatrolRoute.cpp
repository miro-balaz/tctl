#line 5 "PatrolRoute.cpp"
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
// |a-b|+|b-c|+|c-a|
//2c
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class PatrolRoute {
	public:


	int countRoutes(int X, int Y, int minT, int maxT) ;
};
long long mod=1000000007;
int PatrolRoute::countRoutes(int X, int Y, int minT, int maxT){
   long long rval=0;
   REP(i,X+1) REP(j,Y+1) if(i>=3 && j>=3) {
      int t=2*i+2*j-4;
      if(t>=minT && t<=maxT) {
        long long mul=(X-i+1)*(Y-j+1);
        long long inc=(i-2)*(j-2);
        rval=(rval+inc*mul%mod)%mod;
        //printf("%d %d %lld %lld %lld\n",i,j,mul, inc,rval);
      }
   }
   return int((rval*6ll)%mod);
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

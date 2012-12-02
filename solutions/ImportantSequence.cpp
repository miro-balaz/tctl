#line 5 "ImportantSequence.cpp"
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

class ImportantSequence {
	public:


	int getCount(vector <int> B, string operators) ;
};
vector<int> eval(vector<int> a, string o, int v) {
vector<int> rval;
  REP(i,a.size()) {
    if(o[i]=='-') {
      v=v-a[i];
    } else {
      v=a[i]-v;
    }
    rval.push_back(v);
  }
  return rval;
}
int ImportantSequence::getCount(vector <int> B, string operators){
   vector<int> one=eval(B,operators,1);
   vector<int> zero = eval(B,operators,0);
   int low=1;  //must be at least
   int up=-1;  //maximum;
   REP(i,zero.size()) {
     if(one[i]>zero[i]) {
       //increasing so low limit can be set lowered
       low=max(low, -zero[i]+1);
     } else {
       int v=zero[i]-1;
       if(up==-1) up=v;
       else up=min(up, v);
     }
   }
   if(up==-1) return -1;
   if(low>up) return 0;
   return up-low+1;
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

#line 5 "TomekPhone.cpp"
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

class TomekPhone {
	public:


	int minKeystrokes(vector <int> occurences, vector <int> keySizes) ;
};

int TomekPhone::minKeystrokes(vector <int> o, vector <int> k){
sort(o.begin(), o.end());
vector<int> m(k.size());
int rval=0;
REP(i, o.size()) {
  int f=o[o.size()-i-1];
  int x=0;
  REP(j,k.size()) if(m[j]<k[j] && m[j]<m[x]){
    x=j;
  }
  if(m[x]==k[x]) return -1;
  m[x]++;
  rval+=m[x]*f;

}
return rval;
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

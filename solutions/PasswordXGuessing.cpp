#line 5 "PasswordXGuessing.cpp"
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

class PasswordXGuessing {
	public:


	long long howMany(vector <string> guesses) ;
};

long long PasswordXGuessing::howMany(vector <string> guesses){
int cnt = 0;
int n = guesses[0].size();
REP(c,10) {
  REP(j,n) {
    string  ps = guesses[0];  
    ps[j]='0'+c;
    int ok=1;
    REP(i,guesses.size()) {
      int cnt=0;
      REP(x,n) if (guesses[i][x]!=ps[x]) cnt++;
      if (cnt!=1) ok=0;
    }
    cnt+=ok;
  }
}
return cnt;
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

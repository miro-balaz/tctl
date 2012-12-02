#line 5 "GogoXMarisaKirisima.cpp"
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

class GogoXMarisaKirisima {
	public:


	int solve(vector <string> choices) ;
};


int GogoXMarisaKirisima::solve(vector <string> choices){
  int n=choices.size();
  vector<int> reachable(n,0);  //from 0
  vector<int> reaches(n,0);  // n-1 
  reachable[0]=1;
  reaches[n-1]=1;
  REP(x,n+3) {
    REP(i,n) REP(j,n) {
      reachable[j] |= reachable[i] & (choices[i][j]=='Y');
      reaches[i] |= reaches[j] & (choices[i][j]=='Y');
    }
  }
  int nodes=0;
  int edges=0;
  REP(i,n) nodes += reachable[i] && reaches[i];
  REP(i,n) REP(j,n) edges += reachable[i] && reaches[j] && (choices[i][j] == 'Y');
  if(nodes==0) return 0;
  return edges-nodes+2;
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

#line 5 "XorGame.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>
#include <bitset>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class XorGame {
	public:

	int play(string S, string E); 
};
int arr[16];
int solve(int x) {
  if(arr[x]==-2)  {
    if(x==4) 
    return 100;

  }
  if (arr[x]!=-1) return arr[x];
//  cout<<x<<endl;
  
  arr[x] = -2;
  int rval = 100;
  REP(i,5) REP(j,i+1) {//bug: forgot +1 
    int k = x;
    if (i != 4) for(int f=j;f<=i;++f) k ^= 1 << f;
    if(x == 5) {
      cout << k << " fuck " << x << endl;
    }
    if (k==0) return arr[x]=1; //bug: forgot to set this to 1, it is fail because item is marked with -2 :D

    int h_val=0;
    //if(x==10) cout<<k<<endl;
    REP(o,5) {
      int c = k;
      if (o!=4) c ^= 1 << o;
      int b = solve(c)+1;
      if( x==5 && k==6) {
        cout << c << " h " << b<<endl;
      }
      h_val = max(h_val, b);

    }
    rval = min(rval,h_val);    
  }
//  cout << "solve " << x<<" = "<<rval<<endl;
  if x==4 && rval
  return arr[x] = rval;

  
}
int go(vector<int> x ) {
  int cnt=0;
  int n=x.size();
  REP(i,n) if(x[i] && (i==0 || !x[i-1])) cnt++;
  if(cnt==1) return 1;
  if(cnt==0) return 0;
  if(n==3) return 2;
  if(n>4) return -1;
  REP(i,16) arr[i]=-1;
  arr[0]=0;
  int fff= solve(x[0]*8+x[1]*4+x[2]*2+x[3]);
//REP(i,16) cout<<i<<"=" <<arr[i]<<endl;
  return fff;
}
int XorGame::play(string S, string E) {
  vector<int> x;
  int n = S.size();
  REP(i, n) {
    x.push_back(S[i]^E[i]);
  }
  return go(x);
}
int main() {
  XorGame x;
  cout<<x.play("0000","1011")<<endl;
}

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

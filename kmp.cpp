#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
vector<int> get_matches(string hay, string needle) {
  int n=needle.size();
  vector<int> rval(hay.size());
  vector<int> jump(n+1);
  int j=-1;
  int i=0;
  jump[0]=-1;
  while(i<n) {
    if(j>=0 && needle[i]!=needle[j]) j=jump[j];else jump[++i]=++j;
  }
  i=0;
  j=-1;
  while(j<hay.size()) {    
    while(j>=0 && a[j] !=hay[i]) j=jump[j];
    j++;
    if(j==n) {
      rval[i-j+1]=1;
      j=jump[j];
    }
    ++i;
  }
  
  return rval;

}
int main() {
  int n,m,k;
  cin>>n>>m>>k;
  string s,t;cin>>s>>t;
  vector<int> v[4];
  char c[4]={'A','C','T','G'};
  REP(i,4) {
    v[i]=get_matches(s,t,c[i],k);
  }
  int rval=0;
  REP(i,n) {
    rval+=v[0][i]&v[1][i]&v[2][i]&v[3][i];
  }
  cout<<rval<<endl;

}

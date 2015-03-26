#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<stack>
// In this file there is euler tour computation using first random walk in graph to produce closed loops and then those loops are joined in next step
// does not use recursion much, but keeps stack of visited vertices(can be upgraded to set)
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
vector<vector<int> > g;
vector<int> edg;
vector<vector<int> > eu;
vector<pair<int, int> >output;
vector<int> used;
vector<vector<vector<int> > > tours; 
stack<int> visited;
void go(int x, int start_node) {

  vector<int> tour;
  while(used[x]<(int)g[x].size()) {
    for(int i=used[x];i<g[x].size();++i) {
      if(edg[eu[x][i]]==0) {
        edg[eu[x][i]]=1;
        used[x]=max(used[x],i+1);
        int y=g[x][i];        
        tour.push_back(y);      
        visited.push(y);
        x=y;      
        break;
      } else { 
        used[x]=max(used[x],i+1);
      }
    }
  }

  if(tour.size()>0) {
    tours[start_node].push_back(tour);
  }
}
vector<int> seen;
vector<int> result_tour;
int cld_2=0;
void iterate_tours(int x) {
  if(x==2) cld_2=1;
  seen[x]=1;
  REP(i,tours[x].size()) {
    REP(j,tours[x][i].size()) {
      int now=tours[x][i][j];
      result_tour.push_back(now);
      if(!seen[now]) {
        iterate_tours(now);
      }
    }
  }
}
int main() {
  int n,m;cin>>n>>m;
  tours.resize(n);
  seen=vector<int>(n);
  g=vector<vector<int> >(n);
  eu=vector<vector<int> >(n);
  used=vector<int>(n);
  REP(i,m) {
    int a,b;cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    eu[a].push_back(edg.size());
    g[b].push_back(a);
    eu[b].push_back(edg.size());
    edg.push_back(0);
  }
  // Add 
  vector<int> nonp;
  REP(i,n) if(g[i].size()%2) nonp.push_back(i);
  for(int i=0;i<(int)nonp.size();i+=2) {
    int a=nonp[i];
    int b=nonp[i+1];
    g[a].push_back(b);
    eu[a].push_back(edg.size());
    g[b].push_back(a);
    eu[b].push_back(edg.size());
    edg.push_back(0);
  }
  // possibly add loop
  int sum=0;
  REP(i,n) sum+=g[i].size();  
  if(sum/2%2) {
    int a=0;
    int b=0;
    g[a].push_back(b);
    eu[a].push_back(edg.size());
    g[b].push_back(a);
    eu[b].push_back(edg.size());
    edg.push_back(0);
  }
  //setup output
  visited.push(0);
  while(!visited.empty()) {
    int x=visited.top();
    visited.pop();
    go(x,x);
  }

  result_tour.push_back(0);
  iterate_tours(0);

  REP(i,result_tour.size()-1) {
    int a=result_tour[i];
    int b=result_tour[i+1];
    if(i%2) swap(a,b);
    output.push_back(make_pair(a,b));
  }

  cout<<output.size()<<endl;
  REP(i,output.size()) {
    cout<<(output[i].first+1)<<" "<<(output[i].second+1)<<endl;
  }
}

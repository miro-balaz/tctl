#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define N 500010
int start[N], end[N];
inline void MV(int &a, int b) {
  a=max(a,b);
}
class IntervalTree{
  public:
    int first;  // id of first
    vector<int> propagate,l,r,split,propagate;
    IntervalTree(int n){
      int m=1;
      while(m<n) m*=2;
      first = m-1;
      l.resize(2*m);
      r.resize(2*m);
      propagate.resize(2*m);      
      split.resize(2*m);
      propagate.resize(2*m);

      for(int i=first;i<(int)l.size();++i) {
        l[i]=r[i]=i-first;
      }
      for(int i=first-1;i>=0;--i) {
        l[i]=l[i*2+1];
        r[i]=r[i*2+2];
        split[i]=r[i*2+1];
      }
    }
    inline void update_max(int x) {
      propagate[x] = max(propagate[x] , ( x>=first?0:max(propagate[x*2+1], propagate[x*2+2])));
    }
    void update(int x, int left, int right, int value) {
      if(left>right) return;
      if(left==l[x] && right==r[x]) {
        propagate[x]=max(propagate[x],value);        
      } else {
        update(x*2+1, left, min(right,split[x]),value);
        update(x*2+2, max(left,split[x]+1), right,value);
      }
      update_max(x);
    }
    void set_max(int left, int right, int value) {
      update(0,left,right, value);
    }
    inline void push(int x) {
      //alternatilvely we could take propagate[x] + propagate[x] in each check and propagate only propagate, 
      //and in update minimum we would had to add propagete to children, 
      MV(propagate[x*2+1] , propagate[x]);
      MV(propagate[x*2+2] , propagate[x]);
      propagate[x]=0;
    }
    int comp_max(int x, int left, int right) {
      if(left>right) return 0;
      if(x>=first) {        
        return propagate[x];
      }
      if(propagate[x]) push(x);
      if(left==l[x] && right==r[x]) {    
        return propagate[x];
      } else {
        return max(comp_max(x*2+1, left, min(right,split[x])),comp_max(x*2+2, max(left,split[x]+1), right));
      }

    }
    int get_max(int left, int right) {
      return comp_max(0, left, right);    
    }
};
vector<vector<int> > edges;
vector<int> seen;

int t=0;
void go_rek(int x) {
  if(seen[x]) return;
  seen[x]=1;
  start[x]=t++;
  REP(i,edges[x].size()) {
    go_rek(edges[x][i]);
  }
  end[x]=t-1;
}
int main() {
  int n;
  cin>>n;

  edges = vector<vector<int > >(n);
  REP(i,n-1) {
    int a,b;cin>>a>>b;
    a--;
    b--;

    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  seen = vector<int>(n);
  go_rek(0);
  IntervalTree t1(n);
  IntervalTree t2(n);

  int Q;
  cin>>Q;


  REP(qqq,Q) {
    int a, b;
    cin>>a>>b;
    b--;
    if(a==1) {
      t1.set_max(start[b],end[b],qqq+1); //fill me and children

    } else if(a==2) {
      t2.set_max(start[b],start[b],qqq+1); //empty me an ancestor
    } else if(a==3) {
      int x1=t1.get_max(start[b], start[b]); //time filled
      int x2=t2.get_max(start[b],end[b]); //time emptied
      if(x1==0 || x2>x1) {
        cout<<"0"<<endl;
      } else {
        cout<<"1"<<endl;
      }
    }

  }
}


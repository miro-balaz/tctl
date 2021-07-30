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

//This tree is updating intervals using O_func, and querying the Q_func ()
class IntervalTree{
  public:
    int first;  // id of first
    vector<int> propagated,l,r,split,content;
    IntervalTree(int n){
      int m=1;
      while(m<n) m*=2;
      first = m-1;
      l.resize(2*m);
      r.resize(2*m);
      propagated.resize(2*m);      
      split.resize(2*m);
      content.resize(2*m); // content must be initialized to neutral value for Q_func

      for(int i=first;i<(int)l.size();++i) {
        l[i]=r[i]=i-first;
      }
      for(int i=first-1;i>=0;--i) {
        l[i]=l[i*2+1];
        r[i]=r[i*2+2];
        split[i]=r[i*2+1];
      }
    }
    // propagated is basically precomputed recursion, from comp_max
    inline void update_propagated(int x) {
      propagated[x] = O_func(content[x] , ( x>=first?0:UP_func(propagated[x*2+1], propagated[x*2+2])));
      
    }
    // internal function
    void update(int x, int left, int right, int value) {
      if(left>right) return;
      if(left==l[x] && right==r[x]) {
        content[x]=O_func(content[x],value);        // update of interval
      } else {
        update(x*2+1, left, min(right,split[x]),value);
        update(x*2+2, max(left,split[x]+1), right,value);
      }
      update_propagated(x);
    }
    // Interface function
    void set_max(int left, int right, int value) {
      update(0,left,right, value);
    }
    inline int O_func(int a, int b) {
      return max(a, b);
    }
    inline int UP_func(int a, int b) {
      return min(a, b);
    }
    constexpr int UP_neutral() {
      return 100000000;
    }
  
    int comp_max(int x, int left, int right, int topcontent) {
      if(left>right) return UP_neutral();
      if(x>=first) {        
        return O_func(propagated[x],topcontent);
      }
      
      if(left==l[x] && right==r[x]) {    
        return O_func(propagated[x],topcontent);
      } else {
       
        return UP_func(
          comp_max(x*2+1, left, min(right,split[x]), O_func(content[x], topcontent)),
          comp_max(x*2+2, max(left,split[x]+1), right, O_func(content[x], topcontent)));
      }

    }
    int get_max(int left, int right) {
      return comp_max(0, left, right,content[0]);    
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


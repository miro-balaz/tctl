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


inline void MV(int &a, int b) {
  a=max(a,b);
}
#define N 500010
int start[N], end[N];

class IntervalTree{
  public:
    int first;  // id of first
    vector<int> propagate,func;
    IntervalTree(int n){
      int m=1;
      while(m<n) m*=2;
      first = m-1;
      propagate.resize(2*m);  
      func.resize(2*m);

    }
#define PARENT(x) (((x)-1)/2)
#define LEFT(x) ((x)*2+1)
#define RIGHT(x) ((x)*2+2)
    inline void update_max(int x) {
      func[x] =   x >= first?propagate[x]:max(func[LEFT(x)], func[RIGHT(x)]);
    }
    inline void push(int x) {
      if(propagate[x]) {
        propagate[LEFT(x)] = propagate[x];
        propagate[RIGHT(x)] =  propagate[x];
        propagate[x]=0;
      }
    }
    void push_to(int left, int right) {
      int path[62],path_length=0;

      while(left) {
        left = PARENT(left);
        path[path_length++]=left;
        right  = PARENT(right);
        if (left!= right) {
          path[path_length++]=right;
        }
      }
      for(int i=path_length-1;i>=0;--i) push(path[i]);
    }
    void recompute_to(int left, int right) {
      update_max(left);
      update_max(right);
      while(left) {
        left = PARENT(left);
        update_max(left);
        right  = PARENT(right);
        if (left!= right) {
          update_max(right);
        }
      }
    }

    void update(int left, int right, int value) {
      push_to(left, right);  // proppagate, so now put values will not be rewritteny
      int left_orig=left, right_orig=right;
      while(left<right) {
        int parent = PARENT(left);
        if(LEFT(parent) == left) {
          left = parent;
        } else {
          propagate[left] = value; // APPLY
          left = parent+1;
        }
        parent = PARENT(right);
        if (RIGHT(parent) == right) {
          right = parent;
        } else{
          propagate[right] = value;  // APPLY
          right = parent - 1;
        }
      }
      if(left==right) {
        propagate[left]=value; // APPLY
      }
      recompute_to(left_orig, right_orig);



    }
    void set_max(int left, int right, int value) {
      update(first+left,first+right, value);
    }

    int comp_max(int left, int right) {
      push_to(left, right);
      recompute_to(left, right);
      int rval=0;
      while(left<right) {
        int parent = PARENT(left);
        if(LEFT(parent) == left) {
          left = parent;
        } else {
          MV(rval, func[left]); // APPLY
          left = parent+1;
        }
        parent = PARENT(right);
        if (RIGHT(parent) == right) {
          right = parent;
        } else{
          MV(rval,func[right]);  //APPLY
          right = parent - 1;
        }
      }
      if(left==right) {
        MV(rval, func[left]); // APPLY
      }
      return rval;
    }
    int get_max(int left, int right) {
      return comp_max( first+left, first+right);    
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


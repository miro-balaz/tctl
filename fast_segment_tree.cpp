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
template <typename T>
class IntervalTree{
  public:
    int first;  // id of first
    vector<T> propagate,func;
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
    // Modify this four functions OP1, AG1, update_max and push to change semantics of the tree.
    // There are two possible semantics for func 
     //   first:FUNC[x]=G(g(left),g(right))    // left is right subtree
     //    where g(x)=F'(propagate, FUNC(x))   // thus g being the real value of subtree, but FUNC missing his value
     
     //   second FUNC[x]=G'(propagate, FUNC[left], FUNC[right])
    // With second we need to update FUNC[x] each time its propagate changes,
    // with first only when its children propagate changes.
    // Curent implementation is writen that way
    
    // What would change if we reimplemented?
    // update max would have to be called each time you call propagate but also on children
    // but update max would become simpler it would be only G', not two times F'
    // Idea: after we call push_to we call update max
    inline void update_max(int x) {
      // x>= first means that we are on last level
      func[x] =   x >= first ? propagate[x] : max(propagate[x],max(func[LEFT(x)], func[RIGHT(x)]));

    }
    // This is used for precomputed value agregation to result
    inline void AG1(T &result, int node) {
      result = MV(result, func[node]);
    }
    inline void OP1(const int node, const T value) {
      propagate[node] = value;
    }

    // Is never called on last level
    inline void push(const int x) {
      if(propagate[x]) {  // zero is special value
        propagate[LEFT(x)] = propagate[x];
        propagate[RIGHT(x)] =  propagate[x];
        propagate[x]=0;
      }
    }
    /*
    
    void compute_weight(vector<int> w) {
    REP(i,weight.size()) weight[i]=0;
      REP(i,w.size()) weight[first+i] = w[i];
      for(int i=weight.size()-1;i>0;++i) weight[PARENT(i)]+=weight[i];
    }

    inline void update_max(int x) {
      // x>= first means that we are on last level
      func[x] =   x >= first ? propagate[x] : (propagate[x]>0?weight[x] : func[LEFT(x)]+func[RIGHT(x)]);
    }

    // This is used for precomputed value agregation to result
    virtual inline void AG1(int &result, int node) {
      result +=func[node];
    }

    // this is used in update
    inline void OP1(const int node, const int value) {
      propagate[node] += value;   // isnt propagate 0? no but parents is 0.
    }
    inline void push(int x) {
      if(propagate[x]) {  // zero is special value
        propagate[LEFT(x)] += propagate[x];
        propagate[RIGHT(x)] +=  propagate[x];
        propagate[x]=0;
      }
    }*/

    // Computes "path"( actually path forked path), then call push in reverse order on each node in path
    // Ensures, that there is nothing to be propagated to left and right.
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

    // calls update_max bottom up
    void recompute_to(int left, int right) {
      update_max(left);
      update_max(right);
      while(left) {
        left = PARENT(left);
        update_max(RIGHT(left));
        update_max(left);
        right  = PARENT(right);
        update_max(LEFT(right));  #TODO: This might be optimised
        if (left!= right) {
          update_max(right);
        }
      }

    }

// Calls push to - ensuring everythin that applies to interval left-right has been propagated 
//  Then goes with 2 pointers until we converge to one point, for left end:if the parent of node does not span to the left of it, go to the parrent(possibly in future it will cover interval) else 
// Then calls recompute

    void update(int left, int right, T value) {
      push_to(left, right);  // proppagate, so now put values will not be rewritteny
      int left_orig=left, right_orig=right;
      while(left<right) {
        int parent = PARENT(left);
        if(LEFT(parent) == left) {
          left = parent;
        } else {
          OP1(left, value);
          left = parent+1;  // Note: we are sure that parent is not rightmost in current level, otherwise left would be same as right, and loop would be not executed
        }
        parent = PARENT(right);
        if (RIGHT(parent) == right) {
          right = parent;
        } else{
          OP1(right, value);
          right = parent - 1;
        }
      }
      if(left==right) {
        OP1(left, value);
      }
      recompute_to(left_orig, right_orig);



    }
    // JUST calls update
    void set_max(int left, int right, T value) {
      update(first+left,first+right, value);
    }
    // Goes with two pointers from bottom to top, each time it finds interval whose parent covers more than interval (left, right) it will append value of this interval to rval
    // and jumps to next node that covers interval (left, right)

    T comp_max(int left, int right) {
      push_to(left, right);
      recompute_to(left, right);
      T rval=0;
      while(left<right) {
        int parent = PARENT(left);
        if(LEFT(parent) == left) {  
          left = parent;
        } else {
          AG1(rval, left); 
          left = parent+1;
        }
        parent = PARENT(right);
        if (RIGHT(parent) == right) {
          right = parent;
        } else{
          AG1(rval,right);
          right = parent - 1;
        }
      }
      if(left==right) {
        AG1(rval, left); 
      }
      return rval;
    }
    T get_max(int left, int right) {
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


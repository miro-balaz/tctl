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

class Node{
  public:
  int value_propagate_;
  int precomputed_value;  // This is also server as value in leaf nodes
  // precomputed values never includes what is at current node to be propagated
  // so you need to call real_value()
  // if it was, we would have to call update_precomputed each time we alter propagation
  void update_precomputed(const Node &a, const Node &b) {
    precomputed_value = a.real_func()+b.real_func();
  }

  bool propagation_required() const {
    return value_propagate_!=-1;
  }

  bool reset_propagation() {
    value_propagate_=-1;
  }

  void propagate_to(Node &a, Node &b) {
    if(! propagation_required()) return;
    a.value_propagate_ = value_propagate_;
    b.value_propagate_ = value_propagate_;
    reset_propagation();
  }
  int real_func() const{
    if(propagation_required()) {
      return value_propagate_;    
    } else {
      return precomputed_value;
    }
  }
};
class Mutation{
  public:
  virtual void mutate(Node &node) const=0;
};

class SetValueMutation:public Mutation {
  private:
    int value_;
  public :
    SetValueMutation(int x) :value_(x){}
    virtual void mutate(Node &node) const {node.value_propagate_=value_;}
};
class ValueBuilder {
  public:
  // add should use the same function as is in update_precomputed
  virtual void add(const Node &node)=0; 
};
class SumBuilder:public ValueBuilder{
  public:
  int sum;
  SumBuilder():sum(0){}
  virtual void add(const Node &node) {
    sum += node.real_func();
  }
};

template <typename T>
class IntervalTree{
  public:
    int first;  // id of first
    vector<T> tree;
    int leaves;
    IntervalTree(int n){
      int m=1;
      while(m<n) m*=2;
      first = m-1;
      leaves=n;
    }
    virtual T getInitial(int index) {
      return T();
    }
    void initialize(bool keep_default) {
      tree.resize((first+1)*2);
      if(!keep_default) for(int i=first;i<first+leaves;++i) tree[i]=getInitial(i-first); 
      init_precomputed();
    }
#define PARENT(x) (((x)-1)/2)
#define LEFT(x) ((x)*2+1)
#define RIGHT(x) ((x)*2+2)
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
      tree[x].update_precomputed(tree[LEFT(x)], tree[RIGHT(x)]);
    }
    void init_precomputed() {
      for(int i=first-1;i>=0;--i) update_max(i);
    }

    // Is never called on last level
    inline void push(const int x) {
      tree[x].propagate_to(tree[LEFT(x)], tree[RIGHT(x)]);
    }
    
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
        update_max(LEFT(right));  //TODO: This might be optimised
        if (left!= right) {
          update_max(right);
        }
      }

    }

// Calls push to - ensuring everythin that applies to interval left-right has been propagated 
//  Then goes with 2 pointers until we converge to one point, for left end:if the parent of node does not span to the left of it, go to the parrent(possibly in future it will cover interval) else 
// Then calls recompute

    void update(int left, int right,const Mutation &mutation) {
      push_to(left, right);  // proppagate, so now put values will not be rewritteny
      int left_orig=left, right_orig=right;
      while(left<right) {
        int parent = PARENT(left);
        if(LEFT(parent) == left) {
          left = parent;
        } else {
          mutation.mutate(tree[left]);
          left = parent+1;  // Note: we are sure that parent is not rightmost in current level, otherwise left would be same as right, and loop would be not executed
        }
        parent = PARENT(right);
        if (RIGHT(parent) == right) {
          right = parent;
        } else{
          mutation.mutate(tree[right]);
          right = parent - 1;
        }
      }
      if(left==right) {
        mutation.mutate(tree[left]);
      }
      recompute_to(left_orig, right_orig);

    }
    // JUST calls update
    void set_value(int left, int right, int value) {
      SetValueMutation mutation(value);
      mutate_interval(left, right, mutation);
    }
    void mutate_interval(int left, int right,const Mutation &mutation) {
      update(first+left,first+right, mutation);
    }

    // Goes with two pointers from bottom to top, each time it finds interval whose parent covers more than interval (left, right) it will append value of this interval to rval
    // and jumps to next node that covers interval (left, right)

    void comp_max(int left, int right, ValueBuilder &builder) {
      push_to(left, right);  // Why?
      recompute_to(left, right); //Why?
      while(left<right) {
        int parent = PARENT(left);
        if(LEFT(parent) == left) {  
          left = parent;
        } else {
          builder.add(tree[left]);        
          left = parent+1;
        }
        parent = PARENT(right);
        if (RIGHT(parent) == right) {
          right = parent;
        } else{
          builder.add(tree[right]);          
          right = parent - 1;
        }
      }
      if(left==right) {
        builder.add(tree[left]); 
      }
    
    }
    void apply_builder(int left, int right, ValueBuilder &builder) {
      comp_max(first+left, first+right,builder);
    }
    int get_sum(int left, int right) {
      SumBuilder builder;
      apply_builder( left, right, builder);    
      return builder.sum;
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
  IntervalTree<Node> t1(n);
  IntervalTree<Node> t2(n);

  int Q;
  cin>>Q;


  REP(qqq,Q) {
    int a, b;
    cin>>a>>b;
    b--;
    if(a==1) {
      t1.set_value(start[b],end[b],qqq+1); //fill me and children

    } else if(a==2) {
      t2.set_value(start[b],start[b],qqq+1); //empty me an ancestor
    } else if(a==3) {
      int x1=t1.get_sum(start[b], start[b]); //time filled
      int x2=t2.get_sum(start[b],end[b]); //time emptied
      if(x1==0 || x2>x1) {
        cout<<"0"<<endl;
      } else {
        cout<<"1"<<endl;
      }
    }

  }
}


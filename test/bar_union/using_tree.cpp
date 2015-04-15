#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
int n;
vector<int> x0,x1,y0,y1;
struct event{
  int y1,y2,t;
  event(int y11,int y22,int tt):y1(y11),y2(y22),t(tt){}
};
bool operator<(const event &a, const event &b){return a.t+b.t?false:false;}

class IntervalTree{
  public:
    int first;  // id of first
    vector<int> propagate,func,weight,isum,propsum;
    IntervalTree(int n){
      int m=1;
      while(m<n) m*=2;
      first = m-1;
      propagate.resize(2*m-1);  
      func.resize(2*m-1);
      
      weight.resize(2*m-1);
      isum.resize(2*m-1);
      propsum.resize(2*m-1);

    }
#define PARENT(x) (((x)-1)/2)
#define LEFT(x) ((x)*2+1)
#define RIGHT(x) ((x)*2+2)
    
    void compute_weights(vector<int> w) {
    REP(i,weight.size()) weight[i]=0;
      REP(i,w.size()) weight[first+i] = w[i];
      for(int i=weight.size()-1;i>0;--i) weight[PARENT(i)]+=weight[i];
    }

    inline void update_max(int x) {
       // cout<<"update "<<x<<endl;
      // x>= first means that we are on last level
      func[x] =   x >= first ? (isum[x]?weight[x]:0) : (isum[x] >0?weight[x] : func[LEFT(x)]+func[RIGHT(x)]);
    }

    // This is used for precomputed value agregation to result
    inline void AG1(int &result, int node) {
      result +=propsum[node]>0?weight[node]:func[node];
    }

    // this is used in update
    inline void OP1(const int node, const int value) {
      propagate[node] += value;   // isnt propagate 0? no but parents is 0.
      isum[node]+=value;
    }
    inline void push(int x) {
//        cout<<"push "<<x<<endl;
      if(propagate[x]) {  // zero is special value
        propagate[LEFT(x)] += propagate[x];//func[LEFT(x)]=weight[LEFT(x)] would save it
        propagate[RIGHT(x)] +=  propagate[x];
        propsum[LEFT(x)]+=propagate[x];
        propsum[RIGHT(x)]+=propagate[x];
        propagate[x]=0;
      }
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
      //cout<<"recompute to"<<left<<" "<<right<<endl;
      update_max(left);
      update_max(right);
      while(left) {
        left = PARENT(left);
        update_max(RIGHT(left));
        update_max(left);
        right  = PARENT(right);
        update_max(LEFT(right));
        if (left!= right) {
          update_max(right);
        }
      }

    }

// Calls push to - ensuring everythin that applies to interval left-right has been propagated 
//  Then goes with 2 pointers until we converge to one point, for left end:if the parent of node does not span to the left of it, go to the parrent(possibly in future it will cover interval) else 
// Then calls recompute

    void update(int left, int right, int value) {
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
    void add(int left, int right, int value) {
      update(first+left,first+right, value);
    }
    // Goes with two pointers from bottom to top, each time it finds interval whose parent covers more than interval (left, right) it will append value of this interval to rval
    // and jumps to next node that covers interval (left, right)

    int comp_sum(int left, int right) {
      push_to(left, right);
      recompute_to(left, right);
      int rval=0;
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
    int get_sum(int left, int right) {
      return comp_sum( first+left, first+right);    
    }
    void print() {
      cout<<"func:"<<endl;
      REP(i, func.size()) {
        cout<<i<<": "<<func[i]<<", ";
        if (((i+2)&(i+1))==0) cout<<endl;
      }
      cout<<endl<<"propagate:"<<endl;
      REP(i, propagate.size()) {
        cout<<i<<": "<<propagate[i]<<", ";
        if (((i+2)&(i+1))==0) cout<<endl;
      }
      
      cout<<endl<<"isum:"<<endl;
      REP(i, isum.size()) {
        cout<<i<<": "<<isum[i]<<", ";
        if (((i+2)&(i+1))==0) cout<<endl;
      }
      cout<<endl;

    }
};


int main() {
  int n;
  cin>>n;
  x0.resize(n);
  y0.resize(n);
  x1.resize(n);
  y1.resize(n);

  REP(i,n) {
    cin>>x0[i]>>y0[i]>>x1[i]>>y1[i];
    //cin>>y0[i]>>y1[i]>>x0[i];
  }
  vector<int> Y;
  REP(i,n) Y.push_back(y0[i]);
  REP(i,n) Y.push_back(y1[i]);
  sort(Y.begin(),Y.end());
  Y.erase(unique(Y.begin(), Y.end()), Y.end());
  REP(i,n) y0[i]=lower_bound(Y.begin(), Y.end(), y0[i])-Y.begin(); 
  REP(i,n) y1[i]=lower_bound(Y.begin(), Y.end(), y1[i])-Y.begin(); 
  //event will be x,[start/stop], Y
  vector<pair<int, event> > events;
  REP(i,n) {
    events.push_back(make_pair(x0[i],event(y0[i],y1[i],1)));
    events.push_back(make_pair(x1[i],event(y0[i],y1[i],-1)));
//    events.push_back(make_pair(x1[i],event(y0[i],y1[i],x0[i])));
  }
  sort(events.begin(), events.end());
  int rval=0;
  vector<int> p(Y.size()-1);
  REP(i,p.size()) p[i]=Y[i+1]-Y[i];
  IntervalTree tree(p.size());
  tree.compute_weights(p);
  int lastx=0;
  
  REP(i,events.size()) {

    const event &e(events[i].second);
    int delta=events[i].first-lastx;
    if(delta) {
      int sum=  tree.get_sum(0,p.size()-1);
     // cout<<sum <<"x"<<delta<<endl;
      rval+=delta*sum;
      //tree.print();
    }
    
    lastx=events[i].first;
   // cout<<"add:"<<e.y1<<" - "<<e.y2-1<<":"<<e.t<<endl;
    tree.add(e.y1,e.y2-1,e.t);
    cout<<tree.get_sum(e.y1,e.y2-1)<<endl;

    
  }
  cout<<rval<<endl;

}

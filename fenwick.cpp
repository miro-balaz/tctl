#include<vector>
#include<cstdlib>
#include<iostream>
using namespace std;

//=FenwickTree
template<typename T>
class FenwickTree {
  public:
    vector<T> c;
    int max_value_;
    int start_value_;
    // inits 0..count

  public:
    FenwickTree(){}
    FenwickTree(int begin, int end){ // classical closed-open interval of allowed values

      max_value_ = end - begin + 1; //end - begin is the size, and+1 because we do not use zero-th element ==n+2
      start_value_ = begin -1; //==-1
      c = vector<T>(max_value_+1, 0);
    }
    // allowed values will be 0 to count-1
    //  FenwickTree(int count):FenwickTree(0, count){ 
    // }
    // Returns sum from begin to idx inclusively, if idx isoutside the bounds it will return 0 or sum for max value depending of the idx.
    T get_sum(int idx) {
      idx-=start_value_;
      if (idx<1) return 0;
      if (idx>max_value_) idx = max_value_;
      //assert(idx>=0 && idx<=max_value_);
      return get_cummulative_no_check(idx);
    }

    inline T get_cummulative_no_check(int idx) {
      T rval = 0;
      while(idx > 0) {
        //assert(idx<=max_value_);
        rval+=c[idx];
        idx -= idx & (-idx);
      }
      return rval;
    }

    // increases the frequency for idx
    void add(int idx, T val) {
      idx-=start_value_;
      if (idx < 1) return;
      if (idx > max_value_) idx = max_value_ ;
      //assert(idx>=0 && idx<=max_value_);
      update_no_check(idx, val);

    }

    // The actual implementation of add
    inline void update_no_check(int idx, T val) {
      while (idx <= max_value_){
        //assert(idx>=0);
        c[idx] += val;
        idx += (idx & -idx);
      }
    }
    // The slower version of getting value for single element
    T get_single(int idx) {
      return get_sum(idx)-get_sum(idx-1);
    }
};
//#

template<typename T>
class FenwickTree2 {
  public:
    typedef FenwickTree<T> E;
    vector<E> c;
    int max_value_;
    int start_value_;
    // inits 0..count
  public:
    FenwickTree2(int begin, int end, int begin2, int end2){ // classical closed-open interval of allowed values
      max_value_ = end - begin + 1; //end - begin is the size, and+1 because we do not use zero-th element ==n+2
      start_value_ = begin -1; //==-1
      c = vector<E>(max_value_+1, E(begin2, end2));
    }
    // allowed values will be 0 to count-1
    //  FenwickTree(int count):FenwickTree(0, count){ 
    // }
    // Returns sum from begin to idx inclusively, if idx isoutside the bounds it will return 0 or sum for max value depending of the idx.
    T get_sum(int idx, int idx2) {
      idx-=start_value_;
      if (idx<1) return 0;
      if (idx>max_value_) idx = max_value_;
      //assert(idx>=0 && idx<=max_value_);
      return get_cummulative_no_check(idx,idx2);
    }

    inline T get_cummulative_no_check(int idx, int idx2) {
      T rval = 0;
      while(idx > 0) {
        //assert(idx<=max_value_);
        rval+=c[idx].get_sum(idx2);
        idx -= idx & (-idx);
      }
      return rval;
    }

    // increases the frequency for idx
    void add(int idx,int idx2, T val) {
      idx-=start_value_;
      if (idx < 1) return;
      if (idx > max_value_) idx = max_value_ ;
      //assert(idx>=0 && idx<=max_value_);
      update_no_check(idx,idx2, val);

    }

    // The actual implementation of add
    inline void update_no_check(int idx, int idx2, T val) {
      while (idx <= max_value_){
        //assert(idx>=0);
        c[idx].add(idx2, val);
        idx += (idx & -idx);
      }
    }
    // The slower version of getting value for single element  
    T get_rectangle(int idx1start, int idx1end, int idx2start, int idx2end) {
      return get_sum(idx1end, idx2end)
        +get_sum(idx1start-1, idx2start-1)
        -get_sum(idx1start-1, idx2end)
        -get_sum(idx1end, idx2start-1);

    }
    T get_single(int idx, int idx2) {
      idx-=start_value_;
      if (idx<1) return 0;
      if (idx>max_value_) idx = max_value_;
      return c[idx].get_single(idx2);
    }
};
//#

// This tree supports range updates, and range sum
template<typename T>
class IntervalFenwickTree {
  public:
    FenwickTree<T> m,a;
    int max_value_;
    int start_value_;
    // inits 0..count

  public:
    IntervalFenwickTree(int begin, int end){ // classical closed-open interval of allowed values
      max_value_ = end - begin + 1; //end - begin is the size, and+1 because we do not use zero-th element ==n+2
      start_value_ = begin -1; //==-1
      m = FenwickTree<T>(begin, end);
      a = FenwickTree<T>(begin, end);
    }
    T get_sum(int idx) {
      idx -= start_value_;
      if (idx < 1) return 0;
      if (idx > max_value_) idx = max_value_;
      //assert(idx>=0 && idx<=max_value_);
      T sa = a.get_cummulative_no_check(idx);
      T sm = m.get_cummulative_no_check(idx);
      return sm*idx+sa;
    }

    void add(int left, int right, T val) {
      left -= start_value_;
      right -= start_value_;
      //assert(idx>=0 && idx<=max_value_);
      a.update_no_check(left, -val*(left-1));
      m.update_no_check(left, val);

      a.update_no_check(right, val*right);
      m.update_no_check(right, -val);
    }

};
//#
template<typename T>
class IntervalFenwickTree2 {
  public:
    typedef IntervalFenwickTree<T> E;
    vector<E> m;
    vector<E> a;
    int max_value_;
    int start_value_;
    // inits 0..count
  public:
    IntervalFenwickTree2(int begin, int end, int begin2, int end2){ // classical closed-open interval of allowed values
      max_value_ = end - begin + 1; //end - begin is the size, and+1 because we do not use zero-th element ==n+2
      start_value_ = begin -1; //==-1
      m = vector<E>(max_value_ + 1, E(begin2, end2));
      a = vector<E>(max_value_ + 1, E(begin2, end2));
    }
    T get_sum(int idx, int idx2) {
      idx -= start_value_;
      if (idx < 1) return 0;
      if (idx > max_value_) idx = max_value_;
      return get_cummulative_no_check(idx, idx2);
    }

    inline T get_cummulative_no_check(int idx, int idx2) {
      T sa = 0;
      T sm = 0;
      int X=idx;
      while(idx > 0) {
        sa += a[idx].get_sum(idx2);
        sm += m[idx].get_sum(idx2); 
        idx -= idx & (-idx);
      }
  //    cout<<"idx="<<X<<" "<<sa<<" "<<sm<<endl;
      return sa+sm*X;
    }

    // increases the frequency for idx
    void add(int down, int up,int left, int right, T val) {
      down-=start_value_;
      up-=start_value_;
      update_no_check(down, left, right, -val*(down-1),val);
      update_no_check(up, left, right, val*up,-val);


    }

    // The actual implementation of add
    inline void update_no_check(int idx, int left, int right, T va, T vm) {
      while (idx <= max_value_){
        //assert(idx>=0);
        a[idx].add(left, right, va);
        m[idx].add(left, right, vm);

        idx += (idx & -idx);
      }
    }
};
//#
#define REP(i,n) for(int i=0;i<(int)(n);++i)
//{{{
void test_interval() {
  int f[100];
  REP(i,100) f[i]=0;
  IntervalFenwickTree<int> t(0,100);
  REP(i,100) {
    int a=rand()%100;
    int b=rand()%100;
    int c=rand()%7+1;
    for(int i=min(a,b);i<=max(a,b);++i) {
      f[i]+=c;
    }
    t.add(min(a,b), max(a,b),c);

  }
  int x=0;
  REP(i,100) {
    //
    //    if(f[i]!=t.get_sum(i)) cout<<i<<endl;
    x+=f[i];
    cout<<x-t.get_sum(i);

  }
  cout<<endl;

  cout<<endl;
}
//}}}
void test_interval2() {
  int f[100][100];
  int n = 20;
  REP(i,n) REP(j,n) f[i][j]=0;
  IntervalFenwickTree2<int> t(0,100,0,100);
  REP(i,100) {
    int a=rand()%n;
    int b=rand()%n;
    int x=rand()%n;
    int y=rand()%n;
    int c=rand()%7+1;
    for(int i=min(a,b);i<=max(a,b);++i) {
      for(int j=min(x,y);j<=max(x,y);++j) {
        f[i][j]+=c;
      }
    }
    t.add(min(a,b), max(a,b),min(x,y),max(x,y),c);

  }

  REP(i,n) {
    REP(j,n) {
      //
      //    if(f[i]!=t.get_sum(i)) cout<<i<<endl;
      f[i][j]+=(i?f[i-1][j]:0)+(j?f[i][j-1]:0)-(i&&j?f[i-1][j-1]:0);
      cout.width(3);
      
      cout<<t.get_sum(i,j);

    }
    cout<<endl;

  }
  return;
  REP(i,n) {
    REP(j,n) {
      cout<<t.get_sum(4,3);

    }
    cout<<endl;

  }
}
int main() {
  test_interval2();
}


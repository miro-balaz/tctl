#include<vector>
#include<iostream>
using namespace std;

template<typename T>
class MinArraySmall {
  //  O(n) memory, query:O(log(n)) /precompute:O(n)
  vector<vector<T> > a;
  public:
  MinArraySmall(vector<T> one_layer) {
    a.push_back(one_layer);  
    while(one_layer.size()>1) {
      vector<T> next_layer;
      for(int i=0;i<(int)one_layer.size();i+=2 ) {
        if(i+1<(int)one_layer.size()) {
          next_layer.push_back(min(one_layer[i],one_layer[i+1]));
        } else {
          next_layer.push_back(one_layer[i]);
        }      
      }
      one_layer=next_layer;
      a.push_back(next_layer);
    }
  }
  T getMin(int left, int right) {
    // closed, open
    int size=(1<<(a.size()-1));
    T rval=0;
    int first=1;  // no need for neutral element initialization thanks to this
    for(int level=a.size()-1;level>=0;--level) {
      if(left+size<=right) {
        int x=a[level][left/size];
        if(first) {
          rval=x;
          first=0;
        } else {
          rval=min(rval, x);  
        }
        left=left/size*size+size; 
      }
      size/=2;
    }
    return rval;
  }
};

template<typename T>
class MinArrayBig {

  //  O(n log n) memory, query:O(1) /precompute:O(n log n)

  inline aggFNC(T a, T b) {
    return min(a,b)

  }

  vector<vector<T> > a;
  public:
  MinArrayBig(vector<T> one_layer) {
    a.push_back(one_layer);  
    int sz = 1;
    while(one_layer.size() > sz) {
      sz *= 2;
      vector<T> next_layer;
      for(int i = 0; i < (int)one_layer.size() - sz/ 2; i++ ) {        
        next_layer.push_back(aggFNC(one_layer[i],one_layer[i + sz / 2]);
      }
      one_layer = next_layer;
      a.push_back(next_layer);
    }
  }
  T getMin(int left, int right) {
    // closed, open
    int size = 1;
    int level = 0;
    while(left+size<right && level+1<(int)a.size()) {
      size *= 2;
      level++;
    }
    // a[l][i]=max from a[i] to a[i+(2^l)-1]    
    return aggFNC(a[level][left], a[level][right-size])
  }

};

typedef long long int ll;
int main() {
  int n,m;
  cin>>n>>m;
  vector<int> d(n), h(n);
  REP(i,n) cin>>d[i];
  REP(i,n) cin>>h[i];
  vector<ll> for_min(n*2),for_max;
  REP(i,n) for_min[i] = for_min[i+n] = d[i];
  for_min[0]=0;
  REP(i,n+n) if(i) for_min[i]+=for_min[i-1];
  for_max=for_min;
  REP(i, n) for_min[i] -= h[i%n];
  REP(i, n) for_max[i] += h[i%n];
  REP(i,n+n) for_max[i]=-for_max[i];

  MinArraySmall<ll> maxArray(for_max), minArray(for_min);   

  REP(i,m) {
    int left, int right;
    cin>>left>>right;
    int l,r;
    if(left<right) {
      l=right;
      r=n+left;
    } else {
      l=right;
      r=left;
    }
    cout<<(-maxArray.getMin(l,r)-minArray(l,r));
  }
}


#include<vector>
#include<iostream>
using namespace std;

template<typename T>
class MinArraySmall {
  //  O(n) memory, O(log(n))
  vector<vector<T> > a;
  public:
  MinArraySmall(vector<T> one_layer) {
    a.push_back(one_layer);  
    while(one_layer.size()>1) {
      vector<int> next_layer;
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
    int first=1;
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


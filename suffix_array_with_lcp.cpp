#include <string>
#include <vector>
#include <algorithm>
#define REP(i,n) for(int i=0;i<(int)(n);++i)
using namespace std;
void get_suffix_array(string s, vector<int> &SA, vector<int> &LCP) {
  int n=s.size();
  vector<int> rank(n+1);
  rank[0] = 0; //empty suffix
  REP(i,n) rank[i+1]=s[i]; //suffix of length i
  //NOTE: the s is no longer used so this code might be extracted to be used also in function for vector.
  int sorted_by=1;
  while(sorted_by<n) {
    vector<pair<pair<int,int>, int> > v;
    REP(i,n+1) {
      v.push_back(make_pair(
            make_pair(rank[i], i >= sorted_by ? rank[i-sorted_by] : 0),
            i)
          );
      sort(v.begin(), v.end());

      int x=0;
      REP(i, n+1) {
        if(i && v[i].first!=v[i-1].first) x++;
        rank[v[i].second] = x;
      }
    }
    sorted_by *= 2;
  }
  
  SA.resize(n+1); // number of suffix on ith position/ now the suffix number is index of first character
  //the ranks are not from zero, if n>1
  LCP.resize(n);
  REP(i,n+1) { 
    SA[rank[i]]=n-i;
  }
  vector<int> inv(n+1);
  REP(i,n+1) {
    inv[SA[i]]=i;
  }
  // LCP construction
  int l =0;
  REP(i,n) {
    int k=inv[i];
    int j=SA[k-1]; // k cannot be zero because i<n
    while(s[i+l]==s[j+l]) ++l;
    LCP[k]=l;
    if(l>0) --l;
  }
  
  return rval;
}


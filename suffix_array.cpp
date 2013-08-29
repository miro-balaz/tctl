#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// Description of algorithm
// log n rounds
// in each round we use  sort to sort elements
// (number1,number2,suffix,)
//at the begining we have sorted by first letter
// we then
//init array to letter number
//loop:
  //construct
  //sort 
  //renumber

//TODO:calculation of LCP
vector<int> get_suffix_array(string s) {
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
  
  vector<int> rval(n,0); // number of suffix on ith position/ now the suffix number is index of first character
  //the ranks are not from zero, if n>1
  if(n>1) {
    REP(i,n) { 
      rval[rank[i+1]-1]=n-i-1;
    }
  }
  return rval;
}

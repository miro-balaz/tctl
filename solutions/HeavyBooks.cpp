//{{{b

//}}}e
#line 5 "HeavyBooks.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class HeavyBooks {
  public:
    //{{{b

    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { int Arr0[] = {5,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findWeight(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {10, 100, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {110, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findWeight(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {155870,565381}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 565381 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findWeight(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {500,500,500,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,1,1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {500, 1500 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findWeight(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {1,1,1,1,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1000000 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, findWeight(Arg0, Arg1)); }
    void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {110, 100 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, findWeight(Arg0, Arg1)); }

    // END CUT HERE

    //}}}e


    vector <int> findWeight(vector <int> books, vector <int> moves) ;
};
vector<int> books;
int is_set[51][51],obj1[51][51], obj2[51][51];

vector<int> blocks;
int n;
//returns -1 in second for invlaid value
pair<int,int> go(int block_index, int book_index) {
  if(is_set[block_index][book_index]) {
    return make_pair(obj1[block_index][book_index], obj2[block_index][book_index]);
  }
  int block_size = blocks[block_index];
  if(block_size-1>book_index) return make_pair(0,-1);
  pair<int, int> rval = go(block_index, book_index-1);
  int o1_inc=0;
  int o2_inc=0;
  REP(i, block_size) {
    int x = books[book_index-i];
    o2_inc += x;
      if(i) {
        o1_inc+=x;
      } else {
        o1_inc-=x; // here was bug o2 was used instead o1
      }
  }

  if(block_index==0) {
    pair<int, int> nrv(o1_inc, o2_inc);
    if(rval.second ==-1 || rval<nrv) rval=nrv;
  } else {
    REP(j, book_index-block_size+1) {
      pair<int, int> nrv = go(block_index-1, j);
      if(nrv.second!=-1) {
        nrv.first+=o1_inc;
        nrv.second+=o2_inc;
        if(rval.second==-1 || rval<nrv) rval=nrv;
      }
    }
  }
  is_set[block_index][book_index]=1;
  obj1[block_index][book_index]=rval.first;
  obj2[block_index][book_index]=rval.second;
  return rval;
}

vector <int> HeavyBooks::findWeight(vector <int> books, vector <int> moves){
  vector<int> a[2];
  REP(i,moves[0]) a[1].push_back(i);
  REP(i,moves.size()) if(i) {
    int source = i%2;
    int target = source ^ 1;
    REP(j, moves[i]) {
      int sz=a[source].size();
      if(sz==0) break;
      a[target].push_back(a[source][sz-1]);
      a[source].resize(sz-1);

    }
    sort(a[target].begin(), a[target].end());
  }
  blocks=vector<int>();
  int prev=-1;
  REP(i,a[0].size()) {
    blocks.push_back(a[0][i]-prev);
    prev=a[0][i];
  }
  sort(books.begin(), books.end());
  if(a[0].size() == 0) { // BUG: not handling this special case
    vector<int> rval(2,0);
    REP(i, moves[0]) rval[1]+=books[books.size()-1-i];
    return rval;
  }
  int compensation = 0;
  int cnt_comp = moves[0] - 1 - a[0][a[0].size() - 1];  // HERE was bug: books.size() was used instead ov moves[0]
  REP(i, cnt_comp) compensation += books[books.size() - 1 - i];
  books.resize(books.size() - cnt_comp);
  ::books = books;
  n = books.size();
  REP(i,n) REP(j,n) {
    is_set[i][j] = 0;
  }
  pair<int, int> rv=go(blocks.size()-1,n-1);

  int o1=rv.first; // W-T
  int o2=rv.second; // W+T  /// W=(o1+o2)/2 + compensation, T=o2-(o1+o2)/2
  vector<int> rval;
  rval.push_back(o2 - (o1 + o2) / 2);
  rval.push_back((o1 + o2) / 2 + compensation);
  return rval;
}
//{{{b
int main() {
  HeavyBooks ___test;
  ___test.run_test(-1);
}
//}}}e

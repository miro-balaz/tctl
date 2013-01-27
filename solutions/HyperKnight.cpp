//{{{b

//}}}e
#line 5 "HyperKnight.cpp"
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

class HyperKnight {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 8; int Arg3 = 8; int Arg4 = 4; long long Arg5 = 20LL; verify_case(0, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 8; int Arg3 = 8; int Arg4 = 2; long long Arg5 = 16LL; verify_case(1, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 7; int Arg3 = 11; int Arg4 = 0; long long Arg5 = 0LL; verify_case(2, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 10; int Arg3 = 20; int Arg4 = 8; long long Arg5 = 56LL; verify_case(3, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 100; int Arg3 = 10; int Arg4 = 6; long long Arg5 = 564LL; verify_case(4, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1000000000; int Arg3 = 1000000000; int Arg4 = 8; long long Arg5 = 999999988000000036LL; verify_case(5, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

//}}}e


	long long countCells(int a, int b, int numRows, int numColumns, int k) ;
};
typedef long long int num;

void u_in(num &a, num &l, num &u, num L,  num U) {
  if(a > 0) {
    u = min(u, U-a);
  } else {
    l = max(l, L-a);
  }
}
//bug: i used sample solution to find a bug
vector<num> countCells2(int a, int b, int numRows, int numColumns, int k)
{
    // The 8 moves available:
    num dx[8] = {a,a,-a,-a,b,b,-b,-b};
    num dy[8] = {b,-b,b,-b,a,-a,a,-a};
    
    vector<num> exactly(256);
    num result = 0;
    
    // We visit the masks from highest to smallest, this way we
    // can guarantee that all subsets with more elements than the
    // current one have already been solved.
    for (int mask = 255; mask >= 0; mask--) {
        num valid = 0;
        // valid : How many cells allow the moves in mask?
        // (and possibly other moves)
        
        // In the explanation valid is an array, but we do not really
        // need to remember all its values, just valid[mask].
        
        int n = 0;
        // Find the rectangle of such cells:
        num left = 0, right = 0, up = 0, down = 0;
        for (int i=0; i<8; i++) {
            // For each move that benums to the mask subset:
            if (mask & (1<<i)) {
                n++;
                // update the rectangle's dimensions
                if (dx[i] < 0) {
                    left = std::max(left, -dx[i]);
                } else {
                    right = std::max(right, dx[i]);
                }
                if (dy[i] < 0) {
                    up = std::max(up, -dy[i]);
                } else {
                    down = std::max(down, dy[i]);
                }
            }

        }
        // Area of the rectangle
        valid = (numRows - left - right) * (numColumns - up - down);
        // if we make sure to set valid = 0 when the moves are too large
        // this makes the solution work even without the special constraint
        
        exactly[mask] = valid;
        
        // For each subset with more elements than this one.
        // (mask must be a proper subset of mask2):
        for (int mask2 = mask + 1; mask2 < 256; mask2++) {
            if ( (mask & mask2) == mask ) {
                // remove the cells that allow more moves than mask.
                //exactly[mask] -= exactly[mask2];
            }
        }
        // n is the number of moves in the mask.
        // now exactly[mask] contains the number of cells from which the ONLY
        // valid moves are those in the mask:
        if (n == k) {
            result += exactly[mask];
        }
    }
    return exactly;
}

long long HyperKnight::countCells(int a, int b, int Y, int X, int k){
  // A,B, -A,B= (2,1),(-2,1); (28 vs 36)

 // num dx[8] = {A, -A, A, -A, B, -B, B, -B};
  //num dy[8] = {B, B, -B, -B, A, A, -A, -A};
    num dx[8] = {a,a,-a,-a,b,b,-b,-b};
    num dy[8] = {b,-b,b,-b,a,-a,a,-a};
    num r[256];
  REP(s, 1 << 8) {
    num x0 = 0, x1 = X-1;
    num y0 = 0, y1 = Y-1;

    
    REP(i,8) {
      if(s & (1 << i)){
        u_in(dx[i], x0, x1, 0, X - 1);
        u_in(dy[i], y0, y1, 0, Y - 1);
      }
    }
        
    if(x0<=x1 && y0<=y1) r[s]=(x1-x0+1)*(y1-y0+1); //bug:here was += but array was not initialized
  }
  vector<num> t=countCells2(a,b,X,Y,k);
  //etude: copute f(x) if we only know() sum(f(y) for y is superset of x)
  for(int i = 255; i >= 0; --i) {//bug: here was 255
    for(int j = 0; j < i; ++j) if((j&i)==j) {
      r[j] -= r[i];      
    }
  }
  
  num rval=0;
  
  REP(i,256) { 
    int cnt=0;
    REP(j,8) if(i & ( 1 << j) ) cnt++;
    if(cnt==k) {
      rval+=r[i];
    }
  }
  return rval;
}
//{{{b
int main() {
  HyperKnight ___test;
  ___test.run_test(-1);
}
//}}}e

//{{{b

//}}}e
#line 5 "ElevenMultiples.cpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cctype>
#include <sstream>
#include <bitset>
#include <iostream>
#include <cstring>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class ElevenMultiples {
  public:
    //{{{b

    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"58", "2012", "123"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, countMultiples(Arg0)); }
    void test_case_1() { string Arr0[] = {"1", "1111", "1", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(1, Arg1, countMultiples(Arg0)); }
    void test_case_2() { string Arr0[] = {"43925486943738659795389387498953274"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countMultiples(Arg0)); }
    void test_case_3() { string Arr0[] = {"983", "4654", "98", "3269", "861", "30981"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 96; verify_case(3, Arg1, countMultiples(Arg0)); }
    void test_case_4() { string Arr0[] = {"193", "8819", "40676", "97625892", "5719", "45515667", "32598836", "70559374", "38756", "724",
      "93391", "942068", "506", "901150", "874", "895567", "7560480", "7427691", "799450", "85127"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 537147821; verify_case(4, Arg1, countMultiples(Arg0)); }
    void test_case_5() { string Arr0[] = {"687045939630", "997856158148599044", "2014910234712225061", "9658113323175370226", "1584118137",
      "67925153345598920", "6960366756", "863413844386808834", "799302243562410012", "44481835751",
      "8004606814733183", "19623906615609", "23859998326058162", "461385591582", "9261878982390119",
      "1569373294276", "318106951168934", "65389049931", "12791173342", "507877942026",
      "3947173045690", "472425746178910", "524552931853595", "40771812249667850232", "563988469071932",
      "28147819070", "797007158858587", "5716177008624223", "387565700495309324", "4716621063133318"}
      ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 814880650; verify_case(5, Arg1, countMultiples(Arg0)); }

      // END CUT HERE

      //}}}e


      int countMultiples(vector <string> pieces) ;
};
template<typename T, T MOD>
class modular_number{
  public:
  T n;
  modular_number(T x){
    if (x<0) {
      n=MOD-(-x)%MOD;
    } else n=x%MOD;
  }
  modular_number():n(0){}
  modular_number<T, MOD> operator+(const modular_number<T, MOD> &a) {
    return modular_number(n + a.n);
  }
  modular_number<T, MOD> operator-(const modular_number<T, MOD> &a) {
    return modular_number(n - a.n);
  }

  modular_number<T, MOD> operator*(const modular_number<T, MOD> &a) {
    return modular_number(n * a.n);
  }
  modular_number<T, MOD> operator+=(const modular_number<T, MOD> &a) {
    n=(n+a.n)%MOD;
    return *this;
  }
  modular_number<T, MOD> operator-=(const modular_number<T, MOD> &a) {
    n=(MOD+n-a.n)%MOD;
    return *this;
  }

};
typedef modular_number<long long int, 1000000007> num;
int ElevenMultiples::countMultiples(vector <string> p){
  num fact[52];
  fact[0]=1;
  REP(i, 51) if(i) fact[i] = fact[i-1] * i;

  int cnt[2]={0,0}; // number of even length pieces and odd length pieces
  REP(i, p.size()) cnt[p[i].size() % 2]++;

  num D[51][51][11]; //D[x][y][z] = how many placements have x even pieces on even locations and y even pieces on even locations with sum z
  memset(D,0,sizeof(D));
  D[0][0][0]=1;
  REP(s,p.size()) {
    num NEW[51][51][11];
    memset(NEW, 0, sizeof(NEW));
    int sum_even = 0;
    int sum_odd = 0;
    REP(i, p[s].size()) {
      sum_even += 11 + (i%2?-1:1)*(p[s][i] - '0');
    }  
    sum_even %= 11;
    sum_odd = (11-sum_even)%11;

      //sum_odd contribution to modulus when placed on odd start
      //sum_even contribution to modulus when placed to 

      REP(i,cnt[0] + 1) REP(j,cnt[1] + 1) REP(k, 11){
        if(p[s].size() % 2) {
          NEW[i][j ][(k+sum_odd)%11] += D[i][j][k];//we place odd piece on odd location
          if(j+1<=cnt[1])NEW[i][j + 1][(k+sum_even)%11] += D[i][j][k];  //we place odd piece on even location

        } else {
          NEW[i][j][(k+sum_odd)%11] += D[i][j][k]; //we place even piece on odd location
          if (i+1<=cnt[0]) NEW[i+1][j][(k+sum_even)%11] += D[i][j][k]; //we place even piece on even location
        }

      }
    //  if(s==0) {
     // REP(k,10) {
      //REP(i,3) REP(j,3) {
       // cout<<NEW[i][j][k].n<<" ";
     // }
      //cout<<endl;
      //}
      //}
      //REP(i,cnt[0] + 1) REP(j,cnt[1] + 1) REP(k, 11) D[i][j][k]=NEW[i][j][k];
 memcpy(D, NEW, sizeof(NEW));

  }
  //cout<<D[2][1][0].n<<endl;
  num rval(0);
  num D2[51][51]; //remainint, even
  int n=cnt[0]+1;
  D2[n-1][0]=1;
  REP(i,cnt[1]+1) {
    num NEW[51][51];
    memset(NEW,0,sizeof(NEW));
    if(i%2) {
      REP(x,n) REP(y,n) for(int j=x;j<n;++j) NEW[x][y]+=D2[j][y];
    } else {
      REP(x,n) REP(y,n) for(int j = x;j < n; ++j) if(y-j+x>=0) NEW[x][y] += D2[j][y - j + x];
    }
    memcpy(D2, NEW, sizeof(NEW));
  }
  //cout << D2[0][2].n << endl;
  REP(i, n) {
    int z = (cnt[1] + 1) / 2;
   // cout<<i<<" z="<<z<<  D[i][z][0].n<<" "<<D2[0][i].n<<endl;
    rval += D[i][z][0] * D2[0][i]*fact[i]*fact[n-i-1]*fact[z]*fact[cnt[1]-z];

  }
  rval=rval;
  return rval.n;

}
//{{{b
int main() {
  ElevenMultiples ___test;
  ___test.run_test(-1);
}
//}}}e

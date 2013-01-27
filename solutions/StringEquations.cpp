#line 5 "StringEquations.cpp"
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

class StringEquations {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "E = R + hhfnzdujksvaxsaxbuagv", "D = Z + mipysxujvywgmyhrwudvdtju", "L = U + tlrxrwkldkcbpx", "O = D + ctqjttwmwhcbbkrsubdzw", "V = T + ipysxujvywgmyhrwudvdt", "V = X + rqmipysxujvywgmyhrwudvdt", "C = Y + jtxfjejcusaynco", "K = N + qrcildaix", "N = A + qjttwmwhcb", "C = V + juctqjttwmwhcbbkrsubdzwjtxfjejcusaynco", "V = F + wirqmipysxujvywgmyhrwudvdt", "S = E + rjpsjnshonrponceuuitlgfpczovzsbearmfd", "J = G + exgm", "P = C + lhtbrqzrbggbwlzpzyct", "C = O + jtxfjejcusaynco", "C = N + bkrsubdzwjtxfjejcusaynco", "I = T + okgmrttgewrmxbnuekf", "W = N + fiyqxxkbepkoti", "E = V + llbsmwzoafxnnrzrsfydhhfnzdujksvaxsaxbuagv", "E = U + xnnrzrsfydhhfnzdujksvaxsaxbuagv", "M = J + tasvphknzpjxutdrrjphvmxfcfcj", "H = J + htttamxfuivufkmhnukibm", "N = Q + qjttwmwhcb", "B = T + skdlhfzysjhvubstzeguelprzojcftg", "V = J + duxypypprollxngwirqmipysxujvywgmyhrwudvdt"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1357; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { string Arr0[] = { "B = A + coder", "C = B + top", "C = A + topcoder" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { string Arr0[] = { "A = B + p", "C = A + q", "D = F + r", "E = B + x", "G = A + y", "H = F + z" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { string Arr0[] = { "X = X + a" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { string Arr0[] = { "Y = X + a", "Y = X + b" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE

//}}}e

	int getMinimum(vector <string> equations); 
};
string H[26][26];
int n=26;
vector<int> to,seen; //Topological order
void go(int x) {
  if(seen[x]) return;
  seen[x]=1;
  REP(i,n) if(H[x][i]!="")go(i);
  to.push_back(x);
}
int StringEquations::getMinimum(vector <string> equations) {
  //A = B + str  /from a goes edge b
  to.clear(); //bug: forgot this
  REP(i,n) REP(j,n) H[i][j]="";
  REP(i,equations.size()) {
    string s = equations[i];
    int a = s[0] - 'A';
    int b = s[4] - 'A';
    if((H[a][b]!="" && H[a][b]!=s.substr(8))  || a==b) return -1; //bug: forgot this
    H[a][b]=s.substr(8);    
//    cout<<a<<" "<<b<<" "<<H[a][b]<<endl;
  }
  seen = vector<int>(n,0);
  REP(i,n) go(i);
  vector<int> ref(n,0);
  REP(i,n) ref[i]=i;
  vector<string> pref(n);
  vector<int> init(n,0);
  vector<string> sure_suffix(n);
  REP(gg,26)REP(ii,to.size()) { //bug:forgot iteration
    int x=to[ii];
//    cout << "processing" << (char)('A'+(char)x)<<endl;
    vector<pair<string, int> > kok;
    REP(j,n) if(H[x][j]!=""){
      if(!init[j]) return -1;      
      kok.push_back(make_pair(pref[j] + H[x][j], ref[j]));
    }
    if(kok.size()>0) {
      ref[x]=kok[0].second;
      pref[x]=kok[0].first;
 //     cout << char(x+'A')<<" =="<< ref[x] << pref[x]<<endl;
    }
    vector<string> f;
    REP(i, kok.size()) {
      f.push_back(sure_suffix[kok[i].second] + kok[i].first);  //bug: here was f[i]=
    }
    int lon=0;
    REP(i,f.size()) if(f[i].size()>f[lon].size()) lon=i;
    map<int, int> extended;
    REP(i,f.size()) {
      int excess = f[lon].size()-f[i].size();
      if(f[lon].substr(excess)!=f[i]) {  // check if end t
        return -1;      
      } else {
        int variable_used = kok[i].second;
        if(extended.find(variable_used) == extended.end()) {
          extended[variable_used] = excess;
          sure_suffix[variable_used] = f[lon].substr(0, excess) + sure_suffix[kok[i].second];
        } else {
          if(extended[variable_used]!=excess) return -1;
        }
      }
    }

    init[x]=1;

  }
  vector<string> true_value;
  
  REP(i,n) true_value.push_back(sure_suffix[ref[i]] + pref[i]);

  REP(ii,to.size()) {
    int x = to[ii];
    REP(j,n) if(H[x][j]!="") {
      //cout<<char(x+'A')<<" "<<char(j+'A')<<":"<<true_value[x]<<"=="<<true_value[j] + H[x][j]<<endl;

      if(true_value[x] != true_value[j] + H[x][j]) {cout<<"KOKOT"<<endl;return -1;}
    }
  }
  int rval= 0;
  REP(i,n) rval+=true_value[i].size(); //bug: here was sure_suffix
  return rval;
}
//{{{b
int main() {
  StringEquations ___test;
  ___test.run_test(0);
}
//}}}e


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

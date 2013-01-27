//{{{b

//}}}e
#line 5 "FloodFill3D.cpp"
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
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)

class FloodFill3D {
	public:
//{{{b
 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"oxo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"oxo"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"oxo"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 19LL; verify_case(0, Arg3, countBlack(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"ooo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"oo"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"o"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(1, Arg3, countBlack(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"xxo", "oox", "o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"x", "o", "x", "o"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ooo", "xxxoo", "oxx"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 242LL; verify_case(2, Arg3, countBlack(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"xxxxxxxxxxxxxxxxxxxx"
,"xxooooooooooooooooxx"
,"xxooooooooooooooooxx"
,"xxxxxxxxooooxxxxxxxx"
,"xxxxxxxxooooxxxxxxxx"
,"xxxxxxxxooooxxxxxxxx"
,"xxxxxxxxooooxxxxxxxx"
,"xxxxxxxxooooxxxxxxxx"
,"xxxxxxxxooooxxxxxxxx"
,"xxxxxxxxooooxxxxxxxx"
,"xxxxxxxxooooxxxxxxxx"
,"xxxxxxxxooooxxxxxxxx"
,"xxxxxxxxooooxxxxxxxx"
,"xxxxxxxxxxxxxxxxxxxx"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"xxxxxxxxxxxxxxxxxxxx"
,"xxxxxxxoooooooxxxxxx"
,"xxxxxoooooooooooxxxx"
,"xxxxooooooooooooxxxx"
,"xxxxooooxxxxxoooxxxx"
,"xxxxoooxxxxxxxxxxxxx"
,"xxxxoooxxxxxxxxxxxxx"
,"xxxxoooxxxxxxxxxxxxx"
,"xxxxooooxxxxoooxxxxx"
,"xxxxoooooooooooxxxxx"
,"xxxxxooooooooooxxxxx"
,"xxxxxxoooooooxxxxxxx"
,"xxxxxxxxxxxxxxxxxxxx"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"xxxxxxxxxxxxxxxxxxxx"
,"xxxxxxxoooooxxxxxxxx"
,"xxxxoooooooooooxxxxx"
,"xxoooooooooooooooxxx"
,"xxoooooxxxxxoooooxxx"
,"xxooooxxxxxxxooooxxx"
,"xxooooxxxxxxxooooxxx"
,"xxooooxxxxxxxooooxxx"
,"xxooooxxxxxxxooooxxx"
,"xxoooooxxxxxoooooxxx"
,"xxxxoooooooooooxxxxx"
,"xxxxxxxoooooxxxxxxxx"
,"xxxxxxxxxxxxxxxxxxxx"}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 15027148LL; verify_case(3, Arg3, countBlack(Arg0, Arg1, Arg2)); }

// END CUT HERE

//}}}e


	long long countBlack(vector <string> SArray, vector <string> TArray, vector <string> UArray) ;
	long long countBlack_2(vector <string> SArray, vector <string> TArray, vector <string> UArray) ;
};
char c[2500][2500];
char k[2500][2500];
typedef long long num;
vector<num> par(string s,char o) {
  vector<num> rval(3,0);
  int n=s.size();
  REP(i,n) {
    if(s[i]!=o) break;
    rval[0]++;
  }
  if(rval[0]==n) return rval;
  REP(i,n) {
    if(s[n-1-i]!=o) break;
    rval[2]++;
  }
  rval[1]-=rval[0]+rval[2];
  REP(i,n) if(s[i]==o) rval[1]++;
  return rval;  
}
//bug: this solution was not used, because i didn't wanted to waste time, but it turned out to be better to think more
long long FloodFill3D::countBlack(vector <string> SArray, vector <string> TArray, vector <string> UArray){
   string s,t,u;
   REP(i, SArray.size()) s.append(SArray[i]);
   REP(i, TArray.size()) t.append(TArray[i]);
   REP(i,UArray.size()) u.append(UArray[i]);
   num n=s.size(); //bug: used int instead of num
   num m=t.size();
   num l = u.size();
   num rval = n*m*l;
   REP(q,2) {
     char x='x';
     if(q) x='o';
     vector<num> A=par(s,x),B=par(t,x),C=par(u,x);
     rval-=((A[0]+A[2])*(B[0]+B[2])+A[1]*(B[0]+B[2])+ B[1]*(A[0]+A[2]))   *(C[0]+C[1]+C[2]);
     rval-=A[1]*B[1] *(C[0]+C[2]);
   }
   return rval;
}
long long FloodFill3D::countBlack_2(vector <string> SArray, vector <string> TArray, vector <string> UArray){
   string s,t,u;
   REP(i, SArray.size()) s.append(SArray[i]);
   REP(i, TArray.size()) t.append(TArray[i]);
   REP(i,UArray.size()) u.append(UArray[i]);
   num n=s.size(); //bug: used int instead of num
   num m=t.size();
   num l = u.size();
   REP(i,n) REP(j,m) {
     char &x(c[i][j]);
     x=0;
     if(s[i]=='x') {
       if(t[j]=='x') x= 1; 
     } else {
       if(t[j]=='o') x=2;
     }
   }
   memset(k,0,sizeof(k));
   queue<int> Q;
   REP(i,n) {
     if(c[i][0]) {
       Q.push(i);Q.push(0);k[i][0]=1; //bug: here was m-1 instead of 0
     }
     if(c[i][m-1]) {
       Q.push(i);Q.push(m-1);k[i][m-1]=1;
     }
   }
   REP(j,m-1) if(j) {
     if(c[0][j]) {
       Q.push(0);Q.push(j);k[0][j]=1;       
     }
     if(c[n-1][j]) {
       Q.push(n-1);Q.push(j);k[n-1][j]=1;       
     }

   }/*
REP(i,n) {
  REP(j,m) {
    cout<<(k[i][j]?'1':'0');
  }
  cout<<endl;
}
cout<<endl;
REP(i,n) {
  REP(j,m) {
    cout<<((int)c[i][j]);
  }
  cout<<endl;
}*/

   while(!Q.empty()) {
     int y=Q.front();Q.pop();
     int x=Q.front();Q.pop();
     int dx[4]={0,1,0,-1};
     int dy[4]={1,0,-1,0}; //bug:here was dot instead of comma :)
     REP(dir, 4) {
       int nx=x+dx[dir];
       int ny =y+dy[dir];
       if(nx>=0 && ny>=0 && nx<m && ny<n && !k[ny][nx]&& c[ny][nx]==c[y][x]) {
         Q.push(ny);
         Q.push(nx);
         k[ny][nx]=1;
       }
     }
   }
   num rval=0;
   num inc_touch[3]={0,0,0};

   REP(i, l) {
     if(u[i]=='x') inc_touch[1]++;else inc_touch[2]++;
   }
   num inc[3]={0,0,0};
   REP(z,2) {
     char w = 'x';
     if(z) w = 'o';
     num sum = 0;
     REP(i,l) {
       if(u[i] == w) sum++;else break;
     }
     if(sum != l) {
       REP(i, l) {
         if(u[l-1-i] == w) sum++;else break;
       }
     }
     inc[1+z] = sum;
   }
   //cout<<inc[0]<<" "<<inc[1]<<" "<<inc[2]<<endl;
   //cout<<inc_touch[0]<<" "<<inc_touch[1]<<" "<<inc_touch[2]<<endl;
   REP(i, n) {
     REP(j, m) {
//     cout<<((int)c[i][j]);
     if(k[i][j]) rval += inc_touch[(int)c[i][j]];
     else rval += inc[(int)c[i][j]];
     }
   }
/*
REP(i,n) {
  REP(j,m) {
    cout<<(k[i][j]?'1':'0');
  }
  cout<<endl;
}
cout<<endl;
REP(i,n) {
  REP(j,m) {
    cout<<((int)c[i][j]);
  }
  cout<<endl;
}*/
   return n*l*m-rval; //bug:forgot about returning other stuff


}
//{{{b
int main() {
  FloodFill3D ___test;
  ___test.run_test(-1);
}
//}}}e

#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
vector<int> createKMPtable3(string s) {
  int n = s.size();
  vector<int> res(n+1,0);;

  //this is rather tricky way;
  int i=0;
  int j=-1;
  res[0]=-1;  
  while(i<n) {
    if (j>=0 && s[j]!=s[i]) j=res[j];else res[++i]=++j;
  }
  return res;
}
//for(int i=0,j=-1;i<n;) if(j>=0 && s[j]!=s[i]) j=res[j];else res[++i]=++j;//res.psush_back(++j) 
vector<int> KMPsearch3(string s, string patch, vector<int> kmp){
  int  n =s.size();
  vector<int> res;
  int i=0;
  int j=-1;
  while(i<n){
    while(j >=0 && patch[j] != s[i]) j = kmp[j];
    j++;
    if (j == (int)patch.size()) {
      res.push_back(i-j+1);
      j = kmp[j];
    }
    i++;
  }
  return res;
}

int main(){
}

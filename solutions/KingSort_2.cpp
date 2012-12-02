#line 5 "KingSort.cpp"
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

class KingSort {
	public:


	vector <string> getSortedList(vector <string> kings) ;
};

int decode(string s) {
  string a[11]={"","I","II","III","IV","V","VI","VII","VIII","IX","X"};
  string b[6]={"","X","XX","XXX","XL","L"};
   REP(i,6) REP(j,11) {
     string res = string(b[i])+string(a[j]);
     int num = i*10+j;
     if(res==s) return num;
   } 
 return 0;
}
class cmp{
  public:
    bool operator()(string a,string b) {
      int p =a.find(' ');
      string name1=a.substr(0,p);
      int num1 = decode(a.substr(p+1));
      p = b.find(' ');
      string name2 = b.substr(0,p);
      int num2 = decode(b.substr(p+1));
      if(name1==name2) return num1<num2;
      return name1<name2;


    }
};
vector <string> KingSort::getSortedList(vector <string> kings){
   sort(kings.begin(),kings.end(),cmp());
   return kings;
}

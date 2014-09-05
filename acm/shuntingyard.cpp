#include<cstdio>
#include<string>
#include<stack>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define NUM 0
#define LPAR 1
#define RPAR 2
#define OP 3
#define FUN 4
#define COMMA 5
struct token{
  int type;
  string val;
  token(int a,string b) :type(a),val(b) {}
};
vector<token> tokenize(string s) {
    int stav;
    string v;
    stav=-1;
    vector<token> rval;
    REP(i,s.size()) {
        char c=s[i];
        int next=-1;
        if(isdigit(c)) {
            if(stav==FUN) next=FUN;else     next=NUM;
        } else if(isalnum(c)){
            next=FUN;

        } else if(c=='(' ){
            next=LPAR;
        } else if(c==')') {
            next=RPAR;
        } else if(c==',') {
            next=COMMA;
        } else next=OP;
        if(stav!=next) {
            if(stav!=-1) rval.push_back(token(stav,v));
            stav=next;
            v=string(1,c);
        } else v.push_back(c);
    }
    if(stav!=-1)rval.push_back(token(stav,v));
    return rval;
}
int getPriority(char x) {
 if(x=='+') return 5;
 if(x=='*') return 10;
 return 1;
}
int getRightAsoc(char x) {
  if(x=='+') return 1;
  if(x=='*') return 1;
return 0;
}
vector<token> to_polish(vector<token> a)  {
    stack<token> s;
    deque<token>rval;
    REP(i,a.size()) {
        token x=a[i];;
        switch (x.type) {
            case NUM:
                rval.push_front(x);
                break;
            case FUN:
            case LPAR:
                s.push(x);
                break;
            case RPAR:  //OK=0
                while(!s.empty()) {
                  token  b=s.top();
                  s.pop();
                  if(b.type==LPAR) break; //OK=1
                  else rval.push_front(b); 
                }
                if(!s.empty() && s.top().type==FUN) {
                    rval.push_front(s.top());
                    s.pop();
                }
                break;
            case COMMA:
                while(!s.empty()) {
                    if(s.top().type==LPAR) break;
                    rval.push_front(s.top());
                    s.pop();
                }
                break;
            case OP:
                while(!s.empty() && s.top().type==OP) {
                    token z=s.top();
                    if(getPriority(x.val[0])>getPriority(z.val[0])-getRightAsoc(x.val[0])  ) break;
                    rval.push_front(z);
                    s.pop();
                }
                s.push(x);
                break;
        }
    }
    while(!s.empty()) {
      rval.push_front(s.top());
      s.pop();
    }
    vector<token> res(rval.size(),token(0,""));
    REP(i,rval.size()) res[i]=rval[i];
    return res;
}
int main() {
    char p[1000];
    gets(p);
    vector<token> v=to_polish(tokenize(p));
    REP(i,v.size()) printf(" %s",v[i].val.c_str());
    printf("\n");

}

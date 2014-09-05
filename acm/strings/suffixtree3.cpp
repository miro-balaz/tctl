#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>

#define K 128
#define N 520000
char p[650001];
#define REP(i,n) for(int i=0;i<(int)(n);++i) 
using namespace std;
struct edg{
    int beg;
    int len;
    int parent;
    map<char,int> down;
    int suffixlink;
};
edg T[N*3+42];
string P;
vector<string> dumptree(int x) {
    vector<string> rv;
    rv.push_back(P.substr(T[x].beg,T[x].len));        
    REP(i,K) if(T[x].down[i]){
        vector<string> a=dumptree(T[x].down[i]);
        REP(j,a.size()) if(rv.size()==0)   
            rv.push_back(P.substr(T[x].beg,T[x].len)+a[j]);        
        else 
            rv.push_back(string(T[x].len,' ')+a[j]);                
    }
    if (rv.size()==0) rv.push_back(P.substr(T[x].beg,T[x].len));
    return rv;
}
int root;
void printTree() {
    vector<string> vs=dumptree(root);
    //  printf("%d\n",solvetree(root));
    REP(i,vs.size()) printf("%s\n",vs[i].c_str());
}
int treesize;
void buildTree() {
    treesize=0;
    int i=0,j=1;
    int n= strlen(p);
    for(int x=0;x<n;++x) p[x]-='A';
    //j dlzka substrigu ktory pridavame je j-i-1
    //i je index prveho znaku v novom substringu
    int needmoveup=0;
    root= ++treesize;
    T[root].down.clear();
    T[root].beg=0;
    T[root].len=0;
    int pozicia = root;    
    int needsuffixlink=0;
    int cmpx=0;
    while(i!=n) {
            int wtf=-1;
            cmpx++;
        while(needmoveup>=T[pozicia].len) {

            needmoveup-=T[pozicia].len;
            if(needmoveup==0) {
                break;
            } else {
                char c=p[j-1-needmoveup];
                pozicia = T[pozicia].down[c];
            }
            cmpx++;
        }
        if(needmoveup==0) {
        //we reached node that can be set as suffix link        
          T[needsuffixlink].suffixlink=pozicia;
          needsuffixlink=0;        
          char c=p[j-1];
          if( T[pozicia].down[c]==0 ) {
          //case 2 we add another Te, so it will be leaf
             int t=++treesize;
             T[t].down.clear();
             T[pozicia].down[c]=t;
             T[t].parent=pozicia;
             T[t].beg=j-1;
             T[t].len=n-j+1;
             T[t].suffixlink=0;
             wtf=2;
             pozicia=t;
             } else {
                pozicia=T[pozicia].down[c];
                wtf=3;
           } 
        } else {
          if(p[j-1]==p[T[pozicia].beg+needmoveup ]) {                     
              if(T[pozicia].beg+T[pozicia].len==n) {
                  if ( T[pozicia].beg + needmoveup==j-1 ){
                      wtf=1;                      
                  }
              }
              if (wtf==-1) wtf=3;
          }  else {
            //and here it is case 2
            //we need to add 2 Tes
            int t1=++treesize;
            int t2=++treesize;
            T[t1].down.clear();
            T[t2].down.clear();
            T[t2].parent  = t1;
            T[t1].parent = T[pozicia].parent;
            T[pozicia].parent =  t1;

            T[t1].beg = T[pozicia].beg;
            T[t1].len = needmoveup;
            T[pozicia].beg = T[t1].beg+needmoveup;
            T[pozicia].len -= needmoveup;
 
            T[t2].beg = j-1;
            T[t2].len = n-j+1; 
            int t = T[t1].parent;
            T[t].down[p[T[t1].beg]]=t1;
            T[t1].down[p[j-1]]=t2;
            T[t1].down[p[T[pozicia].beg]]=pozicia;
            T[t1].suffixlink=0;
            wtf=2;
            T[needsuffixlink].suffixlink=t1;
            needsuffixlink=t1;            
            pozicia=t1;
          }
        } 
        if(wtf==3) {
          j++;
          needmoveup++;
          if(j>n) break;
        } else {
          i++;
          if(i==j) {j++;needmoveup++;}          
          while(pozicia!=root &&  T[pozicia].suffixlink==0 ) {
            needmoveup+=T[T[pozicia].parent ].len;
            pozicia=T[pozicia].parent;
          }
          if(pozicia!=root) {
            int sl=T[pozicia].suffixlink;
            needmoveup+=T[sl].len- T[pozicia].len;
            pozicia=sl;
          } else {
            needmoveup--;
          }
        }
    }
    printf("complexity=%d\n",cmpx);

}
int solvetree(int x) {
int rv=0;
REP(i,K) if(T[x].down[i]) {
    rv+=solvetree(T[x].down[i]);
}
return rv+T[x].len;
}
int main() {
 //   int t;
//    scanf("%d",&t);    
    REP(i,1) {
    scanf("%s",p);
    
//    P=p;
    buildTree();
   // vector<string> vs=dumptree(root);
//    printf("%d\n",solvetree(root));
   // REP(i,vs.size()) printf("%s\n",vs[i].c_str());
    }
}


#include<cstdio>
#include<queue>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
struct T1{
    T1 *down[255];
    T1 *die;
    int cislo;
};
int add(T1 *x,char *c,int cislo) {
    if(x==0)  {
        x=new T1();
        REP(i,255) x->down[i]=0;
        x->cislo=0;
    }
    if(*c) {
        int k=*c;
        return x->down[k]=add(x->down[k],c+1);
    }  else {
        x->cislo=cislo;
    }
}
T1 *root;
void build() {
    queue<T1*> Q;
    Q.push(root);
    while(!Q.empty()) {
        T1 *k=Q.front();
        Q.pop();
        REP(i,255) if(k->down[i]){
            T1  *now=k->die;
            while(!now->down[i]) now=now->die;
            k->down[i]->die=now->down[i];
            Q.push(k->down[i]);
        }
    }
}
void search(string s) {
T1 *pos=root;
REP(i,s.size()) {
    int k=s[i];
    while(!pos->down[k] ) pos=pos->die;
    pos=pos->down[k];
    if(pos->cislo) {
        //nasiel som
    }
}
}
void uvolni(T1 *x) {
    REP(i,255) if(x->down[i]) uvolni(x->down[i]);
    free(x);
    
}
int main() {
    //add leming source
    int n;
    scanf("%d",&n);
    REP(i,n) {
        char p[100];
        scanf("%s",p);
        root=add(root,p);
    }
    *T1 gate;
    gate = new T1();
    REP(i,255)gate->down[i]=root;
    root->die=gate;
    build();
}


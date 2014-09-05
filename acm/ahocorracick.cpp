#include<cstdio>
#include<queue>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
struct T1{
    int down[255];
    int die;
    int cislo;
};
T1 tree[10000];
int treesize=0;
int add(int x,char *c,int cislo) {
    if(x==0)  {
        x=++treesize;
        REP(i,255) tree[x].down[i]=0;
        tree[x].cislo=0;
    }
    if(*c) {
        int k=*c;
        return tree[x].down[k]=add(tree[x].down[k],c+1);
    }  else {
        tree[x].cislo=cislo;
    }
}
int root=0;
void build() {
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()) {
        int k=Q.front();
        Q.pop();
        REP(i,255) if(tree[k].down[i]){
            int now=tree[k].die;
            while(!tree[now].down[i]) now=tree[now].die;
            tree[tree[k].down[i] ].die=tree[now].down[i];
            Q.push(tree[k].down[i]);
        }
    }
}
void search(string s) {
int pos=root;
REP(i,s.size()) {
    int k=s[i];
    while(!tree[pos].down[k] ) pos=tree[pos].die;
    pos=tree[pos].down[k];
    if(tree[pos].cislo) {
        //nasiel som
    }
}
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
    treesize++;
    REP(i,255) tree[treesize].down[i]=root;
    tree[root].die=treesize;
    build();
}


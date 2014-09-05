#include<cstdio>
#include<vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i) 
struct Node {
    int children[2];
    int key;
};
int treesize;
Node node[10000];
int root=1;

void make_splay(vector<int> &nodes, vector<int> &dirs) {
        int a=dirs.size();
    while(a>=2) {
        if(dirs[a-1]==dirs[a-2] ) {
            //rotatey
            int k=dirs[a-1];
          if(a>=3)  node[nodes[a-3]].children[dirs[a-3]]=nodes[a-1];
            node[nodes[a-1]].children[!k]=nodes[a-2];
            node[nodes[a-2]].children[k]=node[nodes[a-1]].children[!k];
            nodes[a-2]=nodes[a-1];
            nodes[a-1]=nodes[a];
            dirs[a-2]=dirs[a-1];
            a--;
            //rotatex
            if(a>=2)  node[nodes[a-2]].children[dirs[a-2]]=nodes[a];
            node[nodes[a]].children[!dirs[a-1]]=nodes[a-1];
            node[nodes[a-1]].children[dirs[a-1]]=node[nodes[a]].children[!dirs[a-1]];
            nodes[a-1]=nodes[a];
            a--;
        } else {
            //rotate x
            node[nodes[a-2]].children[dirs[a-2]]=nodes[a];
            node[nodes[a]].children[!dirs[a-1]]=nodes[a-1];
            node[nodes[a-1]].children[dirs[a-1]]=node[nodes[a]].children[!dirs[a-1]];
            nodes[a-1]=nodes[a];
            a--;
            //rotate x
            if(a>=2)  node[nodes[a-2]].children[dirs[a-2]]=nodes[a];
            node[nodes[a]].children[!dirs[a-1]]=nodes[a-1];
            node[nodes[a-1]].children[dirs[a-1]]=node[nodes[a]].children[!dirs[a-1]];
            nodes[a-1]=nodes[a];
            a--;
        }
    }
    if(a) {
            node[nodes[a]].children[!dirs[a-1]]=nodes[a-1];
            node[nodes[a-1]].children[dirs[a-1]]=node[nodes[a]].children[!dirs[a-1]];
            nodes[a-1]=nodes[a];
    }
    root=nodes[0];
  
}
void splay(int x) {
    int y=root;
    vector<int> nodes,dirs;
    while(1) {
        nodes.push_back(y);
        if(node[y].key==x) break;
        int k=0;
        if(node[y].key<x) k=1;
        if(node[y].children[k]==0) break;
        y=node[y].children[k];
        dirs.push_back(k);
    }
    make_splay(nodes,dirs);
    //now aply rotations and fuck it up the tree
}
void insert(int x) {
    int y=root;
    vector<int> nodes,dirs;
    while(1) {
        nodes.push_back(y);
        if(node[y].key==x) break;
        int k=0;
        if(node[y].key<x) k=1;
        if(node[y].children[k]==0) {
            treesize++;
            //newnode
            node[treesize].children[0]=0;
            node[treesize].children[1]=0;
            node[treesize].key=x;
            node[y].children[k]=treesize;
            dirs.push_back(k);
            nodes.push_back(treesize);
            break;

        }
        y=node[y].children[k];
        dirs.push_back(k);
    }
    make_splay(nodes,dirs);
}
void print_tree(int x) {
    if(x==0) return;
    print_tree(node[x].children[0]);
    printf("%d\n",node[x].key);
    print_tree(node[x].children[1]);
}
int main() {
    root=1;
    treesize=1;
    node[root].children[0]=0;
    node[root].children[1]=0;
    REP(i,2) insert(i);
    print_tree(root);
}

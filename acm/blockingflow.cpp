#include<cstdio>
#include<vector>
#include<queue>
#define REP(i,n) for(int i=0;i<(int)(n);++i)
using namespace std;
struct Hrana {
    int x,y,c,t;
    Hrana(int xx,int yy,int cc):  x(xx),y(yy),c(cc),t(0)  {}
    void pripocitaj(int a,int cc);
    int res(int a);
    int sused(int a);

};
void Hrana::pripocitaj(int a,int cc) {
    if(a==x) t+=cc;else t-=cc;
}
int Hrana::sused(int a) {
    if(a==x) return y;
    else return x;
}
int Hrana::res(int a) {
    if(a==x) return c-t;
    return t;
}
/*int rec_block(int x) {
    REP(i,graf[x].size()) if(graf[x][i]->res(x)  &&
            dst[graf[x][i]->sused(x)]-dst[x]=1) {
    if(rec_block(graf[x][i]->sused[x]))  {
        graf[x][i]->prirataj(x,1);
        return 1;
    }
    }
    return 0;
}*/
vector<vector< Hrana*> > graf;
int n;
int max_flow(int source,int target) {
    int res=0;
    while(1) {
        queue<int> q;
        vector<int> dst(n,-1);
        dst[source]=0;
        q.push(source);
        //construct layered graph
        while(!q.empty()) {
            int k=q.front();
            q.pop();
            REP(i,graf[k].size()) if(graf[k][i]->res(k)>0) {
                int x=graf[k][i]->sused(k);
                if(dst[x]==-1) {
                    dst[x]=dst[k]+1;
                    q.push(x);
                }
            }
        }
        if(dst[target]==-1) break;
        //find blocking flow


        vector<int> path(1,source);  // current path, 
        vector<int> next(n,0); // Next edge in graph
        while(!path.empty()) {
        
            int t=path.back();
            if(next[t]==(int)graf[t].size()) {  // if there are no more edges for d, pop it from path
                path.resize(path.size()-1);
                if(path.empty()) break;
                next[path.back()]++;
                    continue;
            }
            if(graf[t][next[t]]->res(t)>0) {
                int s=graf[t][next[t]]->sused(t);
                if(s==target) {  // Found target
                    res++;
                    REP(i,path.size()) {
                        graf[path[i]][next[path[i]]]->pripocitaj(path[i],1);
                        if(graf[path[i]][next[path[i]]]->res(path[i])==0) next[path[i]]++;
                    }
                    path.resize(1);
                } else if(dst[s]-dst[t]==1 && next[s]!=(int)graf[s].size())path.push_back(s); //next level and node has some unclosed edges
                else next[t]++;  // next edge
            } else next[t]++; // next edge
        }
    }
    return res;

}
void addedge(int x,int y) {
  Hrana *a;
 // printf("adding edge %d %d\n",x,y);
  a= new Hrana(x,y,1);
  graf[x].push_back(a);
  graf[y].push_back(a);
}
int main() {

}

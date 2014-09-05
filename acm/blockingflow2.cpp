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
vector<vector< Hrana*> > graf;
int n;
int max_flow(int source,int target) {
    int res=0;
    while(1) {
        queue<int> q;
        vector<int> dst(n,-1);
        q.push(source);
        //construct layered graph
        while(!q.empty()) {
            int k=q.front();
            q.pop();
            REP(i,graf[k].size()) {
                int x=graf[k][i]->sused(k);
                if(dst[x]==-1) {
                    dst[x]=dst[k]+1;
                    q.push(x);
                }
            }
        }
        if(dst[target]==-1) return 0;
        //find blocking flow

        
        vector<int> path(1,source);
        vector<int> next(n,0);
        while(!path.empty()) {
            int t=path.back();
            if(next[t]==(int)graf[t].size()) {
                path.resize(path.size()-1);
                if(path.empty()) break;
                next[path.back()]++;
                    continue;
            }
            if(graf[t][next[t]]->res(t)>0) {
                int s=graf[t][next[t]]->sused(t);
                if(s==target) {
                    res++;
                    REP(i,path.size()) {
                        graf[path[i]][next[i]]->pripocitaj(path[i],1);                    
                        if(graf[path[i]][next[i]]->res(path[i])==0) next[i]++;
                    }

                } else if(dst[s]-dst[t]==1) {
                    if(next[s]!=(int)graf[s].size()) path.push_back(s);else next[t]++;
                }
            }        
        }
    }
    return res;

}
int main() {

}

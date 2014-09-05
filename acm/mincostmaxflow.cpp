#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i) 
struct Hrana
{
    int x, y,c, t;
    double pr;

    Hrana(int xx, int yy, int cc, double pp) : x(xx),
    y(yy),c(cc),t(0),pr(pp) {}
    int res(int a);
    int sused(int a);
    void prirataj(int a, int cc);
};
int Hrana::res(int a)
{
    if (a == x) return c - t;
    else return t;
}
void Hrana::prirataj(int a, int cc)
{
    if (a == x) t += cc;
    else t -= cc;
}
int Hrana::sused(int a)
{
    if (a == x) return y;
    else return x;
}
vector<vector< Hrana* > > graf;
int n;
double mcmf(int s,int target) {
    double rval=0;
    double res=0;
    int cnt=0;
    while(1) {
        priority_queue<pair<int, int > > q;
        vector<double> dst(n,-1);
        q.push(make_pair(0,s));
        vector<Hrana*> from(n);
        dst[s]=0;
        while(!q.empty()) {
            pair<int,int> a=q.top();q.pop();
            int k=a.second;
            REP(i,graf[k].size()) if(graf[k][i]->res(k)>0){
                int x=graf[k][i]->sused(k);
                if(  dst[x]==-1 || dst[x]>dst[k]+graf[k][i]->pr){
                    dst[x]=dst[k]+graf[k][i]->pr;
                    //printf("%d <- %lf  %d %lf\n",x,dst[x],k,graf[k][i]->pr);
                    from[x]=graf[k][i];
                    q.push(make_pair(-dst[x],x));
                }
            }
        }
        if(dst[target]==-1) break;
        cnt++;
        //todo: reduce costs
        REP(i,n)  REP(j,graf[i].size()) if(graf[i][j]->res(i)){
            int k=graf[i][j]->sused(i);
            graf[i][j]->pr-=dst[k]-dst[i];
        }

        //push flow
        res+=dst[target];
        rval+=res;
        int t=target;
        //printf("printing %.10lf\n",dst[target]);

        while(t!=s) {
            //printf("%d\n",t);
            from[t]->prirataj(from[t]->sused(t),1);
            from[t]->pr=0;
            t=from[t]->sused(t);
        }
    }
    //printf("cnt=%d\n",cnt);
    if(cnt*2+2!=n) return 0.0;
    return rval;
  
}
void addedge(int a,int b,double c) {
    //printf("hrana %d %d %lf\n",a,b,c);
    Hrana *tmp=new Hrana(a,b,1,c);
    graf[a].push_back(tmp);
    graf[b].push_back(tmp);
}
int main() {
    int N;
    scanf("%d",&N);
    n=N+N+2;
    graf=vector<vector<Hrana* > > (n);
    REP(i,N)  {
        REP(j,N)  {
            double x;
            scanf("%lf",&x);
            if(x) {
                //printf("ooo=%lf\n",x);
                addedge(i,N+j,-log(x/100.0));
            }
        }
    }
    REP(i,N) addedge(n-2,i,0);
    REP(i,N) addedge(N+i,n-1,0);
    double x=mcmf(n-2,n-1);
    if(x>0 )  printf("%lf\n",exp(-x+log(100.0)) );
    else printf("0.00\n");

}

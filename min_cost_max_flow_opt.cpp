typedef int cost_t;
struct Hrana
{
  int x, y,c, t;
  cost_t pr;

  Hrana(int xx, int yy, int cc, cost_t pp) : x(xx),
  y(yy),c(cc),t(0),pr(pp) {}
  int res(int a) const;
  int sused(int a) const;
  void prirataj(int a, int cc);
};
inline int Hrana::res(int a) const
{
  if (a == x) return c - t;
  else return t;
}
void Hrana::prirataj(int a, int cc)
{
  if (a == x) t += cc;
  else t -= cc;
}
inline int Hrana::sused(int a) const
{
  if (a == x) return y;
  else return x;
}
vector<vector< Hrana* > > graf;
int n;

cost_t mcmf(int s,int target) {
  cost_t rval=0;
  cost_t res=0;
  int cnt=0;
  n=graf.size();
  while(1) {
    priority_queue<pair<cost_t, int > > q;
    vector<cost_t> dst(n,-1);
    q.push(make_pair(0,s));
    vector<Hrana*> from(n);
    dst[s]=0;
    while(!q.empty()) {
      pair<cost_t,int> a=q.top();q.pop();
      int k=a.second;
      REP(i,graf[k].size()) if(graf[k][i]->res(k)>0){
        const Hrana &edge(*graf[k][i]);
        int x=edge.sused(k);
        if(  dst[x]==-1 || dst[x]>dst[k]+edge.pr){
          dst[x]=dst[k]+edge.pr;
          //printf("%d <- %lf  %d %lf\n",x,dst[x],k,graf[k][i]->pr);
          from[x]=const_cast<Hrana*>(&edge);
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
  //if(cnt*2+2!=n) return 0.0;
  cout<<rval<<endl;
  return rval;

}
void addedge(int a,int b,int capacity, cost_t cost) {
  //   printf("hrana %d %d  %d %lf\n",a,b,capacity,cost);
  Hrana *tmp=new Hrana(a,b,capacity,cost);
  graf[a].push_back(tmp);
  graf[b].push_back(tmp);
}

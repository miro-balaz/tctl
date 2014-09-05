#include<cstdio>
#include<vector>
#include<map>
#include<string> 
#include<algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i) 
int h[1500][1500];
struct intervaltree{
    int n,m;
    int t[3600];

    void init(int nn);

void add(int a,int b, int x);
int read(int x) ;
int get(int x);
void set(int a,int b,int x);
};
void intervaltree::add(int a,int b,int x) {
    while(a<=b) {
     //   printf("%d %d\n",a,b);
        if(a==b) {
            t[a]=max(t[a],x);
            break;
        }
        if(a%2==0)  t[a]=max(x,t[a]);
        a=a/2;
        if(b%2) t[b]=max(t[b],x);
        b=b/2-1;
    }
}
void intervaltree::set(int a,int b,int x) {
   // printf("kks %d %d %d\n",a,b,n);
    if(a>b || a<0 || b<0 || a>=n || b>=n) return;
   // printf("Setting [%d %d] %d\n",a,b,x);
    add(a+m-1,b+m-1,x);
}
int intervaltree::read(int x) {
    int rval=t[x];
    while(x) {
        x=(x-1)/2;
        rval=max(rval,t[x]);
    }
    return rval;
}
int intervaltree::get(int x) {
    int a= read(x+m-1);
  //  printf("returning %d\n",a);
    return a;

}

void intervaltree::init(int nn) {
    n = nn;
    m=1;
    while(m<n) m*=2;
    REP(i,m+n) t[i]=0;
}
intervaltree hor[1500];
intervaltree ver[1500];
int main() {
int n,r,c;
scanf("%d %d %d",&n,&r,&c);
REP(i,n) REP(j,n) {
    scanf("%d",&h[i][j]);
}
//n=10;
REP(i,n) hor[i].init(n);
REP(i,n) ver[i].init(n);
hor[0].set(0,5,7);
//REP(i,32) printf("%d: %d\n",i,hor[0].t[i]);
//printf("Test:%d\n",hor[0].get(3));
//return 0;
vector<pair<int,pair<int,int > > > v(n*n);
REP(i,n) REP(j,n) v[i*n+j]=make_pair(-h[i][j],make_pair(i,j));
sort(v.begin(),v.end());
int res=0;
REP(i,n*n) {
    int j=i;
    vector<pair<int,int > > vp; 
    while(j<n*n &&  v[i].first==v[j].first) {
        int y=v[j].second.first;
        int x=v[j].second.second;
        vp.push_back(make_pair(j,max(ver[x].get(y),hor[y].get(x)  )));
        j++;
    }
    REP(j,vp.size()) {
        int y=v[vp[j].first].second.first;
        int x=v[vp[j].first].second.second;
//        printf("processsing %d %d: %d\n",x,y,vp[j].second);
        if(y==r-1 && x==c-1) res=vp[j].second; 
     if(x)   ver[x-1].set(0,y-2,vp[j].second+1);
     if(x)   ver[x-1].set(y+2,n-1,vp[j].second+1);
     if(x+1<n)   ver[x+1].set(0,y-2,vp[j].second+1);
     if(x+1<n)   ver[x+1].set(y+2,n-1,vp[j].second+1);
     if(y)   hor[y-1].set(0,x-2,vp[j].second+1);
     if(y)   hor[y-1].set(x+2,n-1,vp[j].second+1);
     if(y+1<n)   hor[y+1].set(0,x-2,vp[j].second+1);
     if(y+1<n)   hor[y+1].set(x+2,n-1,vp[j].second+1);


    }
    i=j-1;

}
printf("%d\n",res+1);

}

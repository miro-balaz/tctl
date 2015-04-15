#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
int n;
vector<int> x0,x1,y0,y1;
struct event{
  int y1,y2,t;
  event(int y11,int y22,int tt):y1(y11),y2(y22),t(tt){}
};
bool operator<(const event &a, const event &b){return a.t+b.t?false:false;}
int main() {
  int n;
  cin>>n;
  x0.resize(n);
  y0.resize(n);
  x1.resize(n);
  y1.resize(n);

  REP(i,n) {
    cin>>x0[i]>>y0[i]>>x1[i]>>y1[i];
  }
  vector<int> Y;
  REP(i,n) Y.push_back(y0[i]);
  REP(i,n) Y.push_back(y1[i]);
  sort(Y.begin(),Y.end());
  Y.erase(unique(Y.begin(), Y.end()), Y.end());
  REP(i,n) y0[i]=lower_bound(Y.begin(), Y.end(), y0[i])-Y.begin(); 
  REP(i,n) y1[i]=lower_bound(Y.begin(), Y.end(), y1[i])-Y.begin(); 
  //event will be x,[start/stop], Y
  vector<pair<int, event> > events;
  REP(i,n) {
    events.push_back(make_pair(x0[i],event(y0[i],y1[i],1)));
    events.push_back(make_pair(x1[i],event(y0[i],y1[i],-1)));
  }
  sort(events.begin(), events.end());
  int rval=0;
  vector<int> p(Y.size()-1);
  int lastx=0;
  REP(i,events.size()) {

    const event &e(events[i].second);
    int delta=events[i].first-lastx;
    int sum=0;
    if(delta) {
      REP(i,p.size()) if (p[i]>0) {
     //   cout<<Y[i+1]<<"-"<<Y[i]<<endl;
        sum += (Y[i+1] - Y[i]);
      }
      rval += delta * sum;
      //cout << sum << "x" << delta << endl;
    }
    lastx=events[i].first;
    //cout << "d:" << e.y1 << "-" << e.y2 << ":" << e.t <<endl;

    for(int k=e.y1;k<e.y2; ++k) p[k]+=e.t;
  }
  cout<<rval<<endl;

}

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <iomanip> 
#include<stack>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

void solve_case()
{
    int n,m;
    cin>>n>>m;
    vector<int> s(m);
    vector<int> has(m,1);
    REP(i,m) cin>>s[i];
    int rval=0;
    int X=10000000;
    REP(j,n) {
        vector<int> p(m+1);
        REP(i,m) cin>>p[i];
        p[m]=1000000002;
        sort(p.begin(), p.end());
        vector<pair<int, int> > v(m+1);
        REP(i,m) v[i]=make_pair(s[i],i+has[i]*X);
        v[m]=make_pair(1000000001,0);
        sort(v.begin(), v.end());
        stack<int> o,t; 
       
       
        int xp=0, xv=0;

        while(xp<m || xv<m) {
            if(p[xp]==v[xv].first) {                
                ++xp;
                ++xv;
            } else if(p[xp]<v[xv].first) {                
                o.push(p[xp]);                
                ++xp;                
            } else {
                t.push(v[xv].second);
                ++xv;
            }

        }
        while(!o.empty()) {
            int sa=o.top();
            int sb=t.top();
            if(sb>=X)sb-=X;
            o.pop();
            t.pop();
            s[sb]=sa;
            if(has[sb]) {
                has[sb]=0;
            } else {
                ++rval;
            }
        
        }
        // REP(i,m) {
        //     cout<<s[i];
        //     if(has[i]) cout<<"*";
        //     cout<< " ";
        // }
        // cout<<endl;




    }
    cout<<rval<<endl;
}
int main()
{
        std::ios::sync_with_stdio(false);
        // y	our code goes here
        int T;
        cin >> T;
        REP(i, T) {
            cout<<"Case #"<<(i+1)<<": ";
            solve_case();
        }
        return 0;
}

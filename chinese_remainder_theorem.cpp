#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<cassert>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef long long int ll;
ll gcd(ll a, ll b, ll &X,ll &Y) {
  if(b==0) {
    X=1;
    Y=0;
    return a;
  }
  ll x2, y2,g;
  // najprv g=b*x2 + (a%b)*y2
  g = gcd(b, a%b,x2,y2);
  // chcem g=a*y2 + b*(x2-y2*(a/b))
 // a*y2+b*x2=(a%b+b*(a/b))*y2+b*x2=g+y2*b*(a/b)
  X=y2;
  Y=x2-(a/b)*y2;
//  cout<<"G:"<<g<<" a="<<a<<" b="<<b<<" x2="<<x2<<" y2="<<y2<<" X="<<X<<" Y="<<Y<<endl;
  return g;

}
ll smod(ll a,ll m) {
  return a%m;
//  return (a%m+m)%m;
}
ll ab(ll a) {
  if(a<0) return -a;
  return a;
}
int fff=0;
ll mul(ll a,ll b) {
  if(b==0) return 0;
  if(ab(1000000000000000000ll/b)<ab(a)) {
    cout<<"FAIL "<<a<<" "<<b<<endl;
    fff = 1;
  }
  return a*b;

}
int solve() {
  ll m,n,k;
  cin>>n>>m>>k;
  ll nsn=1;
  vector<ll> A;
  REP(i,k) {
    ll a;
    cin>>a;
    A.push_back(a);
    ll g = __gcd(a, nsn);
    if(nsn>n/(a/g)) return 0;    
    nsn*=a/g;
  }
  if(n<nsn) return 0;
  //x+0 = 0 mod a[0]
  //x = -1 mod a[1]
  //x = -2 mod a[2]
  ll r1=0,m1=A[0];
  
  REP(i,k) if(i){
    ll inv, g,aux;
    ll m2=A[i];
    ll r2=(m2-i%m2)%m2;
    r2=-i;
    g=gcd(m1, m2, inv, aux);
    ll M = m1/g*m2;
    ll l = r2-r1;
    if(l%g!=0) return 0;
    ll mm=m2/g;
    ll X = mul(smod(l,m2)/g%mm,smod(inv,mm)) % mm;
    r1=X*m1+r1;
    r1=(r1%M+M)%M; // lebo je jedine riesenie modulo M
    m1=M;

  }
  //x+cur_mod=0 mod nsn;
  ll start=r1;
  if(start==0) start += nsn; //bug:forgot about positivity
  if(start + k - 1 > m) return 0;
  REP(i,k) {
    if(__gcd(start,nsn)!=A[i]) return 0;
    start=(start+1);
  }
  return 1;
}
int main() {
  if(solve()) {
    cout<<"YES";
  } else {
    cout<<"NO";
  }
  cout<<endl;
}

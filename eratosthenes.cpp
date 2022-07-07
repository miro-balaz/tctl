#define L 10000
#define REP(i,n) for(int i=0;i<(int)(n);++i)
int h[L];
int main() {
  REP(i,L) h[i]=1;
  h[0]=0;
  h[1]=0;
  for(int i=2;i*i<L;++i) if(h[i]){
    int j=i*i;
    while(j<L) {
      h[j]=0;
      j+=i;
    }
  }

}


/* with divisors
   REP(i,L) h[i]=i;
        h[0]=0;
        h[1]=0;
        for(int i=2;i*i<L;++i) if(h[i]==i){
            int j=i*i;
            while(j<L) {
                h[j]=i;
                j+=i;
        }
*/
vector<int> compute_divisors(int a){    
    if(a==1) return vector<int>(1,1);
    int v=h[a];    
    
    int g=1;
    a/=v;
    while(a%v==0) {
        ++g;
        a/=v;
    }
    vector<int> d=compute_divisors(a);
    vector<int> rval;
    REP(i,g+1) {
        REP(j, d.size()) {
            rval.push_back(d[j]);
            d[j]*=v;
        }
    }
    return rval;
}
int gcd(int a, int b) {
    while(b!=0) {
      int c=a%b;
      
      a=b;
      b=c;
    }
    return a;
}

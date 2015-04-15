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

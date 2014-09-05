#define MOD 1000000007
#define MP(x) ((x)%MOD)
#defie M(x) (((x)%MOD+MOD)%MOD)
#define ADD(x,y) (x)=M((x)+(y))

#define MUL(x,y) (x)=M((x)*(y))
typedef long long int ll;
ll choose[N][N];
REP(i,N) choose[i][i]=choose[i][0]=1;
REP(i,n) if(i) REP(j,i) if(j) choose[i][j]=M(choose[i-1][j]+choose[i-1][j-1]);


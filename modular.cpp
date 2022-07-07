#include <iostream>
using namespace std;
#define N 10
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

// ACtual code begins here
#define MOD 1000000007
#define MP(x) ((x)%MOD)
#define M(x) (((x)%MOD+MOD)%MOD)
#define ADD(x,y) (x)=M((x)+(y))

#define MUL(x,y) (x)=M((x)*(y))
typedef long long int ll;
ll choose[N][N];


// High level
typedef long long int num;
class modNr{
    num a;
    public:
    modNr(num _a){
        if (_a<0 || _a>=MOD) a=M(_a); else a=_a;

    }
    modNr():a(0){}
    modNr& operator+=(const modNr &other) {
        a+=other.a;
        if(a>=MOD)a-=MOD;
        else if(a<0)a+=MOD;
        return *this;
    }
    modNr operator+(const modNr &other) {
        modNr res(a+other.a);
        if(res.a>=MOD)res.a-=MOD;
        else if(res.a<0)res.a+=MOD;
        return res;
    }
    modNr& operator-=(const modNr &other) {
        a-=other.a;
        if(a>=MOD)a-=MOD;
        else if(a<0)a+=MOD;
        return *this;
    }
    modNr& operator*=(const modNr &other) {
        a=M(a*other.a);        
        return *this;
    }
    modNr operator*(const modNr &other) {
        return M(a*other.a);
       
    }
    ostream& operator<<(ostream& os) {
        os << a; 
        return os;
    }
    friend ostream& operator<<(ostream& os, const modNr &datat);
      
};
ostream& operator<<(ostream& os,const modNr &data) {
        os << data.a; 
        return os;
    }
   

int main() {
  REP(i,N+1) choose[i][i]=choose[i][0]=1;
  REP(i,N+1) if(i) REP(j,i) if(j) choose[i][j]=M(choose[i-1][j]+choose[i-1][j-1]);

  modNr a(7);
  modNr b(5); 
  cout<< (a+b)<<endl;
}

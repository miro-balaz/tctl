//tento program este nebol testovany
////
#include<cstdio>
#include<algorithm>
using namespace std;
int n;//pocet riadkov
int m;//pocet stlpcov
int h[100][100];
int tmp_h[100][100];
#define REP(i,n) for(int i=0;i<(int)(n);++i) 
int matrix_rank() {
    int ndim=0;
    if(n<m) {
        REP(i,n) REP(j,m) tmp_h[i][j]=h[i][j];
        REP(i,n) REP(j,m) h[j][i]=tmp_h[i][j];
        swap(m,n);
    }
    REP(i,n) if(i<m){
        int k=i;
        while(k<n && h[k][i]==0) k++;
        if(k==n) {
            ndim++;
        } else {
            //swap lines
            if(k!=1)REP(x,m) swap(h[i][x],h[k][x]);
            int b=h[i][i];
            for(int j=i+1;j<n;++j) {
                int a=h[j][i];
                //multiply determinant by a
                REP(x,m) h[j][x]=h[j][x]*b-h[i][x]*a;
            }
        }

    }
return m-ndim;    
}
int main() {
}

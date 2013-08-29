double M[110][110];
void solve_gauss(int n, int m) {
    vector<int> vars;
    REP(i,n)vars.push_back(i);
    REP(i,n) {
        // find row with maximal value
        double x=M[i][i];
        int xi=i;
        // if there could be infinitely solution, it would need to skip row or swap columns
        for(int j=i+1; j < n; ++j) if(abs(M[j][i]) > abs(x)) {x = M[j][i];xi=j;}
        if(xi!=i) {
            swap(vars[i],vars[xi]);
            REP(j,m)swap(M[i][j],M[xi][j]); 
        }                
        for(int k=i+1;k <n;++k) {
            double c=M[k][i]/M[i][i];
            M[k][i]=0;
            for(int j=i+1;j<m;++j) M[k][j]-=M[i][j]*c;
        }
    }
    for(int i=n-1;i>=0;--i) {
        for(int j=i-1;j>=0;--j) {
            double c = M[j][i] / M[i][i];
            M[j][i] = 0.0;
            M[j][m-1] -= c * M[i][m-1];
        }
    }
    vector<double> rval(n);
    REP(i,n) rval[vars[i]] = M[i][m-1];
    REP(i,n) M[i][m-1] = rval[i];
}


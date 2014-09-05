
H[][] 


// solves non homogenous equation in Z_2, returns number of solutions
ll gauss_num_sol (int n,int m) {
  //n -rows
  //m -variables + 1 column 
  int degree = 0;
  int pivot=0;
  for(int i=0;i<min(n,m);++i,++pivot) {
    // find nonzero row

    while(pivot<m) {
      if(H[i][pivot] == 0)for(int j=i+1; j<n; ++j) if(H[j][pivot] != 0){
        REP(x, m+1) swap(H[i][x], H[j][x]);        
        break;
      }

      if (H[i][pivot]) {
        degree++;
        for(int j=i+1;j<n;++j) if(H[j][pivot] != 0){  // Do just lower triangle zero
          for(int k=pivot;k<=m;++k) H[j][k] ^= H[i][k]; //or H[j][k]-=H[i][k]*(H[j][pivot]/H[i][pivot]);
        }
        break;
      }
      pivot++;  // skip column
    }
  }
  // Check for contradiction;
  REP(i,n) if(H[i][m] !=0){
    int ok=0;
    REP(j,m) if(H[i][j]!=0) {ok=1;break;}
    if(!ok) return 0; // There is no solution
  }
  return 1ll<<(m-degree);

}

ll gauss_num_sol_bit (int n,int m) {
  //n -rows
  //m -variables + 1 column 
  int degree = 0;
  int pivot=0;
  for(int i=0;i<min(n,m);++i,++pivot) {
    // find nonzero row

    while(pivot<m) {
      if(H[i][pivot] == 0)for(int j=i+1; j<n; ++j) if(H[j][pivot] != 0){
        swap(H[i], H[j]);        // if want value remember swaps
        break;
      }
    

    if (H[i][pivot]) {
      degree++;
        for(int j=i+1;j<n;++j) if(H[j][pivot] != 0){  // Do just lower triangle zero
          H[j] ^= H[i]; 
        }
      break;
    }
    pivot++;  // skip column
    }
  }
  // Check for contradiction;
  REP(i,n) if(H[i][m] !=0){
    if(H[i].count()==1) return 0;  
  }
  return 1ll<<(m-degree);

}

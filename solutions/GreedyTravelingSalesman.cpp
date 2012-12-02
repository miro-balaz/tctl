#include<cstdio>
#include<vector>
#include<string>

class GreedyTravelingSalesman{
  public:
    int worstDistance(vector<string> thousands, vector<string> hundreds, vector<string> tens, vector<string> ones);
};
    int GreedyTravelingSalesman::worstDistance(vector<string> thousands, vector<string> hundreds, vector<string> tens, vector<string> ones) {
      int h[30][30];
      int n = hundreds.size();
#define F(x) (int)(x-'0')
      REP(i, n){ 
        REP(j,n) {
          h[i][j]=F(thousands[i][j]);
          h[i][j]=h[i][j]*10+F(hundreds[i][j]);
          h[i][j]=h[i][j]*10+F(tens[i][j]);
          h[i][j]=h[i][j]*10+F(ones[i][j]);          
        }
      }
   int rval=0;
      REP(i,n) {
        REP(j,n) {
          vector<int> sizes;
          sizes.push_back(9999);
          REP(x,n) {
            int f=h[i][x];
            sizes.push_back(f);
            sizes.push_back(f+1);
            if(f) sizes.push_back(f-1);
          }
          REP(x, sizes.size()) {
            int o=h[i][j];
            h[i][j]=sizes[x];
            vector<int> seen(n,0);
            int now=0;
            int pos=0;            
            REP(y,n) {
              seen[pos]=1;
              int best=0;
              REP(k,n) if (seen[best]||!seen[k] && h[pos][k]<h[pos][best]) {
                best=k;
              }
              now+=h[pos][best];
              pos = best;
            }
            if (now > rval) rval=now;
        
            h[i][j]=o;
          }
        }
      }



return rval;
    }

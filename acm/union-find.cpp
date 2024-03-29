//union find s kompresiou
#include<vector>
using namespace std;
vector<int> uf();
int sef(int x) {
    int z,y=x;
    while(uf[x]>=0) x=uf[x];
    while(uf[y]>=0) {
        z=uf[y];
        uf[y]=x;
        y=z;
    }
    return x;
}

void spoj(int a,int b){
  assert(a==sef(a) && b==sef(b) && a!=b);
  if(uf[a]>uf[b]) swap(a,b);    //ak a je  podstrom s menej vrcholmi
  uf[a]+=uf[b];
  uf[b]=a;
}
int main() {
    int n=100;
    uf=vector<int>(n,-1);



}
class UF{
    public:
        vector<int> uf;
        UF(int n) {
            uf=vector<int>(n,-1);
        }
    int sef(int x) {
        int z,y=x;
        while(uf[x]>=0) x=uf[x];
        while(uf[y]>=0) {
            z=uf[y];
            uf[y]=x;
            y=z;
    }
    return x;
  }

    void spoj(int a,int b){
    //assert(a==sef(a) && b==sef(b) && a!=b);
        if(uf[a]>uf[b]) swap(a,b);    //ak a je  podstrom s menej vrcholmi
        uf[a]+=uf[b];
        uf[b]=a;
    }
    void u(int a, int b) {
           int sa=sef(a);
           int sb=sef(b);
           if (sa==sb) return;
           spoj(sa,sb);
    }
};

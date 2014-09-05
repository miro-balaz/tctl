#include<cstdio>
#include<complex>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
typedef complex<double> point;
struct event;
struct breakpoint;
struct event{
    int circle;
    double y;
    int id;
    point site;
    breakpoint *bpointToRight; 
};
struct breakpoint{
    point site2,site1;
    int right;
    point siteToLeft;
    int id;
    event ev; 
    int border;
};
double l;
#define EPS (1e-7)

double getX(breakpoint W) {
    if(W.border) return real(W.site1);;
    point p1=W.site1;
    point p2=W.site2;
    double A=real(p1-p2);
    double B=imag(p1-p2);
    double C=-0.5* real((p1-p2)*conj(p1+p2));
    double sol1,sol2;
    double x1=real(p1);
    double y1=imag(p1);
    if(B!=0) {
        double a=-1;
        double b=2.0*x1+2.0*(l-y1)*A/B;
        double c=l*l-y1*y1-x1*x1+2.0*(l-y1)*C/B;
        double d=b*b-4.0*a*c;
        sol1=(sqrt(d)-b)/(2.0*a);
        sol2=(-sqrt(d)-b)/(2.0*a);
    } else {
        if(A!=0) {
          double x=-C/A;
          //sol1=sol2=(-l*l+x1*x1+x*x-2*x1*x)/(2.0*y1-2.0*l);
          sol1=sol2=x;
        } else sol1=sol2=x1;
    }
    //surely d>=0
    if(sol1>sol2) swap(sol1,sol2);
    if(W.right) return sol2;else return sol1;

}
int xxxid=1000;
bool operator<(const event &a,const event &b) {
    double x1=a.y;
    double x2=b.y;
    if(x1<x2-EPS) return true;
    if(x1>x2+EPS) return false;
    if( a.circle>b.circle) return true;
    if( a.circle<b.circle) return false;
    if(real(a.site)>real(b.site)-EPS) return true;
    if(real(a.site)<real(b.site)+EPS) return false;
    return (a.id<b.id);

}
bool operator<(const breakpoint &a,const breakpoint &b) {
    double x1=getX(a);
    double x2=getX(b);
    if(x1<x2-EPS) return true;
    if(x1>x2+EPS) return false;
    return a.id>b.id;

}
event NULLEVENT;
set<breakpoint> bs;
set<event> evs;
typedef set<breakpoint>::iterator iter;

/*void tryCircle(iter left,iter middle,iter right) {
    printf("try Circle\n");
    printf("%.2lf  %.2lf  %d\n",real(left->siteToLeft),imag(left->siteToLeft),left->id);
    printf("%.2lf  %.2lf  %d\n",real(middle->siteToLeft),imag(middle->siteToLeft),middle->id);
    printf("%.2lf  %.2lf  %d\n",real(right->siteToLeft),imag(right->siteToLeft),right->id );

    if(left->border && left->id!=-48) return;
    if(middle->border && middle->id!=-48) return;
    if(right->border && right->id!=-48) return;
   if(imag( middle->siteToLeft)>=imag(left->siteToLeft ) && (imag(middle->siteToLeft)>=imag(right->siteToLeft ) ) ) return ;
    point p1=left->siteToLeft,p2=middle->siteToLeft,p3=right->siteToLeft;
    point n1,n2;
    double c1,c2;
    n1=p1-p2;
    n2=p2-p3;
    c1=-0.5*real(n1*conj(p1+p2));
    c2=-0.5*real(n2*conj(p3+p2));
    if(imag(n1*conj(n2))!=0) {
        double y=(real(n1)*c2-real(n2)*c1)/imag(n1*conj(n2));
        double x=(imag(n1)*c2-imag(n2)*c1 )/imag(n2*conj(n1));
        event e;
        e.bpointToRight=new breakpoint( *middle);
        e.site=point(x,y);
        e.id=++xxxid; 
        e.y=y+abs(p1-e.site);
        e.circle=1;
        evs.insert(e);
       (event&) (middle->ev)=e;
       printf("TEST %d %d\n",middle->ev.id,e.id);
       printf("KOKOS %lf %lf---->%lf\n",real(e.site),imag(e.site),e.y);
    } else{
        //printf("FUCK\n");
    }
}*/
map<pair<int,int >,int > mapa;
long long int riesenie[100000];
void vylepsi(pair<int,int> A,pair<int,int> B) {
    long long int vzd=(long long int)(A.first-B.first)*(A.first-B.first) + (long long int)(A.second-B.second)*(A.second-B.second);
    if(vzd==0) return;
    if(riesenie[mapa[A]]==-1 || riesenie[mapa[A]]>vzd )riesenie[mapa[A]]=vzd;
    if(riesenie[mapa[B]]==-1 || riesenie[mapa[B]]>vzd )riesenie[mapa[B]]=vzd;

}
pair<int,int> topair(point a) {
  return make_pair((int)real(a),(int)imag(a));
}
void tryCircle(iter left,iter middle,iter right) {
    if(left->border && left->id!=-48) return;
    if(middle->border && middle->id!=-48) return;
    if(right->border && right->id!=-48) return;
    point p1=left->site1,p2=left->site2,p3=middle->site1,p4=middle->site2;
    vylepsi(topair(p1),topair(p2));
    vylepsi(topair(p1),topair(p3));
    vylepsi(topair(p1),topair(p4));
    vylepsi(topair(p2),topair(p3));
    vylepsi(topair(p2),topair(p4));
    vylepsi(topair(p3),topair(p4));
    point n1,n2;
    double c1,c2;
    n1=p1-p2;
    n2=p3-p4;
    c1=-0.5*real(n1*conj(p1+p2));
    c2=-0.5*real(n2*conj(p3+p4));
    if(imag(n1*conj(n2))!=0) {
        double y=(real(n1)*c2-real(n2)*c1)/imag(n1*conj(n2));
        double x=(imag(n1)*c2-imag(n2)*c1 )/imag(n2*conj(n1));
	int ok=1;
	//test if they realy intersect
	
	    double x1=getX(*left);
	    double x2=getX(*middle);
	    if( (x1<x-EPS) && left->right==0  ) ok=0;
	    if( (x1>x+EPS) && left->right==1  ) ok=0;
	    if( (x2<x-EPS) && middle->right==0  ) ok=0;
	    if( (x2>x+EPS) && middle->right==1  ) ok=0;
	
        if(ok){
	    event e;
	    e.bpointToRight=new breakpoint( *middle);
	    e.site=point(x,y);
	    e.id=++xxxid; 
	    e.y=y+abs(p1-e.site);
	    e.circle=1;
	    evs.insert(e);
	    (event&) (middle->ev)=e;
	}
    } else{
        //printf("FUCK\n");
    }
}

iter f(iter x,int n) {
    advance(x,n);
    return x;
}
int main() {
    int n;
    NULLEVENT.id=-470;
    NULLEVENT.y=-100000;
    scanf("%d ",&n);
    vector<pair<int,int > > body;
    REP(i,n) riesenie[i]=-1;
    REP(i,n) {
        double a,b;
        scanf("%lf %lf",&a,&b);
	body.push_back(make_pair((int)a,(int)b));
        event x;
        x.y=b;
        x.circle=0;
        x.site=point(a,b);
        x.bpointToRight=new breakpoint();
        x.id=++xxxid;
        evs.insert(x);
    }
    REP(i,n) mapa[body[i]]=i;

    breakpoint tmp1;
    event e=*(evs.begin());
    evs.erase(evs.begin());
    tmp1.ev=NULLEVENT;
    tmp1.id=-47;
    tmp1.border=1;
    tmp1.site1=point(1E51,0);
    bs.insert(tmp1);
    tmp1.id=-48;
    tmp1.border=1;
    tmp1.site1=point(1E50,0);
    tmp1.siteToLeft=e.site;
    bs.insert(tmp1);   
    tmp1.id=-49;
    tmp1.border=1;
    tmp1.site1=point(-1E50,0);
    bs.insert(tmp1);
    tmp1.id=-50;
    tmp1.border=1;
    tmp1.site1=point(-2E51,0);
    bs.insert(tmp1);
int cnt=0;
    while(!evs.empty()) {
        e=*(evs.begin());
        evs.erase(evs.begin());
        //printf("\n\n\n");
        if(e.circle) {
            printf("circle event  %lf %lf\n",e.y,l);
            if(e.y<l-EPS) continue; 
            printf("%d %d 0\n",(int)real(e.site),(int)imag(e.site));
          cnt++;
	    iter P=bs.find(*(e.bpointToRight));
            if(P->id==0) {
		printf("Wanted to erase %d\n",e.bpointToRight->id);
		continue;
	    }
            delete e.bpointToRight;
            iter A=P;
            A++;
            
            printf("KOKOT %d kkkk\n",P->id);
            bs.erase(P);
             //printf("New sweepline pos  = %lf\n",e.y);
            iter A1=f(A,-1);
            breakpoint kkt=*A1;

            kkt.site1=A1->siteToLeft;
            kkt.site2=A->siteToLeft;
            kkt.right=imag(kkt.site1)>imag(kkt.site2);
	    kkt.right=0;
            bs.erase(A1);
            l=e.y;
	    double wtf=getX(kkt);
	    kkt.right=1;
	    if(abs(real(e.site)-wtf)<abs(real(e.site)-getX(kkt) )) kkt.right=0;
	    printf("%lf $$$$ %d ->%lf\n",wtf, kkt.right,getX(kkt));
	    
            bs.insert(kkt);
            tryCircle(f(A,-2),f(A,-1),A);
            tryCircle(f(A,-1),A,f(A,+1));
      //     printf("printing breakpoints CIRCLE %lf\n",l);
      //   for(iter i=bs.begin();i!=bs.end();++i) {
       //       printf(" [%4.2lf %d  ]  (%.2lf,%.2lf) (%.2lf,%.2lf)\n",getX(*i),i->id,real(i->site1),imag(i->site1),real(i->site2),imag(i->site2));
        //    }
         //   printf("\n");

        } else {
            printf("%d %d 1\n",(int)real(e.site),(int)imag(e.site));
//            printf("normal event %lf %lf\n",real(e.site), imag(e.site));
	    cnt++;
	    //site event
            l=e.y;
           // printf("printing BEFORE ADD    l= %lf\n",l);
         //for(iter i=bs.begin();i!=bs.end();++i) {
         //     printf(" [%4.2lf %d  ]  (%.2lf,%.2lf) (%.2lf,%.2lf)\n",getX(*i),i->id,real(i->site1),imag(i->site1),real(i->site2),imag(i->site2));
          //  }
            breakpoint queryBP;
            queryBP.id=10000000;
            queryBP.border=1;
            queryBP.site1=e.site;
            set<breakpoint>::iterator it=bs.upper_bound(queryBP);
            //printf("it.di=%d\n",it->id);
            breakpoint A,B;
            A.border=0;
            B.border=0;
            A.site1=e.site;
            B.site1=e.site;
            A.site2=it->siteToLeft;
            B.site2=it->siteToLeft;
            A.siteToLeft=A.site2;
            B.siteToLeft=e.site;
            A.right=0;
            B.right=1;
            A.ev=NULLEVENT;
            B.ev=NULLEVENT;
            ++xxxid;
            B.id=xxxid;
           // printf("addding bp%d\n",xxxid);
            ++xxxid;
           // printf("addding bp%d\n",xxxid);
            A.id=xxxid;
            xxxid+=2;
            if(imag(e.site)!=imag(it->siteToLeft) ) bs.insert(A);
            bs.insert(B);
            if(it->ev.id!=NULLEVENT.id) {
             //   printf("Erasing event %d\n",it->ev.id);
                evs.erase(it->ev);
            }
            tryCircle(f(it,-1),it,f(it,+1) );
            tryCircle(f(it,-3),f(it,-2),f(it,-1) );
        //   printf("printing breakpoints %lf after add\n",l);
        // for(iter i=bs.begin();i!=bs.end();++i) {
         //     printf(" [%4.2lf %d  ]  (%.2lf,%.2lf) (%.2lf,%.2lf)\n",getX(*i),i->id,real(i->site1),imag(i->site1),real(i->site2),imag(i->site2));
          //  }
           // for(iter i=bs.begin();i!=bs.end();++i) {
            //  printf(" [%4.2lf %d]",getX(*i),i->id);
            //}
           // printf("\n");
        }
    }
REP(i,n) {
    printf("%lld\n",riesenie[i]);
}
}


//line arrangement problem
//uses double connected edge list
#include<complex>
#include<cstdio>
#include<vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i) 
struct vertex;
struct face;
typedef complex<double> point;
struct edge {
    edge  *n,*t,*p;
    face *f;
    vertex *o;
    int id;
};
struct vertex{
    edge *e;
    point u;

};
struct face{
    edge *e;
    int id;
};
#define POINT 1
#define LINE 2
#define NONE 0
#define SEGMENT 3
struct line {
    point a,b,n;
    line (point aa,point bb);
    int type; 
    line getIntersection(line x) ;
    line ():type(NONE) {}

};

line::line(point aa,point bb) {
    n=(bb-aa)*point(0,1);
    a=aa;
    b=bb;
    type=LINE;
    if(a==b) type=POINT;

}
line line::getIntersection(line x)  {
    double c1=-real(n*conj(a));
    double c2=-real(x.n*conj(x.a));
   // printf("Want to comute:\n");
  //  printf("p:%lfx+ %lfy+ %lf=0\n ",real(n),imag(n),c1);
  //  printf("q:%lfx+ %lfy+ %lf=0\n ",real(x.n),imag(x.n),c2);
    line rval;
    if(imag(n*conj(x.n))==0) {
        if ( real(n*conj(a))!=real(n*conj(x.a)) ){
            rval.type=NONE;
            return rval;
        } else return line(a,b); 
    } else {  
        point tmp((c2*imag(n)-c1*imag(x.n))/imag(x.n*conj(n)) ,(c2*real(n)-c1*real(x.n))/imag(n*conj(x.n))  );
        rval=line(tmp,tmp);
        rval.type=POINT;
        if(x.type==SEGMENT) {
            if(real(n*conj(x.a))*real(n*conj(x.b))<0   ) rval.type=POINT; else rval.type=NONE;
        }

    }
    return rval;
}
line getSegment(edge *x) {
    line rval(x->o->u,x->n->o->u);
    rval.type=SEGMENT;
    return rval;
}
vector<line> vl;
vector<vertex*> vertices;
vector<face*>faces;
vector<edge*> edges;
void printEdges() {
    printf("Printing edges\n");
    REP(i,edges.size()) edges[i]->id=i;


  REP(i,edges.size()) {

      printf("%d %p: n=%d p=%d t=%d [%.2lf %.2lf] %p\n",i,edges[i],edges[i]->n->id,edges[i]->p->id,edges[i]->t->id   , real(edges[i]->o->u) , imag(edges[i]->o->u),edges[i]->f);
  }
}
vertex* SplitEdge(edge *e,point y) {
//    printEdges();
    printf("splitting %d",e->id);
    vertex *tmp=new vertex();
    vertices.push_back(tmp);
    tmp=vertices[vertices.size()-1];

    edge *e1,*e2;
    edges.push_back(new edge());
    e1=edges[edges.size()-1];
    edges.push_back(new  edge()  );
    e2=edges[edges.size()-1];

    e1->n=e->n;
    e1->n->p=e1;
    e1->p=e;

    e2->n=e->t->n;
    e2->n->p=e2;
    e2->p=e->t;

    e1->f=e->f;
    e2->f=e->t->f;

    e1->t=e->t;
    e2->t=e;
    e1->t->t=e1;
    e->t=e2;

    e1->o=tmp;
    e2->o=tmp;
    e1->p->n=e1;
    e2->p->n=e2;


    tmp->e=e1;
    tmp->u=y;
  //  printEdges();
    return tmp;
}
int main() {
    int n;
    scanf("%d",&n);
    REP(i,n) {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        vl.push_back(line(point(a,b),point(c,d) ) );
    }
    double x1,y1,x2,y2;
    int nemam=1;
    REP(i,n) REP(j,i)  {
        line inter=vl[i].getIntersection(vl[j]);
        if(inter.type!=POINT) continue;
        double x=real(inter.a);
        double y=imag(inter.a);
        printf("line intersection %d %d = %lf %lf\n",i,j,x,y);
        if(nemam){
            x1=x2=real(inter.a);
            y1=y2=imag(inter.a);
            nemam=0;
        } else {
            if(x<x1) x1=x;
            if(x>x2) x2=x;
            if(y<y1) y1=y;
            if(y>y2) y2=y;
        }
    }
    x1-=1;
    x2+=1;
    y1-=1;
    y2+=1;

    //now create starting doble connected edge list
    //first create vertices
    point tmp[4]={point(x2,y2),point(x1,y2),point(x1,y1),point(x2,y1)};
    REP(i,4) {
        vertex *v=new vertex();
        v->u=tmp[i];
        vertices.push_back(v);
    }
    //now faces
    faces.push_back(new face());
    faces.push_back(new face());
    faces[0]->id=0;
    faces[1]->id=1;
    //now edges
    //first counterclockwise
    REP(i,4) {
        edge *ted = new edge();
        ted->o=vertices[i];
        ted->f=faces[1];
        edges.push_back(ted);
    }
    REP(i,4) {
        edge *ted  = new edge();
        ted->o=vertices[(i+1)%4];
        ted->f=faces[0];
        edges.push_back(ted);
    }
    //now twin next previous
    REP(i,4) {
        edges[i]->n=edges[(i+1)%4];
        edges[i]->p=edges[(i+3)%4];
        edges[i]->t=edges[i+4];
    }
    printf("DBG:%p %p\n",edges[0]->n,edges[1]);
    REP(i,4)  {
        edges[i+4]->n=edges[i]->p->t;
        edges[i+4]->p=edges[i]->n->t;
        edges[i+4]->t=edges[i];
    }
    faces[0]->e=edges[4];
    faces[1]->e=edges[0];
    // now walkaround the
    printf("x1=%lf y1=%lf x2=%lf y2=%lf\n",x1,y1,x2,y2);
    REP(i,vl.size()) {
        printf(" LLLLLLLLLLLLLLLLLLLLLL %d\n",i);
        edge *start=edges[4];
        edge *ptr;
        ptr=start;
        edge *lastEdge=0,*curEdge=0;
        vertex *lastPoint=0,*curPoint=0;

        while(1){
            if(lastEdge && lastEdge->f==faces[0]) {
                printf("Breaking \n");
                break;
            }
            else printf("not Breaking \n");
                    printf("ptr edge set to %p\n",ptr);
            while(1) {

                if(real(vl[i].n*conj(ptr->o->u) )==0 ) {
                    if(lastPoint ==0) {
                        printf("Found first point [%lf %lf] %p\n",real(ptr->o->u),imag(ptr->o->u),ptr->t);
                        lastPoint = ptr->o;
                        lastEdge=ptr->t;
                        ptr=lastEdge->n->n;
                        continue;
                    } else{
                        printf("Found cur point [%lf %lf] %p\n",real(ptr->o->u),imag(ptr->o->u),ptr->p);
                        curPoint = ptr->o;
                        curEdge = ptr->p;
                    }
                }else {
                    line tmp=vl[i].getIntersection(getSegment(ptr) );
                    if(tmp.type==POINT) {
                        if(lastPoint==0) {
                            lastPoint=SplitEdge(ptr,tmp.a);
                            lastEdge=ptr->n->t;
                            printf("Found first point on edge [%lf %lf] %p\n",real(tmp.a),imag(tmp.a),ptr->n->t);
                            ptr=lastEdge->n->n;
                            continue;

                        } else {
                            curPoint=SplitEdge(ptr,tmp.a);
                            curEdge=ptr;
                            printf("Found cur point on edge [%lf %lf] %p\n",real(tmp.a),imag(tmp.a),ptr);
                        }
                    }
                }
                if(curPoint) {
                    //solve fucking problem;
                    //create left right ,right leftedge
                    printf("cur edge %p\n",curEdge);
                    printf("last edge %p\n",lastEdge);
                    printf("cur point %lf %lf\n",real(curPoint->u),imag(curPoint->u));
                    printf("last point %lf %lf\n",real(lastPoint->u),imag(lastPoint->u));

                    printEdges();
                    edge *e1,*e2;
                    edges.push_back(new edge());
                    e1=edges[edges.size()-1];
                    edges.push_back(new edge());
                    e2=edges[edges.size()-1];
                    e1->o=lastPoint;
                    e2->o=curPoint;
                    e1->n=curEdge->n;
                    e1->p=lastEdge;

                    e2->n=lastEdge->n;
                    e2->p=curEdge;

                    e1->t=e2;
                    e2->t=e1;
                    lastEdge->n->p=e2;
                    lastEdge->n=e1;

                    curEdge->n->p=e1;
                    curEdge->n=e2;

                    e2->f=e2->n->f;
                    e2->f->e=e2;


                    //create new face
                    face *f;
                    faces.push_back(new face());

                    f=faces[faces.size()-1];
                    f->id = faces.size()-1;
                    edge *x=e1;
                    while(1) {
                        x->f=f;
                        x=x->n;
                        if(x==e1) break;
                    }
                    printEdges();
                    lastEdge=curEdge->t->p;
                    printf("last edge set to %p\n",lastEdge);
                    lastPoint = curPoint;
                    curPoint=0;
                    ptr=lastEdge->n->n;
                    printf("ptr edge set to %p\n",ptr);
                    break;
                }

                ptr=ptr->n;
                    printf("ptr edge set to %p\n",ptr);
            }
        }
printf("aa %d\n",faces.size() );
    }
printf("%d\n",faces.size() );
}


//(a+bi) *(i)=ai-b

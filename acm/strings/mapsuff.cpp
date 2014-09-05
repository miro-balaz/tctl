#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<map>
using namespace std;
#define INFTY 1000000
char p[500003];
struct node {
	struct node *backlink;		/* We use them only for internal nodes */
	char *label;			/* Label of edge above this node */
	int lablen;
        map<char,node*> ch;

};
char * split;
int result=0;
int solvetree(node *n,int depth) {
    int res=0;

    for(map<char,node*>::iterator it=n->ch.begin();it!=n->ch.end();++it) {
     node *m   =it->second;
        if(m->lablen>=INFTY/2) {
            if(m->label>split) res|=2;
            else res|=1;
        } else {
            res|=solvetree(m,depth+m->lablen);
        }
    }
    if(res==3 && depth>=result) result=depth;
//  delete n;
    return res;
}
static struct node *build_tree(char *string)
{
	struct node *root = new node();
        root->lablen=0;
        
	struct node *l = root;		/* Currently longest nested suffix as a canonical reference pair (node, label) */
	char *llabel = string;
	int llablen = 0;
	struct node *x, *y, *z, *trash, **blp;
        map<char,node*>::iterator xit;
	for (int i=0; string[i]; i++) {
		blp = &trash;
		for(;;) {
			while (llablen) {				/* Canonicalize the reference pair */
			//	x = l->ch[llabel[0]];
                                xit=l->ch.find(llabel[0]);
                                x=xit->second;
				if (x->lablen > llablen)
					break;
				l = x;
				llabel += x->lablen;
				llablen -= x->lablen;
			}
			if (!llablen) {					/* LNS is an internal node or root */
				*blp = l;
				blp = &trash;
				if (l->ch[string[i]] ) {		/* Found LNS for the new string */
					llabel = string+i;
					llablen = 1;
					break;
				}
				z = new node();
                                l->ch[string[i]]=z;
			} else {					/* LNS is in the middle of an edge */
				//x = l->ch[llabel[0]];
                                if (x->label[llablen] == string[i]) {		/* found LNS for the new string */
					llablen++;
					break;
				}
				y = new node();				/* New interior node which will be parent of x */
				z = new node();				/* New leaf connected below y */

                                y->label=x->label;
                                y->lablen=llablen;

                                x->label+=llablen;
                                x->lablen-=llablen;
                                *blp=y;
                                blp=&y->backlink;
                                y->ch[string[i]]=z;
                                y->ch[x->label[0]]=x;
                                //l->ch[y->label[0]]=y;
                                xit->second=y;
			}
			z->label = string+i;
			z->lablen = INFTY;
			if (l == root) {				/* Cut the first character of the LNS */
				if (!llablen)
					break;
				llabel++;
				llablen--;
			} else {
				l = l->backlink;
                        }
		}
		*blp = root;
	}
	return root;
}

int main()
{
        scanf("%s",p);
        int a=strlen(p);
        split=a+p;
        p[a]='A';
        scanf("%s",p+a+1);
        int b=strlen(p+a);
        a+=b;
        p[a]='B';
        p[a+1]=0;
	struct node *root = build_tree(p);
      //  solvetree(root,0);
        printf("%d\n",result);
	return 0;
}

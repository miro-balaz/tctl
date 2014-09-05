#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFTY 1000000
char p[500003];
struct node {
	struct node *first_son;
	struct node *next_sibling;
	struct node *backlink;		/* We use them only for internal nodes */
	char *label;			/* Label of edge above this node */
	int lablen;
};
char * split;
int result=0;
static void dump_tree(struct node *n, int level, char *strend)
{
    if(level>5) return;
	for (int i=0; i<level; i++)
		putchar('.');
	printf("<%.*s%s> [%p] {%p}\n",
		(n->lablen >= INFTY/2 ?  /*strend-n->label*/6 : n->lablen), n->label,
		(n->lablen >= INFTY/2 ? "*" : ""), n, n->backlink);
	for (n=n->first_son; n; n=n->next_sibling)
		dump_tree(n, level+1, strend);
}
int solvetree(node *n,int depth) {
    int res=0;
    for(n=n->first_son;n;n=n->next_sibling) {
        if(n->lablen>=INFTY/2) {
            if(n->label>split) res|=2;
            else res|=1;
        } else {
            res|=solvetree(n,depth+n->lablen);
        }
    }
    if(res==3 && depth>=result) result=depth;
    return res;
}
void destroytree(node *n) {
    for(n=n->first_son;n;n=n->next_sibling) {
       destroytree(n);
    }
    delete n;
}

static struct node *new_node(void)
{
//	struct node *n = (node*)malloc(sizeof(*n));
	struct node *n = new node();
	bzero(n, sizeof(*n));
	return n;
}
node *last_lookup;
node *root;
static struct node *lookup_edge(struct node *x, int c)
{

    //x=x->first_son;
    //while(x && x->label[0]!=c) x=x->next_sibling;
    //return x;
	x = x->first_son;
        if(!x) return NULL;
        if(x->label[0]==c) return x;

	while (x->next_sibling && x->next_sibling->label[0] != c)
		x = x->next_sibling;
        
        last_lookup=x;
	return x->next_sibling;
}

static struct node *build_tree(char *string)
{
	root = new_node();
	struct node *l = root;		/* Currently longest nested suffix as a canonical reference pair (node, label) */
	char *llabel = string;
	int llablen = 0;
	struct node *x, *y, *z, *trash, **blp;
	for (int i=0; string[i]; i++) {
		blp = &trash;
		for(;;) {
			while (llablen) {				/* Canonicalize the reference pair */
				x = lookup_edge(l, llabel[0]);

				if (x->lablen > llablen)
					break;
				l = x;
				llabel += x->lablen;
				llablen -= x->lablen;
			}
			if (!llablen) {					/* LNS is an internal node or root */
				*blp = l;
				blp = &trash;
				if (lookup_edge(l, string[i])) {		/* Found LNS for the new string */
					llabel = string+i;
					llablen = 1;
					break;
				}
				z = new_node();
				z->next_sibling = l->first_son;
				l->first_son = z;
			} else {					/* LNS is in the middle of an edge */
//				x = lookup_edge(l, llabel[0]);
				if (x->label[llablen] == string[i]) {		/* found LNS for the new string */
					llablen++;
					break;
				}
				y = new_node();				/* New interior node which gets all sons of x */
				z = new_node();				/* New leaf connected below x */
                                y->first_son=z;
                                z->next_sibling=x;
                                y->next_sibling=x->next_sibling;
                                x->next_sibling=NULL;
                                if(l->first_son==x) {
                                    l->first_son=y;
                                } else {
//                                    node *tmp=l->first_son;
 //                                   while(1) {
  //                                      if(tmp->next_sibling==x) {
   //                                         tmp->next_sibling=y;
    //                                         break;
     //                                   }
      //                                  tmp=tmp->next_sibling;
                                 //   }
                                last_lookup->next_sibling=y;
                                }
                                y->label=x->label;
                                y->lablen=llablen;
                                x->label+=llablen;
                                x->lablen-=llablen;
                                *blp=y;
                                y->backlink=NULL;
                                blp=&y->backlink;


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
        a=strlen(p);
        p[a]='B';
        
	struct node *root = build_tree(p);
        solvetree(root,0);
        
        printf("%d\n",result);
        destroytree(root);
	return 0;
}

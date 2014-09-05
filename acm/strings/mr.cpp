#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFTY 1000000
char p[100000];
struct node {
	struct node *first_son;
	struct node *next_sibling;
	struct node *backlink;		/* We use them only for internal nodes */
        node *son_of;
	char *label;			/* Label of edge above this node */
	int lablen;
};
int solvetree(node *n,char *strend) {
    int res=(n->lablen >= INFTY/2 ? strend-n->label : n->lablen);
    for(n=n->first_son;n;n=n->next_sibling) {
        res+=solvetree(n,strend);
    }
    return res;
}
static struct node *lookup_edge(struct node *x, int c)
{
	x = x->first_son;

	while (x && x->label[0] != c)
		x = x->next_sibling;
	return x;
}

static struct node *build_tree(char *string)
{
	struct node *root = new node();
        root->lablen=0;
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
				z = new node();
				z->next_sibling = l->first_son;
				l->first_son = z;
			} else {					/* LNS is in the middle of an edge */
				x = lookup_edge(l, llabel[0]);
				if (x->label[llablen] == string[i]) {		/* found LNS for the new string */
					llablen++;
					break;
				}
				y = new node();				/* New interior node which gets all sons of x */
				z = new node();				/* New leaf connected below x */
                                y->first_son=z;
                                z->next_sibling=x;
                                y->next_sibling=x->next_sibling;
                                x->next_sibling=NULL;

                                if(l->first_son==x) {
                                    l->first_son=y;
                                } else {
                                    node *tmp=l->first_son;
                                    while(1) {
                                        if(tmp->next_sibling==x) {
                                            tmp->next_sibling=y;
                                             break;
                                        }
                                        tmp=tmp->next_sibling;
                                    }
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
    int t;
	scanf("%d",&t);
        for(int i=0;i<t;++i) {
        scanf("%s",p);
        
	struct node *root = build_tree(p);
        
           printf("%d\n",solvetree(root,p+strlen(p)));
           destroytree(root);
        }
	return 0;
}

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
int solvetree(node *n,char *strend) {
    int res=(n->lablen >= INFTY/2 ? strend-n->label : n->lablen);
    for(n=n->first_son;n;n=n->next_sibling) {
        res+=solvetree(n,strend);
    }
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

static struct node *lookup_edge(struct node *x, int c)
{
	x = x->first_son;

	while (x && x->label[0] != c)
		x = x->next_sibling;
	return x;
}
int ptt;
char pole[50000];
void findnode(node *n,node *what,char *strend) {
    if(n==what) {
                pole[ptt]=0;
                printf("fucker hlada:\n");
                printf("%s\n",pole);
                printf("begin printing children\n");
    for(n=n->first_son;n;n=n->next_sibling) {
        printf("%c\n",n->label[0]);
    }
                printf("end printing children\n");

        return;
    }
    for(n=n->first_son;n;n=n->next_sibling) {
        int k=n->lablen;
        if(k>=INFTY/2) k=strend-n->label;

        for(int i=0;i<k;++i) pole[ptt++]=n->label[i];
       findnode(n,what,strend);
       ptt-=k;
    }
}
int findTree(node *n, char *search,int searchlen  ) {
    int i=0;
    int res=1;
    while(i<searchlen) {
        n=lookup_edge(n,search[i]);
        if(!n) return 0;
        for(int j=0;j<n->lablen;++j) {
            if(n->label[j]==0) return 0;
            if(n->label[j]!= search[i]) res=0;
            ++i;
            if(i==searchlen) return res;
        }
    }
    return res;
}

static struct node *build_tree(char *string)
{
	struct node *root = new_node();
	struct node *l = root;		/* Currently longest nested suffix as a canonical reference pair (node, label) */
	char *llabel = string;
	int llablen = 0;
	struct node *x, *y, *z, *trash, **blp;
	for (int i=0; string[i]; i++) {
            int dbg=0;
 //           printf("dumping tree %d %p\n",i,l);
//            dump_tree(root, 0, string+i);
//            printf("A %p %d\n",root,i);
		blp = &trash;
		for(;;) {
                    dbg++;
			while (llablen) {				/* Canonicalize the reference pair */
                    if(i==-1) {
                        printf("the label:");
                        for(int k=0;k<llablen;++k) printf("%c",llabel[k]);
                        printf("\n");
                        printf("dbg=%d %p este chcem %d %c\n",dbg,l,llablen,llabel[0]);
                findnode(root,l,string+strlen(string));
                    }
				x = lookup_edge(l, llabel[0]);

                               // if(!x) exit(0);
				if (x->lablen > llablen)
					break;
				l = x;
                                if(!l) printf("KURVA 2\n");
				llabel += x->lablen;
				llablen -= x->lablen;
			}
			if (!llablen) {					/* LNS is an internal node or root */
//                              printf("writing suffix link %p <-%p \n",blp,l);
				*blp = l;
				blp = &trash;
                           //     printf("1setting bpl to trash\n");
				if (lookup_edge(l, string[i])) {		/* Found LNS for the new string */
					llabel = string+i;
					llablen = 1;
                                      //  l=lookup_edge(l,string[i]);
                                    //llablen++;
					break;
				}
				z = new_node();
				z->next_sibling = l->first_son;
				l->first_son = z;
			} else {					/* LNS is in the middle of an edge */
				x = lookup_edge(l, llabel[0]);
				if (x->label[llablen] == string[i]) {		/* found LNS for the new string */
					llablen++;
					break;
				}
				y = new_node();				/* New interior node which gets all sons of x */
				z = new_node();				/* New leaf connected below x */
				/*
                                y->first_son = x->first_son;
				y->next_sibling = NULL;
				y->label = x->label + llablen;
				y->lablen = x->lablen - llablen;
				x->first_son = z;
				*blp = x;
				y->backlink = x->backlink;
				x->backlink = NULL;
				blp = &x->backlink;// Backlink will be filled in later 
				x->lablen = llablen;
				z->next_sibling = y;
                                */
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
                            if(i==-1) {
                                printf("NOW see suffixlinks\n");
                                findnode(root,l,string+strlen(string));

                                findnode(root,l->backlink,string+strlen(string));
                                //dump_tree(root, 0, string+i);
                            }
				l = l->backlink;
                                if(!l) printf("KURVA 1\n");
                        }
		}
               // printf("Dwriting suffix link %p <-%p \n",blp,root);
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
//        if(i==273) {
    //    printf("%s\n",p);
        
	struct node *root = build_tree(p);
        
       printf("%d\n",solvetree(root,p+strlen(p)));
        destroytree(root);
  //      }
//	puts("Result:");
//	dump_tree(root, 0, string+strlen(string));
        }
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
    char info[16];          
    struct node* lp;        
    struct node* rp;        
} node;

typedef struct 
{
    node* lp;               
} Tree;

// init
void initTree(Tree* t) 
{
    t->lp = NULL;
}

// check tree is empty
int emptyTree(Tree t) 
{
    return t.lp == NULL;
}

// create a new note
node* createNode(const char* label) 
{
    node* p = (node*)malloc(sizeof(node));
    if (!p) return NULL;
    strncpy(p->info, label, sizeof(p->info) - 1);
    p->info[sizeof(p->info) - 1] = '\0';
    p->lp = p->rp = NULL;
    return p;
}

int insertRoot(Tree* t, const char* label) 
{
    if (t->lp != NULL) return 0;             
    t->lp = createNode(label);
    return t->lp != NULL;
}

int insertLeft(node* parent, const char* label) 
{
    if (!parent) return 0;
    if (parent->lp != NULL) return 0;         
    parent->lp = createNode(label);
    return parent->lp != NULL;
}

int insertRight(node* parent, const char* label) 
{
    if (!parent) return 0;
    if (parent->rp != NULL) return 0;         
    parent->rp = createNode(label);
    return parent->rp != NULL;
}

// NLR
void preorder(node* p) 
{ 
    if (!p) return;
    printf("%s ", p->info);
    Preorder(p->lp);
    Preorder(p->rp);
}

// LNR 
void inorder(node* p) 
{ 
    if (!p) return;
    inorder(p->lp);
    printf("%s ", p->info);
    inorder(p->rp);
}

// LRN
void postorder(node* p) 
{ 
    if (!p) return;
    postorder(p->lp);
    postorder(p->rp);
    printf("%s ", p->info);
}

void destroy(node** p)
{
    if (!p || !*p) return;
    destroy(&(*p)->lp);
    destroy(&(*p)->rp);
    free(*p);
    *p = NULL;
}

int main() {
    Tree t;
    initTree(&t);  

    if (emptyTree(t)) 
    {
        printf("Cay dang rong.\n");
    }

    insertRoot(&t, "A");

    node* p = t.lp;

    insertLeft(p, "A.1");
    insertRight(p, "A.2");

    insertLeft(p->lp, "A.1.1");
    insertRight(p->lp, "A.1.2");

    insertLeft(p->rp, "A.2.1");
    insertRight(p->rp, "A.2.2");

    printf("Duyet truoc (NLR): ");
    Preorder(t.lp);
    printf("\n");

    printf("Duyet giua (LNR): ");
    inorder(t.lp);
    printf("\n");

    printf("Duyet sau (LRN): ");
    postorder(t.lp);
    printf("\n");

    destroy(&t.lp);
    return 0;
}

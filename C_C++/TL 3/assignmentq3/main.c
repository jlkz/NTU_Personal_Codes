#include <stdio.h>
#include <stdlib.h>

#define MAX_N 120

typedef struct _btnode{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode** node, char* preO, char* postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s",preO);
    scanf("%s",postO);

    BTNode* root=NULL;
    buildTree(&root,preO,postO);
    if(root==NULL) printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    return 0;
}
void inOrder(BTNode *cur){
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c",cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur){
    if (cur == NULL)
        return;

    printf("%c",cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur){
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c",cur->id);
}

struct _btnode * recurr(char* preO, char* postO, int start, int end, int *num, int sizee)
{
    int i;
    if(*num >= sizee || start>end)
    {
        return NULL;
    }

    BTNode *node = malloc(sizeof(BTNode));
    (node)->id = preO[*num];
    (node)->left = NULL;
    (node)->right = NULL;
    (*num)++;
    //printf("%d", *num);

    if(start == end)
    {
        return node;
    }
    for (i = start; i <= end; i++)
    {
        if (preO[*num] == *(postO+i))
            break;
    }
    //printf("nn %d\n", i);

    if(i <= end)
    {

        (node)->left = recurr(preO, postO, start, i, num, sizee);
        //printf("g\n");
        (node)->right = recurr(preO, postO, i+1, end-1, num, sizee);
    }

    return node;
}


void buildTree(BTNode** node, char* preO, char* postO)
{
    int start=0, end, j=0;
    int num =0, sizee;
    /*int i;
    if(start == 0)
    {
        while(*(postO+i) != '\0')
        {
            i++;
        }
        end = i-1;
    }
    if((*preO) =='\0' || start>end)
    {
        return;
    }
    //printf("%c\n", *preO);
    BTNode* temp=NULL;
    BTNode* l=NULL;
    BTNode* r=NULL;
    BTNode* p = NULL;
    *node = malloc(sizeof(BTNode));
    (*node)->id = *preO;
    (*node)->left = NULL;
    (*node)->right = NULL;
    preO++;

    if(start == end)
    {
        return;
    }
    for (i = start; i <= end; i++)
    {
        if (*preO == *(postO+i))
            break;
    }
    printf("NUm %d\n", i);

    if(i<= end)
    {
        end = i;
        printf("%c\n", *preO);
        buildTree(&((*node)->left), preO, postO);
        start = i+1;
        end = end-1;
        printf("right %c\n", *preO);
        buildTree(&((*node)->right), preO, postO);
    }*/

    while(*(postO+j) != '\0')
    {
            j++;
    }
    end = j-1;
    sizee = j;
    *node = recurr(preO, postO, start, end, &num, sizee);
    /*
    for(i=0; i<end; i++)
    {
        if(*preO == *(postO+i))
            break;
    }
    left = i;
    right = end-1;
    (*node)->left = malloc(sizeof(BTNode));
    (*node)->left->id = *preO;
    (*node)->left->left = NULL;
    (*node)->left->right = NULL;
    l = (*node)->left;
    if(end<=1)
    {
        return;
    }
    (*node)->right = malloc(sizeof(BTNode));
    (*node)->right->id = *(postO+right);
    (*node)->right->left = NULL;
    (*node)->right->right = NULL;
    r = (*node)->right;
    preO++;
    prev = left;
    for(i=0; i<left; i++)
    {
        for(cur=0; cur<left; cur++)
        {
            if(*(preO) == postO[cur])
                break;
        }
        p = l;
        if(cur<prev)
        {
            temp = l;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            temp->left = malloc(sizeof(BTNode));
            temp->left->id = *preO;
            temp->left->left = NULL;
            temp->left->right = NULL;
            while(p->left != temp && p!=temp)
            {
                p = p->left;
            }
        }
        else if(cur>prev)
        {
            temp->right = malloc(sizeof(BTNode));
            temp->right->id = *preO;
            temp->right->left = NULL;
            temp->right->right = NULL;
            temp = p;
        }
        prev = cur;
        preO++;
    }
    //right
    prev = right;
    preO++;
    for(i=left+1; i<right; i++)
    {
        for(cur=left; cur<right; cur++)
        {
            if(*(preO) == postO[cur])
                break;
        }
        p = r;
        if(cur<prev)
        {
            temp = r;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            temp->left = malloc(sizeof(BTNode));
            temp->left->id = *preO;
            temp->left->left = NULL;
            temp->left->right = NULL;
            while(p->left != temp && p!=temp)
            {
                p = p->left;
            }
        }
        else if(cur>prev)
        {
            temp->right = malloc(sizeof(BTNode));
            temp->right->id = *preO;
            temp->right->left = NULL;
            temp->right->right = NULL;
            temp = p;
        }
        prev = cur;
        preO++;
    }*/




}

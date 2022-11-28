#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void insertBSTNode(BTNode** cur, int item);
void printBTNode(BTNode *root, int space, int left);
void deleteTree(BTNode **root);

int main()
{
    BTNode* root = NULL;
    int item;

    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        insertBSTNode(&root, item);
    scanf("%*s");

    printf("The Binary Search Tree:\n");
    printBTNode(root,0,0);

    deleteTree(&root);
    root=NULL;
    return 0;
}

void printBTNode(BTNode *root,int space,int left){
      if (root != NULL)
      {

          int i;
          for (i = 0; i < space-1; i++)
                 printf("|\t");


          if(i<space){
            if(left==1)
              printf("|---");
            else
              printf("|___");
          }

          printf("%d\n", root->item);

          space++;
          printBTNode(root->left, space,1);
          printBTNode(root->right, space,0);
      }
}

void deleteTree(BTNode **root){
    if (*root != NULL)
	{
		deleteTree(&((*root)->left));
		deleteTree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

void insertBSTNode(BTNode** cur, int item)
{
    int x = 0;
    BTNode *mov = *cur;
    BTNode *temp = (BTNode*)malloc(sizeof(BTNode));
    temp->item = item;
    temp ->left = temp->right = NULL;
    if(mov == NULL)
    {
        mov = temp;
        *cur = mov;
        return;
    }
    while(mov != NULL)
    {
        if(temp->item < (mov)->item)
        {
            if(mov->left == NULL)
            {
                x = 1;
                break;
            }
            mov = (mov)->left;
        }
        else if(temp->item > (mov)->item)
        {
            if((mov)->right == NULL)
            {
                x = 2;
                break;
            }
            mov = (mov)->right;
        }
        else
        {
            printf("Duplicated item: %d \n", item);
            break;
        }
    }
    if(x == 1)
    {
        (mov)->left = temp;
    }
    if(x == 2)
    {
        (mov)->right = temp;
    }
    return;
}

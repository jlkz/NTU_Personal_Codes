#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200 //The number digit limitation

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
     BTNode* item;
     struct _node *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    //printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    //printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    //printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

void push(Stack *sPtr, BTNode *item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}
void createExpTree(BTNode** root,char* prefix)
{
    int i = 0, x;
    char* num;
    Stack s;
    s. head = NULL;
    s.size = 0;
    BTNode *temp = NULL, *one, *two;
    while (prefix[i] != '\0')
    {
        i++;
    }
    i--;
    //printf("%d\n", i);
    for(i; i>=0; i--)
    {
        switch(prefix[i])
        {
            case('('):
            case(')'):
                break;
            case(' '):
                if(prefix[i+1] != ' ' && prefix[i+1] > 47)
                {
                    temp = (BTNode*)malloc(sizeof(BTNode));
                    num = prefix + i + 1;
                    temp->item = '0' + atoi(num);
                    temp->left = NULL;
                    temp->right = NULL;
                    push(&s, temp);
                }
                break;

            case('+'):
            case('/'):
            case('-'):
            case('*'):
                one = peek(s);
                pop(&s);
                two = peek(s);
                pop(&s);
                //temp = NULL;
                temp  = (BTNode*)malloc(sizeof(BTNode));
                temp->item = prefix[i];
                temp->left = one;
                temp->right = two;
                push(&s, temp);
                break;
            default:
                break;
        }

    }
    *root = peek(s);
    pop(&s);
}

void printTree(BTNode *node)
{
    if(node == NULL)
    {
        return;
    }
    printTree(node->left);
    if(node->item > '0')
    {
        printf("%d ", (node->item)-'0');
    }
    else
    {
        printf("%c ", node->item);
    }

    printTree(node->right);
}


void printTreePostfix(BTNode *node)
{
    if(node == NULL)
    {
        return;
    }
    printTreePostfix(node->left);
    printTreePostfix(node->right);
    if(node->item > '0')
    {
        printf("%d ", (node->item)-'0');
    }
    else
    {
        printf("%c ", node->item);
    }

}

double computeTree(BTNode *node)
{
    double  left, right, result;
    if(node->left == NULL && node->right == NULL)
    {
        return (node->item) - '0';
    }
    left = computeTree(node->left);
    right = computeTree(node->right);

    if(node->item == '+')
    {
        result = left + right;
    }
    if(node->item == '/')
    {
        result = left / right;
    }
    if(node->item == '-')
    {
        result = left - right;
    }
    if(node->item == '*')
    {
        result = left * right;
    }
    //printf("%lf\n", result);
    return result;

}


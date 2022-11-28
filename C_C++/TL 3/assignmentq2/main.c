#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int nodeV;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _queuenode{
    BTNode* node;
    struct _queuenode *next;
}QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

void printBTNode(BTNode *root, int space,int left);
//Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, BTNode * node);
int dequeue(Queue *qPtr);
BTNode* getFront(Queue q);
int isEmptyQueue(Queue q);

int twoNodesCost(BTNode* node, int nodeV1,int nodeV2);

int main()
{
    BTNode* root = (BTNode*) malloc(sizeof(BTNode));

    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    BTNode* node;
    enqueue(&q,root);

    int nodeV;
    char opL, opR;

    while(!isEmptyQueue(q)){
            scanf("%d %c %c",&nodeV,&opL,&opR);
            node = getFront(q);dequeue(&q);
            node->nodeV = nodeV;

            if(opL != '@'){
                node->left = (BTNode*) malloc(sizeof(BTNode));
                enqueue(&q,node->left);
            }
            else node->left =NULL;
            if(opR != '@'){
                node->right = (BTNode*) malloc(sizeof(BTNode));
                enqueue(&q,node->right);
            }
            else
                node->right = NULL;
    }

    int v1,v2;
    scanf("%d %d",&v1,&v2);
    int cost = twoNodesCost(root,v1,v2);

    printBTNode(root,0,0);

    printf("Distance is %d\n",cost);
    return 0;
}

void enqueue(Queue *qPtr, BTNode *node){
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr){
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return 1;
    }
}

BTNode* getFront(Queue q){
    return q.head->node;
}

int isEmptyQueue(Queue q){
    if(q.size==0) return 1;
    else return 0;
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

          printf("%d\n", root->nodeV);

          space++;
          printBTNode(root->left, space,1);
          printBTNode(root->right, space,0);
      }
}

int find(BTNode* node, int num, char *p)
{
    int result;
    if(node == NULL)
    {
        return 0;
    }
    *p = node->nodeV;
    p++;
    if(node->nodeV == num)
    {
        return 1;
    }
    result = find(node->left, num, p);
    if(result == 1)
    {
        return 1;
    }
    result = find(node->right, num, p);
    if(result == 1)
    {
        return 1;
    }
    else
    {
        p--;
        *p = '\0';
        return 0;
    }
}
int twoNodesCost(BTNode* node, int nodeV1,int nodeV2)
{
    char onee[20];
    char two[20];
    char* p1 = onee;
    char* p2 = two;
    int x = 0, i=0, end = 0, res1 = 0, res2 = 0, nn;
    for(nn =0; nn<20; nn++)
    {
        onee[nn] = '\0';
        two[nn] = '\0';
    }
    find(node, nodeV1, p1);
    find(node, nodeV2, p2);
    while(two[x] != '\0')
    {
        //printf("%d %d\n", x, two[x]);
        x++;
    }
    x = x-1;
    while(onee[i] != '\0')
    {
        //printf("%d %d\n", i, onee[i]);
        i++;
    }
    i = i-1;
    res1 = i;
    //printf("hahha %d\n", x);
    for(x; x>=0; x--)
    {
        i = res1;
        for(i; i>=0; i--)
        {
            //printf("%d, %d\n",x, i);
            if(onee[i] == two[x])
            {
                end = 1;
                break;
            }
        }
        if(end == 1)
        {
            break;
        }
    }
    /*if(i == 0 || x == -1)
    {
        return 0;
    }*/
    res1 = 0 - two[x];
    //printf("%d\n", res1);
    //printf(" ");
    while(onee[i] != '\0')
    {
        res1 = res1 + onee[i];
        //printf("%d\n", res1);
        i++;

    }
    while(two[x] != '\0')
    {
        res2 += two[x];
        //printf("%d\n", res2);
        x++;
    }

    res1 = res1 + res2;

    return res1;


}

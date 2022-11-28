#include <stdio.h>
#include <stdlib.h>
int i = 0;
int x = 2;
int k;
char trash;
typedef struct node
{
    int item;
    struct node *next;
}ListNode;
typedef struct linkedlist
{
    ListNode* head;
    int size;
}LinkedList;

void printList2(LinkedList LL);
void printList(ListNode *cur);
int insertNode(ListNode **ptrHead, int i, int item);
int removeNode(ListNode ** ptrHead, int index);
int removeNode2(LinkedList *xd, int index);
int split(ListNode *cur, ListNode **ptrEvenList, ListNode **ptrOddList);
int duplicateReverse(ListNode* cur, ListNode** ptrNewHead);
ListNode* findNode(ListNode* cur, int i);
int main()
{
    ListNode* temp;
    ListNode* dynamic_node = malloc(sizeof(ListNode));
    dynamic_node -> next = NULL;
    dynamic_node -> item = 50;
    ListNode* head = dynamic_node;
    ListNode** headd = &head;
    temp = head;

    //Odd
    ListNode* tempo;
    ListNode* oddNode = malloc(sizeof(ListNode));
    oddNode -> next = NULL;
    oddNode -> item = 50;
    ListNode* heado= oddNode;
    ListNode** headdo = &heado;
    tempo = heado;

    //Even
    ListNode* tempe;
    ListNode* evenNode = malloc(sizeof(ListNode));
    evenNode -> next = NULL;
    evenNode -> item = 50;
    ListNode* heade = evenNode;
    ListNode** headde = &heade;
    tempe = heade;

    LinkedList LL;
    LL.head = head;
    LL.size = 0;
    LinkedList* xd = &LL;

    while (scanf("%d", &i))
    {
        temp->item = i;
        temp->next = (ListNode*)malloc(sizeof (ListNode));
        temp = temp->next;
        LL.size++;
    }
    temp-> next = NULL;
    printList2(LL);
    printf("%d\n", LL.size);
    /*printf("Found: %d\n", findNode(head, x)->item);
    insertNode(headd, 1, 60);
    printList(LL);
    printf("%d", LL.size); */
    /*printf("Node to be removed: \n");
    scanf("%c", &trash);
    scanf("%d", &x);
    k = removeNode2(xd, x);
    if (k==0)
    {
        printf("The node cannot be removed\n");
    }
    else if (k==1)
    {
        printf("After the removal operation, \n");
    }
    printf("Current list has %d elements:", LL.size);
    printList2(LL);
    printf("\n");
    printf("%d\n", split(head, headde, headdo));
    printList(tempe);
    printList(tempo);*/
    printList(head);
    duplicateReverse(head, headde);
    printf("g\n");
    printList(heade);
    free(dynamic_node);
    return 0;
}

void printList(ListNode *cur)
{
    while(cur->next != NULL)
    {
        printf("%d\n", cur->item);
        cur = cur->next;
    }
}
void printList2(LinkedList LL)
{
    while (LL.head->next != NULL)
    {
        printf("%d -> ", LL.head->item);
        LL.head = LL.head->next;
    }
    printf("\n");
}

int insertNode(ListNode **ptrHead, int i, int item)
{
    ListNode *newNode, *pre;
    if (i==0)
    {
        newNode = (ListNode*) malloc(sizeof (ListNode));
        newNode->item = item;
        newNode->next = *ptrHead;
        *ptrHead = newNode;
        return 1;
    }
    else if ((pre = findNode(*ptrHead, i-1)) != NULL)
    {
          newNode = malloc(sizeof(ListNode));
          newNode->item = item;
          newNode->next = pre->next;
          pre->next = newNode;
          return 1;
    }
    return 0;
}

ListNode* findNode(ListNode* cur, int i)
{
    if (cur == NULL || i<0)
        return NULL;
    while(i>0)
    {
        cur = cur->next;
        if(cur == NULL)
        {
            return NULL;
        }
        i--;
    }
    return cur;
}

int removeNode(ListNode ** ptrHead, int index)
{
    ListNode *cur, *pre;
    if(index==0)
    {
        *ptrHead = (*ptrHead)->next;
        return 1;
    }
    else if ((pre = findNode(*ptrHead, index-1)) != NULL && (cur = findNode(*ptrHead, index)) != NULL )
    {
        pre->next = cur->next;
        cur->next = NULL;
        return 1;
    }
    return 0;
}

int removeNode2(LinkedList *xd, int index)
{

    ListNode *cur, *pre;
    if(index==0)
    {
        *(xd->head) = *(xd->head)->next;
        (xd->size)--;
        return 1;
    }
    else if ((pre = findNode(xd->head, index-1)) != NULL && (cur = findNode(xd->head, index)) != NULL )
    {
        pre->next = cur->next;
        cur->next = NULL;
        (xd->size)--;
        return 1;
    }
    return 0;
}

int split(ListNode *cur, ListNode **ptrEvenList, ListNode **ptrOddList)
{
    int i=0;
    while(cur != NULL)
    {
        if (i%2 == 0)
        {
            (*ptrEvenList)->item = cur->item;
            (*ptrEvenList)->next = (ListNode*)malloc(sizeof (ListNode));

        }
        else if (i%2 == 1)
        {
            (*ptrOddList)->item = cur->item;
            (*ptrOddList)->next = (ListNode*)malloc(sizeof (ListNode));
        }
        if(cur->next != NULL )
        {
            cur = cur->next;
            if(i%2==0)
            {
                (*ptrEvenList) = (*ptrEvenList)->next;
            }
            else
            {
                (*ptrOddList) = (*ptrOddList)->next;
            }
            i++;
        }
        else if(cur->next == NULL)
        {
            cur = cur->next;
            continue;
        }

    }
    (*ptrOddList)->next = NULL;
    (*ptrEvenList)->next = NULL;
    if (cur == NULL)
    {
        return 1;
    }
    else return 0;
}

int duplicateReverse(ListNode* cur, ListNode** ptrNewHead)
{
    int i =0;
    ListNode *bef = NULL;
    ListNode *nexft = (*ptrNewHead);
    (*ptrNewHead)->item = cur->item;
    cur = cur->next;

    while(cur->next!=NULL)
  {
      insertNode(ptrNewHead, i, cur->item);
      cur = cur-> next;
  }

    return 1;

}

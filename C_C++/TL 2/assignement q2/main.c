#include <stdio.h>
#include <stdlib.h>

typedef struct _dbllistnode
{
    int  item;
	struct _dbllistnode *next;
	struct _dbllistnode *pre;
} CDblListNode;

typedef struct _dbllinkedlist{
   int size;
   CDblListNode *head;
} CDblLinkedList;

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value);
void deleteList(CDblLinkedList *ptrCDLL);
void printList(CDblLinkedList CDLL);

int numMountainPairs(CDblLinkedList CDLL);

int main()
{
    CDblLinkedList himalayas;
    himalayas.head = NULL;
    himalayas.size = 0;

    int item;
    int i,cases;
    int numP;
    scanf("%d",&cases);
    for(i=0; i<cases; i++)
    {
        while(scanf("%d",&item))
            insertNode_AtFront(&himalayas, item);
        scanf("%*s");

        numP = numMountainPairs(himalayas);
        printList(himalayas);
        printf("%d Pairs.\n",numP);

        deleteList(&himalayas);
    }
    return 0;
}

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value){
      //create a new node
      CDblListNode* newNode;
      newNode = (CDblListNode *) malloc(sizeof(CDblListNode));
      newNode->item = value;

      if(ptrCDLL->size==0) //first node
      {
          newNode->next = newNode;
          newNode->pre = newNode;
          ptrCDLL->head = newNode;
      }
      else{
        newNode->next = ptrCDLL->head;
        newNode->pre = ptrCDLL->head->pre;

        newNode->pre->next = newNode; //update last node next link;
        ptrCDLL->head->pre = newNode;

        ptrCDLL->head = newNode;
      }
      ptrCDLL->size++;
}

void printList(CDblLinkedList CDLL){

    if(CDLL.head==NULL) return;

    CDblListNode* temp = CDLL.head;
    printf("Current List: ");

    while (temp->next != CDLL.head){
        printf("%d ", temp->item);
        temp = temp->next;

    }
    printf("%d\n",temp->item);
}

void deleteList(CDblLinkedList *ptrCDLL){
    if(ptrCDLL->head==NULL) return;
    CDblListNode *cur = ptrCDLL->head;
    CDblListNode *temp;

    while (cur->next!= ptrCDLL->head) {
        temp=cur->next;
        free(cur);
        cur=temp;
    }

    free(cur);
    ptrCDLL->head =NULL;
    ptrCDLL->size =0;

}



/*int numMountainPairs(CDblLinkedList CDLL)
{
    int i, j, result = CDLL.size;
    int min, yes = 1;
    CDblListNode * two = (CDLL.head)->next, *move = (CDLL.head)->next;
    if(CDLL.size <= 2)
    {
        return result;
    }
    for(i = 0; i < (CDLL.size-3); i++)
    {
        for(j = 0; j<(CDLL.size-3); j++)
        {
            //printf("%d\n", result);
            two = two->next;
            move = (CDLL.head)->next;
            min = CDLL.head -> item;
            if((CDLL.head)->item > two->item)
            {
                min =  two->item;
            }
            //from head to two
            while(move != two)
            {
                if(move->item > min)
                {
                    yes = 0;
                    break;
                }
                move = move->next;
            }

            if(yes == 1)
            {
                //printf("%d %d %d\n", i, j,(move)->item);
                result++;
            }
            // toe to head
            else
            {
                yes = 1;
                move = move->next;
                while(move != CDLL.head)
                {

                    if(move->item > min)
                    {
                        yes = 0;
                        break;
                    }
                    move = move->next;

                }
                if(yes == 1)
                {
                    //printf("%d\n", (CDLL.head)->item);
                    //printf("%d %d %d\n", i, j,(move)->item);
                    result++;
                }
                else
                {
                    yes = 1;
                }
            }


        }
        CDLL.head = (CDLL.head)->next;
        two = (CDLL.head)->next;
    }
    //last one
    two = (CDLL.head)->next;
    move = (CDLL.head)->next;
    //printf("%d\n", (CDLL.head)->item);
    min = CDLL.head -> item;
    if((CDLL.head)->item > two->item)
    {
        min =  two->item;
    }
    while(move != two)
    {
        if(move->item > min)
        {
            yes = 0;
            break;
        }
        move = move->next;
    }

    if(yes == 1)
    {
        //printf("fg");
        result++;
    }
    else
    {
        yes = 1;
        move = move->next;
        while(move != CDLL.head)
        {

            if(move->item > min)
            {
                yes = 0;
                break;
            }
            move = move->next;
        }
        if(yes == 1)
        {
            //printf("yes\n");
            result++;
        }
        else
        {
            yes =1;
        }

    }

    return result;
} */
int numMountainPairs(CDblLinkedList CDLL)
{
    int i, j, result = 0;
    int min, yes = 1;
    CDblListNode * two = (CDLL.head), *move = (CDLL.head)->next;
    if(CDLL.size <= 2)
    {
        return CDLL.size -1;
    }
    for(i = 0; i < (CDLL.size-1); i++)
    {
        for(j = (CDLL.size-1); j > i; j--)
        {
            two = two->next;
            //printf("%d\n", two->item);
            move = (CDLL.head)->next;
            min = CDLL.head -> item;
            if((CDLL.head)->item > two->item)
            {
                min =  two->item;
            }
            //from head to two
            while(move != two)
            {
                if(move->item > min)
                {
                    yes = 0;
                }
                move = move->next;
            }

            if(yes == 1)
            {
                //printf("%d %d %d\n", i, (CDLL.size-1) -j,(move)->item);
                result++;
            }
            // toe to head
            else
            {
                yes = 1;
                move = move->next;
                while(move != CDLL.head)
                {

                    if(move->item > min)
                    {
                        yes = 0;
                        break;
                    }
                    move = move->next;

                }
                if(yes == 1)
                {
                    //printf("%d\n", (CDLL.head)->item);
                    //printf("%d %d %d\n", i, j,(move)->item);
                    result++;
                }
                else
                {
                    yes = 1;
                }
            }
        }
        CDLL.head = (CDLL.head)->next;
        two = (CDLL.head);
    }
    return result;
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 //The size of the array

enum ExpType {OPT,OPERAND};

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);


void in2PreLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
}

void push(Stack *sPtr, char item){
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

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}


void in2PreLL(char* infix, LinkedList *inExpLL)
{
    int i = 0, j =0, num = 0;
    char two[SIZE], *ptrr;
    LinkedList LL;
    LL.head = NULL;
    LL.size = 0;
    Stack s;
    s.head = NULL;
    s.size = 0;
    Stack opr;
    opr.head = NULL;
    opr.size = 0;
    while(infix[i] != '\0')
    {
        switch (infix[i])
        {
            case('+'):
            case('-'):
            case('/'):
            case('*'):
            {
                if(num != 0)
                {
                    insertNode(&LL, num, OPERAND);
                    //printf("%d\n", num);
                    num = 0;
                }
                insertNode(&LL, infix[i], OPT);
                break;
            }
            case(')'):
            {
                if(num != 0)
                {
                    insertNode(&LL, num, OPERAND);
                    //printf("%d\n", num);
                    num = 0;
                }
                insertNode(&LL, '(', OPT);
                break;
            }
            case('('):
            {
                if(num != 0)
                {
                    insertNode(&LL, num, OPERAND);
                    //printf("%d\n", num);
                    num = 0;
                }
                insertNode(&LL, ')', OPT);
            }
            default:
            {
                if (num == 0)
                {
                    ptrr = infix + i;
                }
                num = atoi(ptrr);
                //num = num*10 + infix[i]-'0';
            }
        }
        i++;
    }
    if(num != 0)
    {
        insertNode(&LL, num, OPERAND);
        //printf("%c\n", num-'0');
        num = 0;
    }
    printExpLL(LL);
    //use stack to insert from string into a string
    //i=0;
    while(isEmptyLinkedList(LL)==0)
    {
        if((LL.head)-> type == OPERAND)
        {
            insertNode(inExpLL, (LL.head)->item, OPERAND);
            deleteNode(&LL);
        }
        if(isEmptyLinkedList(LL)==1)
        {
            break;
        }
        switch((LL.head)->item)
        {
            //printf("%c\n", peek(s));
            case('('):
            {
                push(&opr, (LL.head)->item);
                deleteNode(&LL);
                break;
            }
            case(')'):
            {
                while(peek(opr)!= '(')
                {
                    insertNode(inExpLL, peek(opr), OPT);
                    pop(&opr);
                }
                pop(&opr);
                deleteNode(&LL);
                //printf("%c\n", peek(s));
                break;
            }
            case('/'):
            case('*'):
            {
                push(&opr, (LL.head)->item);
                deleteNode(&LL);
                break;
            }
            case('+'):
            case('-'):
            {
                while(isEmptyStack(opr)!= 1 && (peek(opr)== '/' || peek(opr)== '*'))
                {
                    insertNode(inExpLL, peek(opr), OPT);
                    pop(&opr);
                }
                push(&opr, (LL.head)->item);
                deleteNode(&LL);
                break;
            }
            default:
            {
                insertNode(inExpLL, (LL.head)->item, OPERAND);
                deleteNode(&LL);
            }
        }
        //printf("%d", i);
    }
    //printf("NUm: %d %d \n", i, j);
    while(isEmptyStack(opr)==0)
    {
        insertNode(inExpLL, peek(opr), OPT);
        pop(&opr);
    }

}


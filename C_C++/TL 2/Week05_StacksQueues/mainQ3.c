#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    double item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, double item);
int pop(Stack *sPtr);
double peek(Stack s);
int isEmptyStack(Stack s);

double exePostfix(char*);

int main()
{
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    scanf("%[^\n]%*c",postfix);

    printf("The answer is %.2lf.\n",exePostfix(postfix));

    return 0;
}

void push(Stack *sPtr, double item){
    StackNode *newNode;
    newNode = (StackNode *) malloc(sizeof(StackNode));
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

double peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

double exePostfix(char* postfix)
{
    int i, j;
    double result=0, operand1, operand2 ;
    char oper;
    Stack nn;
    nn.head == NULL;
    nn.size == 0;
    for(i=0; i<SIZE; i++)
    {
        if(iscntrl(postfix[i]))
            break;
    }
    //printf("%d\n", i);
    for(j=0; j<i; j++)
    {
        if(isdigit(postfix[j]))
        {
            push(&nn, postfix[j]-'0');
            //printf("%lf\n", peek(nn));
        }
        else
        {
            operand1 = peek(nn);
            pop(&nn);
            operand2 = peek(nn);
            pop(&nn);
            //printf("%lf, %lf\n",operand1, operand2);
            switch(postfix[j])
            {
                case '+':
                    result = operand2 + operand1;
                    break;
                case '-':
                    result = operand2 - operand1;
                    break;
                case '*':
                    result = operand2 * operand1;
                    break;
                case '/':
                    result = operand2 / operand1;
                    break;
            }
            //printf("%lf\n", result);
            push(&nn, result);
        }
    }
    result = peek(nn);
    return result;
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 //The limit of expression length

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
int precedence(char op);

void in2Post(char*, char*);

int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    in2Post(infix,postfix);
    printf("The postfix expression is \n");
    printf("%s\n",postfix);
    return 0;
}

void push(Stack *sPtr, char item){
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

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void in2Post(char* infix, char* postfix)
{
    int i = 0, j = 0;
    Stack s;
    s.head = NULL;
    s.size = 0;

    while(i<SIZE && infix[i] != '\0') // default init in a string is \0, for  int is 0
    {
        switch(infix[i])
        {
            case '+':
            case '-':
            case '/':
            case '*':
                {
                    while(isEmptyStack(s)==0 && peek(s) != '(' && precedence(peek(s)) >= precedence(infix[i]))
                    {
                        postfix[j++] = peek(s);
                        pop(&s);
                    }
                    push(&s, infix[i]);
                    break;
                }
            case ')':
                {
                    //if stack has still operators to cover
                    while(isEmptyStack(s)==0)
                    {
                        if(peek(s) != '(')
                        {
                            postfix[j++]=peek(s);
                            pop(&s);
                        }
                        else //is (
                        {
                            pop(&s);
                            break;
                        }

                    }
                }break;
            case '(':
                {
                    push(&s, infix[i]);
                    break;
                }
            default: //operand
                postfix[j++] = infix[i];

        }
        i++;
    }
    while(isEmptyStack(s)==0)
    {
        postfix[j++]=peek(s);
        pop(&s);
    }




}

int precedence(char op)
{
    if(op == '/' || op == '*')
    {
        return 1;
    }
    else
        return 0;
}

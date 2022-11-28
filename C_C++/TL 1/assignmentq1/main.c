#include <stdio.h>
#include <stdlib.h>
int i =0;
struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);
ListNode *findNode(ListNode* cur, int i);

ListNode *reverseSegment(ListNode* head, int start, int end);

int main()
{
    ListNode *head = NULL, *temp;
	float f = 0.0;
	int S, E;

	scanf("%d %d",&S, &E);

	while (scanf("%f", &f)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = f;
		i++;
	}
	temp->next = NULL;

	head = reverseSegment(head,S,E);
	printList(head);
	deleteList(&head);
	return 0;

}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%.2f ",head->item);
        head = head->next;
    }
    printf("\n");
}

void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

ListNode *findNode(ListNode* cur, int i)
{
    if (cur==NULL || i<0)
        return NULL;
    while(i>0){
    cur=cur->next;
    if (cur==NULL)
    return NULL;
    i--;
    }
    return cur;
}


ListNode *reverseSegment(ListNode* head, int start, int end)
{
    int j, x=0, y = i;
    ListNode *ptr = NULL, *curr, *target = head;
    //creating a same sized list
    while (y>0){
		if (ptr == NULL){
			ptr = (ListNode*) malloc(sizeof(ListNode));
			curr = ptr;
		}
		else{
			curr->next = (ListNode*) malloc(sizeof(ListNode));
			curr = curr->next;
		}
		y--;
	}
	curr->next = NULL;
	curr = ptr;

	for(j=0; j<start; j++)
    {
        ptr->item = target->item;
        ptr = ptr->next;
        target = target->next;
    }
    printList(curr);

    if(end <= i)
    {
        for(x; end-start-x>=0; x++)
        {
        ptr->item = (findNode(head, end-x))->item;
        ptr = ptr->next;
        target = target->next;
        }
    }
    printList(curr);

    if(end > i)
    {
        for(j = start; (i-j)>0; j++)
        {

            ptr->item = target->item;
            ptr = ptr->next;
            target = target->next;

        }
    }
    else
    {
        for(j = end; (i-j)>1; j++)
        {

            ptr->item = target->item;
            ptr = ptr->next;
            target = target->next;

        }
    }
    printList(curr);

    return curr;
}

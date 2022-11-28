#include <stdio.h>
#include <stdlib.h>

int x = 0;
struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void triPartition(ListNode** head, int pivot);

int main()
{
    ListNode *head = NULL, *temp;
	int i = 0;
	int pivot = 0;

	scanf("%d",&pivot);

	while (scanf("%d", &i))
    {
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
		x++;
	}
	temp->next = NULL;


	triPartition(&head, pivot);
	printList(head);
	deleteList(&head);

	return 0;
}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%d ",head->item);
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

void triPartition(ListNode** head, int pivot)
{
    int j;
    ListNode *head1 = NULL, *cur1, *org = *head;
    if(x == 1)
    {
        return;
    }
    for(j=1; j<=x; j++)
    {
        if(head1 == NULL)
        {
            head1 = (ListNode*) malloc(sizeof(ListNode));
            cur1 = head1;
        }
        else
        {
            cur1->next = (ListNode*) malloc(sizeof(ListNode));
            cur1 = cur1->next;
        }
    }
    cur1->next = NULL;
    cur1 = head1;
    //checking smaller
    for(j=1; j<=x; j++)
    {
        if(org->item < pivot)
        {
            cur1->item = org->item;
            cur1 = cur1->next;
        }
        org = org->next;
    }
    org = *head;
    printList(head1);
    //checking equals
    for(j=1; j<=x; j++)
    {
        if(org->item == pivot)
        {
            cur1->item = org->item;
            cur1 = cur1->next;
        }
        org = org->next;
    }
    org = *head;
    printList(head1);
    //checking bigger
    for(j=1; j<=x; j++)
    {
        if(org->item > pivot)
        {
            cur1->item = org->item;
            cur1 = cur1->next;
        }
        org = org->next;
    }
    org = *head;
    printList(head1);

    *head = head1;


}

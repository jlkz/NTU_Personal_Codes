#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

typedef struct _linkedList{
    ListNode *head;
    int size;
}LinkedList;

void printList(LinkedList ll);
void deleteList(LinkedList* llptr);
void printListnorm(ListNode *head);

LinkedList rearrange (LinkedList ll);

int main()
{
    LinkedList ll;

    ll.head = NULL;
    ll.size = 0;
    ListNode* temp;

	int i = 0;

	while (scanf("%d", &i)){
		if (ll.head == NULL){
			ll.head = (ListNode*) malloc(sizeof(ListNode));
			temp = ll.head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
		ll.size++;
	}
	temp->next = NULL;

	ll=rearrange(ll);
	printList(ll);
    deleteList(&ll);
	return 0;
}

void printList(LinkedList ll){
    ListNode* temp = ll.head;

    while(temp !=NULL){
        printf("%d ",temp->item);
        temp = temp->next;
    }
    printf("\n");
}
void printListnorm(ListNode *head){

    while(head !=NULL){
        printf("%d ",head->item);
        head = head->next;
    }
    printf("\n");
}
void deleteList(LinkedList* llptr){
    ListNode *cur = llptr->head;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	llptr->head=NULL;
	llptr->size =0;
}

LinkedList rearrange (LinkedList ll)
{
    ListNode *head1 = NULL, *head2 = NULL, *cur1, *cur2, *org = ll.head;
    int x;
    if(ll.size == 1)
    {
        return ll   ;
    }
    for (x=1; x<=(ll.size/2); x++)
        {
		if (head1 == NULL){
			head1 = (ListNode*) malloc(sizeof(ListNode));
			cur1 = head1;
		}
		else{
			cur1->next = (ListNode*) malloc(sizeof(ListNode));
			cur1 = cur1->next;
		}

        }
        cur1->next = NULL;
        cur1 = head1;
    if (ll.size % 2 == 0)
    {
       for (x=1; x<=(ll.size/2); x++)
        {
		if (head2 == NULL){
			head2 = (ListNode*) malloc(sizeof(LinkedList));
			cur2 = head2;
		}
		else{
			cur2->next = (ListNode*) malloc(sizeof(ListNode));
			cur2 = cur2->next;
		}
        }
        cur2->next = NULL;
        cur2 = head2;

    }
    else
    {
        for (x=1; x<=(ll.size/2 + 1); x++)
        {
		if (head2 == NULL){
			head2 = (ListNode*) malloc(sizeof(ListNode));
			cur2 = head2;
		}
		else{
			cur2->next = (ListNode*) malloc(sizeof(ListNode));
			cur2 = cur2->next;
		}
        }
        cur2->next = NULL;
        cur2 = head2;
    }

    //first split
    for(x=1; x<=(ll.size/2); x++)
    {
        cur1->item = ll.head->item;
        cur1 = cur1->next;
        ll.head = ll.head->next;
    }
    cur1 = head1;
    printListnorm(head1);

    while(ll.head != NULL)
    {
        cur2->item = ll.head->item;
        cur2 = cur2->next;
        ll.head = ll.head->next;
    }
    cur2 = head2;
    printListnorm(head2);
    ll.head = org;

    //return
    for(x=1; x<=(ll.size/2); x++)
    {
        org->item = cur2->item;
        org = org->next;
        cur2 = cur2->next;
        org->item = cur1->item;
        org = org->next;
        cur1 = cur1->next;
    }
    if(ll.size%2 == 1)
    {
        org->item = cur2->item;
    }
    org = ll.head;
    cur1 = head1;
    cur2 = head2;
    printList(ll);

    //second split
    for(x=1; x<=(ll.size/2); x++)
    {
        cur1->item = ll.head->item;
        cur1 = cur1->next;
        ll.head = ll.head->next;
    }
    cur1 = head1;
    printListnorm(head1);

    while(ll.head != NULL)
    {
        cur2->item = ll.head->item;
        cur2 = cur2->next;
        ll.head = ll.head->next;
    }
    cur2 = head2;
    printListnorm(head2);
    ll.head = org;

    //final return
    for(x=1; x<=(ll.size/2); x++)
    {
        org->item = cur1->item;
        org = org->next;
        cur1 = cur1->next;
        org->item = cur2->item;
        org = org->next;
        cur2 = cur2->next;
    }
    if(ll.size%2 == 1)
    {
        org->item = cur2->item;
    }
    return ll;

}

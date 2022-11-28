#include <stdio.h>
#include <stdlib.h>
int i=0;
struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);
ListNode *findNode(ListNode* cur, int i);
void reverseKNodes(ListNode** head, int K);

int main()
{
    ListNode *head = NULL, *temp;
	int K = 0;
    int r;
	scanf("%d",&K);

	while (scanf("%d", &r)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = r;
		i++;
	}
	temp->next = NULL;


	reverseKNodes(&head, K);
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

ListNode *findNode(ListNode* cur, int i)
{
    if (cur==NULL || i<0)
    return NULL;
    while(i>0)
    {
        cur=cur->next;
        if (cur==NULL)
        return NULL;
        i--;
    }
return cur;
}

void reverseeKNodes(ListNode** head, int K)
{
        short x, y;
        ListNode *headd = NULL, *curr;
        ListNode *orghead = *head;
        for(x=0; x<i; x++)
        {
            if (headd == NULL){
                headd = (ListNode*) malloc(sizeof(ListNode));
                curr = headd;
            }
            else{
                curr->next = (ListNode*) malloc(sizeof(ListNode));
                curr = curr->next;
            }
        }
        curr-> next = NULL;
        curr = headd;
        if (K<0)
        {
            K = -K;
            for(x=0; x<(i/K); x++)
            {
                for(y=0; y<K; y++)
            {
                curr->item = (findNode(orghead, (i-(x*K)-(y+1))))->item;
                curr = curr->next;
                (*head) = (*head)->next;
            }
            }
        //printf("Copy: ");
        //printList(headd);
        //others who are out of range
            for(y=0; y<(i-((i/K)*K)); y++)
            {
                curr->item = (findNode(orghead, y))->item;
                curr = curr->next;
                (*head) = (*head)->next;
            }
            *head = headd;
            return ;
        }
        for(x=0; x<(i/K); x++)
        {
            for(y=0; y<K; y++)
            {
                curr->item = (findNode(orghead, ((x*K)+(K-y-1))))->item;
                curr = curr->next;
                (*head) = (*head)->next;
            }
        }
        //printf("Copy: ");
        //printList(headd);
        //others who are out of range
        while(*head != NULL)
        {
            curr->item = (*head)->item;
            curr = curr->next;
            (*head) = (*head)->next;
        }
        //printf("Copy: ");
        //printList(headd);

        *head = headd;


}
void reverseKNodes(ListNode** head, int K)
{
    ListNode *cur, *pre = (ListNode*)malloc(sizeof(ListNode)), *next  ;
    int j, k;

    if(K<=1 || K>i || i == 1)
    {
        return 0;
    }
    pre->next = *head;
    cur = *head;
    next = cur->next;

    // find new head
    for(j=1; j<K; j++)
    {
        cur = cur->next;
    }
    *head = cur;
    //printf("%d\n", (*head)->item);
    cur = pre->next;

    k = i/K;
    while (k>0)
    {
        for(j=1; j<K ; j++)
        {
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = cur->next;
        }
        //printList(*head);
        if(K == i)
        {
            return;
        }
        pre = cur;
        cur = next;
        if(next == NULL)
        {
            return;
        }
        next = next->next;
        k--;
    }

}

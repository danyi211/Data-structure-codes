#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

#define OK 0
#define ERROR 1

typedef struct node {
    // Doubly Linked List
    ElemType data;
    struct node *prior , *next;
    int freq;
    int seq;

}DoublyLinkedList, DLNode;

DoublyLinkedList *CreateDoublyLinkedList(int n)
{
    DoublyLinkedList *head, *p, *s;
    int i;

    head = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    head->freq = 0;
    head->seq = 0;

    p = head;
    for(i = 1; i <= n; i++){
        s = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
        scanf("%d", &s->data);
        s->freq = 0;
        s->seq = 0;

        s->prior = p; 
        p->next = s;
        p = s;
    }

    p->next = head;
    head->prior = p;

    return head;
    
}

void PrintList (DoublyLinkedList *head)
{
    // ignore the head
    DoublyLinkedList *p = head->next;
    while (p != head)
    {
        if (p->next == head) break;
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d", p->data);
    printf("\n");
    
}

void MoveFront (DLNode *p, DLNode *q)
{
    // move node p to the prior of node q
    p->prior->next = p->next;
    p->next->prior = p->prior;
    p->prior = q->prior;
    p->next = q;
    q->prior->next = p;
    q->prior = p;
}

DoublyLinkedList *Locate (DoublyLinkedList *head, ElemType e, int seq)
{
    DoublyLinkedList *p, *q;
    p = head->next;
    while (p != head && p->data != e)
    {
        p = p->next;
    }

    if (p == head) return NULL;
    
    p->freq += 1;
    if (p->seq == 0) p->seq = seq;

    q = head->next;
    while (q != p)
    {
        if (q->freq < p->freq){
            // printf("!! < move !!\n");
            MoveFront(p, q);
            break;
        }
        else if (q->freq == p->freq)
        {
            if (q->seq > p->seq){
                // printf("!! = move, q->data = %d, p->data = %d, q->seq = %d, p->seq = %d !!\n", q->data, p->data, q->seq, p->seq);
                MoveFront(p, q);
                break;
            }
        }

        q = q->next;
            
    }
    
    return p;
    
}

int main()
{
    int n, i;
    char ch;
    ElemType a;
    DoublyLinkedList *p;

    scanf("%d", &n);
    DoublyLinkedList *L = CreateDoublyLinkedList(n);

    // printf("number of elem : %d\n", n);
    // PrintList(L);

    i = 1;
    while (scanf("%d", &a))
    {
        p = Locate(L, a, i);
        ++i;

        // printf("%d time: ", i-1);
        // PrintList(L);
        ch = getchar();
        if (ch == '\n') break;
    }


    PrintList(L);
    

    return 0;
}
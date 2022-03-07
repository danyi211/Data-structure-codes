#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

#define OK 0
#define ERROR 1

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, LinkedList;

LinkedList *CreateList () 
{
    LinkedList *L, *p, *end;
    int i;
    char ch;
    ElemType a;
    L = (LinkedList *)malloc(sizeof(LNode));
    L->next = NULL;

    end = L;

    while(scanf("%d", &a)) {
        p = (LinkedList *)malloc(sizeof(LNode));
        p->data = a;
        // insert to the end of list
        p->next = NULL; 
        end->next = p;
        end = p;

        ch = getchar();
        if (ch == '\n') break;
    }

    return L;
}

Status ListDelete_L (LinkedList *L, int i, ElemType *e)
{

    LinkedList *p, *q;
    p = L;
    int j = 0;
    // find the (i-1)^th node
    while (p && j < i-1)
    {
        p = p->next;
        ++j;
    }

    if (!(p->next) || j > i-1) return ERROR;
    q = p->next;
    p ->next = q->next;
    *e = q->data;
    free(q);

    return OK;
}

void PrintList (LinkedList *L)
{
    // ignore the head
    L = L->next;
    while (L)
    {
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
    
}

int main()
{
    int mink, maxk, i;
    int start = 1, stop = 1;
    ElemType e;
    LinkedList *L, *p;
    L = CreateList();

    scanf("%d %d", &mink, &maxk);

    p = L->next;
    while(p && p->data <= mink){
        ++start;
        ++stop;
        p = p->next;
    }
    // printf("start: %d\n", start);

    while(p && p->data < maxk){
        ++stop;
        p = p->next;
    }
    // printf("stop: %d\n", stop);

    for (i = start; i < stop; i++){
        ListDelete_L(L, start, &e);
        // printf("delete: %d\n", e);
    }

    if (L->next != NULL) PrintList(L);
    else printf("NULL\n");

    return 0;
    
}
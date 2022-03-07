#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
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

    while(scanf("%c", &a)) {
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

void PrintList (LinkedList *L)
{
    // ignore the head
    L = L->next;
    while (L)
    {
        if (L->next == NULL) break;
        printf("%c,", L->data);
        L = L->next;
    }
    printf("%c", L->data);
    printf("\n");
    
}

void InverseList (LinkedList *L)
{
    LNode *prv = NULL;
    LNode *cur = L->next;
    LNode *nxt;

    while (cur)
    {
        nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
    }

    L->next = prv;
    
}

int main()
{
    LinkedList *L = CreateList();
    // PrintList(L);

    InverseList(L);
    PrintList(L);

    return 0;

}
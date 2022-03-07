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

LinkedList *CreateList (int n) 
{
    LinkedList *L, *p, *end;
    int i;
    char ch;
    L = (LinkedList *)malloc(sizeof(LNode));
    L->next = NULL;

    end = L;

    for (i = n; i > 0; --i) {

        p = (LinkedList *)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        // insert to the end of list
        p->next = NULL; 
        end->next = p;
        end = p;

        ch = getchar();
        // if (ch == '\n') break;
    }

    return L;
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
    LinkedList *hbEnd;
    int m, n, i;
    scanf("%d %d", &m, &n);

    LinkedList *ha = CreateList(m);
    LinkedList *hb = CreateList(n);

    // printf("m = %d, n = %d\n", m, n);
    // PrintList(ha);
    // PrintList(hb);

    hbEnd = hb;
    for (i = 0; i<n; i++) {
        hbEnd = hbEnd->next;
    }
    
    // printf("hb end: %d\n", hbEnd->data);
    
    hbEnd->next = ha->next;
    free(ha);
    PrintList(hb);

    return 0;

}
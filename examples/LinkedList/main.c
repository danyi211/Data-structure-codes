#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

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

int main() {
    
    LinkedList *L = CreateList_L (10);
    PrintList(L);

    printf("insert: status %d\n", ListInsert_L(L, 5, 21111));
    PrintList(L);

    ElemType e;
    printf("delete: status %d\n", ListDelete_L(L, 6, &e));
    printf("deleted %d\n", e);
    PrintList(L);

    printf("getElem: status %d\n", GetElem_L(L, 7, &e));
    printf("got %d\n", e);
    PrintList(L);

    return 0;
}
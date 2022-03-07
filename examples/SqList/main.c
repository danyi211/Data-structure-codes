#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

int main() {
    
    SqList L;
    printf("initiate: %d\n", InitList_Sq(&L));

    for (int i = 0; i<10; i++)
        L.elem[i] = 2*i;
    L.length = 10; // change the length after initiate the values

    for (int i = 0; i<10; i++)
        printf("%d ", L.elem[i]);
    printf("\n");

    printf("insert: status %d, index %d\n", ListInsert_Sq( &L, 10, 20), 10);
    // L.length = 11;

    for (int i = 0; i<L.length; i++)
        printf("%d ", L.elem[i]);
    printf("\n");

    int deleteElem;
    printf("delete: status %d, index %d\n", ListDelete_Sq( &L, 3, &deleteElem), 3);
    L.length = 10;

    for (int i = 0; i<L.length; i++)
        printf("%d ", L.elem[i]);
    printf("\n");
    printf("deleted element: %d\n", deleteElem);

    printf("find %d in the list: index %d\n", 20, LocateElem_Sq(&L, 20, &compare));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

#define LIST_INIT_SIZE 100 
#define LISTINCREMENT 10 
#define OK 0
#define ERROR 1
#define OVERFLOW 2
#define LESS -1
#define GREATER 1

Status compare (ElemType a, ElemType b)
{
    if (a<b) return LESS;
    if (a>b) return GREATER;
    return 0;
}

Status InitList_Sq ( SqList *L ){
    // initialize an empty list
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq (SqList *L, int i, ElemType e){
    ElemType *p;

    // check condition
    if (i < 1 || i > L->length + 1) return ERROR; // invalid i
    if (L->length >= L->listsize){
        // full list, increment size
        ElemType *newbase = (ElemType *)realloc(L->elem,
                    (L->listsize + LISTINCREMENT) * sizeof(ElemType) );
        if (!newbase) return ERROR; // fail to realloc
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    ElemType *q = &(L->elem[i-1]); // insert location
    // move the elem after insert position
    for (p = &(L->elem[L->length - 1]); p >= q; --p)
        *(p+1) = *p; // assume L->length +1 < L->listsize
    // insert e
    *q = e;
    L->length ++;
    return OK;
}

Status ListDelete_Sq (SqList *L, int i, ElemType *e){
    ElemType *p, *q;
    if (i < 1 || i > L->length) return ERROR; // invalid i
    p = &(L->elem[i-1]); // delete location
    *e = *p; // assign the value of the deleted elem to e
    q = L->elem + L->length - 1; // pointer to the end of the list
    for ( ++p; p <= q; ++p)
        *(p-1) = *p;
    L->length --;
    return OK;
}

Status LocateElem_Sq (SqList *L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    int i;
    ElemType *p;
    i = 1;
    p = L->elem;
    while (i <= L->length && (*compare)(*p, e) != 0)
    {
        p++;
        i++;
    }
    if (i <= L->length) return i;
    else return 0;
}

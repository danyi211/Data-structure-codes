#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "LinkedList.h"
#include <stdio.h>

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, LinkedList;

LinkedList *CreateList_L (int n);
Status ListInsert_L (LinkedList *L, int i, ElemType e);
Status ListDelete_L (LinkedList *L, int i, ElemType *e);
Status GetElem_L(LinkedList *L,int i, ElemType *e);

#endif /* _LINKEDLIST_H_ */
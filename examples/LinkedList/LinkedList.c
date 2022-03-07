#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define LIST_INIT_SIZE 100 
#define LISTINCREMENT 10 
#define OK 0
#define ERROR 1
#define OVERFLOW 2
#define LESS -1
#define GREATER 1

LinkedList *CreateList_L (int n) 
{
    LinkedList *L, *p;
    int i;
    L = (LinkedList *)malloc(sizeof(LNode));
    L->next = NULL;

    for (i = n; i > 0; --i) {
        p = (LinkedList *)malloc(sizeof(LNode));
        p->data = random()%200;
        // insert to the begining of list (next to L pointer)
        p->next = L->next; 
        L->next = p;
    }

    return L;
}

Status ListInsert_L (LinkedList *L, int i, ElemType e)
{
    //在带头结点的单链表L的第i个元素之前插入元素e
    LinkedList *p, *s;
    p = L;
    int j = 0;
    // find the (i-1)^th node
    while (p && j < i-1)
    {
        p = p->next;
        ++j;
    }
    // i小于1(导致j>i-1成立)或者大于表长+1(导致p为NULL)
    if (!p || j > i-1) return ERROR;
    s = (LinkedList *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

Status ListDelete_L (LinkedList *L, int i, ElemType *e)
{
    //在带头结点的单链表L中删除第i个元素，并由e返回其值
    LinkedList *p, *q;
    p = L;
    int j = 0;
    // find the (i-1)^th node
    while (p && j < i-1)
    {
        p = p->next;
        ++j;
    }
    // i小于1(导致j>i-1成立)或者大于表长(导致pànext为NULL)
    if (!(p->next) || j > i-1) return ERROR;
    q = p->next;
    p ->next = q->next;
    *e = q->data;
    free(q);

    return OK;
}

Status GetElem_L(LinkedList *L,int i, ElemType *e)
{
    // 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
    LinkedList *p;
    p = L->next;
    int j = 1;
    while (p && j<i)
    {
        //顺指针向后查找，直到p指向第i个元素或p为空
        p = p->next;
        ++j;
    }
    if ( !p || j>i ) return ERROR; // 第i个元素不存在
    *e = p->data;
    return OK;
}
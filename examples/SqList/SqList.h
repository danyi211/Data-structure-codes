#ifndef _SQLIST_H_
#define _SQLIST_H_

#include "SqList.h"
#include <stdio.h>

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType *elem;
    int length; //线性表当前长度
    int listsize; //当前分配的存储容量
                  //以sizeof(ElemType)为单位
}SqList;

Status compare (ElemType a, ElemType b);
Status InitList_Sq ( SqList *L );
Status ListInsert_Sq (SqList *L, int i, ElemType e);
Status ListDelete_Sq (SqList *L, int i, ElemType *e);
Status LocateElem_Sq (SqList *L, ElemType e, Status (*compare)(ElemType, ElemType));

#endif /* _SQLIST_H_ */
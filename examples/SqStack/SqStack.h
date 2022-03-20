#ifndef _SQSTACK_H_
#define _SQSTACK_H_

#include "SqStack.h"
#include <stdio.h>

typedef int ElemType;
typedef int Status;

typedef struct
{
    int top; // pointer to the top of the stack
    ElemType *base;
    int stacksize; // allocated space
}SqStack;

/* Initiate an empty stack */
Status InitStack(SqStack *s);

/* Get the length of the stack */
int GetLen(SqStack *s);

/* Get the top element of the stack */
Status GetTop(SqStack *s, ElemType *e);

/* Push element onto the top of the stack */
Status Push(SqStack *s, ElemType e);

/* Pop one element out of the stack */
Status Pop(SqStack *s, ElemType *e);

/* Check if stack is empty */
int IsStackEmpty(SqStack *s);

/* Tranverse stack from top to bottom with func visit() */
Status StackTraverse(SqStack *s, void visit(ElemType *e));

#endif /* _SQSTACK_H_ */
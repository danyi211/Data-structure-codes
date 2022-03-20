#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

#define INITSIZE 100
#define INCREMENTSIZE 10
#define OK 1
#define ERROR 0

Status InitStack(SqStack *s)
{
    s->base = (ElemType *)malloc(INITSIZE * sizeof(ElemType));
    if (!s)
        return ERROR;
    s->stacksize = INITSIZE;
    s->top = 0;
    return OK;
}

int GetLen(SqStack *s)
{
    return s->top;
}

Status GetTop(SqStack *s, ElemType *e)
{
    if (s->top == 0)
        return ERROR; // empty stack
    *e = s->base[s->top - 1];
    return OK;
}

Status Push(SqStack *s, ElemType e)
{
    if (s->top >= s->stacksize)
    {
        // full stack, increase space
        s->base = (ElemType *)realloc(s->base,
                                      (s->stacksize + INCREMENTSIZE) * sizeof(ElemType));
        if (!s->base)
            return ERROR;
        s->stacksize += INCREMENTSIZE;
    }
    s->base[s->top++] = e; // equivalent to
                           // s->base[s->top] = e; s->top++;
    return OK;
}

Status Pop(SqStack *s, ElemType *e)
{
    if (s->top == 0)
        return ERROR;
    *e = s->base[--s->top]; // equivalent to
                            // s->top--; *e = s->base[s->top];
    return OK;
}

int IsStackEmpty(SqStack *s)
{
    if (s->top == 0)
        return 1;
    else
        return 0;
}

Status StackTraverse(SqStack *s, void visit(ElemType *e))
{
    int i;
    if (s->top == 0)
        return ERROR;
    for (i = s->top - 1; i >= 0; i--)
        visit(&s->base[i]);
    return OK;
}
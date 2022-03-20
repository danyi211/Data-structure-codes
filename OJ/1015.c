#include <stdio.h>
#include <stdlib.h>

#define INITSIZE 100
#define INCREMENTSIZE 10
#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct
{
    int top; // pointer to the top of the stack
    ElemType *base;
    int stacksize; // allocated space
} SqStack;

Status InitStack(SqStack *s)
{
    s->base = (ElemType *)malloc(INITSIZE * sizeof(ElemType));
    if (!s)
        return ERROR;
    s->stacksize = INITSIZE;
    s->top = 0;
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

int main()
{
    int i = 0;
    char str[INITSIZE];
    if (fgets(str, INITSIZE, stdin) == NULL)
        return 1;
    // printf("%s", str);
    
    SqStack s;
    int status = 1;
    ElemType e;
    InitStack(&s);
    while (str[i] != '&' && str[i] != '@'){
        Push(&s, str[i]);
        i++;
    }
    i++;
    while (str[i] != '@')
    {
        if (!Pop(&s, &e)) status = 0;
        if (e != str[i]) status = 0;
        i++;
    }
    if (!IsStackEmpty(&s))
        status = 0;
    printf("%d\n", status);
    return 0;
    
}
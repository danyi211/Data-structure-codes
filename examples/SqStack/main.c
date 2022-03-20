#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

#define OK 1
#define ERROR 0

void Conversion(int n, int d)
{
    // conversion of decimal integer to d-base integer
    ElemType e;
    SqStack s;
    if (!InitStack(&s))
        return;
    while (n != 0)
    {
        Push(&s, n % d);
        // printf("n = %d\n", n);
        n = n / d;
    }
    while (!IsStackEmpty(&s))
    {
        Pop(&s, &e);
        printf("%d ", e);
    }
    printf("\n");
}

Status MatchingBrackets(char *exps)
{
    int i = 0;
    Status state = OK;
    ElemType e;
    SqStack s;
    InitStack(&s);
    while (state && exps[i] != '\0')
    {
        switch (exps[i])
        {
        case '(':
        case '[':
        case '{':
            Push(&s, exps[i]);
            break;
        case ')':
        case ']':
        case '}':
            if (!GetTop(&s, &e))
            {
                state = ERROR;
                break;
            }
            if ((e == '(' && exps[i] == ')') || (e == '[' && exps[i] == ']') ||
                (e == '{' && exps[i] == '}'))
                Pop(&s, &e);
            else
                state = ERROR;
            break;
        }
        i++;
    }
    if (IsStackEmpty(&s) && state)
        return OK;
    else
        return ERROR;
}

int main()
{
    /*
    int n, d;
    printf("Please type in the decimal integer: ");
    scanf("%d", &n);
    printf("Please type in the base number d: ");
    scanf("%d", &d);
    // printf("n = %d, d = %d\n", n, d);
    Conversion(n, d);
    */

    char *s = "for(int i = 0; i<n; i++){ a[i] = 0;}";
    char *sw = "{test(})[]";
    char *sw2 = "{{{(((";

    printf("matching brackets of %s: %d\n", s,
           MatchingBrackets(s));
    printf("matching brackets of %s: %d\n", sw,
           MatchingBrackets(sw));
    printf("matching brackets of %s: %d\n", sw2,
           MatchingBrackets(sw2));

    return 0;
}
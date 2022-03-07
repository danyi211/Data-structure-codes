#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef int PolyTerm;
typedef int Status;

#define OK 0
#define ERROR 1
#define SIZE 1000

typedef struct PolyTerm{
    int coeff;
    int power;
} PolyTerm;

typedef struct PolyNode{
  PolyTerm *data;
  struct PolyNode *next;
} PolyNode, PolyLink;

typedef PolyLink LinkedPoly;

LinkedPoly *FindPower(LinkedPoly *LP, int ipower)
{
    LP = LP->next;
    while (LP)
    {
        if (LP->data->power == ipower) return LP;
        LP = LP->next;
    }
    return NULL;
}

void PrintList (LinkedPoly *L)
{
    // ignore the head
    L = L->next;
    while (L)
    {
        if (L->next == NULL) break;
        printf("%dx^%d+ ", L->data->coeff, L->data->power);
        L = L->next;
    }
    printf("%dx^%d", L->data->coeff, L->data->power);
    printf("\n");
    
}

void InsertPolyList(LinkedPoly *LP, int icoeff, int ipower)
{
    // insert a new node to the list
    // ensure power from large to small

    LinkedPoly *p, *prev, *s;
    p = LP->next;
    prev = LP;

    while (p)
    {
        if (p->data->power < ipower){
            s = (PolyNode *)malloc(sizeof(PolyNode));
            s->data = (PolyTerm *)malloc(sizeof(PolyTerm));
            s->data->coeff = icoeff;
            s->data->power = ipower;
            prev->next = s;
            s->next = p;
            // PrintList(LP);
            break;
        }
        
        prev = prev->next;
        p = p->next;
    }

    if (p == NULL){
        // printf("LP == NULL\n");
        s = (PolyNode *)malloc(sizeof(PolyNode));
        s->data = (PolyTerm *)malloc(sizeof(PolyTerm));
        s->data->coeff = icoeff;
        s->data->power = ipower;
        prev->next = s;
        s->next = p;
        // PrintList(LP);
    }
    
}

char getSign (int x)
{
    if (x > 0) return '+';
    else return '-';
}

void PrintSign(LinkedPoly *p)
{
    if (p->data->coeff < 0){
        printf("%c ", '-');
    }
    else{
        printf("%c ", '+');
    }
}

void PrintTerm(LinkedPoly *p)
{
    if (p->data->power == 1){
        printf("%d ", abs(p->data->coeff));
    }
    else if (p->data->power == 2)
    {
        printf("%dx ", abs(p->data->coeff) * p->data->power);
    }
    else
    {
        printf("%dx^%d ", abs(p->data->coeff) * p->data->power, p->data->power - 1);
    }
    
}

void PrintPolyDerivative(LinkedPoly *L)
{
    // ignore the head
    L = L->next;

    int i = 0;
    while (L && L->data->coeff)
    {
        if (i == 0){
            if (L->data->coeff < 0) PrintSign(L);
            PrintTerm(L);
        }
        else{
            PrintSign(L);
            PrintTerm(L);
        }
        
        L = L->next;
        ++i;
    }
    printf("\n");
}

PolyTerm *popFront(LinkedPoly *L)
{
    if (L->next == 0)
    return NULL;

    LinkedPoly *oldhead = L->next;
    L->next = oldhead->next;
    PolyTerm *data = oldhead->data;
    free(oldhead);
    return data;
}

void removeAllNodes(LinkedPoly *L)
{
    PolyTerm *data;
    while (L->next != NULL){
        data = popFront(L);
        free(data);
    }
    
}


int main()
{
    char inputStr[SIZE];
    char coeff[SIZE], power[SIZE];
    char *p, *q;
    int i, sign;
    int icoeff, ipower;
    LinkedPoly *r;

    LinkedPoly *LP = (LinkedPoly *)malloc(sizeof(LinkedPoly));
    LP->next = NULL;

    gets(inputStr);
    // printf("%s\n", inputStr);

    memset(coeff, 0, SIZE);
    memset(power, 0, SIZE);

    p = inputStr;
    while (p)
    {
        // ignore constant term
        p = strstr(p, "x");
        if (p == NULL) break;
        // printf("find x: %s\n", p);
        
        // get coefficient & sign
        if (p == inputStr){
            icoeff = 1;
        }
        else if (*(p-2) == '+')
        {
            icoeff = 1;
        }
        else if (*(p-2) == '-')
        {
            icoeff = -1;
        }
        else{
            q = p-1;
            i = 0;
            while (*q >= '0' && *q <= '9'){
                // printf("coeff: i = %d, q = %c\n", i, *q);
                ++i;
                --q;
            }
            // printf("coeff end loop: i = %d, q = %c\n", i, *(q+1));
            // strncpy dst string is not null-terminated
            strncpy(coeff, q+1, i);
            coeff[i] = '\0';
            // printf("i = %d, coeff = %s\n", i, coeff);
            if (*(q-1) == '-')
                sign = -1;
            else
                sign = 1;
            
            icoeff = sign * atoi(coeff);
        }
        

        // get power
        if (*(p+1) == '^'){
            q = p+2;
            i = 0;
            while ( *q >= '0' && *q <= '9' )
            {
                ++i;
                q++;
            }
            strncpy(power, p+2, i);
            power[i] = '\0';
            // printf("i = %d, power = %s\n", i, power);
            ipower = atoi(power);
        }
        else{
            ipower = 1;
        }
    
        // printf("coeff %d, power %d\n", icoeff, ipower);

        if (FindPower(LP, ipower) == NULL){
            InsertPolyList(LP, icoeff, ipower);
            // PrintList(LP);
        }
        else{
            r = FindPower(LP, ipower);
            r->data->coeff += icoeff;
            // PrintList(LP);
        }

        ++p;
    }

    // final output
    PrintPolyDerivative(LP);
    
    // free the list
    removeAllNodes(LP);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100 
#define LISTINCREMENT 10 
#define OK 0
#define ERROR 1
#define OVERFLOW 2
#define LESS -1
#define GREATER 1

typedef char ElemType;
typedef int Status;

typedef struct
{
    ElemType *elem;
    int length; 
    int listsize; 

}SqList;

Status InitList_Sq ( SqList *L ){
    // initialize an empty list
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
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

void ListInput (SqList *L)
{
    int i = 0;
    char ch;
    ElemType a;

    while(scanf("%c", &a)) {
        L->elem[i] = a;
        ch = getchar();
        if (ch == '\n') break;
        i++;
    }
    L->length = i+1;
}

void ListPrint (SqList *L, char *name)
{
    printf("%s : " , name);
    for (int i = 0; i<L->length; i++)
        printf("%c ", L->elem[i]);
    printf("\n");
}

int min (int a, int b)
{
    if (a >= b) return b;
    else if (a < b) return a;
}

//-----------------------------------------------------------------

int main() 
{
    int i, maxCom;
    int flag = -1;
    ElemType e;

    SqList *LA = (SqList *)malloc(sizeof(SqList));
    SqList *LB = (SqList *)malloc(sizeof(SqList));
    InitList_Sq(LA); InitList_Sq(LB);

    ListInput(LA);
    ListInput(LB);

    // ListPrint(LA, "LA");
    // ListPrint(LB, "LB");

    maxCom = min(LA->length, LB->length);
    // printf ("maxCom : %d\n", maxCom);

    for (i = 0; i < maxCom; i++){
        // printf("iteration: %d\n", i);
        if (LA->length == 0 || LB->length == 0)
            break;
        else if (LA->elem[0] == LB->elem[0]){
            ListDelete_Sq(LA, 1, &e);
            // printf("LA deleted: %c\n", e);
            ListDelete_Sq(LB, 1, &e);
            // printf("LB deleted: %c\n", e);
        }
        else if(LA->elem[0] < LB->elem[0]){
            flag = 1;
        }
        else if(LA->elem[0] > LB->elem[0]){
            flag = 2;
        }
    }

    // ListPrint(LA, "LA");
    // ListPrint(LB, "LB");

    if (flag > 0){
        printf("%d\n", flag);
    }
    else{
        if (LA->length == 0 && LB->length > 0) flag = 1;
        if (LA->length > 0 && LB->length == 0) flag = 2;
        if (LA->length == 0 && LB->length == 0) flag = 0;

        printf("%d\n", flag);
    }

    free(LA);
    free(LB);
    return 0;

}

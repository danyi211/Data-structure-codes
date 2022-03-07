#include<stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10 
#define OK 0
#define ERROR 1

typedef int ElemType;
typedef int Status;

typedef struct List
{
    int *elem;
    int length;
    int listsize;

}SqList;

void InitList_Sq (SqList *L) {
    L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
    if (!L->elem ) exit(0);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    // return 0;
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


int main(){
    
    int i = 0, a;
    char ch;
    int x; /* data insert */

    SqList *L = (SqList *)malloc(sizeof(SqList));
    InitList_Sq(L);

    // initialize the list elements
    while(scanf("%d", &a)) {
        L->elem[i] = a;
        ch = getchar();
        if (ch == '\n') break;
        i++;
    }
    scanf("%d", &x);
    L->length = i+1;

    // printf("length: %d\n", L->length);
    // printf("x: %d\n", x);
    
    // for (i = 0; i < L->length; i++){
    //     printf("%d ", L->elem[i]);
    // }
    // printf("\n");

    for (i = 0; i < L->length; i++){
        if (x <= L->elem[i]){
            ListInsert_Sq(L, i+1, x);
            break;
        }
    }
    if (i == L->length){
        L->elem[L->length] = x;
        L->length += 1;
    }

    // printf("length: %d\n", L->length);

    for (i = 0; i < L->length; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\n");

    free(L);
    
    return 0;
}

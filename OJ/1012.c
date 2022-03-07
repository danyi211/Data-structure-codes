#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef int Status;

#define OK 0
#define ERROR 1

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, LinkedList;

LinkedList *CreateList () 
{
    LinkedList *L, *p, *end;
    int i;
    char ch;
    ElemType a;
    L = (LinkedList *)malloc(sizeof(LNode));
    L->next = NULL;

    end = L;

    while(scanf("%c", &a)) {
        p = (LinkedList *)malloc(sizeof(LNode));
        p->data = a;
        // insert to the end of list
        p->next = NULL; 
        end->next = p;
        end = p;

        ch = getchar();
        if (ch == '\n') break;
    }

    return L;
}

void PrintList (LinkedList *L)
{
    // ignore the head
    L = L->next;
    while (L)
    {
        if (L->next == NULL) break;
        printf("%c,", L->data);
        L = L->next;
    }
    printf("%c", L->data);
    printf("\n");
    
}

int FindElem (LinkedList *L, ElemType e)
{
    // return 0 if found, 1 if not
    LNode *p = L->next;
    while(p){
        if (p->data == e){
            return 0;
        }
        p = p->next;
    }

    return 1;
}

int main()
{
    // char ch;

    LinkedList *LA = CreateList();
    LinkedList *LB = CreateList();
    LinkedList *LC = CreateList();

    // PrintList(LA);
    // PrintList(LB);
    // PrintList(LC);

    // ch = 'f';
    // printf("Find Element %c in LB, result: %d\n", ch, FindElem(LB, ch));
    // printf("Find Element %c in LC, result: %d\n", ch, FindElem(LC, ch));

    LNode *cur = LA->next;
    LNode *prv = LA;
    while (cur)
    {
        // PrintList(LA);
        // printf("find elem %c\n",cur->data);
        if (FindElem(LB, cur->data) == 0 && FindElem(LC, cur->data) == 0){
            // printf("elem %c is found in both lists\n", cur->data);
            prv->next = cur->next;
            free(cur);
            cur = prv->next;
            continue;
        }
        cur = cur->next;
        prv = prv->next;
    }

    PrintList(LA);

    return 0;
}
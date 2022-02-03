#include <stdio.h>
#include <stdlib.h>

typedef struct nodetag
{
    int info;
    struct nodetag *next;
} nodetype;

nodetype *head, *cur, *prev, *next, *target;

nodetype *createnode(int item)
{
    nodetype *head = NULL;
    if ((head = (nodetype *)malloc(sizeof(nodetype))) == NULL)
        printf("malloc eror");
    else
    {
        head->info = item;
        head->next = NULL;
    }
    return head;
}

nodetype *init_l() { return NULL; };

int empty_l(nodetype *head) { return (head == NULL); };

int atend_l(nodetype *cur)
{
    if (cur == NULL)

        return 0;
    else
        return (cur->next == NULL);
}

void insert_front(nodetype *target, nodetype **phead)
{

    target->next = *phead;
    *phead = target;
}

void insert_after(nodetype *target, nodetype *prev)
{

    nodetype *cur;
    cur = prev->next;
    target->next = cur;
    prev->next = target;
}

void delete_front(nodetype **phead)
{

    nodetype *cur;
    cur = *phead;
    *phead = (*phead)->next;
    free(cur);
}

void delete_after(nodetype *prev)
{
    nodetype *cur;
    if (!(atend_l(prev)))
    {
        cur = prev->next;
        prev->next = cur->next;
        free(cur);
    }
}
void printList(nodetype *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->info);
        n = n->next;
    }
}

int main()
{
    nodetype *n = createnode(10);
    insert_front(n,&head);
    n = createnode(20);
    insert_front(n,&head);
    printList(n);
}

// void insert_front(nodetype **head_ref, )
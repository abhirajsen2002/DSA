
typedef struct nodetag
{
    int info;
    struct nodetag *next;
} nodetype;

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
    prev->next = target;
    target->next = cur;
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

nodetype *find(nodetype *n, int x)
{
    while (n != NULL)
    {
        if (n->info == x)
            return n;
        n = n->next;
    }

    return NULL;
}

void printList(nodetype *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->info);
        n = n->next;
    }
}
int find_size(nodetype *n)
{
    int sum = 0;
    while (n != NULL)
    {
        sum += 1;
        n = n->next;
    }
    return sum;
}

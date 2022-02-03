
typedef struct nodetag
{
    int info;
    struct nodetag *next;
} nodetype;

// nodetype *head_l = NULL;

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
void printRevOrder(nodetype *n)
{
    if (n == NULL)
    {
        return;
    }

    printRevOrder(n->next);
    printf(" % d ", n->info);
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
int check_equal(nodetype *head1, nodetype *head2)
{
    int s1 = find_size(head1);
    int s2 = find_size(head2);
    if (s1 != s2)
    {
        return 0;
    }
    else
    {
        while (head1 != NULL)
        {
            if (head1->info != head2->info)
            {
                return 0;
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        return 0;
    }
}
void find_and_del(nodetype **n, int x)
{
    nodetype *temp = *n, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->info == x)
    {
        *n = temp->next; // Changed head
        free(temp);      // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->info != x)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}
void concatinate(nodetype *a, nodetype *b)
{
    if (a->next == NULL)
    {
        a->next = b;
    }
    else
    {
        concatinate(a->next, b);
    }
}
void insert_end(nodetype **head_ref, int new_data)
{
    /* 1. allocate node */
    nodetype *new_node = createnode(new_data);

    nodetype *last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->info = new_data;

    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}
int isSortedDescending(nodetype *head)
{
    if (head == NULL)
        return 1;

    // Traverse the list till last node and return
    // false if a node is smaller than or equal
    // its next.
    for (nodetype *t = head; t->next != NULL; t = t->next)
        if (t->info <= t->next->info)
            return 0;
    return 1;
}
int isSortedAscending(nodetype *head)
{
    if (head == NULL)
        return 1;

    // Traverse the list till last node and return
    // false if a node is smaller than or equal
    // its next.
    for (nodetype *t = head; t->next != NULL; t = t->next)
        if (t->info >= t->next->info)
            return 0;
    return 1;
}
void removeDuplicates_unsorted(nodetype *start)
{
    nodetype *ptr1, *ptr2, *dup;
    ptr1 = start;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->info == ptr2->next->info)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
void removeDuplicates_sorted(nodetype *head)
{
    /* Pointer to traverse the linked list */
    nodetype *current = head;

    /* Pointer to store the next pointer of a node to be deleted*/
    struct Node *next_next;

    /* do nothing if the list is empty */
    if (current == NULL)
        return;

    /* Traverse the list till last node */
    while (current->next != NULL)
    {
        /* Compare current node with next node */
        if (current->info == current->next->info)
        {
            /* The sequence of steps is important*/
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else /* This is tricky: only advance if no deletion */
        {
            current = current->next;
        }
    }
}
void moveToFront(nodetype **head_ref)
{
    /* If linked list is empty, or it contains only one node,
      then nothing needs to be done, simply return */
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    /* Initialize second last and last pointers */
    nodetype *secLast = NULL;
    nodetype *last = *head_ref;

    /*After this loop secLast contains address of second last
    node and last contains address of last node in Linked List */
    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }

    /* Set the next of second last as NULL */
    secLast->next = NULL;

    /* Set next of last as head node */
    last->next = *head_ref;

    /* Change the head pointer to point to last node now */
    *head_ref = last;
}
void deleteList(nodetype **head_ref)
{
    /* deref head_ref to get the real head */
    nodetype *current = *head_ref;
    nodetype *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    /* deref head_ref to affect the real head back
       in the caller. */
    *head_ref = NULL;
}
void bubbleSort(nodetype *start)
{
    int swapped, i;
    nodetype *ptr1;
    nodetype *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->info > ptr1->next->info)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(nodetype *a, nodetype *b)
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}
void reverse(nodetype **head_ref)
{
    nodetype *prev = NULL;
    nodetype *current = *head_ref;
    nodetype *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

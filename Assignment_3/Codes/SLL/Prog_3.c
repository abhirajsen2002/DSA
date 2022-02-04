//Main menu function left.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LL.h"

int size_l(nodetype *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

bool isEqual(nodetype *head_1, nodetype *head_2)
{
    int s1 = find_size(head_1);
    int s2 = find_size(head_2);
    if (s1 != s2)
    {
        return false;
    }
    else
    {
        while (head_1 != NULL)
        {
            if (head_1->info != head_2->info)
            {
                return 0;
            }

            head_1 = head_1->next;
            head_2 = head_2->next;
        }

        return true;
    }
}

nodetype *search(nodetype *head, int x)
{
    return head == NULL ? NULL : (head->info == x ? head : search(head->next, x));
}

void find_and_delete(nodetype **head, int x)
{
    nodetype *temp = *head, *prev;
    if (temp != NULL && temp->info == x)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->info != x)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void append(nodetype *head_1, nodetype *head_2)
{
    if (head_1 != NULL && head_2 != NULL)
    {
        if (head_1->next == NULL)
            head_1->next = head_2;
        else
            append(head_1->next, head_2);
    }
    else
    {
        printf("Either a or b is NULL\n");
    }
}

void delete_n(int n, nodetype *head)
{
    int count = 1;
    while (head->next != NULL)
    {
        if (count == n)
        {
            delete_after(head);
            break;
        }
        count++;
        head = head->next;
    }
}

int isSortedDescending(nodetype *head)
{
    if (head == NULL)
        return 1;
    for (nodetype *t = head; t->next != NULL; t = t->next)
        if (t->info <= t->next->info)
            return 0;
    return 1;
}

int isSortedAscending(nodetype *head)
{
    if (head == NULL)
        return 1;
    for (nodetype *t = head; t->next != NULL; t = t->next)
        if (t->info >= t->next->info)
            return 0;
    return 1;
}

nodetype *merge(nodetype *h1, nodetype *h2)
{
    if (atend_l(h1))
        return h2;
    if (atend_l(h2))
        return h1;
    if (h1->info < h2->info)
    {
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else
    {
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

void insert_mid(nodetype *new_data, nodetype **head, int n)
{
    if (empty_l(*head))
    {
        insert_front(createnode(n), head);
    }
    // int x = n;
    nodetype *temp = *head;
    while (temp != NULL)
    {
        if (temp->next->info == n)
        {
            insert_after(new_data, temp);
            break;
        }
        temp = temp->next;
    }
}

void insert_end(nodetype *new_data, nodetype **head)
{
    nodetype *last = *head;
    if (*head == NULL)
    {
        insert_front(new_data, head);
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_data;
    return;
}

void removeDuplicates_unsorted(nodetype *head)
{
    nodetype *ptr1, *ptr2, *dup;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {

            if (ptr1->info == ptr2->next->info)
            {

                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void removeDuplicates_sorted(nodetype *head)
{

    nodetype *current = head;

    struct Node *next_next;

    if (current == NULL)
        return;

    while (current->next != NULL)
    {

        if (current->info == current->next->info)
        {

            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void pairWiseSwap(nodetype *head)
{
    nodetype *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        swap(&temp->info, &temp->next->info);
        temp = temp->next->next;
    }
}

void moveToFront(nodetype **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    nodetype *secLast = NULL;
    nodetype *last = *head;

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }

    secLast->next = NULL;

    last->next = *head;

    *head = last;
}

void deleteAlt(nodetype *head)
{
    if (head == NULL)
        return;
    nodetype *prev = head;
    nodetype *node = head->next;

    while (prev != NULL && node != NULL)
    {
        prev->next = node->next;
        free(node);
        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}

void rotate(nodetype **head, int k)
{
    if (k == 0)
        return;
    nodetype *current = *head;

    while (current->next != NULL)
        current = current->next;

    current->next = *head;
    current = *head;
    for (int i = 0; i < k - 1; i++)
        current = current->next;
    *head = current->next;
    current->next = NULL;
}

void deleteList(nodetype **head)
{
    nodetype *current = *head;
    nodetype *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void reverse(nodetype **head)
{
    nodetype *prev = NULL;
    nodetype *current = *head;
    nodetype *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void swap(nodetype *a, nodetype *b)
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

void bubbleSort(nodetype *head)
{
    int swapped, i;
    nodetype *ptr1;
    nodetype *lptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

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

int main()
{
}

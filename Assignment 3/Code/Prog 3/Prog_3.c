#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LL.h"

int size_l(nodetype *head) //   returns size of the list in terms of nodes.
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void printReverse(nodetype *head) //    prints the list in reverse order without actually reversing it
{
    // Base case
    if (head == NULL)
        return;

    // print the list after head node
    printReverse(head->next);

    // After everything else is printed, print head
    printf("%d  ", head->info);
}

bool isEqual(nodetype *head_1, nodetype *head_2) //     checks if both lists are equal
{
    int s1 = size_l(head_1);
    int s2 = size_l(head_2);
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

nodetype *search(nodetype *head, int x) //  searches a key in the list
{
    return head == NULL ? NULL : (head->info == x ? head : search(head->next, x));
}

nodetype *find_and_delete(nodetype **head, int x) //    searchs a key in the list. If found the node containing the key is deleted.
{
    nodetype *temp = *head, *prev;
    if (temp != NULL && temp->info == x)
    {
        *head = temp->next;
        // free(temp);
        return temp;
    }
    while (temp != NULL && temp->info != x)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return temp;
    prev->next = temp->next;
    return temp;
}

void append(nodetype *head_1, nodetype *head_2) //  appends a list at the end of another list
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

void delete_n(int n, nodetype *head) // Delete the nth node in the list
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

int isSortedDescending(nodetype *head) // checks if the list is sorted in descending order
{
    if (head == NULL)
        return 1;
    for (nodetype *t = head; t->next != NULL; t = t->next)
        if (t->info < t->next->info)
            return 0;
    return 1;
}

int isSortedAscending(nodetype *head) // checks if the list is sorted in ascending order
{
    if (head == NULL)
        return 1;
    for (nodetype *t = head; t->next != NULL; t = t->next)
        if (t->info > t->next->info)
            return 0;
    return 1;
}

bool isOrdered(nodetype *head) // checks if the list is sorted in order
{
    if (isSortedAscending(head) || isSortedDescending(head))
    {
        return true;
    }
    return false;
}

// nodetype *merge(nodetype *h1, nodetype *h2)
// {
//     if (atend_l(h1))
//         return h2;
//     if (atend_l(h2))
//         return h1;
//     if (h1->info < h2->info)
//     {
//         h1->next = merge(h1->next, h2);
//         return h1;
//     }
//     else
//     {
//         h2->next = merge(h1, h2->next);
//         return h2;
//     }
// }

nodetype *mergeUtil(nodetype *h1, nodetype *h2)
{
    // if only one node in first list
    // simply point its head to second list
    if (!h1->next)
    {
        h1->next = h2;
        return h1;
    }

    // Initialize current and next pointers of
    // both lists
    nodetype *curr1 = h1, *next1 = h1->next;
    nodetype *curr2 = h2, *next2 = h2->next;

    while (next1 && curr2)
    {
        // if curr2 lies in between curr1 and next1
        // then do curr1->curr2->next1
        if ((curr2->info) >= (curr1->info) && (curr2->info) <= (next1->info))
        {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;

            // now let curr1 and curr2 to point
            // to their immediate next pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // if more nodes in first list
            if (next1->next)
            {
                next1 = next1->next;
                curr1 = curr1->next;
            }

            // else point the last node of first list
            // to the remaining nodes of second list
            else
            {
                next1->next = curr2;
                return h1;
            }
        }
    }
    return h1;
}

// Merges two given lists in-place. This function
// mainly compares head nodes and calls mergeUtil()
nodetype *merge(nodetype *h1, nodetype *h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;

    // start with the linked list
    // whose head data is the least
    if (h1->info < h2->info)
        return mergeUtil(h1, h2);
    else
        return mergeUtil(h2, h1);
}

void insert_mid(nodetype *new_data, nodetype **head, int n) //  inserts a new node after specified node
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

void insert_end(nodetype *new_data, nodetype **head) // nserts a node at the end of a list
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

void removeDuplicates_unsorted(nodetype *head) //   removes duplicates from a unsorted list
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
                // find_and_delete(&head, dup->info);
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void removeDuplicates_sorted(nodetype *head) //     removes duplicates from a sorted list
{

    nodetype *current = head;

    nodetype *next_next;

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

void swap(int *a, int *b) //    util function to swap two variables
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void pairWiseSwap(nodetype *head) // pairwise swaps the elements of a list
{
    nodetype *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        swap(&temp->info, &temp->next->info);
        temp = temp->next->next;
    }
}

void moveToFront(nodetype **head) //    moves the last element to the front of the list
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

void deleteAlt(nodetype *head) //   delete alternate nodes of a list
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

void rotate(nodetype **head, int k) //  rotates a list about a given pivot
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

void deleteList(nodetype **head) // deletes a list from memory
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

void reverse(nodetype **head) // reverses a list
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

void swap_node(nodetype *a, nodetype *b) // swaps the info of two nodes
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

void bubbleSort(nodetype *head) //  uses bubble sort technique to sort the list
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
                swap_node(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


//driver function
int main()
{
    nodetype *head_1 = init_l();
    nodetype *head_2 = init_l();

    insert_front(createnode(60), &head_1);
    // insert_front(createnode(30), &head_1);
    insert_front(createnode(40), &head_1);
    // insert_front(createnode(50), &head_1);
    insert_front(createnode(20), &head_1);
    // insert_front(createnode(10), &head_1);

    insert_front(createnode(6), &head_2);
    insert_front(createnode(4), &head_2);
    insert_front(createnode(2), &head_2);

    char ch = 'n';
    int choice;
    int internal_choice;
    printf("\n1. Print List.\n2. Find the size of a list in number of nodes.\n3. Check whether two lists are equal.\n4. Search for a key.\n5. Append a list at the end of another list.\n6. Delete node.\n7. Check whether a list is ordered.\n8. Merge two sorted lists.\n9. Insert node.\n10. Remove duplicates from a linked list.\n11. Swap elements of a list pairwise.\n12. Move last element to front of a list.\n13. Delete alternate nodes of a list.\n14. Rotate a list.\n15. Delete a list.\n16. Reverse a list.\n17. Sort a list.\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("1. Print in same order.\n2. Print in reverse order.\n");
            printf("\nEnter your choice: ");
            scanf("%d", &internal_choice);
            switch (internal_choice)
            {
            case 1:
                printList(head_1);
                break;
            case 2:
                printReverse(head_1);
                break;
            }

            break;
        }

        case 2:
        {
            printf("Size of the list is : %d", size_l(head_1));
            break;
        }

        case 3:
        {
            if (isEqual(head_1, head_2))
            {
                printf("Lists are equal.");
            }
            else
            {
                printf("Lists are not equal.");
            }
            break;
        }

        case 4:
        {
            printf("Enter key to search: ");
            int x;
            scanf("%d", &x);
            if (find(head_1, x) != NULL)
            {
                printf("Found.");
            }
            else
            {
                printf("Not found.");
            }

            break;
        }

        case 5:
        {
            append(head_1, head_2);
            printList(head_1);
            break;
        }

        case 6:
        {
            printf("1. Delete the nth node.\n2. Delete the last node.\n3. Delete the first node.\n");
            printf("\nEnter your choice: ");
            scanf("%d", &internal_choice);
            switch (internal_choice)
            {
            case 1:
            {
                delete_n(1, head_1);
                printList(head_1);
                break;
            }

            case 2:
            {
                int size = size_l(head_1) - 1;
                delete_n(size, head_1);
                printList(head_1);
                break;
            }

            case 3:
            {
                delete_front(&head_1);
                printList(head_1);
                break;
            }
            }

            break;
        }

        case 7:
        {
            if (isOrdered(head_1))
            {
                printf("The list is ordered.\n");
                if (isSortedAscending(head_1))
                {
                    printf("Nature of order: Ascending.");
                }
                else
                {
                    printf("Nature of order: Descending.");
                }
            }
            else
            {
                printf("The list is not ordered.");
            }
            break;
        }

        case 8:
        {
            head_1 = merge(head_1, head_2);
            printList(head_1);
            break;
        }

        case 9:
        {
            printf("1. Insert node in the beginning.\n2. Insert node before a specific node.\n3. Insert node at the end of the list.\n");
            printf("\nEnter your choice: ");
            scanf("%d", &internal_choice);
            switch (internal_choice)
            {
            case 1:
            {
                insert_front(createnode(40), &head_1);
                printList(head_1);
                break;
            }

            case 2:
            {

                insert_mid(createnode(15), &head_1, 20);
                printList(head_1);
                break;
            }

            case 3:
            {
                insert_end(createnode(40), &head_1);
                printList(head_1);
                break;
            }
            }

            break;
        }

        case 10:
        {
            if (isSortedAscending(head_1))
            {
                removeDuplicates_sorted(head_1);
                printList(head_1);
            }
            else
            {
                removeDuplicates_unsorted(head_1);
                printList(head_1);
            }
            break;
        }

        case 11:
        {
            pairWiseSwap(head_1);
            printList(head_1);
            break;
        }

        case 12:
        {
            moveToFront(&head_1);
            printList(head_1);
            break;
        }

        case 13:
        {
            deleteAlt(head_1);
            printList(head_1);
            break;
        }

        case 14:
        {
            printf("Enter the position of the pivot node: ");
            int k;
            scanf("%d", &k);
            if (k > size_l(head_1))
            {
                printf("Out of bounds.");
            }
            else
            {
                rotate(&head_1, k);
                printList(head_1);
            }
            break;
        }

        case 15:
        {
            deleteList(&head_1);
            printList(head_1);
            break;
        }

        case 16:
        {
            reverse(&head_1);
            printList(head_1);
            break;
        }

        case 17:
        {
            bubbleSort(head_1);
            printList(head_1);
            break;
        }
        }

        printf("\nDo you want to continue?\t(y/n): ");
        scanf("%s", &ch);
    } while (ch == 'y');
}
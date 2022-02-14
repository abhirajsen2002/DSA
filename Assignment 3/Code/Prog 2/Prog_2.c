#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

void Build_list(nodetype **head, int x) //  build list in order they are read in
{
    nodetype *temp = createnode(x);
    nodetype *last = *head;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
}

void Build_list_reverse(nodetype **head, int x) //   build list in order they are read in
{
    nodetype *n = createnode(x);
    insert_front(n, head);
}

int main()
{
    nodetype *head_st = init_l();
    nodetype *head_rv = init_l();
    FILE *in_file;
    in_file = fopen("numbers.txt", "r");
    if (in_file == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
        int x;
        while (!feof(in_file))
        {
            fscanf(in_file, "%d", &x);
            // printf("X = %d", x);
            Build_list(&head_st, x);
            Build_list_reverse(&head_rv, x);
        }
    }
    printf("In order: ");
    printList(head_st);
    printf("\nIn reverse order: ");
    printList(head_rv);
}
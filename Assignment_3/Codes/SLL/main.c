#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

int main()
{
    nodetype *head, *cur, *prev, *next, *target = NULL;
    head = init_l();
    char h = 'n';

    nodetype *head2 = init_l();

    int x = check_equal(&head, &head2);
    printf("%d", x);
    /*do
    {
        printf("1. empty_l(head) : boolean function to return true if list pointed to by head is empty\n2. atend_l(cur) : boolean function to return true if cur points to the last node in the list\n3. insert_front(target, head) : insert the node pointed to by target as the first node of the listpointed to by head\n4. insert_after(target, prev) : insert the node pointed to by target after the node pointed to by prev\n5. delete_front(head) : delete the first element of the list pointed to by head\n6. delete_after(prev) : delete the node after the one pointed to by prev\n7.Print");
        printf("\nEnter your choice : ");
        int ch;
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (empty_l(head))
            {
                printf("Empty.");
            }
            else
            {
                printf("Not Empty.");
            }
            break;
        case 2:
        {
            if (empty_l(head))
            {
                printf("Empty list.");
            }
            else
            {
                int x;
                printf("Enter the value of the node you want to check: ");
                scanf("%d", &x);
                //printf("here");
                cur = find(head, x);
                if (atend_l(cur))
                {
                    printf("At end.");
                }
                else
                {
                    printf("Not at end.");
                }
            }
            break;
        }
        case 3:
        {
            int x;
            printf("Enter the data for the new node: ");
            scanf("%d", &x);
            insert_front(createnode(x), &head);
            break;
        }
        case 4:
        {
            int x, y;
            printf("Enter the data for the new node: ");
            scanf("%d", &x);
            if (head == NULL)
            {
                insert_front(createnode(x), &head);
            }
            else
            {
                printf("Enter value node you want to enter after: ");
                scanf("%d", &y);
                prev = find(head, y);
                insert_after(createnode(x), prev);
            }
            break;
        }
        case 5:

            if (empty_l(head))
            {
                printf("Empty list.");
            }
            else
            {
                delete_front(&head);
            }
            break;
        case 6:
        {
            int y;
            printf("Enter value node you want to delete after: ");
            scanf("%d", &y);
            prev = find(head, y);
            delete_after(prev);
            break;
        }
        case 7:
            printList(head);
            break;
        default:
            printf("\nWrong Choice.");
        }
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &h);
    } while (h == 'y' || h == 'Y');*/
    return 0;
}
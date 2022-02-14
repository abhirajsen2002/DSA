#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *create_node(int val) // create a new node
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

int is_empty(node *list) // checks if the list is empty
{
    return (list == NULL);
}

node *init_l()// initialize a list
{
    return NULL;
}

void insert_front(node **list, node *n)// insert in the front of the list
{
    if (is_empty(*list))
        *list = n;
    else
    {
        (*list)->prev = n;
        n->next = *list;
        *list = n;
    }
}

void insert_end(node **list, node *n)// insert at the end of the list
{
    if (is_empty(*list))
        *list = n;
    else
    {
        node *cursor = *list;
        while (cursor->next != NULL)
            cursor = cursor->next;
        cursor->next = n;
        n->prev = cursor;
    }
}

void create_large_integer(node **list, char str[])// creating a large integer using ll
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int number = str[i] - 48;
        node *nd = create_node(number);
        insert_end(list, nd);
    }
}

node *get_tail(node *a)// returns the last node
{
    if (!is_empty(a))
    {
        while (a->next != NULL)
            a = a->next;
    }
    return a;
}

void display(node *list)//  print the list
{
    node *cursor = list;
    while (cursor != NULL)
    {
        if (cursor->data == 45)
            printf("-");
        else
            printf("%d", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}

node *add(node *a, node *b)//   adds two numbers
{
    int c = 0, s;
    node *a1 = get_tail(a);
    node *sum = init_l();
    node *b1 = get_tail(b);

    while (a1 != NULL || b1 != NULL)
    {
        if (a1 != NULL && b1 != NULL)
        {
            s = ((a1->data) + (b1->data) + c) % 10;
            c = ((a1->data) + (b1->data) + c) / 10;
            a1 = a1->prev;
            b1 = b1->prev;
        }
        else if (a1 == NULL && b1 != NULL)
        {
            s = ((b1->data) + c) % 10;
            c = ((b1->data) + c) / 10;
            b1 = b1->prev;
        }
        else if (a1 != NULL && b1 == NULL)
        {
            s = ((a1->data) + c) % 10;
            c = ((a1->data) + c) / 10;
            a1 = a1->prev;
        }
        insert_front(&sum, create_node(s));
    }
    if (c != 0)
        insert_front(&sum, create_node(c));
    return sum;
}

node *nines_complement(node *list)//    finds 9's complement
{
    node *cursor = list;
    while (cursor != NULL)
    {
        cursor->data = (9 - cursor->data);
        cursor = cursor->next;
    }
    return list;
}

node *sub(node *a, node *b)//   subtracts using 9's complement
{
    int c = 0, s;
    node *a1 = get_tail(a);
    node *sum = init_l();
    node *b1 = get_tail(nines_complement(b));

    while (a1 != NULL || b1 != NULL)
    {
        if (a1 != NULL && b1 != NULL)
        {
            s = ((a1->data) + (b1->data) + c) % 10;
            c = ((a1->data) + (b1->data) + c) / 10;
            a1 = a1->prev;
            b1 = b1->prev;
        }
        else if (a1 == NULL && b1 != NULL)
        {
            s = ((b1->data) + c) % 10;
            c = ((b1->data) + c) / 10;
            b1 = b1->prev;
        }
        else if (a1 != NULL && b1 == NULL)
        {
            s = ((a1->data) + 9 + c) % 10;
            c = ((a1->data) + 9 + c) / 10;
            a1 = a1->prev;
        }
        insert_front(&sum, create_node(s));
    }
    if (c == 0)
    {
        sum = nines_complement(sum);
        insert_front(&sum, create_node('-'));
    }
    else
        sum = add(sum, create_node(1));
    return sum;
}

node *mul(node *a, node *b)// multiply two huge numbers using LL
{
    int k = 0, i;
    node *tpro = init_l();
    node *b1 = get_tail(b);
    while (b1 != NULL)
    {
        int c = 0, s = 0;
        node *temp = get_tail(a);
        node *pro = init_l();
        while (temp != NULL)
        {
            s = ((temp->data) * (b1->data) + c) % 10;
            c = ((temp->data) * (b1->data) + c) / 10;
            insert_front(&pro, create_node(s));
            temp = temp->prev;
        }

        if (c != 0)
            insert_front(&pro, create_node(c));
        for (i = 0; i < k; i++)
            insert_end(&pro, create_node(0));

        tpro = add(tpro, pro);
        k++;
        b1 = b1->prev;
    }
    return tpro;
}

//Driver code
int main()
{
    node *number1 = init_l();
    node *number2 = init_l();
    create_large_integer(&number1, "123");
    create_large_integer(&number2, "9999");
    node *result = mul(number1, number2);
    printf("Product: ");
    display(result);
    node *sum = add(number1, number2);
    printf("Sum: ");
    display(sum);
    node *diff = sub(number1, number2);
    printf("Difference: ");
    display(diff);

    return 0;
}
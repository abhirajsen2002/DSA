#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define max 20
#define head_count 5

struct node
{
    int data;
    int next;
};

struct node s[max];
int head[head_count];
int list_no = 0;
int size = max; // contain no of available nodes
int available = 0;

// function prototypes
int check_size();
int is_valid(int); // return true if the list is valid
int size_of_a_list(int);
void new_list();
void display_one_list();
void display_all_list();
void display();
void display_size();
void insert_a_new_data();
void enter_before_head(int, int);
void enter_at_a_position(int, int);
void enter_at_end(int, int);
void delete_something();
void delete_first_element(int);
void delete_nth_element(int);
void delete_last_element(int);
void driver_size_of_a_list();
void compare_two_lists();
void merge_two_lists();
void reverse_print_a_list();

int main()
{

    register int i;

    // initially all are vacant
    for (i = 0; i < max - 1; i++)
    {
        s[i].next = i + 1;
    }
    s[max - 1].next = -1;

    printf("\n\n///***************MENU************///\n");
    printf("1. Enter a new list\n");
    printf("2. Enter a number in a particular list\n");
    printf("3. display\n");
    printf("4. delete\n");
    printf("5. display size of a list\n");
    printf("6. compare two lists\n");
    printf("7. merge two lists\n");
    printf("8.print a list in reverse order\n");
    printf("10. display max no of element you can enter\n");
    printf("11. exit\n");
    printf("**************************************\n\n");

    while (1)
    {

        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            new_list();
            break;
        case 2:
            insert_a_new_data();
            break;
        case 3:
            display();
            break;
        case 4:
            delete_something();
            break;
        case 5:
            driver_size_of_a_list();
            break;
        case 6:
            compare_two_lists();
            break;
        case 7:
            merge_two_lists();
            break;
        case 8:
            reverse_print_a_list();
            break;
        case 10:
            display_size();
            break;
        case 11:
            goto out;
            break;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
out:;

    return 0;
}

void driver_size_of_a_list()
{
    printf("Enter the list number: ");
    int choice;
    scanf("%d", &choice);
    int result = size_of_a_list(choice) - 1;
    printf("The size of the list is: %d\n", result);
}

int checK_size()
{
    if (size <= 0)
        return true;
    else
        return false;
}

int is_valid(int a)
{
    if (a > max)
        return false;
    else
        return true;
}
void new_list()
{
    if (list_no >= head_count || size <= 0)
    {
        printf("not enough space!!!\n\n");
        return;
    }
    else
    {
        int num;
        printf(" enter number of elements you want to enter: ");
        scanf("%d", &num);

        size -= num;
        if (size <= 0)
        {
            printf("no more space left!!!\n\n");
            size += num;
            return;
        }
        else
        {
            head[list_no] = available;
            list_no++;
            int i;
            printf("Enter %d numbers: ", num);
            for (i = 0; i < num; i++)
            {
                int temp;
                scanf("%d", &temp);
                s[available].data = temp;
                if (i != num - 1)
                    available = s[available].next;
                if (i == num - 1)
                {
                    int papa = s[available].next;
                    s[available].next = -1;
                    available = papa;
                }
            }
        }
    }
}

void display_one_list()
{
    printf("Enter which list you want to display: ");
    int a;
    scanf("%d", &a);
    a--;
    int index = head[a];
    printf("\nlist is: ");

    while (s[index].next != -1)
    {
        printf(" %d ->", s[index].data);
        index = s[index].next;
    }

    if (s[index].next == -1)
        printf(" %d-> NULL\n\n", s[index].data);
}

void display_all_list()
{
    int temp = list_no;
    int a = 0;
    while (temp--)
    {
        int index = head[a];
        printf("list no %d: ", ++a);
        while (s[index].next != -1)
        {
            printf(" %d ->", s[index].data);
            index = s[index].next;
        }
        if (s[index].next == -1)
            printf(" %d-> NULL\n", s[index].data);
    }
}

void display()
{
    printf("\n1. display only one list");
    printf("\n2. display all list\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        display_one_list();
        break;
    case 2:
        display_all_list();
        break;
    default:
        printf("invaiid entry:(\n");
        break;
    }
}

void display_size()
{
    printf("number of element left: %d\n", size);
}

void insert_a_new_data()
{
    printf("Enter the number of list: ");
    int a;
    scanf("%d", &a);
    a--;

    if (checK_size())
    {
        printf("NOT ENOUGH MEMORY!!!\n");
        return;
    }
    size--;
    printf("Enter the data: ");
    int datam;
    scanf("%d", &datam);

    printf("\n1. enter data before 1st number\n");
    printf("2. enter data at a particular positon\n");
    printf("3. enter data at the end\n\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        enter_before_head(datam, a);
        break;
    case 2:
        enter_at_a_position(datam, a);
        break;
    case 3:
        enter_at_end(datam, a);
        break;
    default:
        printf("!!INVALID CHOICE!! :( \n");
        return;
    }
}

void enter_before_head(int datam, int a) // a contains the head position of the list
{
    int temp;
    s[available].data = datam;
    temp = s[available].next;
    s[available].next = head[a];
    head[a] = available;
    available = temp;
}

void enter_at_a_position(int datam, int a)
{
    printf("enter the position: ");
    int pos;
    scanf("%d", &pos);

    int temp = s[head[a]].next;

    int i;
    for (i = 1; i < pos - 1; i++)
    {
        temp = s[temp].next;
    }
    int store, temp1;
    s[available].data = datam;
    store = s[available].next;
    temp1 = s[temp].next;
    s[temp].next = available;
    s[available].next = temp1;
    available = store;
}

void enter_at_end(int datam, int a)
{
    int temp = s[head[a]].next;
    while (s[temp].next != -1)
    {
        temp = s[temp].next;
    }

    s[available].data = datam;
    int store = s[available].next;
    s[available].next = -1;
    s[temp].next = available;
    available = store;
}

void delete_something()
{
    if (size == max)
    {
        printf("NO ENTRY RECORDED!!\n");
        printf("you can't delete anything!!\n");
        return;
    }
    printf("Enter the list number: ");
    int num;
    scanf("%d", &num);
    num--;

    printf("\n1. delete first element\n");
    printf("2. delete a particular element\n");
    printf("3. delete last element\n");
    // printf("4. delete an entire list\n\n");

    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        delete_first_element(num);
        break;
    case 2:
        delete_nth_element(num);
        break;
    case 3:
        delete_last_element(num);
        break;
        // case 4: delete_entire_list(num);break;
    default:
        printf("INVALID OPERATION :(\n");
        return;
    }
}

void delete_first_element(int a)
{
    s[head[a]].data = '\0';
    int store = s[head[a]].next;
    s[head[a]].next = available;
    available = head[a];
    head[a] = store;
    size++;
}

void delete_nth_element(int a)
{
    printf("Enter the number of the element you want to delete: ");
    int n;
    scanf("%d", &n);

    int start = head[a];
    int i;
    int temp = s[start].next;
    for (i = 1; i < n - 1; i++)
    {
        temp = s[temp].next;
    }

    int temp1 = s[temp].next; // ager tai store korte hobe
    size++;
    s[temp].next = available;
    available = temp;
    for (i = 1;; i++)
    {
        if (s[start].next == temp)
        {
            s[start].next = temp1;
            break;
        }
        else
        {
            start = s[start].next;
        }
    }
}

void delete_last_element(int a)
{
    int store = s[head[a]].next;
    while (s[s[store].next].next == -1)
    {
        store = s[store].next;
    }
    s[s[store].next].next = available;
    available = s[store].next;
    s[store].next = -1;
    size++;
}

int size_of_a_list(int choice)
{
    choice--;
    int count = 1;
    int store = s[head[choice]].next;
    while (s[store].next != -1)
    {
        count++;
        store = s[store].next;
    }
    count++;
    return count;
}

void compare_two_lists()
{
    printf("Enter the number of first list: ");
    int first;
    scanf("%d", &first);
    if (!is_valid(first))
    {
        printf("INvalid list!!\n");
        return;
    }

    printf("Enter the number of second list: ");
    int second;
    scanf("%d", &second);
    if (!is_valid(second))
    {
        printf("INvalid list!!\n");
        return;
    }

    int len1 = size_of_a_list(first);
    int len2 = size_of_a_list(second);
    int count = 0;

    if (len1 != len2)
    {
        printf("Two lists are not equal\n");
        return;
    }
    else
    {
        int start1 = head[first];
        int start2 = head[second];
        while (s[start1].next != -1 && s[start2].next != -1)
        {
            if (s[start1].data != s[start2].data)
            {
                printf("Two lists are not equal:(\n");
                count = 1;
                break;
            }
            else
            {
                start1 = s[start1].next;
                start2 = s[start2].next;
            }
        }
        if (count == 0)
            printf("the two lists are equal!!\n");
    }
}

void merge_two_lists()
{
    printf("second list will get appended with first list\n");
    printf("Enter the number of first list: ");
    int first;
    scanf("%d", &first);
    if (!is_valid(first))
    {
        printf("INvalid list!!\n");
        return;
    }

    printf("Enter the number of second list: ");
    int second;
    scanf("%d", &second);
    if (!is_valid(second))
    {
        printf("INvalid list!!\n");
        return;
    }
    first--;
    second--;

    int i;
    int store = head[first];
    while (s[store].next != -1)
    {
        store = s[store].next;
    }
    s[store].next = head[second];
    // update head array
    second++;
    while (second < max)
    {
        head[second - 1] = head[second];
        second++;
    }
}

void reverse_print_a_list()
{
    printf("Enter the number of the list: ");
    int choice;
    scanf("%d", &choice);
    choice--;
    int len = size_of_a_list(choice);
    int temp[len];
    int i = 0;
    int start = head[choice];
    while (s[start].next != -1)
    {
        temp[len - i - 1] = s[start].data;
        start = s[start].next;
        i++;
    }
    s[start].data = temp[0];
    printf("the list in reverse order: ");
    for (i = 0; i < len; i++)
    {
        printf("%d->", temp[i]);
    }
    printf("NULL\n");
}

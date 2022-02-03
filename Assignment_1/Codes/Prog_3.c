#include <stdio.h>
#include <stdlib.h>

int fill_array_int(int *arr, int limit)
{
    printf("Enter the elements of the array : \n");
    for (int i = 0; i < limit; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int fill_array_float(float *x, int limit)
{
    printf("Enter the elements of the array : \n");
    for (int i = 0; i < limit; i++)
    {
        scanf("%f", &x[i]);
    }
}

int lin_search_int(int *arr, int search_term, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (*(arr + i) == search_term)
            return 1;
    }
    return 0;
}

int binary_search_int(int *arr, int search_term, int len)
{
    int ll = 0;
    int ul = len - 1;
    while (ul >= ll)
    {
        int mid = (ll + ul) / 2;
        if (*(arr + mid) == search_term)
            return 1;
        else if (*(arr + mid) < search_term)
        {
            ll = mid + 1;
        }
        else
        {
            ul = mid - 1;
        }
    }
    return 0;
}

int lin_search_float(float *arr, float search_term, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (*(arr + i) == search_term)
            return 1;
    }
    return 0;
}

int binary_search_float(float *arr, float search_term, int len)
{
    int ll = 0;
    int ul = len - 1;
    while (ul >= ll)
    {
        int mid = (ll + ul) / 2;
        if (*(arr + mid) == search_term)
            return 1;
        else if (*(arr + mid) < search_term)
        {
            ll = mid + 1;
        }
        else
        {
            ul = mid - 1;
        }
    }
    return 0;
}

int main()
{
    printf("Press 1 liner search.\nPress 2 for binary search.\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Press 1 to use integer input.\nPress 2 to use float input.\n");
        int input_choice;
        scanf("%d", &input_choice);
        switch (input_choice)
        {
        case 1:
        {
            printf("Enter the limit of the array : ");
            int limit;
            scanf("%d", &limit);
            int *x = (int *)malloc(limit * sizeof(int));
            fill_array_int(x, limit);
            printf("Enter the search term : ");
            int search_term;
            scanf("%d", &search_term);
            int result = lin_search_int(x, search_term, limit);
            if (result == 1)
                printf("\nFound!!");
            else
                printf("\nNot found!!");
            break;
        }
        case 2:
        {
            printf("Enter the limit of the array : ");
            int limit;
            scanf("%d", &limit);
            float *x = (float *)malloc(limit * sizeof(float));
            fill_array_float(x, limit);
            printf("Enter the search term : ");
            float search_term;
            scanf("%f", &search_term);
            int result = lin_search_float(x, search_term, limit);
            if (result == 1)
                printf("\nFound!!");
            else
                printf("\nNot found!!");
            break;
        }
        }
        break;
    case 2:
    {
        printf("Press 1 to use integer input.\nPress 2 to use float input.\n");
        int input_choice;
        scanf("%d", &input_choice);
        switch (input_choice)
        {
        case 1:
        {
            printf("Enter the limit of the array : ");
            int limit;
            scanf("%d", &limit);
            int *x = (int *)malloc(limit * sizeof(int));
            fill_array_int(x, limit);
            printf("Enter the search term : ");
            int search_term;
            scanf("%d", &search_term);
            int result = binary_search_int(x, search_term, limit);
            if (result == 1)
                printf("\nFound!!");
            else
                printf("\nNot found!!");
            break;
        }
        case 2:
        {
            printf("Enter the limit of the array : ");
            int limit;
            scanf("%d", &limit);
            float *x = (float *)malloc(limit * sizeof(float));
            fill_array_float(x, limit);
            printf("Enter the search term : ");
            float search_term;
            scanf("%f", &search_term);
            int result = binary_search_float(x, search_term, limit);
            if (result == 1)
                printf("\nFound!!");
            else
                printf("\nNot found!!");
            break;
        }
        }
        break;
    }
    }
}

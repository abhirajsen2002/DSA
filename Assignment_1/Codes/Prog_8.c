#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

void Sum(int a[], int b[], int n, int m)
{
    int sum[n];
    int i = n - 1, j = m - 1, k = n - 1;
    int c = 0, s = 0;
    while (j >= 0)
    {
        s = a[i] + b[j] + c;
        sum[k] = (s % 10);
        c = s / 10;
        k--;
        i--;
        j--;
    }
    while (i >= 0)
    {
        s = a[i] + c;
        sum[k] = (s % 10);
        c = s / 10;
        i--;
        k--;
    }
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d", sum[i]);
    }
}

void main()
{
    char str[100], newstr[6], final_str[100] = "";
    int ascval;
    int count = 0;
    char temp;
    printf("Enter name : ");
    scanf("%c", temp);
    scanf("%100[^\n]%*c", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            int num = (int)str[i];
            if (num < 100)
            {
                count = count + 2;
            }
            if (num > 100)
            {
                count = count + 3;
            }
        }
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            //printf("%s\n", final_str);
            ascval = str[i];
            sprintf(newstr, "%d", ascval);
            strcat(final_str, newstr);
        }
    }
    int mid = ceil(count / 2.0);
    int half_1[mid];
    int half_2[mid];
    int k1 = 0, k2 = 0;
    for (int i = 0; i < count; i++)
    {
        if (i < mid)
        {
            half_1[k1] = (final_str[i] - 48);
            k1++;
        }

        else
        {
            half_2[k2] = (final_str[i] - 48);
            k2++;
        }
    }
    printf("\n");
    printf("Entire string converted to ascii : %s\n", final_str);
    printf("First half : ");

    for (int i = 0; i < mid; i++)
    {
        printf("%d", half_1[i]);
    }
    printf("\nSecond half : ");
    for (int i = 0; i < count - mid; i++)
    {
        printf("%d", half_2[i]);
    }
    printf("\nSum of the halves : ");
    Sum(half_1, half_2, mid, count - mid);
}
#include <stdio.h>
#include <stdlib.h>

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
    printf("\n");
}

void Diff(int a[], int b[], int n, int m)
{
    int i = n - 1;
    int j = m - 1;
    int k = n - 1;
    int d = 0;
    int c = 0;
    int diff[n];
    while (j >= 0)
    {
        d = a[i] - b[j] - c;
        if (d < 0)
        {
            d = d + 10;
            c = 1;
        }
        else
        {
            c = 0;
        }

        diff[k] = d;

        i--;
        j--;
        k--;
    }

    while (i >= 0)
    {

        d = a[i] - c;
        if (d < 0)
        {
            d = d + 10;
            c = 1;
        }
        else
        {
            c = 0;
        }

        diff[k] = d;

        i--;
        k--;
    }

    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d", diff[i]);
    }
    printf("\n");
}

void mult(int a[], int b[], int n, int m)
{
    int i = n - 1;
    int j = m - 1;
    
}

int main()
{
    int a[] = {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int b[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n = 60;
    int m = 55;
    Sum(a, b, n, m);
    Diff(a, b, n, m);
}

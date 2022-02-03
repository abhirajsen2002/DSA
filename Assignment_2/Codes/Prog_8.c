#include <stdio.h>

int isSorted(int *a, int n)
{
    // array with 1 or 2 elements are always sorted
    if (n == 1 || n == 2)
        return 1;

    for (int i = 2; i < n; i++)
        // check three consecutive elements and check if the 3
        // are in a particular order: either increasing or decreasing
        if ((a[i] - a[i - 1]) * (a[i - 1] - a[i - 2]) < 0)
            return 0;
    return 1;
}

int main()
{
    int a[100], n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    if (n > 0)
    {
        printf("Enter elements of the array: ");
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if (isSorted(a, n))
        {
            if (a[0] == a[n-1])//If the array is sorted and the last element matches the first element, it means that all the elements are same
                printf("No variation in elements.");
            else
            {
                printf("Array is sorted.\n");
                if (a[0] > a[n - 1])
                {
                    printf("Sorting type: Descending.\n");
                }
                else
                {
                    printf("Sorting type: Ascending.\n");
                }
            }
        }
        else
            printf("Array is not sorted.\n");
    }
    else
        printf("Number of terms must be positive.\n");
    return 0;
}
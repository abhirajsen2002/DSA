#include <stdio.h>
#include <string.h>

int main()
{
    char name[31];

    printf("Enter name: ");
    scanf(" %[^\n]", name);
    char large_int[62] = "";

    for (int i = 0; name[i] != '\0'; i++)
    {
        char temp[4];
        sprintf(temp, "%d", (int)name[i]);

        strcat(large_int, temp);
    }

    printf("\nConverted integer = %s", large_int);

    int len = strlen(large_int);
    int left_half[31], right_half[31];
    int p = 0, q = 0;
    for (int i = 0; i < len; i++)
        if (i < len / 2)
            left_half[p++] = large_int[i] - '0';
        else
            right_half[q++] = large_int[i] - '0';

    int sum[32], reverse_sum[32];
    int k = 0, carry = 0;
    while (p && q)
    {
        int s = left_half[--p] + right_half[--q] + carry;
        reverse_sum[k++] = s % 10;
        carry = s / 10;
    }

    while (q)
    {
        int s = right_half[--q] + carry;
        reverse_sum[k++] = s % 10;
        carry = s / 10;
    }

    if (carry)
        reverse_sum[k++] = carry;

    printf("\nSum of two halves = ");
    for (int i = 0; i < k; i++)
    {
        sum[i] = reverse_sum[k - i - 1];
        printf("%d", sum[i]);
    }
    int P;
    printf("\nEnter a 4-digit prime number: ");
    scanf("%d", &P);
    int x = 1, rem = 0;

    // Apply modular multiplication to x and modular addition to rem
    for (int i = 0; i < k; i++)
    {
        rem += (reverse_sum[i] * x) % P;
        rem %= P;
        x = (x * 10) % P;
    }

    printf("Remainder when divided by %d = %d\n", P, rem);
    return 0;
}

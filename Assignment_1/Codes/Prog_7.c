#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 30

long random(long, long);
int prime_check(long a) // checks if a is prime
{
    int i;
    for (i = 2; i <= a / 2; i++)
        if (a % i == 0)
            return 0;
    return 1;
}
int main()
{
    long L[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        L[i] = random(10000, 100000); // Generating a large number
    }
    int x = 0;
    while (x != 8)
    {
        printf("\n\nIteration No. : %d\n\n", (x + 1));
        x++;

        srand(time(NULL));
        long P;
        printf("Enter PRIME number : ");
        scanf("%ld", &P);
        if (!prime_check(P))
        {
            printf("Wrong input!");
        }
        else
        {
            long R[ARR_SIZE];
            int i;
            printf("Sr. no \t\t\t Li \t\t\t Ri \n");
            for (i = 0; i < ARR_SIZE; i++)
            {
                R[i] = L[i] % P;

                printf("%d \t\t\t %ld \t\t\t %ld \n", i + 1, L[i], R[i]);
            }
        }
    }
}
long random(long a, long b)
{

    return a + rand() % (b - a);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long random(long, long);
int prime_check(long a) //checks if a is prime
{
    int i;
    for (i = 2; i <= a / 2; i++)
        if (a % i == 0)
            return 0;
    return 1;
}
int main()
{
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
        long L[100];
        long R[100];
        int i;
        printf("Sr. no \t\t\t Li \t\t\t Ri \n");
        for (i = 0; i < 100; i++)
        {
            L[i] = random(10000, 100000); //generating a large number
            R[i] = L[i] % P;

            printf("%d \t\t\t %ld \t\t\t %ld \n", i + 1, L[i], R[i]);
        }
        return 0;
    }
}
long random(long a, long b)
{

    return a + rand() % (b - a);
}
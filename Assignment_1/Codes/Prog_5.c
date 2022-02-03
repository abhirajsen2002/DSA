#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LIMIT 100000

const char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int intN(int n)
{
    return rand() % n;
}

/**
 * Input: length of the random string [a-z0-9] to be generated
 */
char *randomString(int len)
{
    char *rstr = malloc((len + 1) * sizeof(char));
    int i;
    for (i = 0; i < len; i++)
    {
        rstr[i] = alphabet[intN(strlen(alphabet))];
    }
    rstr[len] = '\0';
    return rstr;
}

int count_duplicates(char *test[MAX_LIMIT])
{
    int count = 0;
    for (int i = 0; i < MAX_LIMIT; i++)
    {
        for (int j = i + 1; j < MAX_LIMIT; j++)
        {
            if (strcmp(test[i], test[j]) == 0)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    srand(time(NULL));
    char *test[MAX_LIMIT];
    FILE *fptr;
    fptr = fopen("C:\\Users\\Abhiraj Sen\\DSA\\Assignment_1\\Output\\Prog_5_Output.txt", "w");
    char *p;
    for (int i = 0; i < MAX_LIMIT; i++)
    {
        p = randomString(10);
        test[i] = p;
        fprintf(fptr, "%s\n", test[i]);
    }
    int count = count_duplicates(test);
    fprintf(fptr, "\nTotal number of strings :  %d", MAX_LIMIT);
    fprintf(fptr, "\nNumber of duplicates : %d", count);
}
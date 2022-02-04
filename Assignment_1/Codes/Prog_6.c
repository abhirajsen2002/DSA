#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sort(char *arr[50], int n)
{
    char temp[50];
    // Sorting strings using bubble sort
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
}

void display(char *arr[50], int wordcount)
{
    char max[50];
    char min[50];
    strcpy(max, arr[0]);
    int max_len = strlen(max);
    strcpy(min, arr[0]);
    int min_len = strlen(min);
    for (int i = 0; i < wordcount; i++)
    {
        if ((strcmp(arr[i], "") != 0) && (strcmp(arr[i], max) > 0))
        {
            strcpy(max, arr[i]);
            max_len = strlen(max);
        }
        if ((strcmp(arr[i], "") != 0) && (strcmp(arr[i], min) < 0))
        {
            strcpy(min, arr[i]);
            min_len = strlen(min);
        }
    }

    printf("%s is the largest name with %d letters.\n", max, max_len);
    printf("%s is the smallest name with %d letters.\n", min, min_len);
}
int main()
{
    FILE *fptr;
    fptr = fopen("C:\\Users\\Abhiraj Sen\\Year-2 Sem-1\\DSA\\Assignment_1\\Output\\Prog_6_Input.txt", "r");
    char word[50];
    char *arr_of_words[50];
    int wordcount = 0;
    while (fscanf(fptr, "%s", word) != EOF)
    {
        wordcount++;
    }
    for (int j = 0; j < wordcount; j++)
        *(arr_of_words + j) = (char *)malloc(50 * sizeof(int));
    fseek(fptr, 0, SEEK_SET);
    // free(arr_of_words);
    int i = 0;
    while (fscanf(fptr, "%s", word) != EOF)
    {
        strcpy(arr_of_words[i++], word);
    }
    display(arr_of_words, wordcount);

    sort(arr_of_words, wordcount);
    fptr = fopen("C:\\Users\\Abhiraj Sen\\Year-2 Sem-1\\DSA\\Assignment_1\\Output\\Prog_6_Output.txt", "w");
    for (int i = 0; i < wordcount; i++)
        fprintf(fptr, "%s\n", arr_of_words[i]);

    fclose(fptr);
}

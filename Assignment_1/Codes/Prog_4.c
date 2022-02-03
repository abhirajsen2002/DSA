#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LIMIT 100000
#define MAX_LIMIT 100000

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b; 
    *b = temp;
}

int generate_random(int random[]) //Generated using the Fisher-Yates Shuffle algorithm.
{
    srand(time(0));
    for(int i = 1; i <= MAX_LIMIT; i++)
    {
        random[i] = i;//Filling the array from 1 to MAX_LIMIT
    }
    for(int i = MAX_LIMIT-1; i > 0; i--)
    {
        int j = rand()%(MAX_LIMIT+1); //Picking a random number between the first and last index
        swap(&random[i], &random[j]); // Swapping it out with the last index
    }
}//Since we keep taking a random index, repetition is avoided

int return_Duplicates(int arr[])
{
    int noOfDuplicates=0;
    for(int i = 0; i < MAX_LIMIT; i++)
    {
        for(int j = i + 1; j < MAX_LIMIT; j++)
        {
            if(arr[i] == arr[j])
            {
                noOfDuplicates++;
            }
        }
    }
    return noOfDuplicates;
}

int print_array(int random[])
{
    generate_random(random);
    FILE *fptr;
    fptr = fopen("C:\\Users\\Abhiraj Sen\\DSA\\Assignment_1\\Output\\Prog_4_Output.txt", "w");
    for(int i = 0; i < MAX_LIMIT; i++)
    {
        fprintf(fptr,"%d\n",random[i]);
    }
    int noOfDuplicates = return_Duplicates(random);
    fprintf(fptr, "\nTotal number of elements : %d", MAX_LIMIT);
    fprintf(fptr, "\nNumber of duplicates = %d", noOfDuplicates);

}

int main()
{
    int random[MAX_LIMIT];
    print_array(random);
}
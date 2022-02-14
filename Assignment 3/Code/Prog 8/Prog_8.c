#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define maxCount 5
#define M 31
typedef struct Coordinates
{
    float x;
    float y;
    struct Coordinates *next;
} sPoint;

void foo(sPoint *head)
{

    {
        head->x = 0;
        head->y = 0;
    }
}

sPoint *init() //initializing a polygon
{
    printf("Initialisation of the polygon!!!\n");
    sPoint *head = (sPoint *)malloc(sizeof(sPoint));
    foo(head);
    // {
    //     head->x=rand()%M;
    //     head->y=rand()%M;
    // }
    head->next = NULL;
    return head;
}

void addPoint(sPoint *head) // adding point
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = (sPoint *)malloc(sizeof(sPoint));
    foo(head->next);
    head->next->next = NULL;
}

void takeInput(sPoint *head)
{
    // printf("Enter the coodinates of the vertices:\n");
    for (int i = 0; i < maxCount; i++, head = head->next)
        scanf(" %f%f", &(head->x), &(head->y));
}
float getSlope(float x1, float y1, float x2, float y2) // calculate slope using formula
{
    return (y2 - y1) / (x2 - x1);
}
float getDistance(float x1, float y1, float x2, float y2)// calculate distance using distance formula
{
    return sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
}
bool checkTouching(sPoint *head1, sPoint *head2)// chekcs if the polygons are touching each other
{
    for (int i = 0; i < maxCount; i++, head1 = head1->next)
    {
        float slope1 = getSlope(head1->x, head1->y, head1->next->x, head1->next->y);

        sPoint *temp = head2;
        for (int j = 0; j < maxCount; j++, temp = temp->next)
        {
            float slope2 = getSlope(head1->x, head1->y, temp->x, temp->y);
            if (slope1 == slope2)
            {
                float d = getDistance(head1->x, head1->y, head1->next->x, head1->next->y);
                float d1 = getDistance(head1->x, head1->y, temp->x, temp->y);
                float d2 = getDistance(head1->next->x, head1->next->y, temp->x, temp->y);
                if ((d1 + d2) == d)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// bool isIsolated(sPoint *head1, sPoint *head2, float *arr)
// {
//     float x1 = head1->x;
//     float y1 = head1->y;
//     float x2 = head2->x;
//     float y2 = head2->y;
//     float c = -1 * (arr[0] * x2 + arr[1] * y2 + arr[2]) / (pow(arr[0], 2) + pow(arr[1], 2));
//     float x3 = x2 + (c * arr[0]);
//     float y3 = y2 + (c * arr[1]);
//     float dd = getDistance(x3, y3, x1, y1);
//     float d = getDistance(head1->next->x, head1->next->y, x1, y1);
//     if ((dd / d) < 1)
//         return true;
//     else
//         return false;
// }

float computeResult(sPoint *head, float *arr)
{
    float sum = 0;
    float secArr[3] = {head->x, head->y, 1};
    for (int i = 0; i < 3; i++)
    {
        sum = sum + arr[i] * secArr[i];
    }
    return sum;
}
bool checkIntersection(sPoint *head1, sPoint *head2)// checks if the polygons are intetrsecting
{
    for (int i = 0; i < maxCount; i++, head1 = head1->next)
    {
        float slope = getSlope(head1->x, head1->y, head1->next->x, head1->next->y);
        float c = head1->y - (slope * head1->x);
        float arr[3] = {slope, -1, c};

        sPoint *temp = head2;
        for (int j = 0; j < maxCount; j++, temp = temp->next)
        {
            float sum1 = computeResult(temp, arr);
            float sum2 = computeResult(temp->next, arr);
            // second condition computing just for confirmation. Not Req.
            // float slope2 = getSlope(temp->x, temp->y, temp->next->x, temp->next->y);
            // float c2 = temp->y - (slope2 * temp->x);
            // float secArr[3] = {slope2, -1, c2};
            // float sum3 = computeResult(head1, secArr);
            // float sum4 = computeResult(head1->next, secArr);
            if (((sum1 * sum2) < 0))
            {
                return true;
            }
        }
    }
    return false;
}
void displayPolygon(sPoint *head)
{
    for (int i = 0; i < maxCount; i++, head = head->next)
        printf("(%.2f,%.2f)\t", head->x, head->y);
    printf("\n");
}

//driver code
int main(int argc, char **argv)
{
    system("cls");
    srand(time(NULL));
    sPoint *head1 = init();
    sPoint *head2 = init();
    for (int i = 0; i < maxCount - 1; i++)
    {
        addPoint(head1);
        addPoint(head2);
    }
    sPoint *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head1;
    temp = head2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;

    // displayPolygon(head1);
    // displayPolygon(head2);
    printf("Enter the coodinates of the vertices for 1st pentagon:\n");
    takeInput(head1);
    printf("Enter the coodinates of the vertices for 2nd pentagon:\n");
    takeInput(head2);
    displayPolygon(head1);
    displayPolygon(head2);
    bool condition = checkTouching(head1, head2);
    if (condition == true)
    {
        printf("The polygons touch each other!!!\n");
    }
    else
    {
        printf("The polygons do not touch each other!!!\n");
        bool conditionSec = checkIntersection(head1, head2);
        if (conditionSec == true)
        {
            printf("The polygons intersect each other!!!\n");
        }
        else
        {
            printf("The polygons do not intersect each other!!!\n");
        }
    }

    return 0;
}
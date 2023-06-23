/*****************************************************************************
 File name: draft.c
 Description: Sort the array using the bubbling sort algorithm and print it
 Author: Ming
 Date: April 17, 2023
 *****************************************************************************/

#include <stdio.h>

#define COUNT 10 // The array has 10 elements

void *myBubbling(int *, int); // Pass in an integer array and length
void *myPrintf(int *, int);   // Pass in an integer array and length

/*****************************************
 Define arrays and get inputs
 call sort and print array functions
 *****************************************/
void main()
{
    int arr[COUNT] = {0};
    void *(*my[3])(int *, int);
    void *(*myp)(int *, int); 
    myp = myPrintf;
    my[0] = myp;
    my[1] = myBubbling;
    printf("Please enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) // Loop 10 times to get parameters from the terminal
    {
        scanf("%d", arr + i);
    }
    printf("Before sorting:\n");
    (*(my[0]))(arr, COUNT);
    (my[1])(arr, COUNT); // Call the sort function
    printf("After sorting:\n");
    (*myp)(arr, COUNT);
}

/*****************************************
 Bubble sorts the incoming array
 *****************************************/
void *myBubbling(int *a, int len)
{
    int tem = 0;
    for (int i = 1; i < len; i++)         // The outer layer circulates a total of 9 times
        for (int j = 0; j < len - i; j++) // The inner layer circulates 9 times and subtracts 1 successively
        {
            if (a[j] > a[j + 1]) // If the front side is larger than the back side
            {
                tem = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tem;
            }
        }
}

/*****************************************
 Prints the incoming array
 *****************************************/
void *myPrintf(int *arr, int len)
{
    for (int i = 0; i < len; i++) // Loop 10 times to print array elements
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

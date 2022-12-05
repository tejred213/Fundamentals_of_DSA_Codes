// FAQ

/*
 *C program to sort height(in cm) in ascending order using Bubble sort
 *and print both the given and the sorted array
*/
#include <stdio.h>
#define MAXSIZE 10
 
void main()
{
    int array[MAXSIZE];
    int i, j, num, temp;
 
    printf("Enter the number of heights to be sorted \n");
    scanf("%d", &num);
    printf("Enter the elements one by one \n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Input array is \n");
    for (i = 0; i < num; i++)
    {
        printf("%d\n", array[i]);
    }
    /*   Bubble sorting begins */
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < (num - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];//Time Complexity: O(N2)
                array[j + 1] = temp;
            }
        }
    }
    printf("Sorted array is...\n");
    for (i = 0; i < num; i++)
    {
        printf("%d\n", array[i]);
    }
}

// This algorithm has a worst-case time complexity of O(n2). The bubble sort has a space complexity of O(1). 
//The number of swaps in bubble sort equals the number of inversion pairs in the given array. 
//When the array elements are few and the array is nearly sorted, bubble sort is effective and efficient

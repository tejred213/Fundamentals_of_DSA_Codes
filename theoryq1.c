#include <stdio.h>

int getCeilingValue(int *arr, int size, int num)
{
    if (num <= arr[0])
    {
        return arr[0];
    }

    if (num > arr[size - 1])
    {
        return -1;
    }

    int i;
    for (i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            return arr[i];
        }

        if (arr[i] < num && arr[i + 1] > num)
        {
            return arr[i + 1];
        }
    }
}

int main()
{
    int givenArray[10] = {1, 3, 5, 7, 9, 11, 14, 18, 22, 33};
    int givenNum;
printf("Enter a number to find ceil value : ");
    scanf("%d", &givenNum);

    int ceil = getCeilingValue(givenArray, 10, givenNum);

    if (ceil == -1)
    {
        printf("Ceil value not found.");
    }
    else
    {
        printf("Ceil value : %d\n", ceil);
    }
    return 0;
}
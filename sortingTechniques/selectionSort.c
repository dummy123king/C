#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void printArray(int *arr, int len)
{
    printf("[");
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

void selectionSort(int *arr, int len)
{
    int minIndex;

    for (int i = 0; i < len - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int arr[] = {3, 3, 12, 5, 7, 0, 2};

    int len = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, len);
    selectionSort(arr, len);
    printArray(arr, len);
}
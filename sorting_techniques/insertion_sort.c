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

void insertionSort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while ((key < arr[j]) && j >= 0 )
        {
            arr[j + 1 ] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {3, 3, 12, 5, 7, 0, 2};
    int len = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, len);
    insertionSort(arr, len);
    printArray(arr, len);

}
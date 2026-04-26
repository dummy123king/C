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

void  bubbleSort(int *arr, int len)
{
    bool isSwapped = false;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 -i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = true;
            }
        }
        if (isSwapped != true)
        {
            break;
        }
    }        
}

int main()
{
    int arr[] = {3, 3, 12, 5, 7, 0, 2};

    int len = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, len);
    bubbleSort(arr, len);
    printArray(arr, len);

}
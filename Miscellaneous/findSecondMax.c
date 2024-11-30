#include <stdio.h>

int secondMax(int *arr, int len)
{
    int max1 = arr[0];
    int max2 = arr[1];

    if (max2 > max1)
    {
        int temp = max1;
        max1 = max2;
        max2 = temp;
    }

    for (int i = 2; i < len; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        
        else if (arr[i] > max2 && arr[i] != max1)
        {
            max2 = arr[i];
        }
    }
    return max2;
}

int main()
{
    int arr[10] = {1, -10, 5, 333, 999, 11, 888, 555, 999, 100};
    int len = sizeof(arr) / sizeof(arr[1]);
    printf("Second max = %d\n", secondMax(arr, len));
    return 0;
}

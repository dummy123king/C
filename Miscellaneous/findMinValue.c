#include <stdio.h>
#include <stdlib.h>

void printArray(int *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", ptr[i]);  // Print each element of the array
    }
    printf("\n");  // Print newline character after printing array elements
}

int findMinValue(int *ptr, int len)
{
    int minValue = ptr[0];  // Initialize minValue with the first element of the array
    for (int i = 1; i < len; i++)
    {
        if (ptr[i] < minValue)
        {
            minValue = ptr[i];  // Update minValue if current element is smaller than minValue
        }
    }
    return minValue;  // Return the minimum value found in the array
}

int main(int argc, char **argv)
{
    int minValue = 0;  // Variable to store the minimum value in the array
    int arr[10] = {1, 2, 5, 6, 7, 8, 9, 0, 88, -11};  // Array containing integer values
    
    int len =  sizeof(arr)/sizeof(arr[0]);  // Calculate the length of the array

    printArray(arr, len);  // Print the elements of the array
    minValue = findMinValue(arr, len);  // Find the minimum value in the array
    printf("Min value is : %d\n", minValue);  // Print the minimum value
    
    return 0;  // Exit the program
}
/*
Expected Output:
1, 2, 5, 6, 7, 8, 9, 0, 88, -11, 
Min value is : -11
*/

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

int findMaxValue(int *ptr, int len)
{
    int maxValue = ptr[0];  // Initialize maxValue with the first element of the array
    for (int i = 1; i < len; i++)
    {
        if (ptr[i] > maxValue)
        {
            maxValue = ptr[i];  // Update maxValue if current element is greater than maxValue
        }
    }
    return maxValue;  // Return the maximum value found in the array
}

int main(int argc, char **argv)
{
    int maxValue = 0;  // Variable to store the maximum value in the array
    int arr[10] = {1, 2, 5, 6, 7, 8, 9, 0, 88, -11};  // Array containing integer values
    
    int len =  sizeof(arr)/sizeof(arr[0]);  // Calculate the length of the array

    printArray(arr, len);  // Print the elements of the array
    maxValue = findMaxValue(arr, len);  // Find the maximum value in the array
    printf("Max value is : %d\n", maxValue);  // Print the maximum value
    
    return 0;  // Exit the program
}
/*
Expected Output:
1, 2, 5, 6, 7, 8, 9, 0, 88, -11, 
Max value is : 88
*/

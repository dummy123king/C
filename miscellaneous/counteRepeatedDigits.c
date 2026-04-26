#include <stdio.h>
#include <stdlib.h>

int mostRepeatedDigit(long unsigned int n) 
{
    int digitCount[10] = {0}; // Array to count occurrences of each digit
    int maxCount = 0; // Maximum count of repeated digits
    int repeatedDigit = -1; // Most repeated digit
    
    while (n > 0) {
        int digit = n % 10; // Extract the last digit
        digitCount[digit]++; // Increment count for the current digit
        n /= 10; // Move to the next digit
    }

    // Find the digit with the maximum count
    for (int i = 0; i < 10; i++) {
        if (digitCount[i] > maxCount) {
            maxCount = digitCount[i];
            repeatedDigit = i;
        }
    }

    // If no digit is repeated, return -1
    if (maxCount == 1) {
        return -1;
    }

    printf("%d is repeated %d times\n", repeatedDigit, maxCount);
    return maxCount;
}

int main() {
    long unsigned int n = 555544444;
    mostRepeatedDigit(n);
    return 0;
}
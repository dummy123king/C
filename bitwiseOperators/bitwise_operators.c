#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* Function to print a given integer in binary representation */
void print_binary(int data)
{
    for (int i = 31; i >= 0 ; i--)
    {
        printf("%d ", (data >> i) & 1);
    }
    printf("\n");
}

/* Function to set a bit at a given position in an integer */
int set_bit(int data, int pos)
{
    return (data | (1u << pos)); /* Use unsigned literal for portability */
}

/* Function to clear a bit at a given position in an integer */
int clear_bit(int data, int pos)
{
    return (data & (~(1u << pos))); /* Use unsigned literal for portability */
}

/* Function to toggle a bit at a given position in an integer */
int toggle_bit(int data, int pos)
{
    return (data ^ (1u << pos)); /* Use unsigned literal for portability */
}

/* Function to test if a bit is set at a given position in an integer */
int test_bit(int data, int pos)
{
    return ((data >> pos) & 1u); /* Use unsigned literal for portability */
}

/* Function to swap two bits at given positions in an integer */
int swap_two_bits(int data, int p1, int p2)
{
    int pos_1, pos_2; 
    int mask = 0;
    pos_1 = 1u & (data >> p1); /* Use unsigned literal for portability */
    pos_2 = 1u & (data >> p2); /* Use unsigned literal for portability */
    mask = ~((1u << p1) | (1u << p2)); /* Use unsigned literal for portability */
    data = data & mask;
    data = data | (pos_2 << p1) | (pos_1 << p2);
    return data;
}

/* Function to swap nibbles (4 bits) in an integer */
int swap_nibble(int data)
{
    return (((data & 0x0fu) << 4) | ((data & 0xf0u) >> 4)); /* Use unsigned literals for portability */
}

/* Function to swap bytes (8 bits) in an integer */
int swap_byte(int data)
{
    return (((data & 0xff00u) >> 8) | ((data & 0x00ffu) << 8)); /* Use unsigned literals for portability */
}

/* Function to swap two numbers without using a third variable */
void swap_two_numbers_without_third_var(int *a, int *b)
{
    if (*a == *b) /* Check if both the values are the same */
        return;

    *a ^= *b ^= *a ^= *b; /* XOR swap technique */
}

/* Function to reverse the bits of an integer */
int reverse_bits(int data)
{
    int temp_data = 0;

    for (int i = 31; i >= 0; i--)
    {
        if((data >> i) & 1)
        {
            temp_data = temp_data | (1u << (31u - i)); /* Use unsigned literals for portability */
        }
    }
    return temp_data;
}

/* Function to reverse the bits of an integer using swapping */
int reverse_bits_1(int data)
{
    for (int i = 31; i > 15; i--) /* Start from 31 and end at 16 to avoid unnecessary swaps */
    {
        data =  swap_two_bits(data, i, 31 - i); /* Swap ith and (31 - i)th bits */
    }
    return data;
}

/* Function to reverse the bits of an integer using bitwise operations */
int reverse_bits_2(int data)
{
    data = ((data & 0xaaaaaaaau) >> 1) | ((data & 0x55555555u) << 1); /* Use unsigned literals for portability */
    data = ((data & 0xccccccccu) >> 2) | ((data & 0x33333333u) << 2); /* Use unsigned literals for portability */
    data = ((data & 0xf0f0f0f0u) >> 4) | ((data & 0x0f0f0f0fu) << 4); /* Use unsigned literals for portability */
    data = ((data & 0xff00ff00u) >> 8) | ((data & 0x00ff00ffu) << 8); /* Use unsigned literals for portability */
    data = (data >> 16) | (data << 16); /* Swap the upper and lower 16 bits */
    return data;
}

/* Function to count the number of set bits in an integer using iteration */
int count_set_bits(int data)
{
    int no_of_set_bits = 0;
    for(int i = 0; i <= 31; i++)
    {
        if((data >> i) & 1u) /* Use unsigned literal for portability */
            no_of_set_bits++;
    }
    return no_of_set_bits;
}

/* Function to count the number of set bits in an integer using Brian Kernighan's algorithm */
int count_set_bits_1(int data)
{
    int no_of_set_bits = 0;
    while (data)
    {
        data = data & (data - 1); /* Clear the least significant set bit */
        no_of_set_bits++;
    }
    return no_of_set_bits;
}

/* Function to check the sign of an integer */
int check_sign(int data)
{
    if ((data >> 31) & 1) /* Check the sign bit */
    {
       return 1; /* Negative */
    }
    return 0; /* Positive or zero */
}

/* Function to calculate the one's complement of an integer */
int ones_complement(int data)
{
    return (~(data)); /* Use one's complement operator */
}

/* Function to multiply an integer by two using left shift */
int multiply_by_two(int data)
{
    return (data << 1); /* Left shift by one bit */
}

/* Function to divide an integer by two using right shift */
int divide_by_two(int data)
{
    return (data >> 1); /* Right shift by one bit */
}

/* Function to check if the system is little-endian using method 1 */
bool isLittleEndian_1(void)
{
    int data =  0x1;
    char lsb = (char) data; /* Store the least significant byte */
    if (0x1 == lsb) /* Check if the least significant byte is 0x1 */
    {
        return true; /* Little-endian */
    }
    return false; /* Big-endian */
}

/* Function to check if the system is little-endian using method 2 */
bool isLittleEndian_2(void)
{
    int data = 0x1;
    union checkEndian
    {
        int data;
        char check[4]; /* Store the bytes of an integer */
    };
    
    union checkEndian obj;
    obj.data = data;

    if (data == obj.check[0]) /* Check if the least significant byte is 0x1 */
    {
        return true; /* Little-endian */
    }
    return false; /* Big-endian */
}

/* Function to check if the system is little-endian using method 3 */
bool isLittleEndian_3(void)
{
    int data =  0x1;
    char *lsb = (char *) &data; /* Get a pointer to the least significant byte */
    if (*lsb == 0x1) /* Check if the least significant byte is 0x1 */
    {
        return true; /* Little-endian */
    }
    return false; /* Big-endian */
}

/**
 * Converts an integer value between little-endian and big-endian byte order.
 *
 * @param data The integer value to be converted.
 *
 * @return The converted integer value (either big-endian or little-endian).
 */
int LittleEndianToBigEndianVisVersa(int data)
{
    data = ((data & 0xFF000000) >> 24) | ((data & 0x000000FF) << 24) | 
            ((data & 0x00FF0000) >> 8) | ((data & 0x0000FF00) << 8); /* Swap bytes */
    return data;
}


/**
 * Rotates an integer value to the left by a specified number of bits.
 *
 * @param data The integer value to be rotated.
 * @param rotationBits The number of bits to rotate the value by.
 *
 * @return The rotated integer value.
 */
int rotateLeft(int data, int rotationBits)
{
    return ((data << rotationBits) | ( data >> (32 - rotationBits)));
}


/**
 * Rotates an integer value to the right by a specified number of bits.
 *
 * @param data The integer value to be rotated.
 * @param rotationBits The number of bits to rotate the value by.
 *
 * @return The rotated integer value.
 */
int rotateRight(int data, int rotationBits)
{
    return ((data >> rotationBits) | ( data << (32 - rotationBits)));
}


/* Entry point */
int main()
{
    int data = 0x05;
    int rotationBits = 1;
    print_binary(data);
    data = rotateRight(data, rotationBits);
    print_binary(data);
    return 0;
}



#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * Prints the binary representation of the given integer.
 *
 * @param data The integer value to be printed in binary format.
 *
 * @return None. Prints the 32-bit binary representation of the integer.
 */
void print_binary(int data)
{
	int count = 0;
	for (int i = 31; i >= 0; i--)
	{
		count++;
		printf("%d", (data >> i) & 1);
		if (count == 4)
		{
			count = 0;
			printf(" ");
		}
	}
	printf("\n");
}

/**
 * Sets the bit at the specified position in the given integer.
 *
 * @param data The integer value to be modified.
 * @param pos The bit position to set.
 *
 * @return The updated integer value with the specified bit set.
 */
int set_bit(int data, int pos)
{
	return (data | (1 << pos));
}

/**
 * Clears the bit at the specified position in the given integer.
 *
 * @param data The integer value to be modified.
 * @param pos The bit position to clear.
 *
 * @return The updated integer value with the specified bit cleared.
 */
int clear_bit(int data, int pos)
{
	return (data &  (~( 1 << pos)));
}

/**
 * Toggles the bit at the specified position in the given integer.
 *
 * @param data The integer value to be modified.
 * @param pos The bit position to toggle.
 *
 * @return The updated integer value with the specified bit toggled.
 */
int toggle_bit(int data, int pos)
{
	return (data ^ (1 << pos));
}

/**
 * Checks whether the bit at the specified position is set.
 *
 * @param data The integer value to be checked.
 * @param pos The bit position to test.
 *
 * @return 1 if the bit is set, otherwise 0.
 */
int test_bit(int data, int pos)
{
	return ((data >> pos) & 1);
}

/**
 * Swaps the bits at the two specified positions in the given integer.
 *
 * @param data The integer value to be modified.
 * @param p1 The first bit position.
 * @param p2 The second bit position.
 *
 * @return The updated integer value with the two bits swapped.
 */
int swap_two_bits(int data, int p1, int p2)
{
	int pos1_bit, pos2_bit;
	int mask = 0;
	pos1_bit = (data >> p1) & 1;
	pos2_bit = (data >> p2) & 1;
	mask = ~((1 << p1) | ( 1 << p2));
	data = data & mask;
	data = data | (pos2_bit << p1) | (pos1_bit << p2);
	return data;
}

/**
 * Swaps the lower and upper nibbles of the given integer value.
 *
 * @param data The integer value to be modified.
 *
 * @return The updated integer value with its nibbles swapped.
 */
int swap_nibble(int data)
{
	return (((data & 0xf0) >> 4) | (data & 0x0f) << 4);
}

/**
 * Swaps the lower and upper bytes of the given integer value.
 *
 * @param data The integer value to be modified.
 *
 * @return The updated integer value with its bytes swapped.
 */
int swap_byte(int data)
{
	return (((data & 0xff00) >> 8) | ((data & 0x00ff) << 8));
}

/**
 * Swaps two integer values without using a temporary variable.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 *
 * @return None. The values pointed to by a and b are swapped.
 */
void swap_two_numbers_without_third_var(int *a, int *b)
{
	if (*a == *b)
		return;

	*a^= *b^= *a^= *b;
}

/**
 * Reverses the bit order of the given integer value.
 *
 * @param data The integer value whose bits are to be reversed.
 *
 * @return The integer value with its bits reversed.
 */
int reverse_bits(int data)
{
	int temp = 0;

	for(int i = 0; i <= 31; i++)
	{
		if ((data >> i) & 1)
		{
			temp = temp | (1 << (31 - i));
		}
	}
	return temp;
}

/**
 * Reverses the bit order of the given integer by swapping bit positions.
 *
 * @param data The integer value whose bits are to be reversed.
 *
 * @return The integer value with its bits reversed.
 */
int reverse_bits_1(int data)
{
	for (int i = 31; i > 15; i--)
		data = swap_two_bits(data, i, 31 - i);

	return data;
}

/**
 * Reverses the bit order of the given integer using bitwise operations.
 *
 * @param data The integer value whose bits are to be reversed.
 *
 * @return The integer value with its bits reversed.
 */
int reverse_bits_2(int data)
{
	data = ((data & 0xaaaaaaaa) >> 1) | ((data & 0x55555555) << 1);
	data = ((data & 0xcccccccc) >> 2) | ((data & 0x33333333) << 2);
	data = ((data & 0xf0f0f0f0) >> 4) | ((data & 0x0f0f0f0f) << 4);
	data = ((data & 0xff00ff00) >> 8) | ((data & 0x00ff00ff) << 8);
	data = (data >> 16) | (data << 16);
	
	return data;
}

/**
 * Counts the number of bits set to 1 in the given integer using iteration.
 *
 * @param data The integer value to be checked.
 *
 * @return The number of set bits in the integer.
 */
int count_set_bits(int data)
{
	int no_of_set_bits = 0;
	for(int i = 0; i <=31; i++)
	{
		if((data >> i) & 1)
			no_of_set_bits++;
	}

	return no_of_set_bits;
}

/**
 * Counts the number of bits set to 1 using Brian Kernighan's algorithm.
 *
 * @param data The integer value to be checked.
 *
 * @return The number of set bits in the integer.
 */
int count_set_bits_1(int data)
{
	int no_of_set_bits = 0;
	while(data)
	{
		data = data & (data - 1);
		no_of_set_bits++;
	}
	
	return no_of_set_bits;
}

/**
 * Checks whether the given integer is negative.
 *
 * @param data The integer value to be checked.
 *
 * @return 1 if the integer is negative, otherwise 0.
 */
int check_sign(int data)
{
	if ((data >> 31) & 1) /* Check the sign bit */
    {
       return 1; /* Negative */
    }

    return 0; /* Positive or zero */
}

/**
 * Function to multiply an integer by two using left shift.
 *
 * @param data The integer value to be multiplied.
 *
 * @return returns result of multiplication by two.
*/
int multiply_by_two(int data)
{
	return (data << 1);
}

/**
 * Function to divide an integer by two using right shift.
 *
 * @param data The integer value to be divided.
 *
 * @return returns result of division by two.
*/
int divide_by_two(int data)
{
	return (data >> 1);
}

/**
 * Converts an integer value between little-endian and big-endian byte order.
 *
 * @param data The integer value to be converted.
 *
 * @return The converted integer value (either big-endian or little-endian).
*/
int little_endian_to_big_endian_vis_versa(int data)
{
	return(
        ((data & 0xff000000) >> 24) | ((data & 0x000000ff) << 24) | 
            ((data & 0x00ff0000) >> 8)  | ((data & 0x0000ff00) << 8)
        );
}

/**
 * Rotates an integer value to the left by a specified number of bits.
 *
 * @param data The integer value to be rotated.
 * @param rotationBits The number of bits to rotate the value by.
 *
 * @return The rotated integer value.
 */
int rotate_left(int data, int rotationBits)
{
	return ((data << rotationBits) | (data >> (32 - rotationBits)));
}

/**
 * Rotates an integer value to the right by a specified number of bits.
 *
 * @param data The integer value to be rotated.
 * @param rotationBits The number of bits to rotate the value by.
 *
 * @return The rotated integer value.
 */
int rotate_right(int data, int rotationBits)
{
	return ((data >> rotationBits) | (data << (32 - rotationBits)));
}

/**
 * Checks whether the given integer is odd or even.
 *
 * @param data The integer value to be checked.
 *
 * @return None. Prints whether the number is odd or even.
 */
void odd_or_even(int data)
{
	if (data & 1)
		printf("odd number\n");
	else 
		printf("even number\n");

}

/* Entry point */
int main()
{
	int data = 0x55;
	int rotationBits = 1;
	print_binary(data);
	
	
	// data = set_bit(data, 1);
	// data = clear_bit(data, 0);
	// data = toggle_bit(data, 5);
	
	// int bit = 0;
	// bit = test_bit(data, 1);

	// data = swap_two_bits(data, 0, 28);
	// data = swap_nibble(data);
	// data = swap_byte(data);
	
	// int a = 10, b = 20;
	// printf("a = %d, b = %d\n", a, b);
	// swap_two_numbers_without_third_var(&a, &b);
	// printf("a = %d, b = %d\n", a, b);
	
	// data = reverse_bits(data);
	// data = reverse_bits_1(data);
	// data = reverse_bits_2(data);
	
	// int count = 0;
	// count = count_set_bits(data);
	// count = count_set_bits_1(data);
	// printf("count --->> %d\n", count);

		
	// odd_or_even(data);
	// printf("data = 0x%x\n", 0x11223344);
	// data = little_endian_to_big_endian_vis_versa(0x11223344);
	// printf("data = 0x%x\n", data);
	
	// isLittleEndian_1();
	data = rotate_left(data, 8);
	
	print_binary(data);
	return 0;
}

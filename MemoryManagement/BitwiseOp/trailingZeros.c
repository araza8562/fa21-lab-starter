#include <stdio.h>
#include <limits.h>

// Calculate the number of bits in an int
int bits_in_int = CHAR_BIT * sizeof(int);

// Function prototypes
int convert_to_binary(int number);
void count_trailing_zeros(int number);

int main()
{
    int input_number;

    // Prompt the user to enter a value
    printf("Enter the value to convert to binary: ");
    (void)scanf("%d", &input_number);

    // Convert the number to binary and display it
    convert_to_binary(input_number);

    // Count the trailing zeros in the binary representation
    count_trailing_zeros(input_number);

    return 0;
}

// Function to convert a number to binary and print the result
int convert_to_binary(int number)
{
    int i, bit;
    unsigned mask = 1;

    // Set the mask to the highest bit
    mask = mask << (bits_in_int - 1);

    // Iterate over each bit
    for (i = 0; i < bits_in_int; i++)
    {
        // Check if the current bit is set
        bit = (mask & number) ? 1 : 0;
        // Print the current bit
        printf("%d", bit);
        // Shift the mask to the right
        mask >>= 1;
    }
    printf("\n");
    return bit;
}

// Function to count the number of trailing zeros in a binary representation
void count_trailing_zeros(int number)
{
    int i;
    int mask = 1;
    int trailing_zeros = 0;

    // Iterate over each bit position
    for (i = 0; i < (bits_in_int - 1); i++)
    {
        // While there are bits left to check
        while (number != 0)
        {
            // Check if the current bit is zero
            if (!(mask & number))
            {
                trailing_zeros += 1;
            }
            else
            {
                // Stop counting if a 1 bit is found
                break;
            }
            // Shift the mask to the left
            mask <<= 1;
        }
    }

    // Print the number of trailing zeros
    printf("Number of trailing zeros: %d\n", trailing_zeros);
}

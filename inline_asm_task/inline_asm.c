#include <stdio.h>

int main()
{
    unsigned int x, y;

    printf("Enter the values to be added: ");

    (void)scanf("%d %d", &x, &y); // Read two unsigned integer values from the user and store them in x and y

    // Inline assembly code to add y to x
    __asm__ volatile(" add %1, %0" : "+r"(x) : "r"(y) : "cc");
    // " add %1, %0"    - The assembly instruction to add the values
    // "+r"(x)          - The output operand, x, which is both read and written
    // "r"(y)           - The input operand, y, which is read-only
    // "cc"             - Indicates that the condition code register is clobbered

    printf("New value after adding x and y: %d", x); // Print the new value of x after adding y to it
    printf("\n");
}

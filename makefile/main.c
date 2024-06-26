#include <stdio.h>

int main()
{
    float billAmount, tipPercentage, totalAmount;
    printf("Enter the bill amount: ");
    scanf("%f", &billAmount);
    printf("Enter the tip percentage (0 to 100): ");
    scanf("%f", &tipPercentage);
    // Calculate total amount including tip
    totalAmount = billAmount + (billAmount * tipPercentage / 100);
    printf("Total amount including tip: %.2f\n", totalAmount);
    return 0;
}

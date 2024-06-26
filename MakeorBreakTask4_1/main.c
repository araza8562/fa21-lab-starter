#include <stdio.h>
#include "header.h"

int main()
{
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    int sum = addTwoNumbers(num1, num2);
    printf("%d + %d = %d\n", num1, num2, sum);

    return 0;
}

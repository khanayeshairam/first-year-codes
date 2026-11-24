
#include <stdio.h>
int main() {
    int num1, num2;
    int sum, sub, mult, mod;
    float div;
    // Input two numbers from the user
    printf("Enter any two numbers: ");
    scanf("%d%d", &num1, &num2);
    // Perform arithmetic operations
    sum = num1 + num2;           // Addition
    sub = num1 - num2;           // Subtraction
    mult = num1 * num2;          // Multiplication
    div = (float)num1 / num2;    // Division (cast to float for decimal result)
    mod = num1 % num2;           // Modulus (remainder)
    // Display results
    printf("SUM = %d\n", sum);
    printf("DIFFERENCE = %d\n", sub);
    printf("PRODUCT = %d\n", mult);
    printf("QUOTIENT = %f\n", div);
    printf("MODULUS = %d\n", mod);
    return 0;
}

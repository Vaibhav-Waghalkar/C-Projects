#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void add(float a, float b) {
    printf("Result: %.2f\n", a + b);
}

void subtract(float a, float b) {
    printf("Result: %.2f\n", a - b);
}

void multiply(float a, float b) {
    printf("Result: %.2f\n", a * b);
}

void divide(float a, float b) {
    if (b != 0)
        printf("Result: %.2f\n", a / b);
    else
        printf("Error: Division by zero is not allowed.\n");
}

void modulus(int a, int b) {
    if (b != 0)
        printf("Result: %d\n", a % b);
    else
        printf("Error: Modulus by zero is not allowed.\n");
}

void power(double base, double exponent) {
    printf("Result: %.2f\n", pow(base, exponent));
}

void square_root(double num) {
    if (num >= 0)
        printf("Result: %.2f\n", sqrt(num));
    else
        printf("Error: Square root of a negative number is not allowed.\n");
}

void factorial(int num) {
    if (num < 0) {
        printf("Error: Factorial of a negative number is not possible.\n");
        return;
    }
    long long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    printf("Result: %lld\n", fact);
}

void trigonometric_functions(int choice) {
    double angle;
    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);
    double radians = angle * (M_PI / 180.0);
    switch (choice) {
        case 7: printf("sin(%.2f) = %.4f\n", angle, sin(radians)); break;
        case 8: printf("cos(%.2f) = %.4f\n", angle, cos(radians)); break;
        case 9: printf("tan(%.2f) = %.4f\n", angle, tan(radians)); break;
        default: printf("Invalid choice!\n");
    }
}

int main() {
    int choice;
    float num1, num2;
    int int1, int2;
    while (1) {
        printf("\n\n******** Advanced Calculator ********\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        printf("5. Modulus\n6. Power\n7. Sine\n8. Cosine\n9. Tangent\n");
        printf("10. Square Root\n11. Factorial\n12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 12) {
            printf("Exiting calculator.\n");
            break;
        }
        
        switch (choice) {
            case 1: case 2: case 3: case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                if (choice == 1) add(num1, num2);
                else if (choice == 2) subtract(num1, num2);
                else if (choice == 3) multiply(num1, num2);
                else divide(num1, num2);
                break;
            case 5:
                printf("Enter two integers: ");
                scanf("%d %d", &int1, &int2);
                modulus(int1, int2);
                break;
            case 6:
                printf("Enter base and exponent: ");
                scanf("%f %f", &num1, &num2);
                power(num1, num2);
                break;
            case 7: case 8: case 9:
                trigonometric_functions(choice);
                break;
            case 10:
                printf("Enter a number: ");
                scanf("%f", &num1);
                square_root(num1);
                break;
            case 11:
                printf("Enter an integer: ");
                scanf("%d", &int1);
                factorial(int1);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

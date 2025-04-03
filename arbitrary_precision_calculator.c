#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define INT_INFINITY 2147483647

// Function to handle input validation
bool get_valid_input(double *num)
{
    if (scanf("%lf", num) != 1)
    {
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid number.\n");
        //return false;
    }
    return true;
}
// Function to get multiple double inputs for operations
void get_double_array(double numbers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Enter number %d: ", i + 1);
        while (!get_valid_input(&numbers[i]))
        {
            printf("Enter number %d again: ", i + 1);
        }
    }
}
// Function to add multiple double numbers
double add_numbers(double numbers[], int count)
{
    double sum = 0.0;
    for (int i = 0; i < count; i++)
    {
        sum += numbers[i];
    }
    return sum;
}
// Function to subtract multiple double numbers
double subtract_numbers(double numbers[], int count)
{
    double result = numbers[0];
    for (int i = 1; i < count; i++)
    {
        result -= numbers[i];
    }
    return result;
}
// Function to multiply multiple double numbers
double multiply_numbers(double numbers[], int count)
{
    double result = 1.0;
    for (int i = 0; i < count; i++)
    {
        result *= numbers[i];
    }
    return result;
}
// Division function
double divide_numbers(double num1, double num2)
{
    if (num2 != 0)
        return num1 / num2;
    else
    {
        printf("Error: Division by zero is not allowed.\n");
        return INT_INFINITY;
    }
}

// Modulus function
double modulus_numbers(double num1, double num2)
{
    if ((int)num2 != 0)
        return (int)num1 % (int)num2;
    else
    {
        printf("Error: Modulus by zero is not allowed.\n");
        return INT_INFINITY;
    }
}

// Square root function using absoulute value
double square_root(double num)
{
    return sqrt(fabs(num));
}

// Square function
double square(double num)
{
    return num * num;
}

// Logarithm base e function
double log_base_e(double num)
{
    if (num <= 0)
    {
        printf("Error: Logarithm of zero or negative number is undefined in real numbers.\n");
        return INT_INFINITY;
    }
    return log(num);
}

// Logarithm base 10 function
double log_base_10(double num)
{
    if (num <= 0)
    {
        printf("Error: Logarithm of zero or negative number is undefined in real numbers.\n");
        return INT_INFINITY;
    }
    return log10(num);
}

// Function to display the menu
void display_menu()
{
    printf("\n\t\t\tArbitrary Precision Calculator\n\n");
    printf("\t\tCalculator Menu:\n");
    printf("\t\t1. Addition (+) (supports multiple numbers)\n");
    printf("\t\t2. Subtraction (-) (supports multiple numbers)\n");
    printf("\t\t3. Multiplication (*) (supports multiple numbers)\n");
    printf("\t\t4. Division (/)\n");
    printf("\t\t5. Modulus (%%)\n");
    printf("\t\t6. Square root (sqrt)\n");
    printf("\t\t7. Square (^2)\n");
    printf("\t\t8. Logarithm (log base e)\n");
    printf("\t\t9. Logarithm (log base 10)\n");
    printf("\t\t10. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    double num1, num2, result;
    int choice, count;
    double *numbers;

    while (1)
    {
        display_menu();

        // Validate choice input
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        if (choice == 10)
        {
            printf("Terminating the calculator. Goodbye!\n");
            break;
        }

        if (choice >= 1 && choice <= 3)
        {
            printf("Enter the number of values: ");
            // Validate count input
            if (scanf("%d", &count) != 1 || count < 2)
            {
                printf("Invalid input. You must enter at least two numbers for this operation.\n");
                while (getchar() != '\n');
                continue;
            }
            while (getchar() != '\n');

            numbers = (double *)malloc(count * sizeof(double));
            if (numbers == NULL)
            {
                printf("Memory allocation failed. Exiting...\n");
                return -1;
            }

            get_double_array(numbers, count);

            if (choice == 1)
            {
                result = add_numbers(numbers, count);
                printf("Sum of the numbers = %.5lf\n", result);
            }
            else if (choice == 2)
            {
                result = subtract_numbers(numbers, count);
                printf("Subtraction result = %.5lf\n", result);
            }
            else if (choice == 3)
            {
                result = multiply_numbers(numbers, count);
                printf("Multiplication result = %.5lf\n", result);
            }

            free(numbers);
            continue;
        }

        if (choice >= 4 && choice <= 9)
        {
            if (choice == 4 || choice == 5)
            {
                printf("Enter the first number: ");
                if (!get_valid_input(&num1)) continue;
                printf("Enter the second number: ");
                if (!get_valid_input(&num2)) continue;
            }
            else
            {
                printf("Enter a number: ");
                if (!get_valid_input(&num1)) continue;
            }
        }
        switch (choice)
        {
        case 4:
            result = divide_numbers(num1, num2);
            if (result != INT_INFINITY)
                printf("Result: %.10lf / %.10lf = %.5lf\n", num1, num2, result);
            break;
        case 5:
            result = modulus_numbers(num1, num2);
            if (result != INT_INFINITY)
                printf("Result: %.0lf %% %.0lf = %.03f\n", num1, num2, result);
            break;
        case 6:
            result = square_root(num1);
            printf("Square root of |%.10lf| is %.5lf\n", num1, result);
            break;
        case 7:
            result = square(num1);
            printf("Square of %.10lf is %.5lf\n", num1, result);
            break;
        case 8:
            result = log_base_e(num1);
            if (result != INT_INFINITY)
                printf("Natural logarithm (log base e) of %.2lf is %.5lf\n", num1, result);
            break;
        case 9:
            result = log_base_10(num1);
            if (result != INT_INFINITY)
                printf("Logarithm (log base 10) of %.2lf is %.2lf\n", num1, result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    return 0;
}

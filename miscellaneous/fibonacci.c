#include <stdio.h>

void fibonacci_with_iteration(int number)
{
    int n1 = 0, n2 = 1, fib = 0;

    printf("0, ");

    if (number == 1)
    {
        printf("\n\n");
        return;
    }

    printf("%d, %d, ", n1, n2);

    for (int i = 2; i < number; i++)
    {
        fib = n1 + n2;
        n1 = n2;
        n2 = fib;
        printf("%d, ", fib);
    }

    printf("\n\n");
}

int fibonacci_with_recursion(int number)
{
    if (number < 0)
        return -1;

    if (number == 0)
        return 0;

    if (number == 1)
        return 1;

    return (fibonacci_with_recursion(number - 1) + fibonacci_with_recursion(number - 2));
}

int main(void)
{
    fibonacci_with_iteration(1);

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d, ", fibonacci_with_recursion(i));
    }
    printf("\n\n");
    
    return 0;
}


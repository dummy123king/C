#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
    return (a + b);
}

int sub(int a, int b)
{
    return (a - b);
}

int mul(int a, int b)
{
    return (a * b);
}

int function_ptr(int (*operation)(int, int), int a, int b)
{
    return operation(a, b);
}


int main(int argc, char **argv)
{
    int a = 5, b = 10;
    printf("Add %d and %d is %d\n", a, b, function_ptr(add, a, b));
    printf("mul %d and %d is %d\n", a, b, function_ptr(mul, a, b));
    printf("sub %d and %d is %d\n", a, b, function_ptr(sub, a, b));

    return 0;
}
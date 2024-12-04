#include <stdio.h>

double f(double x)
{
    return 1 / (1 + x * x);
}

double simpsonsRule(double a, double b, int n)
{

    if (n % 2 != 0)
    {
        printf("The number of subintervals (n) must be even.\n");
        return -1;
    }

    double h = (b - a) / n;

    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
    {
        sum += 4 * f(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2)
    {
        sum += 2 * f(a + i * h);
    }

    sum *= h / 3;

    return sum;
}

int main()
{
    double a, b;
    int n;

    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);

    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);

    printf("Enter the number of subintervals (n, must be even): ");
    scanf("%d", &n);

    double result = simpsonsRule(a, b, n);
    if (result != -1)
    {
        printf("The approximate integral is: %.4f\n", result);
    }

    return 0;
}

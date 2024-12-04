#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 1 / (1 + x * x);
}

double simpsons38Rule(double a, double b, int n)
{

    if (n % 3 != 0)
    {
        printf("The number of subintervals must be a multiple of 3 for Simpson's 3/8 Rule.\n");
        return -1;
    }

    double h = (b - a) / n;

    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)

        {
            sum += 2 * f(a + i * h);
        }
        else

        {
            sum += 3 * f(a + i * h);
        }
    }

    sum *= 3 * h / 8;

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

    printf("Enter the number of subintervals (n) (must be a multiple of 3): ");
    scanf("%d", &n);

    double result = simpsons38Rule(a, b, n);

    if (result != -1)
    {
        printf("The approximate integral using Simpson's 3/8 rule is: %.4f\n", result);
    }

    return 0;
}

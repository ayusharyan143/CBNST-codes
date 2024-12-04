#include <stdio.h>
#include <math.h>

#define EPS 0.00005

float f(float x)
{
    return x * x * x - 2 * x + 1;
}

float g(float x)
{
    return (x * x * x + 1) / 2;
}

void IterationMethod()
{
    float x0, x1, x2, f0, f1, f2, error;
    int i = 0, n;

    for (x1 = 1;; x1++)
    {
        f1 = f(x1);
        if (f1 > 0)
            break;
    }

    for (x0 = x1 - 1;; x0--)
    {
        f0 = f(x0);
        if (f0 < 0)
            break;
    }

    x2 = (x0 + x1) / 2;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    printf("\n\n\t\t The 1 approximation to the root is: %f\n", x2);

    for (; i < n; i++)
    {
        f2 = g(x2);
        printf("\n\t\t The %d approximation to the root is: %f\n", i + 2, f2);

        error = fabs(f2 - x2);

        x2 = f2;

        if (error < EPS)
        {
            break;
        }
    }

    if (error >= EPS)
    {
        printf("NOTE: The number of iterations may not be sufficient to converge.\n");
    }

    printf("-----------------------------------------------------------------------------\n");
    printf("The root is approximately %.5f\n", x2);
    printf("-----------------------------------------------------------------------------\n");
}

int main()
{
    printf("f(x) = x*x*x - 2*x + 1\n");
    IterationMethod();
    return 0;
}

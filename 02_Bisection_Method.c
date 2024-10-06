#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * log10(x) - 1.2;
}

void BisectionMethod(float a, float b, int n, float tolerance)
{
    float x, f0, f1, f2;
    f0 = f(a);
    f1 = f(b);

    if (f0 * f1 >= 0)
    {
        printf("The function does not have opposite signs at the given interval.\n");
        return;
    }

    printf("Iteration |       a       |       b       |       x       |      f(x)     \n");
    printf("----------|---------------|---------------|---------------|---------------\n");

    for (int i = 1; i <= n; i++)
    {
        x = (a + b) / 2;
        f2 = f(x);

        printf("    %2d    | %13.4f | %13.4f | %13.4f | %13.4f \n", i, a, b, x, f2);

        if (fabs(f2) < tolerance || (b - a) / 2 < tolerance)
        {
            printf("Root found: x = %.4f\n", x);
            return;
        }

        if (f2 < 0)
        {
            a = x;
        }
        else
        {
            b = x;
        }
    }

    printf("Approximate root after %d iterations: x = %.4f\n", n, x);
}

int main()
{
    float a, b, tolerance = 0.000001; // Default tolerance
    int n;

    printf("f(x) = x * log10(x) - 1.2\n");
    printf("Enter the value of a and b: ");
    scanf("%f %f", &a, &b);

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    BisectionMethod(a, b, n, tolerance);

    return 0;
}

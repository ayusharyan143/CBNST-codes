#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 3 * x + sin(x) - exp(x);
}

void RegulaFaulse(float a, float b, int n)
{
    float x0, x1, x2, f0, f1, f2;
    int i = 0;

    f0 = f(a);
    f1 = f(b);

    if (f0 * f1 >= 0)
    {
        printf("The function does not have opposite signs at the given interval.\n");
        return;
    }

    x0 = a;
    x1 = b;

    printf("Iteration |       a       |       b       |       x0      |      f(x0)    \n");
    printf("----------|---------------|---------------|---------------|---------------\n");

    while (i < n)
    {
        if (f1 - f0 == 0)
        {
            printf("Division by zero error.\n");
            return;
        }

        x2 = x0 - (f0 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);

        printf("    %2d    | %13.4f | %13.4f | %13.4f | %13.4f \n", i + 1, a, b, x2, f2);

        if (fabs(f2) < 0.000001)
        {
            printf("Root found: x = %.4f\n", x2);
            return;
        }

        if (f0 * f2 < 0)
        {
            b = x2;
            f1 = f2;
        }
        else
        {
            a = x2;
            f0 = f2;
        }

        x0 = a;
        x1 = b;

        i++;
    }

    printf("Maximum iterations reached. Approximate root: x = %.4f\n", x2);
}

int main()
{
    float a, b;
    int n;

    printf("f(x) = 3*x + sin(x) - e^x\n");
    printf("Enter the value of a and b: ");
    scanf("%f %f", &a, &b);

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    RegulaFaulse(a, b, n);
    return 0;
}

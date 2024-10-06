#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 3 * x - cos(x) - 1;
}

float f_derivative(float x)
{
    return 3 + sin(x);
}

void NewtonRaphson(float a, float b, int n)
{
    float x0, x1, fx, dfx;

    float f0 = f(a);
    float f1 = f(b);

    if (f0 * f1 >= 0)
    {
        printf("The function does not have opposite signs at the given interval.\n");
        return;
    }

    x0 = (fabs(f0) < fabs(f1)) ? a : b;

    printf("Iteration |       xi      |      f(x0)    \n");
    printf("----------|---------------|---------------\n");

    for (int i = 1; i <= n; i++)
    {
        fx = f(x0);
        dfx = f_derivative(x0);

        if (dfx == 0)
        {
            printf("Derivative is zero. Newton-Raphson method fails.\n");
            return;
        }

        x1 = x0 - fx / dfx;

        printf("    %2d    | %13.6f | %13.6f \n", i , x1 , f(x1) );

        if (fabs(x1 - x0) < 0.000001)
        {
            printf("Root found: x = %.4f after %d iterations.\n", x1, i);
            return;
        }

        x0 = x1;
    }

    printf("Did not converge within %d iterations.\n", n);
}

int main()
{
    float a, b;
    int n;

    printf("f(x) = 3 * x - cos(x) - 1\n");
    printf("Enter the value of a and b: ");
    scanf("%f %f", &a, &b);

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    NewtonRaphson(a, b, n);

    return 0;
}

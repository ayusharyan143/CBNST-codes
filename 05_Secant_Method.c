#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * x * x - 5 * x + 1;
}

void SecondMethod(float a, float b, int n)
{
    float x0 = a, x1 = b, x2, fx0, fx1, fx2;
    int i = 0;

    fx0 = f(x0);
    fx1 = f(x1);

    if (fx0 * fx1 >= 0)
    {
        printf("The function does not have opposite signs at the given interval.\n");
        return;
    }

    printf("Iteration |       x0      |       x1      |       x2      |      f(x2)    \n");
    printf("----------|---------------|---------------|---------------|---------------\n");

    while (i < n)
    {

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        fx2 = f(x2);

        printf("    %2d    | %13.6f | %13.6f | %13.6f | %13.6f \n", i + 1, x0, x1, x2, fx2);

        if (fabs(x2 - x1) < 0.000001)
        {
            printf("\nRoot found: x = %.4f \n\n", x2);
            return;
        }

        x0 = x1;
        fx0 = fx1;

        x1 = x2;
        fx1 = fx2;

        i++;
    }

    printf("Did not converge within %d iterations.\n", n);
}

int main()
{
    float a, b;
    int n;

    printf("f(x) = x*x*x - 5*x + 1 \n");

    printf("Enter value of a and b : ");
    scanf("%f %f", &a, &b);

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    SecondMethod(a, b, n);
}
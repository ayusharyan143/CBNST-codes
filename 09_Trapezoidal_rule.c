#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 1 / (1 + x * x);
}

void trapezoidalRule(double a, double b, int n)
{
    double h = (b - a) / n;
    double Integral  =(f(a) + f(b)) / 2;


    for (int i = 1; i < n; i++)
    {
        Integral += f(a + i * h);

    }

    Integral *= h;


    printf("\n\nThe approximate integral is: %.4f\n", Integral);

}

int main()
{

    double a, b;

    int n;

    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);

    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);

    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    trapezoidalRule(a, b, n);
}

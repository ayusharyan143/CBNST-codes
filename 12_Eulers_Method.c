#include <stdio.h>

double f(double x, double y)
{
    return (x - y) / (x + y);
}

int main()
{
    double x0, y0, h, xn, x, y;

    printf("Enter initial value x0: ");
    scanf("%lf", &x0);
    
    printf("Enter initial value y0: ");
    scanf("%lf", &y0);
    
    printf("Enter the end value of x: ");
    scanf("%lf", &xn);
    
    printf("Enter step size h: ");
    scanf("%lf", &h);

    x = x0;
    y = y0;

    printf("\n x0 = %.4f  y0 = %.4f\n", x0, y0);

    while (x < xn)
    {

        y = y + h * f(x, y);

        x = x + h;

        printf(" x = %.4f  y = %.4f\n", x, y);
    }

    return 0;
}

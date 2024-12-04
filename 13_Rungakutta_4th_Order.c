#include <stdio.h>

double f(double x, double y)
{
    return (x - y) / (x + y);
}

int main()
{
    double x0, y0, h, xn, k1, k2, k3, k4, k, x, y;
    int n;

    printf("Enter the initial values for x0, y0, h, xn: ");
    scanf("%lf %lf %lf %lf", &x0, &y0, &h, &xn);

    n = (xn - x0) / h;

    x = x0;
    y = y0;

    for (int i = 0; i <= n; i++)
    {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        printf("x = %.4f  y = %.4f\n", x, y);

        x = x + h;
        y = y + k;
    }

}

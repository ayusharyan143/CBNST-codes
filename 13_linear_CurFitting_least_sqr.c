#include <stdio.h>

void leastsquareFit(double x[], double y[], int n)
{
    double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0, a, b;

    printf("x \t\t y \t\t x*y \t\t x^2\t \n");
    printf("___________________________________________________________\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f \t %.4f \t %.4f \t %.4f\t \n", x[i], y[i], x[i] * y[i], x[i] * x[i]);
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    printf("___________________________________________________________\n");
    printf("%f \t %.4f \t %.4f \t %.4f\t \n", sumX , sumY ,sumXY ,sumX2);
    printf("___________________________________________________________\n\n");

    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);

    a = (sumY - b * sumX) / n;

    printf("Y = %.4f + ( %.4f x )\n\n", a, b);
}

int main()
{
    int n = 6;

    double x[] = {1, 2, 3, 4, 5, 6};
    double y[] = {1200, 900, 600, 200, 110, 50};

    leastsquareFit(x, y, n);

    return 0;
}

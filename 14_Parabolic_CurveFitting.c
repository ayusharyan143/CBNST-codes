#include <stdio.h>

void linearCurveFitting(int n, double x[], double y[])
{
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    double b, a;

    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / n;

    printf("The linear equation is: y = %.4f + %.4fx\n", a, b);
}

int main()
{

    int n = 5;
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {14, 27, 40, 55, 68};

    linearCurveFitting(n, x, y);

    return 0;
}

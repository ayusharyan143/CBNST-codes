#include <stdio.h>

#define MAX 20

double interpolate(float x[], float y[], int n, float value)
{
    double result = 0.0;

    for (int i = 0; i < n; i++)
    {
        double term = y[i];

        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term = term * (value - x[j]) / (double)(x[i] - x[j]);
            }
        }

        result += term;
    }

    return result;
}

int main()
{
    float x[MAX], y[MAX];
    int n;

    printf("Enter the number of data points (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || n <= 0)
    {
        printf("Invalid number of data points.\n");
        return 1;
    }

    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }

    float value;
    printf("Enter the value to interpolate: ");
    scanf("%f", &value);

    printf("Value of f(%.2f) is: %.4f\n", value, interpolate(x, y, n, value));

    return 0;
}

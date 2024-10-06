#include <stdio.h>

#define MAX 100

void calculateBackwardDifferences(float x[], float y[], float diff[MAX][MAX], int n)
{

    for (int i = 0; i < n; i++)
    {
        diff[i][0] = y[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = n - 1; i >= j; i--)
        {
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }
}

float newtonsBackwardInterpolation(float x[], float y[], float value, int n)
{
    float diff[MAX][MAX];
    calculateBackwardDifferences(x, y, diff, n);

    float h = x[1] - x[0];
    float u = (value - x[n - 1]) / h;
    float interpolation = diff[n - 1][0];

    for (int i = 1; i < n; i++)
    {
        float term = 1;
        for (int j = 0; j < i; j++)
        {
            term *= (u + j) / (j + 1);
        }
        interpolation += term * diff[n - 1][i];
    }

    return interpolation;
}

int main()
{
    float x[MAX], y[MAX];
    int n;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

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

    float result = newtonsBackwardInterpolation(x, y, value, n);
    printf("The interpolated value at x = %.2f is: %.4f\n", value, result);

    return 0;
}

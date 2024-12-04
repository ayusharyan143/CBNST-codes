#include <stdio.h>
#include <math.h>

void calculateMeans(double x[], double y[], int n, double *meanX, double *meanY)
{
    double sumX = 0, sumY = 0;
    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumY += y[i];
    }
    *meanX = sumX / n;
    *meanY = sumY / n;
}

void calculateSums(double x[], double y[], int n, double meanX, double meanY, double *sumXY, double *sumX2, double *sumY2)
{
    *sumXY = 0;
    *sumX2 = 0;
    *sumY2 = 0;
    for (int i = 0; i < n; i++)
    {
        *sumXY += (x[i] - meanX) * (y[i] - meanY);
        *sumX2 += (x[i] - meanX) * (x[i] - meanX);
        *sumY2 += (y[i] - meanY) * (y[i] - meanY);
    }
}

double calculateCorrelationCoefficient(double sumXY, double sumX2, double sumY2)
{
    return sumXY / sqrt(sumX2 * sumY2);
}

double calculateRegressionCoefficients(double sumXY, double sumX2,double sumY2, double *bxy, double *byx)
{
    *bxy = sumXY / sumX2;
    *byx = sumXY / sumY2;
}

void printResults(double meanX, double meanY, double bxy, double byx, double r)
{
    printf("\nRegression Line: y = bxy * x + c\n");
    printf("Slope (bxy) = %.4f\n", bxy);
    printf("Slope (byx) = %.4f\n", byx);
    printf("Correlation Coefficient (r) = %.4f\n", r);

    printf("\nRegression Equations:\n");
    printf("x on y: x - x' = r * (sigma_x / sigma_y) * (y - y')\n");
    printf("y on x: y - y' = r * (sigma_y / sigma_x) * (x - x')\n");
}

int main()
{
    int n;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    printf("Enter the values of x and y:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i + 1);
        scanf("%lf", &y[i]);
    }

    double meanX, meanY, sumXY, sumX2, sumY2;
    calculateMeans(x, y, n, &meanX, &meanY);
    calculateSums(x, y, n, meanX, meanY, &sumXY, &sumX2, &sumY2);

    double r = calculateCorrelationCoefficient(sumXY, sumX2, sumY2);
    double bxy, byx;
    calculateRegressionCoefficients(sumXY, sumX2,sumY2, &bxy, &byx);

    printResults(meanX, meanY, bxy, byx, r);

    return 0;
}

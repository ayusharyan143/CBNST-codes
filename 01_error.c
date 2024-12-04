#include <stdio.h>
#include <math.h>
int main()
{
    float trueVal, approxVal;
    
    printf("\n\nEnter the true value: ");
    scanf("%f", &trueVal);
    
    printf("Enter the approximate value: ");
    scanf("%f", &approxVal);
    
    float absolute_error = fabs(trueVal - approxVal);
    
    float relative_error = fabs( absolute_error / trueVal);
    
    float percent_error = 100 * relative_error ;
    
    printf("\n\nAbsolute Error: %f\n", absolute_error);
    
    printf("Relative Error: %f\n", relative_error);
    
    printf("Percentage Error: %f\n\n", percent_error);
    
    return 0;
}
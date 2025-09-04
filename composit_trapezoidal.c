# include<stdio.h>
# include<math.h>

float trapezoidalC(float x);

int main(){
    int n;
    float x0, x1, h, sum, I;
    
    // Input section
    printf("lower limit x0 = ");
    scanf("%f", &x0);
    printf("upper limit x1 = ");
    scanf("%f", &x1);
    printf("n (number of sub-intervals) = ");
    scanf("%d", &n);
    
    // Step size calculation
    h = (x1 - x0) / n;
    
    // Composite trapezoidal rule sum initialization
    sum = 0.0;
    
    // Loop for the inner points
    for (int i = 1; i < n; i++) {
        sum += trapezoidalC(x0 + i * h);
    }
    
    // Composite trapezoidal rule formula
    I = (h / 2.0) * (trapezoidalC(x0) + trapezoidalC(x1) + 2 * sum);
    
    // Output the result
    printf("Approximate value of the integral I = %.3f\n", I);
    
    return 0;
}

// Function to compute f(x) = x^3 + 1
float trapezoidalC(float x) {
    return pow(x, 3) + 1;
}

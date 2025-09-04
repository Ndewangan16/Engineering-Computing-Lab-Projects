#include <stdio.h>
#include <math.h>

// Function to calculate f(x) = 1 / log(x)
double f(double x) {
    return 1.0 / log(x);
}

// Function to apply the Midpoint Rule
double midpoint_rule(double a, double b, int n) {
    double h = (b - a) / n;  // Step size
    double sum = 0.0;
    
    for (int i = 0; i < n; i++) {
        double x_mid = a + (i + 0.5) * h;  // Midpoint of the subinterval
        sum += f(x_mid);
    }
    
    return h * sum;  // Final result
}

int main() {
    double a = 2.0, b = 5.0;
    int n;

    // Input number of steps
    printf("Enter the number of steps: ");
    scanf("%d", &n);

    // Calculate the integral using the Midpoint Rule
    double result = midpoint_rule(a, b, n);

    // Output the result
    printf("The integral is approximately: %lf\n", result);

    return 0;
}

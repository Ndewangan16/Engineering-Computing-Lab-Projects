#include <stdio.h>
#include <math.h>

// Function to compute f(x) = sqrt(sin(x))
float func(float x) {
    return sqrt(sin(x)); // sqrt(sin(x))
}

// Function to perform the composite Simpson's 1/3 rule
float simpsonsOneThirdC(float x0, float x1, float deltaX) {
    int n = (int)((x1 - x0) / deltaX); // Number of intervals

    // Ensure n is even for Simpson's rule
    if (n % 2 != 0) {
        n++; // Increment n to make it even if necessary
    }

    float h = (x1 - x0) / n; // Adjusted width of each interval
    float sum_odd = 0.0, sum_even = 0.0;

    // Sum the function values at odd and even intervals
    for (int i = 1; i < n; i++) {
        float xi = x0 + i * h;
        if (i % 2 == 0) {
            sum_even += func(xi);
        } else {
            sum_odd += func(xi);
        }
    }

    // Apply Simpson's 1/3 rule
    return (h / 3) * (func(x0) + func(x1) + 4 * sum_odd + 2 * sum_even);
}

// Main function
int main() {
    float result; // To store the result
    const float I_exact = 2.62205755429; // Exact value of the integral

    // Interval (0, 10) using Δx = 0.5
    result = simpsonsOneThirdC(0.0f, 3.141f, 0.5f);
    printf("Simpson's 1/3 Result: %f\n", result);
    printf("Exact Result: %f\n", I_exact);
    printf("Error: %f\n", result - I_exact);

    return 0;
}

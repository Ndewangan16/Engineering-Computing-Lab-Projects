#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TOL 1e-10
#define MAX_ITER 1000

// Take  Functions 
void evaluate_functions(double x[], double f[]);
void jacobian(double x[], double J[3][3]);
void inverse_jacobian(double J[3][3], double J_inv[3][3]);
double norm_inf(double dx[]);

int main() {
    double x[3] = {0.1, 0.5, 0.5};  // Initial guess
    double f[3];
    double J[3][3];
    double J_inv[3][3];
    double dx[3];
    double E;
    
    FILE *output_file = fopen("output_problem_4.txt", "w");
    if (output_file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fprintf(output_file, "Iteration    x1\t           x2\t\t     x3\t\t  Error\n");

    for (int k = 0; k < MAX_ITER; k++) {
        evaluate_functions(x, f);
        jacobian(x, J);
        inverse_jacobian(J, J_inv);

        // Compute dx = -J_inv * f
        for (int i = 0; i < 3; i++) {
            dx[i] = 0.0;
            for (int j = 0; j < 3; j++) {
                dx[i] += -J_inv[i][j] * f[j];
            }
        }

        // Update x
        for (int i = 0; i < 3; i++) {
            x[i] += dx[i];
        }

        // Calculate error
        E = norm_inf(dx);
        
        // Write to file
        fprintf(output_file, "%d\t  %lf\t %lf\t %lf\t %lf\n", k, x[0], x[1], x[2], E);

        // Check for convergence
        if (E < TOL) {
            break;
        }
    }

    fclose(output_file);
    printf("Converged in %d iterations.\n", MAX_ITER);
    return 0;
}

// Given functions f(x1,x2,x3)
void evaluate_functions(double x[], double f[]) {
    f[0] = exp(x[0]) - 8 * x[0] * sin(x[1]);
    f[1] = x[0] + x[1] - 1;
    f[2] = pow(x[2] - 1, 3);
}

// find jacobian of f
void jacobian(double x[], double J[3][3]) {
    J[0][0] = exp(x[0]) - 8 * sin(x[1]);
    J[0][1] = -8 * x[0] * cos(x[1]);
    J[0][2] = 0;

    J[1][0] = 1;
    J[1][1] = 1;
    J[1][2] = 0;

    J[2][0] = 0;
    J[2][1] = 0;
    J[2][2] = 3 * pow(x[2] - 1, 2);
}

// find inverse of jacobian
void inverse_jacobian(double J[3][3], double J_inv[3][3]) {
    double det = J[0][0] * (J[1][1] * J[2][2] - J[1][2] * J[2][1])
               - J[0][1] * (J[1][0] * J[2][2] - J[1][2] * J[2][0])
               + J[0][2] * (J[1][0] * J[2][1] - J[1][1] * J[2][0]);

    if (fabs(det) < 1e-10) {
        printf("Jacobian is singular or close to singular.\n");
        exit(EXIT_FAILURE);
    }

    J_inv[0][0] = (J[1][1] * J[2][2] - J[1][2] * J[2][1]) / det;
    J_inv[0][1] = -(J[0][1] * J[2][2] - J[0][2] * J[2][1]) / det;
    J_inv[0][2] = (J[0][1] * J[1][2] - J[0][2] * J[1][1]) / det;

    J_inv[1][0] = -(J[1][0] * J[2][2] - J[1][2] * J[2][0]) / det;
    J_inv[1][1] = (J[0][0] * J[2][2] - J[0][2] * J[2][0]) / det;
    J_inv[1][2] = -(J[0][0] * J[1][2] - J[0][2] * J[1][0]) / det;

    J_inv[2][0] = (J[1][0] * J[2][1] - J[1][1] * J[2][0]) / det;
    J_inv[2][1] = -(J[0][0] * J[2][1] - J[0][1] * J[2][0]) / det;
    J_inv[2][2] = (J[0][0] * J[1][1] - J[0][1] * J[1][0]) / det;
}

// find error 
double norm_inf(double dx[]) {
    double max_val = fabs(dx[0]);
    for (int i = 1; i < 3; i++) {
        if (fabs(dx[i]) > max_val) {
            max_val = fabs(dx[i]);
        }
    }
    return max_val;
}


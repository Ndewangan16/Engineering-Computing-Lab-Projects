#include <stdio.h>
#include <math.h>

int main(){
    FILE *f;
    f = fopen("input.txt", "r");
    int n; // number of rows
    fscanf(f, "no of row is %d\n", &n);
    double A[n][n+1];
    
    // Reading the augmented matrix from the input file
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n+1; j++){
            fscanf(f, "%lf", &A[i][j]);
        }
    } 
    fclose(f); 
    
    // Gauss Elimination with Partial Pivoting
    for(int i = 0; i < n; i++){
        // Partial Pivoting: Finding the row with the largest element in the current column
        int max_row = i;
        for(int k = i+1; k < n; k++){
            if(fabs(A[k][i]) > fabs(A[max_row][i])){
                max_row = k;
            }
        }
        
        // Swapping the current row with the row of the largest element
        if(max_row != i){
            for(int j = 0; j < n+1; j++){
                double temp = A[i][j];
                A[i][j] = A[max_row][j];
                A[max_row][j] = temp;
            }
        }
        
        // Forward Elimination
        for(int ii = i+1; ii < n; ii++){
            double factor = A[ii][i] / A[i][i];
            for(int j = 0; j < n+1; j++){
                A[ii][j] -= factor * A[i][j];
            }
        }
    }  
    
    // Checking the type of solution
    if(A[n-1][n-1] == 0 && A[n-1][n] != 0){
        printf("No solution\n");
    } else if(A[n-1][n-1] == 0 && A[n-1][n] == 0){
        printf("Multiple solutions\n");
    } else {
        printf("Unique solution\n"); 
        
        // Back Substitution
        double x[n];
        for(int i = n-1; i >= 0; i--){
            x[i] = A[i][n];
            for(int j = i+1; j < n; j++){
                x[i] -= A[i][j] * x[j];
            }
            x[i] = x[i] / A[i][i];
        }
        
        // Writing the result to the output file
        FILE *fo;
        fo = fopen("output.txt", "w");
        fprintf(fo, "Upper triangular augmented matrix is:\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n+1; j++){
                fprintf(fo, "%.3lf\t", A[i][j]);
            }
            fprintf(fo, "\n");
        } 
        fprintf(fo, "\nValue of variables:\n");
        for(int i = 0; i < n; i++){
            fprintf(fo, "x%d = %.3lf\n", i+1, x[i]);
        }
        fclose(fo);
    }
    
    return 0;
}

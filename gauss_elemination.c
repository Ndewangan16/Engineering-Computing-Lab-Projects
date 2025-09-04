#include<stdio.h>
#include<math.h>


int main(){
    FILE *f ;
    f = fopen("input.txt","r");
    int n ; //no of row
    fscanf(f,"no of row is %d\n",&n);
    double A[n][n+1] ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            fscanf(f,"%lf",&A[i][j]);
        }
    } 
    fclose(f) ;
    
    for(int i=0;i<n;i++){
        double temp1 = A[i][i] ;
        for(int ii=i+1;ii<n;ii++){
            double temp2 = A[ii][i] ;
            for(int j=0;j<n+1;j++){
                A[ii][j] = A[ii][j] - (temp2/temp1)*A[i][j]; 
            }
        }
        
    }  
    if(A[n-1][n-1]==0 && A[n-1][n]!=0){
        printf("no solution \n");
    }
    if(A[n-1][n-1]==0 && A[n-1][n]==0){
        printf("multiple solution \n");
    }
    if(A[n-1][n-1]!=0 && A[n-1][n]!=0){
        printf("unique solution \n"); 
    }
    
    // Back Substitution
    double x[n];
    if(A[n-1][n-1]!=0 && A[n-1][n]!=0){
    for(int i=n-1; i>=0; i--){
        x[i] = A[i][n];
        for(int j=i+1; j<n; j++){
            x[i] = x[i] -  A[i][j] * x[j];
        }
        x[i] = x[i] / A[i][i];
    }    
    }
    
    
    
    FILE *fo ;
    fo = fopen("output.txt","w");
    fprintf(fo,"Upper triangular Augument matrix is \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            fprintf(fo,"%.3lf\t",A[i][j]);
        }
        fprintf(fo,"\n") ;
    } 
    fprintf(fo,"\n") ;
    fprintf(fo,"Value of variable is \n");
    for(int i=0;i<n;i++){
        fprintf(fo,"x%d = %0.3lf\n",i+1,x[i]);
    }
    fclose(fo);
    
    
    return(0);
    
}
#include<stdio.h>
#include<math.h> 

void main(){
    FILE *fi ;
    fi = fopen("input.txt","r");
    int n ;
    fscanf(fi,"no of eq %d\n",&n);
    double a[n][n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            fscanf(fi,"%lf",&a[i][j]) ;
        }
    }
    double error = 5 ;
    double x_old[n] ;
    double x[4]={0,0,0,0}; 
    while(error>0.0001){
        for(int i=0;i<n;i++){
            x_old[i] = x[i] ;
        }
        for(int i=0;i<n;i++){
            double sum = 0.0 ;
            for(int j=0;j<n;j++){
                if(j!=i){
                    sum = sum + a[i][j]*x[j] ;
                }
            }
            x[i] =( a[i][n] - sum ) / a[i][i] ;
            printf("%0.4lf\t",x[i]) ;
        }
    printf("\n");
    
   
   double sum = 0 ;
   for(int i=0;i<n;i++){
        sum = sum + x[i] - x_old[i];
   }    
   error = fabs(sum); 
   printf("%0.6lf\n",error);
    }
        

    FILE *fo ;
    fo = fopen("output.txt","w") ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            fprintf(fo,"%0.3lf\t",a[i][j]) ;
        }
        fprintf(fo,"\n");    
    }
    for(int i=0;i<n;i++){
        fprintf(fo,"x%d = %0.4lf\n",i+1,x[i]);
    }
    
    
}
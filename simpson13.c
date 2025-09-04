# include<stdio.h>
# include<math.h>

float simpson13(float x) ;

int main(){
    int n ;
    float x0,x1,h,sum_odd=0, sum_even=0,I ;
    
    printf("lower limit x0 = ");
    scanf("%f",&x0);
    printf("upper limit x1 = ");
    scanf("%f",&x1);  
    printf("n (must be even) = ");
    scanf("%d",&n);
    
    // Check if n is even
    if(n%2 != 0){
        printf("n must be even for Simpson's 1/3 rule.\n");
        return 1; // Exit with error code
    }
    
    h = (x1-x0)/n ;
    
    // Calculating sum for odd indexed points
    for(int i=1;i<n;i+=2){
        sum_odd += simpson13(x0 + i*h) ;
    }
    
    // Calculating sum for even indexed points
    for(int i=2;i<n;i+=2){
        sum_even += simpson13(x0 + i*h) ;
    }
    
    I = (h/3)*(simpson13(x0) + simpson13(x1) + 4*sum_odd + 2*sum_even) ;
    
    printf("I = %.3f",I) ; 
    
    return 0 ;
}

float simpson13(float x){
    return pow(x,3) + 1 ; // function f(x) = x^3 + 1
}

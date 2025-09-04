# include<stdio.h>
# include<math.h>

float simpson38(float x) ;

int main(){
    int n ;
    float x0,x1,h,sum_3=0, sum_2=0,I ;
    
    printf("lower limit x0 = ");
    scanf("%f",&x0);
    printf("upper limit x1 = ");
    scanf("%f",&x1);  
    printf("n (must be a multiple of 3) = ");
    scanf("%d",&n);
    
    // Check if n is a multiple of 3
    if(n%3 != 0){
        printf("n must be a multiple of 3 for Simpson's 3/8 rule.\n");
        return 1; // Exit with error code
    }
    
    h = (x1-x0)/n ;
    
    // Calculating sum for points with index multiple of 3
    for(int i=3;i<n;i+=3){
        sum_2 += simpson38(x0 + i*h) ;
    }
    
    // Calculating sum for other points (i.e. not multiple of 3)
    for(int i=1;i<n;i++){
        if(i%3 != 0){
            sum_3 += simpson38(x0 + i*h) ;
        }
    }
    
    I = (3*h/8)*(simpson38(x0) + simpson38(x1) + 3*sum_3 + 2*sum_2) ;
    
    printf("I = %.3f",I) ; 
    
    return 0 ;
}

float simpson38(float x){
    return pow(x,3) + 1 ; // function f(x) = x^3 + 1
}

# include<stdio.h>
# include<math.h>

float trapezoidal(float x) ; 

int main(){
    int n ;
    float x0,x1,h,sum,I ;
    
    printf("lower limit x0 = ");
    scanf("%f",&x0);
    printf("upper limit x1 = ");
    scanf("%f",&x1);  
    printf("n = ");
    scanf("%d",&n);
    
    h = (x1-x0)/n ;
    
    sum = 0 ;
    for(int i=1;i<n;i++){
        sum = sum + trapezoidal(x0+i*h) ;
    }
    
    I = 0.5*h*(trapezoidal(x0) + trapezoidal(x1) + 2*sum) ;
    
    printf("I = %.3f",I) ; 
    
    return 0 ;
}





float trapezoidal(float x){
    return pow(x,3)+1 ;
}
    

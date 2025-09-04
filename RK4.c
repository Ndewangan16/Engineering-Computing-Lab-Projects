# include<stdio.h>
# include<math.h>

double fun(double x , double y ){
	return x*x /(1 +y*y ); 
	//return -y;
	} 
	
	
void main(){
	double a = 0 ;
	double b = 1 ;
	double x_0 = 0 ;
	double y_0 = 0 ;
	int n ;
	printf("Enter n = ") ;
	scanf("%d",&n );
	double h = (b-a)/n ; 
	
	FILE *f ;
	f = fopen("out_RK4.txt","w");
	for(int i=1;i<=n;i=i+1){
		double x_1 = x_0 + h ;
		double k1 = fun(x_0,y_0) ;
		double k2 = fun(x_0 + 0.5*h , y_0 + 0.5*h*k1) ;
		double k3 = fun(x_0 + 0.5*h , y_0 + 0.5*h*k2) ;
		double k4 = fun(x_0 + h , y_0 + h*k3) ;
		
		double y_1 = y_0 + (h/6)*(k1 + 2*k2 + 2*k3 + k4) ;
		
		fprintf(f,"%d\t %0.8f\t %0.8f\n",i,x_1,y_1) ;  
		x_0 = x_1 ; 
		y_0 = y_1 ; 
		} 
		
} 
	

		
		

	

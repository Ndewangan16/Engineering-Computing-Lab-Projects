# include<stdio.h>
# include<math.h>

double fun(double x , double y ){
	return x*x /(1 +y*y ); 
	//return -y;
	} 
	
	
void main(){ 
	double a = 0 ;
	double b = 1 ;
	double w1 = 0.5 ;
	double w2 = 0.5 ;
	double alpha = 1 ;
	double beta = 1 ;
	
	int n ;
	printf("Enter n = ") ;
	scanf("%d",&n );   
	double h = (b-a)/n ; 
	double x_0 = 0 ;
	double y_0 = 0 ;
	FILE *f ;
	f = fopen("out_RK2.txt","w");
	for(int i=1;i<=n;i=i+1){
		double x_1 = x_0 + h ;
		double k1 = fun(x_0,y_0) ;
		double k2 = fun(x_0 + h*alpha ,y_0 + h*beta*k1) ;
		double y_1 = y_0 + h*(w1*k1 + w2*k2) ; 
		
		fprintf(f,"%d\t %0.8f\t %0.8f\n",i,x_1,y_1) ;  
		x_0 = x_1 ; 
		y_0 = y_1 ; 
		} 
		
} 
	

		
		

	

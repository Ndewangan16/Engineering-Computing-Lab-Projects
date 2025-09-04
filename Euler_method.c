# include<stdio.h>
# include<math.h>

double fun(double x , double y ){
	return x*x /(1 +y*y ) ; 
	} 
	
	
void main(){ 
	double a,b,x_0,y_0,h,x_1,y_1 ;
	a = 0 ; // lower limit 
	b = 1 ; // upper limit
	x_0 = 0 ;
	y_0 = 0 ;
	int n ;
	printf("Enter n = ") ;
	scanf("%d",&n );   
	h = (b-a)/n ; 
	
	FILE *f ;
	f = fopen("out_Euler.txt","w");
	fprintf(f,"n\t\t x\t\t\t y\n") ;
	for(int i=1;i<=n;i=i+1){
		x_1 = x_0 + h ;
		y_1 = y_0 + h*fun(x_0,y_0) ; 
		
		fprintf(f,"%d\t %0.8f\t %0.8f\n",i,x_1,y_1) ;  
		x_0 = x_1 ; 
		y_0 = y_1 ; 
		} 
		
}
#include<stdio.h>
#include<math.h>

double fun(double x){
	return pow(x,3) - 13 ;            // f(x) = x^3 - 13 
	}
	
int main(){
	double x_0 = 0.1 ;                 // initial gausse value 
	double delta = 0.01 ;
	double error = 1 ;
	FILE *fp ;
	fp = fopen("Output_Problem_1.txt","w") ; 
	fprintf(fp,"Iteration   function value\t Error\n");
	int it = 0 ;                       // no of iteration 
	while(error > 1e-5){
		double df = ( fun(x_0+delta) - fun(x_0-delta) )/(2*delta) ;  //  central difference 
		double x_1 = x_0 - fun(x_0)/df; 
		error = fabs(x_1 - x_0) ; 
		x_0 = x_1 ;                             // update new point 
		it = it+1 ;
		fprintf(fp,"%d\t\t\t %0.5f\t\t %0.5f\n",it,x_1,error);
		}
	fclose(fp);	
	return 0; 
	}


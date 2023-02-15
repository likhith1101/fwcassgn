/*Code by G. Likhitheshwar (works on termux)
Feb 15, 2023
Find the coordinates of the point which divides the join (−1,7) and (4,−3) in the ratio 3:2*/
 
#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"			//Functions
int main()                 
{
	double **a,**b,**c,**p,**q,**r;		//initializing the variables
	double area1;	 
	int m=2,n=1;
	a=loadtxt("a.dat",2,1);		//loading the point P from the text file
	b=loadtxt("b.dat",2,1);	 
	c=loadtxt("c.dat",2,1);
	p=scalar_mul(linalg_add(a,b,m,n),m,n,0.5);
	q=scalar_mul(linalg_add(b,c,m,n),m,n,0.5);
	r=scalar_mul(linalg_add(a,c,m,n),m,n,0.5);
	area1=0.5*(linalg_norm(cross_prod(linalg_sub(p,q,m,n),linalg_sub(p,r,m,n),1)));
	printf("%lf",area1);
	print(r,m,n);		//printing the result
	save(r,m,n);		//saving the result to the figure
}

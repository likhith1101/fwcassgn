/*Code by G. Likhitheshwar (works on termux)
Feb 15, 2023
Find the area of the triangle formed by joining the mid-points of the sides of the triangle
whose vertices are (0, –1), (2, 1) and (0, 3). Find the ratio of this area to the area of the
given triangle*/
#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"			//Functions
int main()                 
{
	double **a,**b,**c,**p,**q,**r;		//initializing the variables
	double area1,area2;	 
	int m=2,n=1;
	a=loadtxt("a.dat",2,1);				//loading the point A from the text file
	b=loadtxt("b.dat",2,1);	 			//loading the point B from the text file
	c=loadtxt("c.dat",2,1);				//loading the point C from the text file
	p=scalar_mul(linalg_add(a,b,m,n),m,n,0.5);	//Midpoint of A and B
	q=scalar_mul(linalg_add(b,c,m,n),m,n,0.5);	//Midpoint of B and C
	r=scalar_mul(linalg_add(a,c,m,n),m,n,0.5);	//Midpoint of A and C
	area1=0.5*(linalg_norm(cross_prod(linalg_sub(p,q,m,n),linalg_sub(p,r,m,n))));	//Area of triangle PQR 
	area2=0.5*(linalg_norm(cross_prod(linalg_sub(a,b,m,n),linalg_sub(a,c,m,n))));	//Area of triangle ABC
	printf("Resultant ratio is %lf : %lf",area1,area2);                             //printing the resultant ratio of two areas of triangle
	save_p(p,m,n);									//saving the resultant point P to the figure
	save_q(q,m,n);									//saving the resultant point Q to the figure
	save_r(r,m,n);									//saving the resultant point R to the figure
}

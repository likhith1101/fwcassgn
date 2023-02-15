/*Code by G. Likhitheshwar (works on termux)
Feb 14, 2023
Find the distance between the following pairs of points :
 a) (2,3), (4,1)
 b) (-5,7), (-1,3)
 c) (a,b), (-a,-b)*/
 
#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"			//Functions
int main()                 
{
	double **p,**q,**r;
	double ratio;		//initializing the variables as matrices
	int m=2,n=1;
	p=loadtxt("p.dat",2,1);		//loading the point A from the text file
	q=loadtxt("q.dat",2,1);	        //loading the point B from the text file
	ratio=3/2;
	r= scalar_mul((linalg_add(q,scalar_mul(p,m,n,ratio),m,n)),m,n,0.4);
	print(r,m,n);			//printing the result
	save(r,m,n);		//saving the result to the figure
}

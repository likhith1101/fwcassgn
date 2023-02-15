/*Code by G. Likhitheshwar (works on termux)
Feb 15, 2023
Find the coordinates of the point which divides the join (−1,7) and (4,−3) in the ratio 3:2*/
 
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
	ratio=1.5;
	r=scalar_mul(linalg_add(q,scalar_mul(p,m,n,ratio),m,n),m,n,1/(1+ratio));
	print(r,m,n);			//printing the result
	save(r,m,n);		//saving the result to the figure
}

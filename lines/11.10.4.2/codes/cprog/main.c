/*Code by G. Likhitheshwar (works on termux)
Feb 18, 2023
Find the values of theta  and  p, if the equation xcos(theta)+ysin(theta)=p is the normal form
of the line sqrt(3)x+y+2=0.
Code is free any one can use 
https://github.com/likhith1101/fwcassgn/blob/main/LICENSE.md
*/
 
#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"							//Functions
int main()                 
{
	double **a,**x,**b,**y,**n;				//initializing the variables
	double theta;
	double deg=210.0;
	int M=2,N=1,c=-2,p;
	x=loadtxt("x.dat",2,1);					//loading the point x intercepts from the given line
	y=loadtxt("y.dat",2,1);					//loading the point y intercepts from the given line
	n=loadtxt("n.dat",2,1);					//loading the point n from the text file
	a=loadtxt("a.dat",2,1);					//loading the point A from the text file
	p=abs(c)/linalg_norm(n,2);				//finding perpendicular distance pd	
	theta=radians(deg);   					//Store 210deg in radians form
	b=scalar_mul(dir_vec(cos(theta),sin(theta)),M,N,p);	//point B with a perpendicular distance
	save(b,M,N); 						//saving the result to the figure 
	printf("perpendicular distance is %d\n",p);		//printing the perpendicular distance
	printf("angle theta is %lf",deg);			//printing the angle	
	
	
}

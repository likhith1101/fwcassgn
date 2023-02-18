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
	double **a,**x1,**b1,**b2,**b3,**y1,**n1,**n2,**n3,**x2,**y2,**x3,**y3;				//initializing the variables
	double theta1,theta2,theta3;
	double deg1=120.0;
	double deg2=90.0;
	double deg3=315.0;
	int M=2,N=1;
	int c1=-8,c2=2,c3=4;
	double d1,d2,d3;
	
	// a) for line x−sqrt(3)y+8 = 0
	a=loadtxt("a.dat",2,1);	
	x1=loadtxt("x1.dat",2,1);					//loading the point x1 intercepts from the given line
	y1=loadtxt("y1.dat",2,1);
	n1=loadtxt("n1.dat",2,1);
	d1=abs(c1)/linalg_norm(n1,2);
	theta1=radians(deg1); 
	b1=scalar_mul(dir_vec(cos(theta1),sin(theta1)),M,N,d1);
	save_b1(b1,M,N);
	printf("perpendicular distance d1 is %lf\n",d1);		//printing the perpendicular distance
	printf("angle theta1 is %lf\n",deg1);			//printing the angle	
	
	// b) for line y-2=0
	x2=loadtxt("x2.dat",2,1);					//loading the point x intercepts from the given line
	y2=loadtxt("y2.dat",2,1);
	n2=loadtxt("n2.dat",2,1);
	d2=abs(c2)/linalg_norm(n2,2);
	theta2=radians(deg2);  
	b2=scalar_mul(dir_vec(cos(theta2),sin(theta2)),M,N,d2);
	save_b2(b2,M,N);
	printf("perpendicular distance d2 is %lf\n",d2);		//printing the perpendicular distance
	printf("angle theta2 is %lf\n",deg2);
	
	// c) for line x-y=4
	x3=loadtxt("x3.dat",2,1);					//loading the point x intercepts from the given line
	y3=loadtxt("y3.dat",2,1);
	n3=loadtxt("n3.dat",2,1);				//loading the point y intercepts from the given line			//loading the point n from the text file
	d3=abs(c3)/linalg_norm(n3,2);					//loading the point A from the text file
	theta3=radians(deg3);   					//Store 210deg in radians form									
	b3=scalar_mul(dir_vec(cos(theta3),sin(theta3)),M,N,d3);	//point B with a perpendicular distance
	save_b3(b3,M,N); 						//saving the result to the figure 
	printf("perpendicular distance d3 is %lf\n",d3);		//printing the perpendicular distance
	printf("angle theta3 is %lf\n",deg3);			//printing the angle	
	
	
}

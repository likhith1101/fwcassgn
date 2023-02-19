/*Code by G. Likhitheshwar (works on termux)
Feb 19, 2023

Reduce the following equations into normal form. Find their perpen-
dicular distances from the origin and angle between perpendicular and the
positive x-axis.
a) x − √3y + 8 = 0
b) y − 2 = 0
c) x − y = 4

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
	
	// a) for line x−√3y+8 = 0
	a=loadtxt("a.dat",2,1);						//loading the point A from the text file
	x1=loadtxt("x1.dat",2,1);					//loading the point x1 intercepts from the given line
	y1=loadtxt("y1.dat",2,1);					//loading the point y1 intercepts from the given line
	n1=loadtxt("n1.dat",2,1);					//loading the point normal vector from the given line
	d1=abs(c1)/linalg_norm(n1,2);					//calculating perpendicular distance d1
	theta1=radians(deg1); 						//Store 120deg in radians form	
	b1=scalar_mul(dir_vec(cos(theta1),sin(theta1)),M,N,d1);		//point B1 with a perpendicular distance
	save_b1(b1,M,N);						//saving the result to the figure 
	printf("perpendicular distance d1 is %lf\n",d1);		//printing the perpendicular distance d1
	printf("angle theta1 is %lf\n",deg1);				//printing the angle	
	
	
	
	// b) for line y-2=0
	x2=loadtxt("x2.dat",2,1);					//loading the point x2 intercepts from the given line
	y2=loadtxt("y2.dat",2,1);					//loading the point y2 intercepts from the given line
	n2=loadtxt("n2.dat",2,1);					//loading the point normal vector from the given line
	d2=abs(c2)/linalg_norm(n2,2);					//calculating perpendicular distance d2
	theta2=radians(deg2);  						//Store 90deg in radians form	
	b2=scalar_mul(dir_vec(cos(theta2),sin(theta2)),M,N,d2);		//point B2 with a perpendicular distance
	save_b2(b2,M,N);						//saving the result to the figure 
	printf("perpendicular distance d2 is %lf\n",d2);		//printing the perpendicular distance d2
	printf("angle theta2 is %lf\n",deg2);				//printing the angle
	
	
	
	// c) for line x-y=4
	x3=loadtxt("x3.dat",2,1);					//loading the point x3 intercepts from the given line
	y3=loadtxt("y3.dat",2,1);					//loading the point y3 intercepts from the given line
	n3=loadtxt("n3.dat",2,1);					//loading the point normal vector from the given line
	d3=abs(c3)/linalg_norm(n3,2);					//calculating perpendicular distance d3
	theta3=radians(deg3);   					//Store 315deg in radians form									
	b3=scalar_mul(dir_vec(cos(theta3),sin(theta3)),M,N,d3);		//point B3 with a perpendicular distance
	save_b3(b3,M,N); 						//saving the result to the figure 
	printf("perpendicular distance d3 is %lf\n",d3);		//printing the perpendicular distance d3
	printf("angle theta3 is %lf\n",deg3);				//printing the angle	
	
	
}

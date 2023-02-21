/*Code by G. Likhitheshwar (works on termux)
Feb 22, 2023

In each of the following cases, determine the direction cosines of the normal to
the plane and the distance from the origin.
1) z=2
2) x + y + z = 1
3) 2x + 3y – z = 5
4) 5y + 8 = 0

Code is free any one can use 
https://github.com/likhith1101/fwcassgn/blob/main/LICENSE.md
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"				//Functions
int main()
{
double **n1,**n2,**n3,**n4;      		//initializing the variables
int c1=2,c2=1,c3=5,c4=8;
double mag1,mag2,mag3,mag4;
double d1,d2,d3,d4;
int m=3;

// 1) z=2
n1 = loadtxt("n1.dat",m, 1);			//loading the point n1 from the text file
mag1=linalg_norm(n1,m);				//finding the magnitude of normal vector n1
d1=abs(c1)/mag1;				//finding the distance d1 from origin
printf("%lf\n",d1);				//printing distance d1

// 2) x+y+z=1
n2 = loadtxt("n2.dat",m, 1);			//loading the point n2 from the text file
mag2=linalg_norm(n2,m);				//finding the magnitude of normal vector n2
d2=abs(c2)/mag2;				//finding the distance d2 from origin
printf("%lf\n",d2);				//printing distance d2

// 3) 2x+3y-z=5
n3 = loadtxt("n3.dat",m, 1);			//loading the point n3 from the text file
mag3=linalg_norm(n3,m);				//finding the magnitude of normal vector n3
d3=abs(c3)/mag3;				//finding the distance d3 from origin
printf("%lf\n",d3);				//printing distance d3

// 4) 5y+8=0
n4 = loadtxt("n4.dat",m, 1);			//loading the point n4 from the text file
mag4=linalg_norm(n4,m);				//finding the magnitude of normal vector n4
d4=abs(c4)/mag4;				//finding the distance d4 from origin
printf("%lf\n",d4);				//printing distance d4
return 0;
}

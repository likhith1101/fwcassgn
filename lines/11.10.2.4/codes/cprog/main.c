/*Code by G. Likhitheshwar (works on termux)
Feb 17, 2023
Passing through (2,3.146) and inclined with the x-axis at an angle of 75 deg.
*/
 
#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"				//Functions
int main()                 
{
	double **a,**z,**m,**n;		//initializing the variables
	double theta;
	int M=2,N=1;
	a=loadtxt("a.dat",2,1);		//loading the point A from the text file
	theta=radians(75.0);   		//Store 75deg in radians form
	m=dir_vec(cos(theta),sin(theta));	//Direction vector m
	save(m,M,N); 			//saving the result to the figure
	z=loadtxt("z.dat",2,2);		//loading the point z from the text file
	n=matmul(z,m,M,2,2);		//Matrix multiplication of two matrices
	print(n,M,N);			//printing the normal vector
	
}

/*Code by G. Likhitheshwar (works on termux)
Feb 14, 2023
Find the distance between the following pairs of points :
 i) (2,3), (4,1)
 ii) (-5,7), (-1,3)
 iii) (a,b), (-a,-b)*/
 
#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"			//Functions
int main()                 
{
	double **a,**b,**c,**d,**e,**f,**sub1,**sub2,**sub3;		//initializing the variables as matrices
	double d1,d2,d3;
	int m=2,n=1;
	a=loadtxt("a.dat",2,1);		//loading the point A from the text file
	b=loadtxt("b.dat",2,1);	        //loading the point B from the text file
	c=loadtxt("c.dat",2,1);         //loading the point C from the text file
	d=loadtxt("d.dat",2,1);         //loading the point D from the text file
	e=loadtxt("e.dat",2,1);		//loading the point E from the text file
	f=loadtxt("f.dat",2,1);		//loading the point F from the text file
	sub1=linalg_sub(a,b,m,n);	//Subtraction of A and B matrices
	d1=linalg_norm(sub1,m);		//finding the Square of the norm
	sub2=linalg_sub(c,d,m,n);	//Subtraction of C and D matrices
	d2=linalg_norm(sub2,m);		//finding the Square of the norm
	sub3=linalg_sub(e,f,m,n);	//Subtraction of E and F matrices
	d3=linalg_norm(sub3,m);		//finding the Square of the norm
	
	print(d1,d2,d3);			//printing the result
	save(d1,d2,d3);		//saving the result to the figure
}

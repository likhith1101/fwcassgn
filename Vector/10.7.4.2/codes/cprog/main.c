/*Code by G. Likhitheshwar (works on termux)
Feb 16, 2023
Find a relation between x and y if the points (x, y), (1, 2)  and  (7, 0) are collinear.
Code is free any one can use 
https://github.com/likhith1101/fwcassgn/blob/main/LICENSE.md
*/
 
#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"			//Functions
int main()                 
{
	double **a,**b,**c,**d,**e,**f,**dt,**et;		//initializing the variables
	int r;
	int m=2,n=1;
	a=loadtxt("a.dat",2,1);	 //loading the point A from the text file
	b=loadtxt("b.dat",2,1);	//loading the point B from the text file 
	c=loadtxt("c.dat",2,1);//loading the point C from the text file
	d=linalg_sub(a,b,m,n); //subtraction of two matrices A and B
	e=linalg_sub(a,c,m,n);//subtraction of two matrices A and B
	dt=transpose(d,m,n); //transpose of matrix D
	et=transpose(e,m,n); //transpose of matrix E
	f=concat_two(dt,et); //concatentaing two matrices into a single matrix F
	r=rank(2,2,f);      //Finding the rank of matrix F
	save_r(r);          //saving the result to the figure
	if(r==1)            //check whether rank of matrix is equal to 1 or not
	{
		printf("collinear because rank(F) is one");
	}
	else
	{
		printf("not collinear because rank(F) is not equal to one");
	}
	
}

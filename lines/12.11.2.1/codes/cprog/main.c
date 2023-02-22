/*Code by G. Likhitheshwar (works on termux)
Feb 22, 2023
Show that the three lines with direction cosines  are mutually perpendicular.
12/13 ,−3/13 ,−4/13 ;4/13 ,12/13 ,3/13 ;3/13 ,−4/13 ,12/13
Code is free any one can use 
https://github.com/likhith1101/fwcassgn/blob/main/LICENSE.md
*/
 
#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>
#include"lib.h"			//Functions
int main()                 
{
	double **a,**b,**c,**p,**pt,**mul1,**mul2,**i;		//initializing the variables
	int m=3,n=1;
	a=loadtxt("a.dat",m,n);	//loading the point A from the text file
	b=loadtxt("b.dat",m,n);	//loading the point B from the text file 
	c=loadtxt("c.dat",m,n); //loading the point C from the text file
	i=loadtxt("i.dat",m,m); //loading the point i from the text file
	p=concat_three(a,b,c);//concatentaing three matrices into a single matrix p
	pt=transpose(p,3,3); //transpose of matrix P
	mul1=matmul(p,pt,3,3,3);//Multiplicaion of two matrices p.pt
	mul2=matmul(pt,p,3,3,3);//Multiplicaion of two matrices pt.p
	if(isOrthogonal(mul1,i,3,3,3,3) && isOrthogonal(mul2,i,3,3,3,3))//check whether p.pt and pt.p equal to I or not 
	{
		printf("Hence it is Orthogonal");
	}
	else
	{
        printf("Not Orthogonal");
	}
 
}

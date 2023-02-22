/*Code by G. Likhitheshwar (works on termux)
Feb 22, 2023
Show that the line joining the origin to the point (2, 1, 1) is perpendicular to the
line determined by the points (3, 5, – 1), (4, 3, – 1).
Code is free any one can use 
https://github.com/likhith1101/fwcassgn/blob/main/LICENSE.md

*/
 
#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"			//Functions
int main()                 
{
	int **p,**a,**b,**M,**Mt;	//initializing the variables
	int mul; 
	int m=3,n=1;
	p=loadtxt("p.dat",m,n);		//loading the point P from the text file
	a=loadtxt("a.dat",m,n);	        //loading the point A from the text file
	b=loadtxt("b.dat",m,n);		//loading the point B from the text file
	M=linalg_sub(a,b,m,n);		//Subtraction of A and B gives direction vector
	Mt=transpose(M,3,1);		//Transpose of a Matrix
	if(matmul(Mt,p,1,3,3)==0)	//Check whether it is perpendicular or not
	{
		printf("Hence,it satisfies both the above conditions, shows that line passing through origin is perpendiclar to the line passing through points A and B");
	}
	else
	{
		printf("Not perpendicular");
	}

				//finding R points using Section formula
			//printing the result		//saving the result to the figure
}

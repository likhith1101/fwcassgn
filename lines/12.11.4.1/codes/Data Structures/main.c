/*Code by G. Likhitheshwar (works on termux)
March 06, 2023
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
       Node *a = NULL;  // declaring the node for point A
       Node *b = NULL;  // declaring the node for point B	
       Node *p=NULL;    // declaring the node for point P
       Node *M=NULL;    // declaring the node for direction vector M
       Node *Mt=NULL;   // declaring the node for transpose of direction vector Mt
	int m=3,n=1;
	p=loadtxt("p.dat",m,n);		//loading the point P from the text file
	a=loadtxt("a.dat",m,n);	        //loading the point A from the text file
	b=loadtxt("b.dat",m,n);		//loading the point B from the text file
	M=linalg_sub(a,b);		//Subtraction of A and B gives direction vector
	Mt=transpose_matrix(M);	//Transpose of a Matrix
	if(matmul(Mt,p,n,n)->value==0)	//Check whether it is perpendicular or not
	{
		printf("Hence,it satisfies both the above conditions, shows that line passing through origin is perpendiclar to the line passing through point A and B");
	}
	else
	{
		printf("Not perpendicular");
	}

			
}

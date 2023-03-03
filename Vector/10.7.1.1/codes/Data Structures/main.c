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
    Node *a = NULL;  // declaring the node for point A
    Node *b = NULL;  // declaring the node for point B
Node *c = NULL;      // declaring the node for point C
    Node *d = NULL;  // declaring the node for point D
    Node *e= NULL;   // declaring the node for point E
    Node *f = NULL;  // declaring the node for point F
    Node *sub1=NULL; // declaring the node for sub1 
    Node *sub2=NULL; // declaring the node for sub2
    Node *sub3=NULL; // declaring the node for sub3
	double d1,d2,d3;
	int m=2,n=1;
	a=loadtxt("a.dat",2,1);		//loading the point A from the text file
	b=loadtxt("b.dat",2,1);	        //loading the point B from the text file
	c=loadtxt("c.dat",2,1);         //loading the point C from the text file
	d=loadtxt("d.dat",2,1);         //loading the point D from the text file
	e=loadtxt("e.dat",2,1);		//loading the point E from the text file
	f=loadtxt("f.dat",2,1);		//loading the point F from the text file
	sub1=linalg_sub(a,b);	//Subtraction of A and B matrices
	d1=linalg_norm(sub1,m,n);		//finding the Square of the norm
	sub2=linalg_sub(c,d);	//Subtraction of C and D matrices
	d2=linalg_norm(sub2,m,n);		//finding the Square of the norm
	sub3=linalg_sub(e,f);	//Subtraction of E and F matrices
	d3=linalg_norm(sub3,m,n);		//finding the Square of the norm
	
	printf("%lf,%lf,%lf",d1,d2,d3);			//printing the result
	save(d1,d2,d3);		//saving the result to the figure
}

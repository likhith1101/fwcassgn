/*Code by G. Likhitheshwar (works on termux)
Feb 23, 2023
Link to License("https://github.com/likhith1101/fwcassgn/blob/main/LICENSE.md")
Find the equation of circle with centre (-2,3) and radius 4 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{
	// Declaring the variables
	int **c, **u;
	int r=4, f;
	int m=2, n=1;

	// Loading the matrices from the text files
	c = loadtxt("c.dat", m, n);

	// Converting the value of c to negative(u=-c)
	u = neg(c, m, n);
	f = pow(linalg_norm(u,m), 2) - pow(r,2);

	// Printing and saving the results
	print(u, m, n);
	printf("\n%d",f);
	save_r(r);
	return r;

}

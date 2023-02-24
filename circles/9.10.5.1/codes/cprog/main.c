/*Code by G. Likhitheshwar (works on termux)
Feb 24, 2023
Link to License("https://github.com/likhith1101/fwcassgn/blob/main/LICENSE.md")

Q1. In Figure 1. A,B,C are the three points with centre O such that angleBOC=30degree and angleAOB=60degree. If D is a point on the circle other than the arc ABC, find angleADC
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{
	// Declaring the variables
	int **o;
	double **b,**c, **a, **d,**m1,**m2,**m1t;
	double normM1,normM2,angle;
	int r=1;
	int m=2, n=1;
	double mul,x;
	double alphadeg=30.0,betadeg=60.0,gammadeg=45.0;
	double phideg=alphadeg+betadeg;
	double alpha,beta,gamma,phi;

	o = loadtxt("o.dat", 2, 1);  // Loading the matrix O from the text files
	c = loadtxt1("c.dat", 2, 1); // Loading the matrix C from the text files


	alpha=radians(alphadeg);     //convert alpha degree into radians
	b=dir_vec(cos(alpha),sin(alpha)); //direction vector in B point
	print(b,m,n); //printing point B

	phi=radians(phideg);   //convert phi degree into radians
         a=dir_vec(cos(phi),sin(phi));//    direction vector in A point
       print(a,m,n);  //printing point A

       gamma=radians(gammadeg);  //convert gamma degree into radians
 d=dir_vec(-cos(gamma),-sin(gamma));  //direction vector in D point
         print(d,m,n);   //printing point D

	m1=linalg_sub(a,d,m,n);  //subtraction of A and D matrix
	m2=linalg_sub(c,d,m,n);  //subtracti    on of C and D matrix
	m1t=transpose(m1,m,n);   //transpose of m1 matrix
	normM1=linalg_norm1(m1,m);  //Norm or magnitude of m1
	normM2=linalg_norm1(m2,m);  //Norm or magnitude of m2
	mul=matmul(m1t,m2,1,2,2);  //matrix multiplication of two matrices
	x=mul/(normM1*normM2);  //finding the angle
  angle=acos(x)*180/3.14159265359; //Angle in degrees form
	printf("%lf",angle);  //printing the angle
	//saving all the results to the figure
	save_r(r);
        save_o(o,m,n);
	save_a(a,m,n);
	save_b(b,m,n);
	save_c(c,m,n);
	save_d(d,m,n);
	return 0;

}

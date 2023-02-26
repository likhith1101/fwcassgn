/*Code by G. Likhitheshwar (works on termux)
Feb 26, 2023
Link to License("https://github.com/likhith1101/fwcassgn/blob/main/LICENSE.md")

Q1. Prove that the line of centres of two intersecting circles subtends equal angles at the two points of intersection.
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{
	
	double **b,**c, **a, **d,**m,**m1,**m2,**m1t,**m3,**m4,**m3t,**v,**u,**q; // Declaring the variables
	double normM1,normM2,angle1,an1,normM3,normM4,angle2,an2;
	int r1=3,r2=2;
	double f=-9.0;
	double mul1,mul2,x;
	
	
	a = loadtxt1("a.dat", 2, 1); 	// Loading the matrix A from the text files
	b = loadtxt1("b.dat", 2, 1);	// Loading the matrix B from the text files
	m = loadtxt1("m.dat", 1, 2);	// Loading the matrix m from the text files
	v = loadtxt1("v.dat", 2, 2);	// Loading the matrix V from the text files
	u = loadtxt1("u.dat", 2, 1);	// Loading the matrix u from the text files
	q = loadtxt1("q.dat", 2, 1);	// Loading the matrix q from the text files
	
        
      
      c=inter_pt1(m,q,v,u,f);  //finding intersection point C
      d=inter_pt(m,q,v,u,f); 	//finding intersection point D
      print(c,2,1);            //printing point C
      print(d,2,1);		//printing point D
      
      m1=linalg_sub(a,d,2,1);  //subtraction of A and D matrix
	m2=linalg_sub(b,d,2,1);  //subtraction of C and D matrix
	m1t=transpose(m1,2,1);   //transpose of m1 matrix
	normM1=linalg_norm1(m1,2);  //Norm or magnitude of m1
	normM2=linalg_norm1(m2,2);  //Norm or magnitude of m2
	mul1=matmul_1(m1t,m2,1,2,2);  //matrix multiplication of two matrices
	an1=mul1/(normM1*normM2);  //finding the angle
  angle1=acos(an1)*180/3.14159265359; //Angle in degrees form
	printf("%lf\n",angle1);  //printing the angle
	
	m3=linalg_sub(a,c,2,1);  //subtraction of A and C matrix
	m4=linalg_sub(b,c,2,1);  //subtraction of B and C matrix
	m3t=transpose(m3,2,1);   //transpose of m3 matrix
	normM3=linalg_norm1(m3,2);  //Norm or magnitude of m3
	normM4=linalg_norm1(m4,2);  //Norm or magnitude of m4
	mul2=matmul_1(m3t,m4,1,2,2);  //matrix multiplication of two matrices
	an2=mul2/(normM3*normM4);  //finding the angle
  angle2=acos(an2)*180/3.14159265359; //Angle in degrees form
	printf("%lf\n",angle2); 	 //printing the angle
	
	if(angle1==angle2) //Check whether two angles are equal or not
	{
	printf("Hence proved, that two intersecting angles are equal");
	}
	else
	{
	printf("The intersecting angles are not equal");
	}
	

//saving the results to the figure
	save_r1(r1);
	save_r2(r2);
	save_a(a,2,1);
	save_b(b,2,1);
	save_c(c,2,1);
	save_d(d,2,1);
	

	return 0;

}

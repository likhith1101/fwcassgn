/*Code by G. Likhitheshwar (works on termux)
Feb 26, 2023
Link to License("https://github.com/likhith1101/fwcassgn/blob/main/LICENSE.md")
Find the coordinates of the focii, the vertices, the length of major and minor axes, the eccentricity and the length of the latus rectum of an ellipse whose equation is given by x^2/16 +y^2/9 = 1.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{
	// Declaring the variables
	double **v, **u, **o, **z, **A, **B, **C, **D, **F1, **F2, **G, **H, **I, **J, **N, **M, **e1;
	double **ellipAxis_A, **ellipAxis_B, **ellipMinorAxis_A, **ellipMinorAxis_B; 
	double lamda0, lamda1, fl1, fl2, lr1_Ay, lr2_Ay;
	int m=2,n=1, a=4, b=3, f=-144, f0=144;

	// Loading the matrices from text files
	v = loadtxt("data/v.dat", m, m);
	u = loadtxt("data/u.dat", m, n);
	o = loadtxt("data/o.dat", m, n);
	N = loadtxt("data/n.dat", m, n);
	e1 = loadtxt("data/e1.dat", m, n);
	z = loadtxt("data/z.dat", m, n);

	// Creating the matrices
	G = np_array(a, 0);
	H = np_array(-(a), 0);
	I = np_array(0, b);
	J = np_array(0, -(b));


	// Determining the Lamda vlaues from V matrix
	lamda0 = v[0][0];
	lamda1 = v[1][1];

        // Computing the eccentricity of ellipse
    	double e = sqrt(1 - lamda0 / lamda1);
    	double e_square = e * e;
   	printf("Eccentricity of Ellipse is %lf\n", e);

    	// Computing the Focal points 
    	F1 = mult_float(e * sqrt( f0 / (lamda1 * (1 - pow(e, 2)))), e1, m, n);
    	F2 = neg(F1, m, n);

    	// Finding the Norm values of Focal Points
    	fl1 = linalg_norm(F1, m);
    	fl2 = linalg_norm(F2, m);

    	// Determining the points of Major Axis 
ellipAxis_A = loadtxt("data/n.dat", m, n);
ellipAxis_B = scalar_mul(loadtxt("data/n.dat", m,n),m,n,-1.0);
    	// Determinig the points of Minor Axis
    	ellipMinorAxis_A=scalar_mul(matmul(z, N, m, n, 2), m, n,1/1.33);
    	ellipMinorAxis_B=scalar_mul(matmul(z, N, m, n, 2), m, n,-1/1.33);

    	lr1_Ay = sqrt((f0 - lamda0 * pow(fl1, 2)) / lamda1);
    	A = linalg_add(F1, np_array(0, lr1_Ay), m, n);
    	B = linalg_add(F1, np_array(0, -(lr1_Ay)), m, n);

    	lr2_Ay = sqrt((f0 - lamda0 * pow(fl2,2)) / lamda1);
    	C = linalg_add(F2, np_array(0, lr2_Ay), m, n);
    	D = linalg_add(F2, np_array(0, -(lr2_Ay)), m, n);

    	// Saving the results in text files
    	save(ellipAxis_A, m, n,"data/ellipAxis_A.dat");
    	save(ellipAxis_B, m, n, "data/ellipAxis_B.dat");
    	save(ellipMinorAxis_A, m, n, "data/ellipMinorAxis_A.dat");
    	save(ellipMinorAxis_B, m, n, "data/ellipMinorAxis_B.dat");
    	save(A, m, n, "data/A.dat");
    	save(B, m, n, "data/B.dat");
    	save(C, m, n, "data/C.dat");
    	save(D, m, n, "data/D.dat");
    	save(H, m, n, "data/H.dat");
    	save(G, m, n, "data/G.dat");
    	save(F1, m, n, "data/F1.dat");
    	save(F2, m, n, "data/F2.dat");
}

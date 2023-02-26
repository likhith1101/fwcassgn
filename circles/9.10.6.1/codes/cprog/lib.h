//Function declaration
//End function declaration


//Defining the function for matrix creation


int **createMat(int m,int n)
{
 int i;
 int **a;
 
 //Allocate memory to the pointer
a = (int **)malloc(m * sizeof( *a));
    for (i=0; i<m; i++)
         a[i] = (int *)malloc(n * sizeof( *a[i]));

 return a;
}
//End function for matrix creation


//Defining the function for reading matrix 
void readMat(double **p, int m,int n)
{
 int i,j;
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%lf",&p[i][j]);
  }
 }
}
//End function for reading matrix

//Read  matrix from file
int **loadtxt(char *str,int m,int n)
{
FILE *fp;
int **a;
int i,j;


a = createMat(m,n);
fp = fopen(str, "r");

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   fscanf(fp,"%d",&a[i][j]);
  }
 }
//End function for reading matrix from file

fclose(fp);
 return a;

}



//Defining the function for printing
void print(double **p, int m,int n)
{
 int i,j;

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  printf("%lf ",p[i][j]);
 printf("\n");
 }
}
//End function for printing

//Defining the function for norm



//End function declaration

//Defining the function for matrix creation
double **createMat1(int m,int n)
{
 int i;
 double **a;
 
 //Allocate memory to the pointer
a = (double **)malloc(m * sizeof( *a));
    for (i=0; i<m; i++)
         a[i] = (double *)malloc(n * sizeof( *a[i]));

 return a;
}
//End function for matrix creation


//Defining the function for matrix creation
//End function for matrix creation



//Read  matrix from file

//End function for reading matrix from file



double **loadtxt1(char *str,int m,int n)
{
FILE *fp;
double **a;
int i,j;


a = createMat1(m,n);
fp = fopen(str, "r");

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   fscanf(fp,"%lf",&a[i][j]);
  }
 }
//End function for reading matrix from file

fclose(fp);
 return a;

}



//Defining the function for norm

double linalg_norm1(double **a, int m)
{
int i;
double norm=0.0;

 for(i=0;i<m;i++)
 {
norm = norm + a[i][0]*a[i][0];
}
return sqrt(norm);

}


int linalg_norm(int **a, int m)
{
int i;
int norm=0;

 for(i=0;i<m;i++)
 {
norm = norm + a[i][0]*a[i][0];
}
return sqrt(norm);

}
//End function for norm

//Defining the function for difference of matrices

double **linalg_sub(double **a, double **b, int m, int n)
{
int i, j;
double **c;
c = createMat1(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]-b[i][j];
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for inverse of 2x2 matrix


/*double **linalg_inv(double **mat, int m)
{
double **c, det;
c = createMat(m,m);

det = mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];

c[0][0] = mat[1][1]/det;
c[0][1] = -mat[1][0]/det;
c[1][0] = -mat[0][1]/det;
c[1][1] = mat[0][0]/det;

return c;

}*/
// End  function for inverse of 2x2 matrix


//Defining the function for difference of matrices

double **matmul(double **a, double **b, int m, int n, int p)
{
int i, j, k;
double **c, temp =0;
c = createMat1(m,p);

 for(i=0;i<m;i++)
 {
  for(k=0;k<p;k++)
  {
    for(j=0;j<n;j++)
    {
	temp= temp+a[i][j]*b[j][k];
    }
	c[i][k]=temp;
	temp = 0;
  }
 }
return c;

}

double matmul_1(double **a, double **b, int m, int n, int p)
{
int i, j, k;
double **c, temp =0;
c = createMat1(m,p);

 for(i=0;i<m;i++)
 {
  for(k=0;k<p;k++)
  {
    for(j=0;j<n;j++)
    {
	temp= temp+a[i][j]*b[j][k];
    }
	c[i][k]=temp;
	temp = 0;
  }
 }
return c[0][0];

}

//End function for difference of matrices

//Defining the function for transpose of matrix

double **transpose(double **a,  int m, int n)
{
int i, j;
double **c;
//printf("I am here");
c = createMat1(n,m);

 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
c[i][j]= a[j][i];
//  printf("%lf ",c[i][j]);
  }
 }
return c;

}
//End function for transpose of matrix
double mat_mult(double **a, double **b, int m,int n, int p)
{
int i, j, k;
double c, temp =0;
//c = createMat(m,p);                                                            
for(i=0;i<m;i++)
 {
  for(k=0;k<p;k++)
  {
    for(j=0;j<n;j++)
    {
        temp= temp+a[i][j]*b[j][k];
    }
        c=temp;
        temp = 0;
  }
 }
return c;

}

double **mult_int(int scalar,double **a,int m, int n)
{
  int i, j;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      a[i][j] *= scalar;
    }
  }
  return a;
}


void save_a(double **a, int rows, int cols) {
  FILE *fp;
  fp = fopen("a.dat", "w");
  //fprintf(fp, "The result of the multiplication is:\n");
  int i, j;
  for (i = 0; i < rows; i++) {
    //fprintf(fp, "[");
    for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);
      if (j < cols - 1) {
        //fprintf(fp, ", ");
      }
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}

void save_b(double **a, int rows, int cols) {
  FILE *fp;
  fp = fopen("b.dat", "w");
  //fprintf(fp, "The result of the multiplication is:\n");
  int i, j;
  for (i = 0; i < rows; i++) {
    //fprintf(fp, "[");
    for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);
      if (j < cols - 1) {
        //fprintf(fp, ", ");
      }
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}


void save_c(double **a, int rows, int cols) {
  FILE *fp;
  fp = fopen("c.dat", "w");
  //fprintf(fp, "The result of the multiplication is:\n");
  int i, j;
  for (i = 0; i < rows; i++) {
    //fprintf(fp, "[");
    for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);
      if (j < cols - 1) {
        //fprintf(fp, ", ");
      }
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}

void save_d(double **a, int rows, int cols) {
  FILE *fp;
  fp = fopen("d.dat", "w");
  //fprintf(fp, "The result of the multiplication is:\n");
  int i, j;
  for (i = 0; i < rows; i++) {
    //fprintf(fp, "[");
    for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);
      if (j < cols - 1) {
        //fprintf(fp, ", ");
      }
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}

double **linalg_add(double **a, double **b,
int m, int n)
{
int i, j;
double **c;
c = createMat1(m,n);

 for(i=0;i<m;i++)
{
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]+b[i][j];
  }
 }
return c;

}

double **linalg_add_1(double **a, double **b,double **c, int m, int n)
{
int i, j;
double **d;
d = createMat1(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
d[i][j]= a[i][j]+b[i][j]+c[i][j];
  }
 }
return d;

}

double **mult_float(float scalar,double **a,int m, int n)
{
  int i, j;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      a[i][j] *= scalar;
    }
  }
  return a;
}

double **scalar_mul(double **A,int row,int col,double num)
{
int i,j;
 for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            /* (cAij) = c . Aij */
            A[i][j] = num * A[i][j];
        }
    }
    return A;
}

int** neg(int** matrix, int m, int n) {
    int** neg_matrix = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        neg_matrix[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) {
                neg_matrix[i][j] = -matrix[i][j];
            } else {
                neg_matrix[i][j] = matrix[i][j];
            }
        }
    }
    return neg_matrix;
}
 void save_r1(int r1) {
  FILE *fp;
  fp = fopen("r1.dat", "w");
  //fprintf(fp, "The result of the multiplication is:\n");
      fprintf(fp, "%d", r1);
  fclose(fp);
}




 void save_r2(int r2) {
  FILE *fp;
  fp = fopen("r2.dat", "w");
  //fprintf(fp, "The result of the multiplication is:\n");
      fprintf(fp, "%d", r2);
  fclose(fp);
}

double **dir_vec(double a,double b)
{
	double **m;
	m=createMat1(2,1);
	m[0][0]=a;
	m[1][0]=b;
	return m;
}

double radians(double deg)
{
	double rad;
	rad=deg*(3.14159265/180.0);
	return rad;
}

double **roots(double a,double b,double c)
{
	double discriminant, root1, root2, realPart, imagPart; 
	   double **z;
discriminant = b * b - 4 * a * c;

    // condition for real and different roots
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
 
    }

    // condition for real and equal roots
    else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
   
    }

    // if roots are not real
    else {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
       
    }
   z=createMat1(2,1);
   z[0][0]=root1;
   z[1][0]=root2;
   return z;
}

double conic_quad(double **q,double **v,double **u,double f)
{
	double s= (matmul_1(matmul(transpose(q,2,1),v,1,2,2),q,1,2,2))+2*(matmul_1(transpose(u,2,1),q,1,2,2))+f;
return s;
}

double **inter_pt(double **m,double **q,double **v,double **u,double f)
{
double **x;
double **l;
double a,b,c,l1,l2;
double **x1,**x2;
x=matmul(m,v,1,2,2);
a=matmul_1(x,transpose(m,1,2),1,2,2);
b=matmul_1(m,linalg_add(matmul(v,q,2,2,2),u,2,1),1,2,2);
c = conic_quad(q,v,u,f);
l = roots(a,2*b,c);
l1=l[0][0];
x1=linalg_add(q,scalar_mul(transpose(m,1,2),2,1,l1),2,1);
return x1;
}

double **inter_pt1(double **m,double **q,double **v,double **u,double f)          
      {                                           
       double **x;                                  
       double **l;                                 
       double a,b,c,l1,l2;
 double **x1,**x2;                           
 x=matmul(m,v,1,2,2);
a=matmul_1(x,transpose(m,1,2),1,2,2);
b=matmul_1(m,linalg_add(matmul(v,q,2,2,2),u,2,1),1,2,2);                             
 c = conic_quad(q,v,u,f);              
       l = roots(a,2*b,c);              
                  l2=l[1][0];                             
                      x2=linalg_add(q,scalar_mul(transpose(m,1,2),2,1,l2),2,1);                               
                        return x2;    
                                                       }

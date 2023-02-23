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

/*double **linalg_sub(double **a, double **b, int m, int n)
{
int i, j;
double **c;
c = createMat(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]-b[i][j];
  }
 }
return c;

}*/
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

}
// End  function for inverse of 2x2 matrix


//Defining the function for difference of matrices

double **matmul(double **a, double **b, int m, int n, int p)
{
int i, j, k;
double **c, temp =0;
c = createMat(m,p);

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
//End function for difference of matrices

//Defining the function for transpose of matrix

double **transpose(double **a,  int m, int n)
{
int i, j;
double **c;
//printf("I am here");
c = createMat(n,m);

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

void save(double **a, int rows, int cols) {
  FILE *fp;
  fp = fopen("result.dat", "w");
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
c = createMat(m,n);

 for(i=0;i<m;i++)
{
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]+b[i][j];
  }
 }
return c;

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
}*/

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
 void save_r(int r) {
  FILE *fp;
  fp = fopen("r.dat", "w");
  //fprintf(fp, "The result of the multiplication is:\n");
      fprintf(fp, "%d", r);
  fclose(fp);
}

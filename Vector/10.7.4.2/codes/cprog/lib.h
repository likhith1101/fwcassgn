double **createMat(int m,int n);
void print(double **p, int m,int n);
double **loadtxt(char *str,int m,int n);
double linalg_norm(double **a, int m);
double **linalg_sub(double **a, double **b, int m, int n);
double **linalg_add(double **a, double **b, int m, int n);
double **scalar_mul(double **A,int row,int col,double num);
double cross_prod(double **a,double **b);
double **concat_two(double **a,double **b);
int rank(int r1, int c1,double **a);
double **transpose(double **a,  int m, int n);
double **createMat1(int m,int n);
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
double **createMat(int m,int n)
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



//Read  matrix from file
double **loadtxt(char *str,int m,int n)
{
FILE *fp;
double **a;
int i,j;


a = createMat(m,n);
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

double linalg_norm(double **a, int m)
{
int i;
double norm=0.0;

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
c = createMat(m,n);

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

double **linalg_add(double **a, double **b, int m, int n)
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

double **concat_two(double **a,double **b)
{
	double **f;
	int m=2;
	int n=2;
	f=createMat(m,n);
	f[0][0]=a[0][0];
	f[0][1]=a[0][1];
	f[1][0]=b[0][0];
	f[1][1]=b[0][1];
	return f;
}

void swap(int r1, int r2, int c,double **a)
{
   int t;
   int i,j;
   for(i=0;i<c;i++)
   {
      t= a[r1][i];
      a[r1][i] = a[r2][i];
      a[r2][i]=t;
   }
}
	
int rank(int r1, int c1,double **a)
{
    int i,j,k;
    float ratio;
    for(i=0;i<c1;i++)
    {
       if(a[i][i]!=0)    /* Diagonal element is not zero */
     for(j=0;j<r1;j++)
       if (j!=i)
       {
          /* Make all the element above and nelow the current principal
         diagonal element zero */
          ratio = a[j][i]/a[i][i];
          for(k=0;k<c1;k++)
         a[j][k]-=ratio*a[i][k];
       }
       else
         printf("\n");
         /* principal Diagonal element is zero */
       else
       {
       for(j=i+1;j<r1;j++)
          if(a[j][i]!=0)
          {   /* Find non zero elements in the same column */
          swap(i,j,c1,a);
          break;
          }
          if(j==r1)
          {
          c1--;
          for(j=0;j<r1;j++)
             a[j][i] = a[j][c1];
          }
          i--;
         }
     }
   return  c1;
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

void save_r(int r)
{
	FILE *fp;                                   fp = fopen("rank.dat", "w");
	fprintf(fp,"%d",r);
fclose(fp);
}

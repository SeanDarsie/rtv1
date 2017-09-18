#include "../ft_rtv1.h"

/* t_augmat *solve_system(t_vec *a, t_vec *b, t_vec * c) */
/* { */
/*   t_augmat *matrix; */

/*   matrix = malloc (sizeof(t_augmat)); */

  
/* } */
void swap_row(double **matrix, int row1, int row2)
{
  int i;
  double temp;

  i = -1;
  while (++i < 4)
    {
      temp = matrix[row1][i];
      matrix[row1][i] = matrix[row2][i];
      matrix[row2][i] = temp;
    }
}

void print_mat(double **matrix)
{
  int i;
  int k;

  i = -1;
  while (++i < 3)
    {
      k = -1;
      while (++k < 4)
	printf("(row,col) (%i,%i) val: %f\n", i, k, matrix[i][k]); 
    }
}

/* void row_echelon(double **matrix) /\* transform matrix to row echelon form *\/ */
/* { */
/*   int i; */

/*   i = -1; */
  
/* } */

double  **init_matrix(t_vec *a,t_vec *b,t_vec *c, t_vec *pi)
{
  double **matrix;
  int i;
  
  matrix = (double**)malloc(sizeof(double*) * 3);
  i = -1;
  while (++i < 3)
    matrix[i] = (double*)malloc(sizeof(double) * 4);
  matrix[0][0] = a->x;
  matrix[0][1] = b->x;
  matrix[0][2] = c->x;
  matrix[0][3] = pi->x;
  matrix[1][0] = a->y;
  matrix[1][1] = b->y;
  matrix[1][2] = c->y;
  matrix[1][3] = pi->y;
  matrix[2][0] = a->z;
  matrix[2][1] = b->z;
  matrix[2][2] = c->z;
  matrix[2][3] = pi->z;
  return (matrix);
}

void delete_matrix(double **matrix)
{
  int i;

  i = -1;
  while (++i < 3)
    free(matrix[i]);
  free(matrix);
}




int forward_elim(double **mat)
{
  int k;
  int i;
  int j;
  int i_max;
  int v_max;

  k = -1;
  while (++k < 3)
    {
        // Initialize maximum value and index for pivot
        i_max = k;
        v_max = mat[i_max][k];
 
        /* find greater amplitude for pivot if any */
	i = k + 1;
        while (i < 3)
	  {
	    if (fabs(mat[i][k]) > v_max)
	      v_max = mat[i][k], i_max = i;
	    i++;
	  }
 
        /* if a prinicipal diagonal element  is zero,
         * it denotes that matrix is singular, and
         * will lead to a division-by-zero later. */
        if (!mat[k][i_max])
            return k; // Matrix is singular
 
        /* Swap the greatest value row with current row */
        if (i_max != k)
            swap_row(mat, k, i_max);
 
	i = k + 1;
        while (i < 3)
        {
            /* factor f to set current row kth elemnt to 0,
             * and subsequently remaining kth column to 0 */
            double f = mat[i][k]/mat[k][k];
 
            /* subtract fth multiple of corresponding kth
               row element*/
	    j = k + 1;
            while (j <= 3)
	      {
		mat[i][j] -= mat[k][j]*f;
		j++;
	      }
 
            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0;
	    i++;
        }
 
	//    print_mat(mat);        //for matrix state
    }
  //print_mat(mat);            //for matrix state
    return -1;
}

double *back_sub(double **mat)
{
    double *x;  // An array to store solution
    int i;
    int j;
    /* Start calculating from last equation up to the
       first */
    i = 2;
    x  = malloc(sizeof(double) * 3);
    while (i >= 0)
    {
        /* start with the RHS of the equation */
        x[i] = mat[i][3];
 
        /* Initialize j to i+1 since matrix is upper
           triangular*/
	j = i + 1;
        while (j < 3)
        {
            /* subtract all the lhs values
             * except the coefficient of the variable
             * whose value is being calculated */
            x[i] -= mat[i][j]*x[j];
	    j++;
        }
 
        /* divide the RHS by the coefficient of the
           unknown being calculated */
        x[i] = x[i]/mat[i][i];
	i--;
    }
 
    /* printf("\nSolution for the system:\n"); */
    /* for (int i=0; i<3; i++) */
    /*     printf("%lf\n", x[i]); */
    return (x);
}

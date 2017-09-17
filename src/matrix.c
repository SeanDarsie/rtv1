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

void row_echelon(double **matrix) /* transform matrix to row echelon form */
{
  int i;

  i = -1;
  
}

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




int forwardElim(double **mat)
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
                mat[i][j] -= mat[k][j]*f;
 
            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0;
        }
 
        print_mat(mat);        //for matrix state
    }
    //print(mat);            //for matrix state
    return -1;
}

/* int forwardElim(double mat[N][N+1]) */
/* { */
/*     for (int k=0; k<N; k++) */
/*     { */
/*         // Initialize maximum value and index for pivot */
/*         int i_max = k; */
/*         int v_max = mat[i_max][k]; */
 
/*         /\* find greater amplitude for pivot if any *\/ */
/*         for (int i = k+1; i < N; i++) */
/*             if (abs(mat[i][k]) > v_max) */
/*                 v_max = mat[i][k], i_max = i; */
 
/*         /\* if a prinicipal diagonal element  is zero, */
/*          * it denotes that matrix is singular, and */
/*          * will lead to a division-by-zero later. *\/ */
/*         if (!mat[k][i_max]) */
/*             return k; // Matrix is singular */
 
/*         /\* Swap the greatest value row with current row *\/ */
/*         if (i_max != k) */
/*             swap_row(mat, k, i_max); */
 
 
/*         for (int i=k+1; i<N; i++) */
/*         { */
/*             /\* factor f to set current row kth elemnt to 0, */
/*              * and subsequently remaining kth column to 0 *\/ */
/*             double f = mat[i][k]/mat[k][k]; */
 
/*             /\* subtract fth multiple of corresponding kth */
/*                row element*\/ */
/*             for (int j=k+1; j<=N; j++) */
/*                 mat[i][j] -= mat[k][j]*f; */
 
/*             /\* filling lower triangular matrix with zeros*\/ */
/*             mat[i][k] = 0; */
/*         } */
 
/*         //print(mat);        //for matrix state */
/*     } */
/*     //print(mat);            //for matrix state */
/*     return -1; */
/* } */

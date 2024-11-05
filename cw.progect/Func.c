//
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"

int create_vector(int* count, int** vector)
{
  int i = 0;
  printf("Enter n - number measurement, in which the vector exists : ");
  scanf("%d", count);
  if (*count < 0 || *count>500000000)
  {
    printf("Error sizer!!!\n");
    return -1;
  }
  *vector = (int*)malloc(*count * sizeof(int));
  for (i = 0; i < *count; i++)
  {
    (*vector)[i] = rand() % 10;
  }
  return 0;
}
//
void free_vector(int* vector)
{
  return free(vector);
}
//
int sum_vectors(int n1, int* vector_1, int n2, 
  int* vector_2, int** vector_3)
{
  int i, nsum, n3 = 0;
  printf("Vector sum: ");
  if (n1 >= n2)
    n3 = n1;
  else
    n3 = n2;
  *vector_3 = (int*)malloc(n3 * sizeof(int));
  if (n1 >= n2)
  {
    nsum = n2;
    for (i = 0; i < n3; i++)
    {
      if (i < nsum)
      {
        (*vector_3)[i] = (int)vector_1[i] + (int)vector_2[i];
        printf("%d ", (int)((*vector_3)[i]));
      }
      else
      {
        (*vector_3)[i] = (int)vector_1[i];
        printf("%d ", (int)((*vector_3)[i]));
      }
    }
  }
  else
  {
    nsum = n1;
    for (i = 0; i < n3; i++)
    {
      if (i < nsum)
      {
        (*vector_3)[i] = (int)vector_1[i] + (int)vector_2[i];
        printf("%d ", (int)((*vector_3)[i]));
      }
      else
      {
        (*vector_3)[i] = (int)vector_2[i];
        printf("%d ", (int)((*vector_3)[i]));
      }
    }
  }
  printf("\n");
  return 0;
}

//
int mul_vectors(int n1, int* vector_1, int n2, int* vector_2)
{
  int i, nmul, mul = 0;
  if (n1 > n2)
    nmul = n2;
  else
    nmul = n1;
  for (i = 0; i < nmul; i++)
  {
    mul += (vector_1[i] * vector_2[i]);
  }
  return mul;
}

//
double len_of_vector(int n, int* vector)
{
  int i = 0, len = 0;
  double res = 0;
  for (i = 0; i < n; i++)
  {
    len += (vector[i] * vector[i]);
  }
  res = pow(len, 0.5);
  return res;
}
//
double angle_between_vectors(int n1, int* vector1, int n2, int* vector2)
{
  double res;
  res = (mul_vectors(n1, vector1, n2, vector2) / (double)(len_of_vector(n1, vector1) * len_of_vector(n2, vector2)));
  res = acos(res) * (double)180 / M_PI;
  return res;
}

//
void mul_vector_on_scal(int n, int* vector, int scal)
{
  int i = 0;
  for (i; i < n; i++)
  {
    vector[i] *= scal;
  }
}
//
void create_matrix(int* columns, int* strings, int*** matrix)
{
  printf("Enter quantity columns: ");
  scanf("%d", columns);
  printf("Enter quantity strings: ");
  scanf("%d", strings);
  (*matrix) = (int**)malloc(sizeof(int*) * *columns);
  for (int counter = 0; counter < *columns; counter++)
  {
    (*matrix)[counter] = (int*)malloc(sizeof(int) * *strings);
  }

  for (int counter1 = 0; counter1 < *columns; counter1++)
  {
    for (int counter2 = 0; counter2 < *strings; counter2++)
    {
      (*matrix)[counter1][counter2] = rand() % 10;
    }
  }
}
void create_vector_matrix(int* columns, int* strings, int*** matrix)
{
  printf("Enter n - number measurement, in which the vector exists : ");
  scanf("%d", columns);
  (*matrix) = (int**)malloc(sizeof(int*) * *columns);
  for (int counter = 0; counter < *columns; counter++)
  {
    (*matrix)[counter] = (int*)malloc(sizeof(int) * *strings);
  }

  for (int counter1 = 0; counter1 < *columns; counter1++)
  {
    for (int counter2 = 0; counter2 < *strings; counter2++)
    {
      if (counter2 % 2 == 0)
        (*matrix)[counter1][counter2] = rand() % 10;
      else
        (*matrix)[counter1][counter2] = 0;
    }
  }
}
//
void free_matrix(int columns, int** matrix)
{
  for (int counter = 0; counter < columns; counter++)
    free(matrix[counter]);
  free(matrix);
}

void Sum_matrix(int** matrix_1, int** matrix_2, int columns_1, int string_1, 
   int columns_2, int string_2, int*** matrix)
{
  int counter_1, counter_2, columns_res, string_res;
  if (columns_1 != columns_2 || string_1 != string_2)
    return;
  (*matrix) = (int**)malloc(sizeof(int*) * columns_1);
  for (int counter = 0; counter < columns_1; counter++)
  {
    (*matrix)[counter] = (int*)malloc(sizeof(int) * string_1);
  }
  for (counter_1 = 0; counter_1 < columns_1; counter_1++)
  {
    for (counter_2 = 0; counter_2 < string_2; counter_2++)
    {
      (*matrix)[counter_1][counter_2] = matrix_1[counter_1][counter_2] + matrix_2[counter_1][counter_2];
    }
  }
}
int Mul(int n_a, int m_a, int** matrix_a, int n_b,
  int m_b, int** matrix_b, int*** matrix_res)
{
  int i, j, e, n, m;
  int k;
  if (m_a != n_b)
    return -1;
  (*matrix_res) = (int**)malloc(n_a * sizeof(int*));
  for (i = 0; i < n_a; ++i)
  {
    (*matrix_res)[i] = (int*)malloc(m_b * sizeof(int));
    for (j = 0; j < m_b; ++j)
    {
      (*matrix_res)[i][j] = 0;
    }
  }

  n = n_a;
  m = m_b;
  k = n_b;

  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < m; ++j)
    {
      for (e = 0; e < k; ++e) {
        (*matrix_res)[i][j] += matrix_a[i][e] * matrix_b[e][j];
      }
    }
  }

  return 0;
}

int MulK(int n, int m, int*** matrix, int k)
{
  int i, j;
  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < m; ++j)
    {
      *matrix[i][j] *= k;
    }
  }
  return 0;
}
int Trans(int n, int m, int** matrix, int*** matrix_res)
{
  int i, j, n_res, m_res;
  n_res = m;
  m_res = n;
  (*matrix_res) = (int**)malloc(m * sizeof(int*));
  for (i = 0; i < m; ++i)
  {
    (*matrix_res)[i] = (int*)malloc(n * sizeof(int));
    for (j = 0; j < n; ++j)
    {
      (*matrix_res)[i][j] = matrix[j][i];
    }
  }
  return 1;
}
void print_for_matrix(int columns, int strings, int** matrix)
{
  int counter1, counter2;
  for (int counter1 = 0; counter1 < columns; counter1++)
  {
    if (counter1 == 0)
      printf("/\t");
    else if (counter1 + 1 == columns)
      printf("\\\t");
    else
      printf("|\t");
    for (int counter2 = 0; counter2 < strings; counter2++)
    {
      printf("%d\t", (matrix)[counter1][counter2]);
    }
    if (counter1 == 0)
      printf("\\\t\n");
    else if (counter1 + 1 == columns)
      printf("/\t\n");
    else
      printf("|\t\n");
  }
}
void print_for_vector(int n, int* vector)
{
  int counter;
  printf("(\t");
  for (counter = 0; counter < n; counter++)
    printf("%d\t", vector[counter]);
  printf(")\n");
}
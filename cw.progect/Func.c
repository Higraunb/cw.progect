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
  printf("Vector sum: \n");
  if (n1 >= n2)
    n3 = n1;
  else
    n3 = n2;
  *vector_3 = (int*)malloc(n3 * sizeof(int));
  printf("(\t");
  if (n1 >= n2)
  {
    nsum = n2;
    for (i = 0; i < n3; i++)
    {
      if (i < nsum)
      {
        (*vector_3)[i] = (int)vector_1[i] + (int)vector_2[i];
        printf("%d\t", (int)((*vector_3)[i]));
      }
      else
      {
        (*vector_3)[i] = (int)vector_1[i];
        printf("%d\t", (int)((*vector_3)[i]));
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
  printf(")\n");
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
  if ((*columns < 2) || (*strings < 2))
  {
    printf("Eror");
    exit(0);
  }
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
      if(counter2 < 1)
        (*matrix)[counter1][counter2] = rand() % 10;
      else
        (*matrix)[counter1][counter2] = 1;
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
void Sum_matrix_vector(int** matrix_1, int** matrix_2, int columns_1, int string_1,
  int columns_2, int string_2, int*** matrix)
{
  int counter_1, counter_2, columns_res, string_res;
  if (columns_1 != columns_2 || string_1 != string_2)
  {
    printf("Eror\n");
    exit(1);
  }
  (*matrix) = (int**)malloc(sizeof(int*) * columns_1);
  for (int counter = 0; counter < columns_1; counter++)
  {
    (*matrix)[counter] = (int*)malloc(sizeof(int) * string_1);
  }
  for (counter_1 = 0; counter_1 < columns_1; counter_1++)
  {
    for (counter_2 = 0; counter_2 < string_2; counter_2++)
    {
      if (counter_2 < 1)
        (*matrix)[counter_1][counter_2] = matrix_1[counter_1][counter_2] + matrix_2[counter_1][counter_2];
      else
        (*matrix)[counter_1][counter_2] = matrix_1[counter_1][counter_2];
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

void print_for_extended_matrix(int order, int** matrix, int* b_vector)
{
  int counter1, counter2;
  for (int counter1 = 0; counter1 < order; counter1++)
  {
    if (counter1 == 0)
      printf("/\t");
    else if (counter1 + 1 == order)
      printf("\\\t");
    else
      printf("|\t");
    for (int counter2 = 0; counter2 < order; counter2++)
    {
      printf("%d\t", (matrix)[counter1][counter2]);
    }
    printf("|\t%d\t", b_vector[counter1]);
    if (counter1 == 0)
      printf("\\\t\n");
    else if (counter1 + 1 == order)
      printf("/\t\n");
    else
      printf("|\t\n");
  }
}
void new_matrix_for_determinant(int string, int column, int order, int** matrix, int*** new_matrix)
{
  int counter1, counter2, new_counter1 = 0, new_counter2;
  (*new_matrix) = (int**)malloc(sizeof(int*) * (order - 1));
  for (counter1 = 0; counter1 < order - 1; counter1++)
    (*new_matrix)[counter1] = (int*)malloc(sizeof(int) * (order - 1));
  for (counter2 = 0; counter2 < order; counter2++)
  {
    if (counter2 != column)
    {
      new_counter2 = 0;
      for (counter1 = 0; counter1 < order; counter1++)
      {
        if (counter1 != string)
        {
          (*new_matrix)[new_counter2][new_counter1] = matrix[counter1][counter2];
          new_counter2++;
        }
      }
      new_counter1++;
    }
  }
}

int determinant(int order, int** matrix)
{
  int counter1, counter2, det = 0;
  int** new_matrix;
  if (order == 2)
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  else
  {
    for (counter1 = 0; counter1 < order; counter1++)
    {
      new_matrix_for_determinant(counter1,order , order, matrix, &new_matrix);
      det += matrix[counter1][0] * determinant(order - 1, new_matrix) * pow(-1, counter1);
    }
    return det;
  }
}

void create_matrix_for_cramer(int*** matrix_for_cramer, int** matrix, int* b_vector, int order, int column)
{
  int counter;
  int counter2, counter1;
  (*matrix_for_cramer) = (int**)malloc(sizeof(int*) * order);
  for (counter1 = 0; counter1 < order; counter1++)
    (*matrix_for_cramer)[counter1] = (int*)malloc(sizeof(int) * order);
  for (counter1 = 0; counter1 < order; counter1++)
  {
    for (counter2 = 0; counter2 < order; counter2++)
    {
      (*matrix_for_cramer)[counter1][counter2] = matrix[counter1][counter2];
    }
  }

  for (counter = 0; counter < order; counter++)
    (*matrix_for_cramer)[counter][column] = b_vector[counter];
}
void cramer(int** matrix, int* b_vector, int order)
{
  int counter, determinant_of_matrix;
  int** matrix_for_cramer;
  determinant_of_matrix = determinant(order, matrix);
  for (counter = 0; counter < order; counter++)
  {
    create_matrix_for_cramer(&matrix_for_cramer, matrix, b_vector, order, counter);
    printf("\n");
    print_for_matrix(order, order, matrix_for_cramer);
    printf("x[%d] = %d/%d\n", counter, determinant(order, matrix_for_cramer), determinant_of_matrix);
    free_matrix(order, matrix_for_cramer);
  }
}
void create_inverse_of_the_matrix(int order, int** matrix, double*** inverse_matrix)
{
  int counter2, counter1;
  int** det_matrix;
  int det = determinant(order, matrix);
  (*inverse_matrix) = (double**)malloc(sizeof(double*) * order);
  for (counter1 = 0; counter1 < order; counter1++)
    (*inverse_matrix)[counter1] = (double*)malloc(sizeof(double) * order);

  for (counter1 = 0; counter1 < order; counter1++)
  {
    for (counter2 = 0; counter2 < order; counter2++)
    {
      new_matrix_for_determinant(counter1, counter2, order, matrix, &det_matrix);
      (*inverse_matrix)[counter2][counter1] = (determinant(order - 1, det_matrix) * pow(-1, counter1 + counter2)) / (double)det;
      free_matrix(order - 1, det_matrix);
    }
  }
}
void print_for_double_matrix(int columns, int strings, double** matrix)
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
      printf("%lf\t", (matrix)[counter1][counter2]);
    }
    if (counter1 == 0)
      printf("\\\t\n");
    else if (counter1 + 1 == columns)
      printf("/\t\n");
    else
      printf("|\t\n");
  }
}
void free_double_matrix(int columns, double** matrix)
{
  for (int counter = 0; counter < columns; counter++)
    free(matrix[counter]);
  free(matrix);
}
double Gölderova_norm(int* array, int len_of_array, int norm)
{
  double res = 0;
  int counter = 0;
  for (counter = 0; counter < len_of_array; counter++)
    res += pow(abs(array[counter]), norm);
  res = pow(res, (1.0 / norm));
  return res;
}
int Endless_norm(int* array, int len_of_array, int left, int right)
{
  int res = 0;
  Quick_Sort(array, left, right);
  res = array[right];
  return res;
}
void Quick_Sort(int* array, int left, int right)
{
  int pivot; 
  int index; 
  int l_hold = left; 
  int r_hold = right; 
  pivot = array[left];
  while (left < right) 
  {
    while ((array[right] > pivot) && (left < right))
      right--; 
    if (left != right) 
    {
      array[left] = array[right]; 
      left++;
    }
    while ((array[left] < pivot) && (left < right))
      left++; 
    if (left != right) 
    {
      array[right] = array[left]; 
      right--; 
    }
  }
  array[left] = pivot; 
  index = left;
  left = l_hold;
  right = r_hold;
  if (left < index)
    Quick_Sort(array, left, index - 1);
  if (right > index)
    Quick_Sort(array, index + 1, right);
}
#ifndef __HEADER_H__
#define __HEADER_H__

int create_vector(int* count, int** vector);

int sum_vectors(int n1, int* vector_1, int n2,
	int* vector_2, int** vector_3);

void print_for_extended_matrix(int order, int** matrix, int* b_vector);

void new_matrix_for_determinant(int string, int column, int order, int** matrix, int*** new_matrix);

void Sum_matrix_vector(int** matrix_1, int** matrix_2, int columns_1, int string_1,
	int columns_2, int string_2, int*** matrix);

int determinant(int order, int** matrix);

void create_matrix_for_cramer(int*** matrix_for_cramer, int** matrix, int* b_vector, int order, int column);

void cramer(int** matrix, int* b_vector, int order);

void free_double_matrix(int columns, double** matrix);

void print_for_double_matrix(int columns, int strings, double** matrix);

void create_inverse_of_the_matrix(int order, int** matrix, double*** inverse_matrix);

int mul_vectors(int n1, int* vector_1, int n2, int* vector_2);

void free_vector(int* vector);

double len_of_vector(int n, int* vector);

double angle_between_vectors(int n1, int* vector1,int n2, int* vector2);

void mul_vector_on_scal(int n, int* vector, int scal);

void create_matrix(int* columns, int* strings, int*** matrix);

void free_matrix(int columns, int** matrix);

double Gölderova_norm(int* array, int len_of_array, int norm);

int Endless_norm(int* array, int len_of_array, int left, int right);

void Quick_Sort(int* array, int left, int right);

void Sum_matrix(int** matrix_1, int** matrix_2, int columns_1, int string_1,
	int columns_2, int string_2, int*** matrix);

int Mul(int n_a, int m_a, int** matrix_a, int n_b,
	int m_b, int** matrix_b, int*** matrix_res);

void create_vector_matrix(int* columns, int* strings, int*** matrix);

int MulK(int n, int m, int*** matrix, int k);

int Trans(int n, int m, int** matrix, int*** matrix_res);

void print_for_matrix(int columns, int strings, int** matrix);

void print_for_vector(int n, int* vector);

#endif // !__HEADER_H__
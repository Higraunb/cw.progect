#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"

int main()
{
	int user = 0, count = 0, count_2 = 0, * vector = 0,
		* vector_2 = 0, * vector_3 = 0, user_selection = 0,** matrix = 0, ** matrix_2 = 0,
		** matrix_res = 0, columns = 0, columns_res = 0, strings = 0, strings_res = 0, columns_2 = 0,
		columns_inverse = 0, strings_2 = 0, norm = 0;
	double ** inverse_matrix = 0;
	printf("Hello, user\n");
	while (user_selection == 0)
	{
		system("cls");
		printf("Lvl 1 vector/vector\nLvl 2 matrix/vector\nLvl 3 matrix/matrix\n");
		printf("Enter lvl, that you want: ");
		scanf("%d", &user);
		system("cls");
		switch (user)
		{
		case 0:
			break;
		case 1:
			create_vector(&count, &vector);
			print_for_vector(count, vector);
			//lvl 1
			user = 0;
			//
			printf("Enter what command do you want to run : \n1 - sum\n"
				"2 - multiplication\n3 - length first\n4 - length second\n"
				"5 - multiplication by scalar\n6 - Angle\n7 - Golderova norm.\n"
				"8 - Endless norm\n");
			scanf("%d", &user);
			switch (user)
			{
			case 0:
				return 0;
			case 1:
				system("cls");
				printf("Enter second vector\n");
				create_vector(&count_2, &vector_2);
				print_for_vector(count_2, vector_2);
				printf("\t    +\n");
				print_for_vector(count, vector);
				sum_vectors(count, vector, count_2, vector_2, &vector_3);
				system("pause");
				break;
			case 2:
				system("cls");
				printf("Enter second vector\n");
				create_vector(&count_2, &vector_2);
				print_for_vector(count_2, vector_2);
				printf("\t    *\n");
				print_for_vector(count, vector);
				printf("Multiplication = %d\n", mul_vectors(count, vector, count_2, vector_2)); 
				system("pause");
				// функция
				break;
			case 3:
				system("cls");
				printf("Len = %lf\n", len_of_vector(count, vector));
				system("pause");
				// функция
				break;
			case 4:
				system("cls");
				printf("Enter second vector\n");
				create_vector(&count_2, &vector_2);
				print_for_vector(count_2, vector_2);
				printf("Len = %lf\n", len_of_vector(count_2, vector_2));
				system("pause");
				// функция
				break;
			case 5:
				system("cls");
				mul_vector_on_scal(count, vector, -1);
				print_for_vector(count, vector);
				system("pause");
				// функция
				break;
			case 6:
				system("cls");
				printf("Enter second vector\n");
				create_vector(&count_2, &vector_2);
				print_for_vector(count_2, vector_2);
				printf("\t   and\n");
				print_for_vector(count, vector);
				printf("Angle = %lf\n", angle_between_vectors(count, vector, count_2, vector_2));
				system("pause");
				// функция
				break;
			case 7:
				system("cls");
				printf("Enter norm what you whant:\n");
				scanf("%d", &norm);
				printf("Res : %lf\n", Gölderova_norm(vector, count, norm));
				system("pause");
			case 8:
				system("cls");
				printf("Res : %d\n", Endless_norm(vector, count,0 , count - 1));
				system("pause");
			default:
				printf("Eror");
				break;
			}
			break;
		case 2:
			//lvl 2
			create_matrix(&columns, &strings, &matrix);
			print_for_matrix(columns, strings, matrix);
			user = 0;
			printf("Enter what command do you want to run : \n1 - sum\n"
				"2 - multiplication\n3 - Cramer\n");
			scanf("%d", &user);
			switch (user)
			{
			case 0:
				return 0;
			case 1:
				system("cls");
				printf("Enter second vector\n");
				create_vector_matrix(&count, &strings, &matrix_2);
				print_for_matrix(count, 1, matrix_2);
				printf("\t    +\n");
				print_for_matrix(columns, strings, matrix);
				Sum_matrix_vector(matrix, matrix_2, columns, strings,count ,strings, &matrix_res);
				printf("Result:\n");
				columns_res = columns;
				print_for_matrix(columns, strings, matrix_res);
				system("pause");
				// функция
				break;
			case 2:
				system("cls");
				printf("Enter second vector\n");
				create_vector_matrix(&count, &strings, &matrix_2);
				print_for_matrix(count, strings, matrix_2);
				printf("\t    *\n");
				print_for_matrix(columns, strings, matrix);
				Mul(columns, strings, matrix, count, strings, matrix_2, &matrix_res);
				printf("Result:\n");
				columns_res = columns;
				print_for_matrix(columns, strings, matrix_res);
				system("pause");
				// функция
				break;
			case 3:
				create_vector(&count, &vector);
				print_for_vector(count, vector);
				printf("\nSolution:\n");
				if ((strings != columns)||((strings != count)))
					printf("Eror, strings != columns\n");
				else
				{
					print_for_extended_matrix(columns, matrix ,vector);
					cramer(matrix, vector, columns);
				}
				system("pause");
				// функция
				break;
			case 4:
				// функция
				break;
			default:
				printf("Errrrrrrrrrrrrrrrrror\n");
				break;
			}
			break;
		case 3:
			//lvl 3
			create_matrix(&columns, &strings, &matrix);
			print_for_matrix(columns, strings, matrix);
			user = 0;
			printf("Enter what command do you want to run : \n1 - sum\n"
				"2 - multiplication\n3 - creation of the Transitive matrix\n"
				"4 - creation of the inverse matrix\n");
			scanf("%d", &user);
			switch (user)
			{
			case 0:
				return 0;
			case 1:
				system("cls");
				printf("Enter second matrix\n");
				create_matrix(&columns_2, &strings_2, &matrix_2);
				print_for_matrix(columns_2, strings_2, matrix_2);
				printf("\t    +\n");
				print_for_matrix(columns, strings, matrix);
				Sum_matrix(matrix, matrix_2, columns, strings, columns_2, strings_2, &matrix_res);
				printf("Result:\n");
				print_for_matrix(columns_2, strings_2, matrix_res);
				columns_res = columns_2;
				system("pause");
				// функция
				break;
			case 2:
				system("cls");
				printf("Enter second matrix\n");
				create_matrix(&columns_2, &strings_2, &matrix_2);
				print_for_matrix(columns_2, strings_2, matrix_2);
				printf("\t    *\n");
				print_for_matrix(columns, strings, matrix);
				Mul(columns, strings, matrix, columns_2, strings_2, matrix_2, &matrix_res);
				printf("Result:\n");
				print_for_matrix(columns_2, strings_2, matrix_res);
				columns_res = columns_2;
				system("pause");
				// функция
				break;
			case 3:
				system("cls");
				Trans(columns, strings, matrix, &matrix_res);
				printf("Result:\n");
				print_for_matrix(columns, strings, matrix_res);
				system("pause");
				break;
			case 4:
				system("cls");
					create_inverse_of_the_matrix(columns, matrix, &inverse_matrix);
					print_for_double_matrix(columns, strings, inverse_matrix);
					columns_inverse = columns;
					printf("Result:\n");
				system("pause");
			default:
				printf("Errrrrrrrrrrrrrrrrror\n");
				break;
			}
			break;
		default:
			printf("Errrrrrrrrrrrrrrrrrrrrrror\n");
			break;
		}
	}
	free_vector(vector);
	free_vector(vector_2);
	free_vector(vector_3);
	free_matrix(columns, matrix);
	free_matrix(columns_2, matrix_2);
	free_double_matrix(columns_inverse, inverse_matrix);
	free_matrix(columns_res, matrix_res);
	return 0;
}
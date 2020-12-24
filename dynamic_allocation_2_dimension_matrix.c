#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNIGNS

void input_value(int **m, int row, int col);
void output_value(int **m, int row, int col);

int main(void)
{
	int row, col;
	scanf("%d %d", &row, &col);

	int **d_Array = malloc(sizeof(int *) * row);

	for (int i = 0; i < row; i++)
		d_Array[i] = malloc(sizeof(int) * col);

	input_value(d_Array, row, col);
	output_value(d_Array, row, col);

	for (int i = 0; i < row; i++)
		free(d_Array[i]);

	free(d_Array);

	return 0;
}

void input_value(int **m, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			m[i][j] = i + j;
	}
}

void output_value(int **m, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}
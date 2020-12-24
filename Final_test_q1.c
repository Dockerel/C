#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void input_value(int** m, int row, int col);
efficiency_comp(int** m, int row, int col, int x, int y, int set_x, int set_y);

int main(void)
{
	printf("2020114932 ������\n");
	int m, n, x, y;
	scanf("%d %d %d %d", &m, &n, &x, &y);
	int set_x = x;
	int set_y = y;

	int **d_array = malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++)
	{
		d_array[i] = malloc(sizeof(int) * m);
	}

	input_value(d_array, n, m);

	printf("%d(�ִ�)\n", efficiency_comp(d_array, n, m, x, y, set_x, set_y));

	for (int i = 0; i < n; i++)
	{
		free(d_array[i]);
	}

	free(d_array);

	return 0;
}

void input_value(int** m, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &m[i][j]);
		}
	}
}

efficiency_comp(int** m, int row, int col, int x, int y, int set_x, int set_y)
{
	int max = 0;

	for (int i = 0; i < row - y + 1; i++)
	{
		for (int j = 0; j < col - x + 1; j++)
		{
			int sum = 0;

			for (int n1 = i; n1 < i + set_y; n1++)
			{
				for (int n2 = j; n2 < j + set_x; n2++)
				{
					sum += m[n1][n2];
				}
			}

			if (sum > max)
			{
				max = sum;
			}
		}
	}

	return max;
}
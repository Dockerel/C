#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int result_2(int *card, int n);
int result_3(int* card, int n);

int heart[13];
int diamonds[13];
int clubs[13];
int spades[13];

int main(void)
{
	printf("2020114932 ������\n");
	long seconds = (long)time(NULL);
	srand(seconds);

	int cards[52];
	int i = 0;

	printf("<��> of <���>\n");

	while (1)
	{
		int nb = rand() % 13 + 1;
		int shape_nb = rand() % 4 + 1;
		char shape[20];

		if (shape_nb == 1)
			if (heart[nb] == 0)
			{
				heart[nb] = 1;
				strcpy(shape, "hearts");
				printf("<%d> of <%s>\n", nb, shape);
			}
			else
				continue;
		else if (shape_nb == 2)
			if (diamonds[nb] == 0)
			{
				diamonds[nb] = 1;
				strcpy(shape, "diamonds");
				printf("<%d> of <%s>\n", nb, shape);
			}
			else
				continue;
		else if (shape_nb == 3)
			if (clubs[nb] == 0)
			{
				clubs[nb] = 1;
				strcpy(shape, "clubs");
				printf("<%d> of <%s>\n", nb, shape);
			}
			else
				continue;
		else if (shape_nb == 4)
			if (spades[nb] == 0)
			{
				spades[nb] = 1;
				strcpy(shape, "spades");
				printf("<%d> of <%s>\n", nb, shape);
			}
			else
				continue;

		cards[i] = nb;

		int first_result = result_2(cards, i);
		int second_result = result_3(cards, i);

		if (first_result == 1 && second_result == 1)
		{
			printf("Full House!!\n");
			break;
		}
		else
			i++;
	}

	return 0;
}

int result_2(int *card, int n)
{
	int nb_list[13];
	for (int i = 1; i < 14; i++)
	{
		int count = 0;
		for (int j = 0; j < n + 1; j++)
		{
			if (*(card + j) == i)
			{
				count += 1;
			}
			nb_list[i - 1] = count;
		}
	}

	for (int i = 0; i < 13; i++)
	{
		if (nb_list[i] == 2)
		{
			return 1;
			break;
		}
	}
}

int result_3(int *card, int n)
{
	int nb_list[13];
	for (int i = 1; i < 14; i++)
	{
		int count = 0;
		for (int j = 0; j < n + 1; j++)
		{
			if (*(card + j) == i)
			{
				count += 1;
			}
			nb_list[i - 1] = count;
		}
	}

	for (int i = 0; i < 13; i++)
	{
		if (nb_list[i] == 3)
		{
			return 1;
			break;
		}
	}
}
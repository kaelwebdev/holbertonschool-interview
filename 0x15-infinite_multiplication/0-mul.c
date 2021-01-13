#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_error - error checker
 * @argc: number of arguments
 * @argv: an array consisting arguments
 *
 * Return: 0 | Error
 */

int check_error(int argc, char **argv)
{
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				printf("Error\n");
				exit(98);
			}
		}
	}
	return (0);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: an array consisting arguments
 *
 * Return: 0 | 1
 */

int main(int argc, char **argv)
{
	int len1, len2, carry, a, b, i, j;
	int *result;

	check_error(argc, argv);
	len1 = strlen(argv[1]), len2 = strlen(argv[2]);
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		printf("0\n");
		return (EXIT_SUCCESS);
	}
	result = calloc(len1 + len2, sizeof(*result));
	if (!result)
		return (EXIT_FAILURE);
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		a = argv[1][i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			b = argv[2][j] - '0';
			carry += result[i + j + 1] + (a * b);
			result[j + i + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[i + j + 1] += carry;
	}
	a = result[0] == 0 ? 1 : 0;
	for (; a < len1 + len2; a++)
		printf("%d", result[a]);
	printf("\n");
	free(result);
	return (EXIT_SUCCESS);
}

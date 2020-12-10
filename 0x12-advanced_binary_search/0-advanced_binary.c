 #include "search_algos.h"

/**
 * printA - Prints an array
 * @a: Target array
 * @l: Left index of @array
 * @r: Right index of @array
 */
void printA(int *a, size_t l, size_t r)
{
	size_t i;

	printf("Searching in array: ");

	for (i = l; i <= r; i++)
	{
		printf("%d", a[i]);
		if (i == r)
			printf("\n");
		else
			printf(", ");
	}
}


/**
 * b_s - Binary search
 * @a: Target array
 * @s: Start of the @array
 * @e: End of the @array
 * @v: Value to be searched
 * Return: Index where @value is located
 */
int b_s(int *a, size_t s, size_t e,  int v)
{
	size_t m;

	if (s > e)
		return (-1);

	m = (e + s) / 2;
	printA(a, s, e);
	if (a[m] == v && a[m - 1] != v)
	{
		return (m);
	}
	if (a[m] < v)
	{
		return (b_s(a, m + 1, e,  v));
	}
	else
		return (b_s(a, s, m, v));
}

/**
 * advanced_binary - Advanced binary search
 * @array: Target array
 * @size: Size of @array
 * @value: Value to be searched
 * Return: Index where @value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (b_s(array, 0, size - 1, value));
}

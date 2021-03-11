#include "sort.h"

/**
 * counting_sort_radix - Counting sort
 * @array: Array to be sorted
 * @size: Size of the @array
 * @exp: Exponent
 * Return: Nothing.
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int freq[10] = {0}, j;
	int *output = NULL;
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (i = 0; i < size; i++)
		freq[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		freq[i] += freq[i - 1];
	for (j = size - 1; j >= 0; j--)
	{
		output[freq[(array[j] / exp) % 10] - 1] = array[j];
		freq[(array[j] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Radix sorting
 * @array: Array to be sorted
 * @size: Size of the @array
 * Return: Nothing.
 */
void radix_sort(int *array, size_t size)
{
	uint i = 1;
	int max = 0, exp = 1;

	if (!array || size < 2)
		return;
	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	while (max)
	{
		counting_sort_radix(array, size, exp);
		exp *= 10;
		max /= 10;
	}
}

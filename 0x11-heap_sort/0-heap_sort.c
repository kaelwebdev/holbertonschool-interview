#include "sort.h"

/**
 * swap - Swaps two numbers
 * @n1: First number
 * @n2: Second number
 * Return: Nothing
 */
void swap(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

/**
 * s_d - Sift down, rearrange heap
 * @array: Array
 * @start: Start index
 * @end: End index
 * @size: Size of the @array
 * Return: Nothing
 */
void s_d(int *array, size_t start, size_t end, size_t size)
{
	size_t root, n;

	root = start;
	while (root * 2 + 1 <= end)
	{
		n = root * 2 + 1;
		if (n + 1 <= end && array[n] < array[n + 1])
			n++;
		if (array[root] < array[n])
		{
			swap(&array[root], &array[n]);
			print_array(array, size);
			root = n;
		}
		else
			return;
	}
}

/**
 * heapify - Creates heap from array
 * @array: Array
 * @size: Size of the @array
 * Return: Nothing
 */
void heapify(int *array, size_t size)
{
	int s;

	s = (size - 2) / 2;
	while (s >= 0)
	{
		s_d(array, s, size - 1, size);
		s = s - 1;
	}
}

/**
 * heap_sort - Heap sort
 * @array: Array
 * @size: Size of the @array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t end = 0;

	if (array == NULL)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end--;
		s_d(array, 0, end, size);
	}

}

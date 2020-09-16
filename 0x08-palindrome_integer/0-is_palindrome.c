#include "palindrome.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - checks whether if
 * unsigned integer is a palindrome.
 * @n: int number
 * Return: 1 | 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long int inv_n = 0, last_digit, new_n;

	new_n = n;

	while (new_n != 0)
	{
		last_digit = new_n % 10;
		inv_n = inv_n * 10 + last_digit;
		new_n = new_n / 10;
	}

	if (inv_n == n)
		return (1);
	else
		return (0);
}

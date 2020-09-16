#include "palindrome.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - a function that checks whether or not
 * a given unsigned integer is a palindrome.
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
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

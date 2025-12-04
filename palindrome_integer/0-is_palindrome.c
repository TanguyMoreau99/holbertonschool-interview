#include "palindrome.h"

/*
 * is_palindrome - check whether or not
 * @n: number to be check
 *
 * Return: 1 if n is a palindrome, and 0 in th e other case
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, remainder, original;

	original = n;

	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	if (original == reversed)
		return (1);
	else
		return (0);
}

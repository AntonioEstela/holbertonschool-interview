#include "palindrome.h"
/**
 * is_palindrome - function that checks if aunsigned integer is a palindrome.
 * @n: unsigned long number type.
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversedInt = 0;

	if (n % 10 == 0 && n != 0)
		return (0);

	while (n > reversedInt)
	{
		reversedInt = (reversedInt * 10) + n % 10;
		n /= 10;
	}

	return (n == reversedInt || n == reversedInt / 10);
}

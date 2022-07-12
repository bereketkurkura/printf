#include "main.h"
/**
 *print_num - prints an integer of format 'd'
 *@list:list to increment
 *Return:count of characters printed
 */
int print_num(va_list list)
{
	int num = va_arg(list, int);
	unsigned int n;
	int count = 0;
	int x = 1;

	if (num < 0)
	{
		n = -num;
		_putchar('-');
		count++;
	}
	else
	{
		n = num;
	}
	while ((n / x) > 9)
	{
		x *= 10;
	}
	while (x >= 1)
	{
		_putchar(((n / x) % 10) + '0');
		x /= 10;
		count++;
	}
	return (count);
}
/**
 *print_unsigned - prints unsigned no.
 *@list:list to increment
 *Return:count of no. printed
 */
int print_unsigned(va_list list)
{
	unsigned int num;
	int len = 0;
	int d = 1;

	num = va_arg(list, unsigned int);
	for (; num / d > 9; )
	{
		d = d * 10;								}
	while (d > 0)
	{
		len += _putchar('0' + (num / d));
		num = num % d;
		d = d / 10;
	}
	return (len);
}

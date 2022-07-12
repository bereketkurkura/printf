#include "main.h"
#include <stdio.h>

/**
 *print_binary - prints an unsigned int in binary format
 *@list:list to increment
 *Return:no. of characters printed
 */

int print_binary(va_list list)

{
	unsigned int num;
	int i, j, len;
	char *str;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	len = base_len(num, 2);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
		return (-1);
	i = 0;
	while (num > 0)
	{
		str[i] = num % 2;
		num = num / 2;
		i++;
	}
	for (j = (i - 1); j >= 0; j--)
	{
		_putchar(str[j] + '0');
	}
	free(str);
	return (len);
}

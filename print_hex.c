#include "main.h"
#include <stdio.h>

/**
 *print_hex - prints unsigned int in hex lower format
 *@list:list to increment
 *Return:no. of characters printed
 */

int print_hex(va_list list)

{
	unsigned int num;
	int i, j, temp, len;
	char *str;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	len = base_len(num, 16);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
	{
		return (-1);
	}
	i = 0;
	while (num > 0)
	{
		temp = num % 16;
		if (temp < 10)
		{
			str[i] = temp + 48;
			i++;
		}
		else
		{
			str[i] = temp + 87;
			i++;
		}
		num = num / 16;
	}
	for (j = (i - 1); j >= 0; j--)
	{
		_putchar(str[j]);
	}
	free(str);
	return (len);
}

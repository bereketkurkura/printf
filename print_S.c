#include "main.h"
#include <stdio.h>

/**
 *print_S - handles custom conversion S which for instance
 *         -prints '\n' as \x and hex equivalent of n
 *@list:list to increment
 *Return:no. of characters printed
 */

int print_S(va_list list)
{
	char *hex;
	char *s = va_arg(list, char *);
	unsigned int i = 0, j;
	int c = 0, len;

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');									len = base_len(s[i], 16);
			if (len != 2)
			{
				_putchar('0');
				c++;
			}
			c += 2;
			hex = hex_conv(s[i]);								for (j = 0; hex[j]; j++)
			{
				_putchar(hex[j]);
				c++;
			}
		}
		else
		{
			_putchar(s[i]);
			c++;
		}
	}
	return (c);
}

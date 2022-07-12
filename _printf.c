#include "main.h"

/**
 * _printf - is a function that prints data in printf format
 * @format: identifier to look for.
 * Return: the length of the string.
 */

int _printf(const char *format, ...)
{
	convert_match m[] = {
		{"%s", printf_string},
		{"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int},
		{"%d", printf_dec},
		{"%b", printf_bin}
	};

	va_list arg;
	int i = 0, j, len = 0;

	va_start(arg, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

START:
	while (format[i] != '\0')
	{
		j = 5;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(arg);
				i = i + 2;
				goto START;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(arg);
	return (len);
}

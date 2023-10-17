#include <stdio.h>
#include "main.h"
#include <limits.h>

/**
  * _printf - function produces formatted string
  * @format: format string
  * Description: function produces output according to
  * format and returns the number of char printed.
  * Return: Number of characters
  */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				const char *str = va_arg(args, const char *);

				while (*str)
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}

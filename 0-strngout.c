#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
  * _printf - A function that produces output according to format.
  * @format: format string.
  * Description: This function will print out according to format
  * string and format specifiers.
  * Return: len of the formatted string.
  */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int char_count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			char_count++;
		}
		else
		{
			formt++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				_putchar(c);
				char_count++;
			}
			else if (*format == 's')
			{
				const char *str = va_args(args, const char *);

				while (*str)
				{
					_putchar(*str);
					str++;
					char_count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				char_count++;
			}
		}
		format++;
	}

	va_end(args);
	return (char_count);
}

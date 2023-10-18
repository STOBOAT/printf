#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * my_printf - Custom printf implementation with support for 'd' and 'i' specifiers
 * @format: A format string containing format specifiers
 * @...: Additional arguments corresponding to format specifiers
 */

void my_printf(const char *format, ...)
{
	va_list specifiers;

	va_start(specifiers, format);

	for (*format != '\0' && *format == '%')
	{
		{
			format++;
		}
		if (*format == 'd' || *format == 'i')
		{
			int val = va_arg(specifiers, int);
		}
		else
		{
			_putchar(*format);
		}
		format++;
	}

	va_end(specifier);
}

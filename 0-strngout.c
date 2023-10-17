#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int char_count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
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

				putchar(c);
				char_count++;
			}
			else if (*format == 's')
			{
				const char *str = va_args(args, const char *);

				while (*str)
				{
					putchar(*str);
					str++;
					char_count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				char_count++;
			}
		}
		format++;
	}

	va_end(args);
	return (char_count);
}

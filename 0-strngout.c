#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

_printf(const char *format, ...)
{
	va_list newprintf;
	char *strn;
	int strSize;

	va_start(newprintf, format);

	strn = (char *)malloc((strlen(format) * sizeof(char)) + 1);
	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
			i++;
		switch (format[i])
		{
			case 'c':
				{
					char c = va_arg(newprintf, int);

					write(1, &c, sizeof(char));
					break;
				}
			case 's':
				{
					char *s = va_arg(newprintf, *);

					strSize = strlen(s) * sizeof(char);
					write(1, s, strSize);
					break;
				}
			case '%':
				{
					_putchar('%');
					break;
				}
		}
		else
		{
			write(1, &strn, sizeof(char));
		}
		va_end(newprintf);
		free(strn);
	}
}

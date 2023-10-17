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
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (my_flag(*p, &flags))
				p++;
			pfunc = my_print(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);

}

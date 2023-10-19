#include "main.h"
#include <stdio.h>

/**
  * _printf - function produces formatted string
  * @format: format string
  * Description: function produces output according to
  * format and returns the number of char printed.
  * Return: Number of characters
  */

int _printf(const char *format, ...)
{
	int countChar = 0;

	va_list argumentList;

	if (format == NULL)
		return (-1);

	va_start(argumentList, format);

	while (*format)
		/* a loop to iterate over char of the string */
	{
		if (*format != '%')
		{
			_putchar(*format);
			countChar++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				_putchar(*format);
				countChar++;
			}
			else if (*format == 'c')
			{
				char character = va_arg(argumentList, int);

				_putchar(character);
				countChar++;
			}
			else if (*format == 's')
			{
				char *myStr = va_arg(argumentList, char *);
					int strLen = 0;

				while (myStr[strLen] != '\0')
					strLen++;
				write(1, myStr, strLen);
				countChar += strLen;
			}
		}
		format++;
	}

	va_end(argumentList);

	return (countChar);
}

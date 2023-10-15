#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

_printf(const char *format, ...)

int main(void)
{
	_printf("This string is for the popping!");
	return (0);
}
_printf(const char *format, ...)
{
	va_list newprintf;
	char *format;
	int output;

	va_start(newprintf,format)
		
		format = (char *)malloc((format * sizeof(char)) + 1)

		for (output = 0; output&& format != '\0'; i++)
		{
			if (*format == '%')
				format++;
			switch(*format)
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

						write(1, &s, strSize);
						break;
					}
				case '%':
					{
						_putchar('%');
						break;
					}
			}
		}
	else
	{
		write(1,&format, strln(char));
	}
	va_end(format)
		free(format)
}

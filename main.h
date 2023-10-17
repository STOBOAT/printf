#ifndef MAIN_H
#define main_H

#include <stdlib.h>
#include <stdarg.h>


/**
 * struct flags - struct containing flags to "TURN ON"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' Addition
 * @space: flag for the ' ' Empty space
 * @hash: flag for the '#' Hash
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf.
 * @c: format specifier
 * @f: pointer to the correct function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;


/* write functions puchar and puts declarations */
int _putchar(char c);
int _puts(char *str);

/* Customize printf function declaration*/
int _printf(const char *format, ...);

/* my print */
int (*my_print(char s))(va_list, flags_t *);

/* my flag */
int my_flag(char s, flags_t *f);

#endif

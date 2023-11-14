#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - print according to format
 * @format: format argument
 * Description: print arguments according to format
 * Return: integer value
 */
int _printf(const char *format, ...)
{
	va_list args;
	int c_count;

	va_start(args, format);

	c_count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 's':
				c_count += printf("%s", va_arg(args, char *));
				break;
			case 'c':
				c_count += printf("%c", va_arg(args, int));
				break;
			case 'x':
				c_count += printf("%x", va_arg(args, unsigned int));
				break;
			case 'd':
				c_count += printf("%d", va_arg(args, int));
				break;
			default:
				c_count += printf("%%");
				break;
			}
		}
		else
		{
			c_count += printf("%c", *format);
		}
		format++;
	}
	va_end(args);
	return (c_count);
}

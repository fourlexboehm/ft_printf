#include "../includes/printf.h"
#include <stdio.h>

int write_str(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int flag_select(char *str_in, va_list arglist, size_t count)
{
	if (*str_in == 'd' || *str_in == 'i')
	{
		ft_putnbr_fd( (int)va_arg(arglist, int), 1);
		count += sizeof(int);
	}
	else if (*str_in == 'c')
	{
		ft_putchar_fd(va_arg(arglist,int), 1);
		count++;
	}
	else if (*str_in == 's')
		count += write_str(va_arg(arglist, char *));
//	else if (*str_in == 'p')
//		count += put_pointer();
	else if (*str_in == 'u')
	{
		ft_putnbr_fd(va_arg(arglist, int), 1);
		count += sizeof(int);
	}
//	else if (*str_in == 'x'|| *str_in == 'X')
//		
	return (count);
}

int ft_printf(const char *format, ...)
{
	size_t count;
	char *str_in;
	va_list arglist;

	str_in = (char *) format;
	va_start(arglist, format);
	count = 0;
	while (*str_in)
	{
		if (*str_in != '%')
		{
			write(1, &*str_in++, 1);
			count++;
		}
		else 
		{
			count = flag_select(str_in + 1, arglist, count);
			str_in += 2;
		}
		if (count == 0)
			break;
	}
	va_end(arglist);
	return (count);
}


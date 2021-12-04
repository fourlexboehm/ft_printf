/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:42:11 by aboehm            #+#    #+#             */
/*   Updated: 2021/12/01 19:05:36 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int write_char(char c)
{
	write(1, &c, 1);
	return (1);
}




int	flag_select(char const * str_in, va_list *arglist, int count)
{
	if (*str_in == 'd' || *str_in == 'i')
		count += write_int(va_arg(*arglist, int));
	else if (*str_in == 'c')
		count += write_char(va_arg(*arglist, int));
	else if (*str_in == 's')
		count += write_str(va_arg(*arglist, char *));
	else if (*str_in == 'p')
		count += put_pointer(va_arg(*arglist, void *), &count);
	else if (*str_in == 'u')
		write_uint(va_arg(*arglist, int), &count);
	else if (*str_in == 'x'|| *str_in == 'X')
        put_hex(va_arg(*arglist, int), &count, *str_in);
	else if ( *str_in == '%')
		count += write_char('%');
	else if (*str_in != 0)
		count += write_char(*str_in);
	else
		count = 0;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	char	*str_in;
	va_list	arglist;

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
			count = flag_select(str_in + 1, &arglist, count);
			str_in += 2;
		}
		if (count == 0)
			break ;
	}
	va_end(arglist);
	return (count);
}

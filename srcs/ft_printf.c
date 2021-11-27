/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:42:11 by aboehm            #+#    #+#             */
/*   Updated: 2021/11/27 20:48:39 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	write_str(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int put_hex(size_t n, char base, size_t count)
{
	char *basep;

		if (base == 'x')
			basep = "0123456789abcdef";
		else
			basep = "0123456789ABCDEF";
	if (n >= 16)
		put_hex(n / 16, base, count);
	ft_putchar_fd(basep[n % 16], 1);
	count++;
	return (count);
}

int	put_pointer(void *pointer)
{
	size_t count;
	
	count = 0;
	ft_putstr_fd("0x", 1);
	return (2 + (put_hex((size_t)pointer, 'x', count)));
}

int	flag_select(char *str_in, va_list arglist, size_t count)
{
	if (*str_in == 'd' || *str_in == 'i')
	{
		ft_putnbr_fd((long)va_arg(arglist, int), 1);
		count += sizeof(int);
	}
	else if (*str_in == 'c')
	{
		ft_putchar_fd(va_arg(arglist, int), 1);
		count++;
	}
	else if (*str_in == 's')
		count += write_str(va_arg(arglist, char *));
	else if (*str_in == 'p')
		count += put_pointer(va_arg(arglist, void *));
	else if (*str_in == 'u')
	{
		ft_putnbr_fd(va_arg(arglist, int), 1);
		count += sizeof(int);
	}
	else if (*str_in == 'x'|| *str_in == 'X')
		count = put_hex(va_arg(arglist, int), *str_in, count);
	else if ( *str_in == '%')
	{
		write(1, '%', 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	size_t	count;
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
			count = flag_select(str_in + 1, arglist, count);
			str_in += 2;
		}
		if (count == 0)
			break ;
	}
	va_end(arglist);
	return (count);
}

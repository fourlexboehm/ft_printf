/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:58:33 by aboehm            #+#    #+#             */
/*   Updated: 2021/12/08 12:00:25 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	put_hex_static(size_t n, char *base, int *count)
{
	if (n >= 16)
		put_hex_static(n / 16, base, count);
	ft_putchar_fd(base[n % 16], 1);
	(*count)++;
}

int	put_pointer(void *pointer, int *count)
{
	ft_putstr_fd("0x", 1);
	put_hex_static((size_t)pointer, "0123456789abcdef", count);
	return (2);
}

void	put_hex(unsigned int n, int *count, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	put_hex_static(n, base, count);
}

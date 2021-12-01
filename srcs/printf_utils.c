/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:42:11 by aboehm            #+#    #+#             */
/*   Updated: 2021/12/01 15:17:49 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int numlen(int i)
{
	int	len;

	len = 0;
	if (i <= 0)
		len = 1;
	else
		len = 0;
	while (i != 0)
	{
		i = i / 10;
		len ++;
	}
	return (len);
}
int	write_int(int i)
{
	ft_putnbr_fd(i, 1);
	return numlen(i);
}

int	write_str(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}



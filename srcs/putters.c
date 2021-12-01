/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:42:11 by aboehm            #+#    #+#             */
/*   Updated: 2021/12/01 15:13:09 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putuint(unsigned int n)
{
	int len;

	len = 0;
	if (n > 9)
	{
		putuint(n / 10);
		putuint(n % 10);
	}
	else
	{
		len++;
		ft_putchar_fd(n + 48, 1);
	}
	return (len);
}

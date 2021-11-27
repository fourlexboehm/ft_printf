/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:52:05 by aboehm            #+#    #+#             */
/*   Updated: 2021/09/20 14:42:12 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int nbr, int base)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0 && base == 10)
		len += 1;
	while (nbr)
	{
		nbr /= base;
		len += 1;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	n_size;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_size = ft_nbrlen(n, 10);
	str = (char *)malloc(sizeof(char) * (n_size + 1));
	if (!str)
		return (NULL);
	str[n_size] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < n_size--)
	{
		str[n_size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

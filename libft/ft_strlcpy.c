/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:16:48 by aboehm            #+#    #+#             */
/*   Updated: 2021/09/08 19:07:06 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen((char *)src));
	i = 0;
	while (size-- > 1 && *src)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	while (*dst || *src)
	{
		if (*src++)
			i++;
	}
	return (i);
}

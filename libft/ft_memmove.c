/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:19:13 by aboehm            #+#    #+#             */
/*   Updated: 2021/09/08 13:18:59 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if ((size_t)(dst - src) >= len)
		return (ft_memcpy(dst, src, len));
	while (len--)
		*((unsigned char *)dst + len) = *((unsigned char *)src + len);
	return (dst);
}

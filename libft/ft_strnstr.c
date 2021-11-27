/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:33:18 by aboehm            #+#    #+#             */
/*   Updated: 2021/09/11 18:09:08 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen((char *)needle);
	if (*needle)
	{
		if (len == 0)
			return (NULL);
		while (len-- && ft_strncmp(haystack, needle, needle_len) != 0)
		{
			if (len < needle_len)
				return (NULL);
			if (*haystack++ == '\0')
				return (NULL);
		}
	}
	return ((char *)haystack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:40:45 by aboehm            #+#    #+#             */
/*   Updated: 2021/09/19 14:35:49 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	result = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1len + 1);
	ft_strlcat(result, s2, s1len + s2len + 1);
	return (result);
}

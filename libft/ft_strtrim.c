/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:57:03 by aboehm            #+#    #+#             */
/*   Updated: 2021/09/20 15:07:05 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rear;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (!(ft_strchr(set, *s1)))
			break ;
		s1++;
	}
	rear = (char *)s1 + (ft_strlen((char *)s1) - 1);
	while (rear >= s1)
	{
		if (!(ft_strchr(set, *rear)))
			break ;
		rear--;
	}
	return (ft_strndup(s1, ++rear - s1));
}

/*
int main()
{
	char set[] = "\t \n";
	char s1[] = "\t lorem ipsum";

	printf("%s", s1);
	printf("%s", ft_strtrim(s1, set));
}
*/

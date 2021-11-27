/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 20:36:51 by aboehm            #+#    #+#             */
/*   Updated: 2021/09/18 20:54:59 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, const char *src, unsigned int nb)
{
	unsigned int	desti;
	unsigned int	srci;

	desti = 0;
	srci = 0;
	while (dest[desti] != '\0')
		desti++;
	while (desti < nb && src[srci])
	{
		dest[desti] = src[srci];
		srci++;
		desti++;
	}
	dest[desti] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*src = "I'm the SOurce";
	char	*dest= "Please Add to me";
	printf("%s\n", ft_strncat(dest, src, 40));
	printf("\n");

	char	src2[] = "I'm the SOurce";
	char	dest2[80] = "Please Add to me";
	printf("%s\n", ft_strncat(dest2, src2, 40));

	printf("\n");

	char	src3[] = "I'm the SOurce";
	char	dest3[25] = "Please Add to me";
	printf("%s\n", ft_strncat(dest3, src3, 10));


	printf("\n");

	char	src4[] = "I'm an important source";
	char	dest4[80] = "does this work";
	printf("%s\n", ft_strncat(dest4, src4, 20));


	printf("\n");

	char	src5[] = "I'm the SOurce";
	char	dest5[25] = "im not that into source";
	printf("%s\n", ft_strncat(dest5, src5, 35));

}
*/

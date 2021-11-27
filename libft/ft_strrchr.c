/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:19:05 by aboehm            #+#    #+#             */
/*   Updated: 2021/09/11 18:08:50 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *p, int ch)
{
	char	*save;

	save = NULL;
	while (1)
	{
		if (*p == (char) ch)
			save = (char *)p;
		if (!*p++)
			return (save);
	}
}

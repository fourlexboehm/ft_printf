/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:46:29 by aboehm            #+#    #+#             */
/*   Updated: 2021/12/01 15:19:12 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		write_int(int i);
int 	write_uint(unsigned int i);
int 	write_char(char c);
int		write_str(char *str);
int 	numlen(int n);
int		putuint(unsigned int n);

#endif

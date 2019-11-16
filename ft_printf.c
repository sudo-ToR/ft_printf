/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:15:35 by lnoirot           #+#    #+#             */
/*   Updated: 2019/11/16 19:32:14 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		str += ft_putstr_m((char *)str);
		if (*str == '%')
		{
			str++;
			if (*(str) == '%')
			{
				ft_putchar('%');
				str++;
			}
			else if ((*(str) == 'd' ||  *(str) == 'i') && str++)
				i = ft_putnbr_base_d(va_arg(ap, int), "0123456789");
		}
	}
	va_end(ap);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:15:35 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/20 14:20:51 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_converter_selector(char *str, int *ret, va_list ap, int j)
{
	if (str[j] == 'c')
		*ret += ft_converter_c(str, ap);
	else if (str[j] == 's')
		return;
	else if (str[j] == 'p')
		*ret += ft_converter_p(str, ap);
	else if (str[j] == 'd'|| str[j] == 'i')
		*ret += ft_converter_d(str, ap);
	else if (str[j] == 'u')
		return;
	else if (str[j] == 'x' || str[j] == 'X')
		return;
	else if (str[j] == '%')
		ft_putchar('%');
}

int 	ft_printf(const char *str, ...)
{
	int		ret;
	int		j;
	va_list	ap;

	ret = 0;
	j= 0;
	va_start(ap, str);
	while (*str)
	{
		str += ft_putstr_m((char *)str, &ret);
		if (*str == '%' && str++)
		{
			j = 0;
			while (ft_is_converter(str[j]) != 1 && str[j])
				j++;
			ft_converter_selector((char *)str, &ret, ap, j);
			while (ft_is_converter(*str) != 1)
				str++;
			str++;
		}
	}
	va_end(ap);
	return (ret);
}

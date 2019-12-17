/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:40:14 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/09 19:28:39 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		flag_0(char *str, int prec, int minus, va_list ap)
{
	int ret;
	int length;
	int arg;

	ret = 0;
	length = 0;
	if (*str == '.' || *str == '0')
		prec = ft_atoi(str++);
	length =  (*str == '*') ? prec - va_arg(ap, int) : prec - ft_atoi(str);
	arg = va_arg(ap, int);
	if (prec == 0 && arg != 0)
		return(ret += ft_putnbr_base_d(arg, "0123456789"));
	else if (prec == 0 && str[-1] == '0')
		return (ret += write(1, "0", 1));
	length *= (length > 0) ? 1 : -1;
	while (minus == 0 && length > ret)
		ret += write(1, " ", 1);
	prec -= (minus != 0) ? ret + ft_count_d(arg) + length : ret + ft_count_d(arg);
	prec *= (prec > 0) ? 1 : -1;
	while (prec-- > 0)
		ret += write(1, "0", 1);
	if (arg != 0)
		ret += ft_putnbr_base_d(arg, "0123456789");
	while (minus != 0 && length-- > 0)
		ret+= write(1, " ", 1);
	return (ret);
}
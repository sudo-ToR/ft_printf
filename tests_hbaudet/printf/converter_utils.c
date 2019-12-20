/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:40:14 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/20 20:43:50 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		ft_star(va_list ap, char *str, int *number, int *nb, int minus)
{
	minus += 0;
	if (*(str - 1) != '.')
		*number = va_arg(ap, int);
	if (*(str + 2) == '*')
		*nb = va_arg(ap, int);
	if (*nb < 0 || (*number < 0 && (*number *= -1)))
		return(1);
	return (0);
}

int		ft_aff_d(va_list ap, int prec, int len, int zero, int minus)
{
	int ret;
	int nb_len;
	int arg;

	ret = 0;
	arg = va_arg(ap, int);
	prec *= (prec < 0) ? -1 : 1;
	nb_len = ft_count_d(arg);
	if (arg < 0 && (nb_len += 1))
		ret += write(1, "-", 1);
	prec -= len;
	//printf("len = %d\t prec = %d\t zero = %d\t minus  = %d\n", len, prec, zero, minus);
	while (prec - nb_len > 0 && prec-- && (minus == 0 || minus == 2))
		ret += write(1, " ", 1);
	while (zero-- > nb_len || (len > nb_len && len--))
		ret += write(1, "0", 1);
	if (arg == 0 && minus > 1 && len == 0)
		return (ret);
	ret += ft_putnbr_base_d(arg, "0123456789");
	return (ret);
}
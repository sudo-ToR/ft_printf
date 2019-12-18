/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:40:14 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/18 17:51:47 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		flag_0_bis(char *str, int *ret, int prec, int l)
{
	while (*str == '0')
		str++;
	if ((*str == 'd' || *str == 'i') && prec != 0 && l != 0)
		*ret += write(1, "0", 1);
	else if (prec == 0 && l == 0)
		return (0);
	else
		return (write(1, "0", 1));
	return (0);
}

int		flag_0(char *str, int prec, int minus, va_list ap)
{
	int r;
	int l;
	int a;

	r = 0;
	l = (*str == '*') ? va_arg(ap, int) : ft_atoi(str);
	(a = va_arg(ap, int) < 0) ? (r += write(1, "-", 1) && ABS(&a)) : 1;
	if (prec == 0 && a == 0 && l == 0 && *(str - 1) != '0')
		return (r);
	(*(str - 1) == '0' && a == 0) ? flag_0_bis(str, &r, prec, l) : 1;
	while (a == 0 && l == 0 && prec-- > 0)
		r += write(1, " ", 1);
	if (prec == 0 && l == 0 && a == 0)
		return (*(str - 1) == '0' ? ft_putnbr_base_d(a, "0123456789") : 0);
	prec -= (l == 0) ? ft_count_d(a) : ABS(&l);
	l -= ft_count_d(a);
	while (minus == 0 && prec > 0 && (prec--))
		r += write(1, " ", 1);
	while (l > 0 && l--)
		r += write(1, "0", 1);
	r += (prec < 0 && l < 0 && a == 0 && *(str - 1) != '0') ? 0 :
		ft_putnbr_base_d(a, "0123456789");
	while (prec-- > 0 && minus == 1)
		r += write(1, " ", 1);
	return (r);
}

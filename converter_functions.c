/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:18:19 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/18 13:42:55 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		ft_converter_c(char *str, va_list ap)
{
	int ret;
	int prec;
	int minus;

	ret = 0;
	minus = 0;
	prec = 0;
	if (ft_isdigit(*str) && (prec = ft_atoi(str)))
		while (ret < prec - 1)
			ret += write(1, " ", 1);
	if (*str == '*' && str++ && (prec = va_arg(ap, int)))
		while ( prec > 0 && --prec > 0)
			ret += write(1, " ", 1);
	if (prec < 0 && (minus = 1))
		prec *=-1; 
	if (*str == '-' && str++ && (prec = ft_atoi(str)))
		minus = 1;
	while (*str == '0' && (prec = ft_atoi(str + 1)) && ret < prec && minus != 1)
		ret += write(1, "0", 1);
	ft_putchar(va_arg(ap, int));
	if (minus == 1 && (ret += prec))
		while ((prec > 0) ? --prec != 0 : ++prec != 0)
			ret += write(1, " ", 1);
	return (ret + 1);
}

int		ft_converter_d(char *str, va_list ap)
{
	int	ret;
	int arg;
	int	minus;
	int prec;

	ret = 0;
	minus = 0;
	if (*str == '-' && (minus = 1) && str++)
		prec = (*str == '*') ? va_arg(ap, int) : ft_atoi(str);
	else if (*str == '*' && str++)
		prec = va_arg(ap, int);
	else
		prec = ft_atoi(str);
	prec *= (prec < 0 && (minus = 1)) ? -1 : 1;
	while ((*str != '0' && ft_isdigit(*str)) || *str == '*')
		str++;
	if ((*str == '.' || (minus != 1 && *str == '0')))
		return (ret += flag_0(str + 1, prec, minus, ap));
	arg = va_arg(ap, int);
	while (minus == 0 && --prec >= ft_count_d(arg))
		ret += write(1, " ", 1);
	ret += ft_putnbr_base_d(arg, "0123456789");
	while (ret++ < prec && prec > ft_count_d(arg))
		write(1, " ", 1);
	return (ret);
}

int		ft_converter_p(char *str, va_list ap)
{
	int		ret;
	int 	prec;
	int		minus;
	void 	*arg;

	ret = 0;
	minus = 0;
	prec = 0;
	if (*str == '-' && (minus = 1) && str++)
		prec = (*str == '*') ?  va_arg(ap, int) : ft_atoi(str++);
	else if (*str == '*' && str++)
		prec = va_arg(ap, int);
	else 
		prec = ft_atoi(str);
	arg = va_arg(ap, void *);
	if (prec < 0 && (minus = 1))
		prec *= -1;
	if (minus == 0)
		prec -= ft_count_p(arg);
	while (minus == 0 &&  prec > 0 && (prec--))
	 	write(1, " ", 1);
	write(1, "0x", 2);
	ret += ft_putnbr_p(arg) + 2;
	while (ret++ < prec)
		write(1, " ", 1);
	return (ret);
}
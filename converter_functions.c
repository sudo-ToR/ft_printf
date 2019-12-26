/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:18:19 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/26 20:56:50 by lnoirot          ###   ########.fr       */
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
		while (prec > 0 && --prec > 0)
			ret += write(1, " ", 1);
	if (prec < 0 && (minus = 1))
		prec *= -1;
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
	int		ret;
	t_flag	stock;
	int		bool;

	ret = 0;
	bool = 0;
	stock = ft_fill_struct(str, ap);
	if (stock.zero > 0 && stock.arg < 0 && (bool = 1))
		ret += write(1, "-", 1);
	while (stock.zero > 0 && (stock.zero--))
		ret += write(1, "0", 1);
	//printf("%d\t%d\t%d\t%d\n", stock.arg, stock.flag, stock.pre, stock.flag);
	while (stock.pre-- > 0)
		ret += write(1, " ", 1);
	if (stock.arg < 0 && stock.zero <= 0 && bool == 0)
		ret += write(1, "-", 1);
	ft_converter_d_pt1(&stock);
	while (stock.width-- > 0)
		ret += write(1, "0", 1);
	//printf("%d\t%d\t%d\t%d\n", stock.arg, stock.flag, stock.pre, stock.flag);
	if ((stock.arg != 0 || (stock.flag == 0 && stock.pre != 0)) || (stock.star == -1))
		ret += ft_putnbr_base_d(stock.arg, "0123456789");
	while (stock.min-- > 0)
		ret += write(1, " ", 1);
	return (ret);
}

int		ft_converter_p(char *str, va_list ap)
{
	int		ret;
	int		prec;
	int		minus;
	void	*arg;

	ret = 0;
	minus = 0;
	prec = 0;
	if (*str == '-' && (minus = 1) && str++)
		prec = (*str == '*') ? va_arg(ap, int) : ft_atoi(str++);
	else if (*str == '*' && str++)
		prec = va_arg(ap, int);
	else
		prec = ft_atoi(str);
	arg = va_arg(ap, void *);
	prec *= (prec < 0 && (minus = 1)) ? -1 : 1;
	if (minus == 0)
		prec -= ft_count_p(arg);
	while (minus == 0 && prec > 0 && (prec--))
		write(1, " ", 1);
	write(1, "0x", 2);
	ret += ft_putnbr_p(arg) + 2;
	while (ret++ < prec)
		write(1, " ", 1);
	return (ret);
}

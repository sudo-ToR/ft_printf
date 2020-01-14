/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:18:19 by lnoirot           #+#    #+#             */
/*   Updated: 2020/01/14 23:15:31 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		ft_converter_c(char *str, va_list ap, int i)
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
	if (*str == '-' && str++ && (minus = 1))
		prec = ft_atoi(str);
	(*str == '*' && minus == 1) ? prec = va_arg(ap, int) : 0;
	while (*str == '0' && (prec = ft_atoi(str + 1)) && ret < prec && minus != 1)
		ret += write(1, "0", 1);
	(i == 0) ? ft_putchar(va_arg(ap, int)) : ft_putchar('%');
	if (minus == 1 && (ret += abs(prec)) && (ret--))
		while ((prec > 0) ? --prec != 0 : ++prec != 0)
			write(1, " ", 1);
	return (ret + 1);
}

int		ft_converter_d(char *str, va_list ap)
{
	int		ret;
	t_flag	stock;
	int		b;

	ret = 0;
	b = 0;
	stock = ft_fill_struct(str, ap);
	if (stock.zero > 0 && stock.arg < 0 && (b = 1))
		ret += write(1, "-", 1);
	while (stock.zero > 0 && (stock.zero--))
		ret += write(1, "0", 1);
	while (stock.pre-- > 0)
		ret += write(1, " ", 1);
	ft_converter_d_pt1(&stock, b, &ret);
	while (stock.width-- > 0)
		ret += write(1, "0", 1);
	if (!(stock.star) && ((!(stock.star) && (stock.arg != 0))
		|| (stock.flag == 0 && stock.pre)))
		ret += ft_putnbr_base_d(stock.arg, "0123456789");
	else if (stock.star > 0)
		ret += ft_putnbr_base_d(stock.arg, "0123456789");
	while (stock.min-- > 0)
		ret += write(1, " ", 1);
	return (ret);
}

int		ft_converter_xu(char *str, va_list ap, char c)
{
	int		ret;
	t_flag	stock;

	ret = 0;
	stock = ft_fill_struct_xu(str, ap, c);
	if (stock.width <= 0 && stock.flag)
		stock.zero = 0;
	else if (stock.flag && !(stock.star))
		stock.width -= count_xu(stock.flag, c);
	while (stock.zero > 0 && (stock.zero--))
		ret += write(1, "0", 1);
	while (stock.pre && stock.pre-- > 0)
		ret += write(1, " ", 1);
	while (stock.width-- > 0)
		ret += write(1, "0", 1);
	if (!(stock.star) && ((!(stock.star) && (stock.arg != 0))
		|| (stock.flag == 0 && stock.pre)))
		ret += ft_putnbr_base(stock.arg, c);
	else if (stock.star > 0)
		ret += ft_putnbr_base(stock.arg, c);
	while (stock.min-- > 0)
		ret += write(1, " ", 1);
	return (ret);
}

int		ft_converter_s(char *str, va_list ap)
{
	int		ret;
	t_flag	stock;
	char	*tmp;

	ret = 0;
	ft_init(&stock);
	if (*str == '-')
		stock.min = (*(++str) == '*') ? abs(va_arg(ap, int)) : (ft_atoi(str));
	else if (*str == '*')
		stock.pre = va_arg(ap, int);
	else if (ft_isdigit(*str))
		stock.pre = ft_atoi(str);
	if (stock.pre < 0 && (stock.min = abs(stock.pre)))
		stock.pre = 0;
	while (ft_isdigit(*str) || *str == '*')
		str++;
	if (*str == '.' && (stock.flag = 1))
		stock.width = (*(++str) == '*') ? (va_arg(ap, int)) : (ft_atoi(str));
	ft_converter_s_pt1(&tmp, ap, &stock);
	while (stock.width < stock.pre--)
		ret += write(1, " ", 1);
	ret += write(1, tmp, stock.width);
	while (stock.min-- > stock.width)
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
		ret += write(1, " ", 1);
	write(1, "0x", 2);
	ret += ft_putnbr_p(arg) + 2;
	while (ret < prec)
		ret += write(1, " ", 1);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:40:14 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/22 21:22:16 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_init(t_flag *stock)
{
	stock->prec = 0;
	stock->width = 0;
	stock->minus = 0;
	stock->zero = 0;
	stock->flags = 0;
}

void	ft_fill_struct_pt1(t_flag *stock)
{
	(stock->width == stock->minus) ? stock->minus = 0 : 0;
	if (stock->arg == 0 && stock->prec == 1 
		&& stock->flags == 0 && (stock->prec--))
		return;
	if (stock->arg == 0 && (stock->prec != 0 || stock->minus != 0)
		&& stock->width == 0 && stock->flags != 0)
		return;
	stock->width -= (stock->arg != 0 && stock->width > 0) ? ft_count_d(stock->arg) : 0;
	//printf("%d\t%d\t%d\t%d\t%d\n", stock->prec, stock->width, stock->zero, stock->minus, stock->flags);
	stock->zero -= ft_count_d(stock->arg);
	stock->minus -= ft_count_d(stock->arg);
	if (stock->arg == 0 && (stock->minus == 1
		|| stock->prec == 1) && stock->flags == 0)
		return;
	stock->prec -= (stock->width > 0) ? stock->width : ft_count_d(stock->arg);
	stock->prec += (stock->arg == 0 && stock->flags != 0 
		&& stock->prec != 0) ? 1 : 0;
	(stock->minus > 0) ? stock->zero = 0 : 0;
	if (stock->zero > stock->width && stock->flags != 0)
	{
		stock->prec = (stock->width > 0) ? stock->zero - stock->width
			: stock->zero;
		stock->zero = 0;
	}
	else if (stock->prec > stock->width && stock->flags != 0 && stock->width > 0)
		stock->prec -= ft_count_d(stock->arg);
}

t_flag	ft_fill_struct_starrs(t_flag *stock, va_list ap, char *str)
{
	int star_1;

	star_1 = va_arg(ap, int);
	if (star_1 < 0 || *(str - 1) == '-')
		stock->minus = star_1;
	if (*(++str) == '.' && *str == '*')
		stock->prec = va_arg(ap, int);
	return (*stock);
}

t_flag	ft_fill_struct(char *str, va_list ap)
{
	t_flag	stock;

	ft_init(&stock);
	if (*str ==  '-')
		stock.minus = ft_atoi(++str);
	if (*str == '*')
		return (ft_fill_struct_starrs(&stock, ap, str));
	if (*str == '0' && stock.minus == 0)
		stock.zero = ft_atoi(str++);
	else if (ft_isdigit(*str) && *str != 0 && stock.minus == 0)
		stock.prec = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str == '.' && (stock.flags = 1))
		stock.width = ft_atoi(++str);
	if(*str == '*')
		return (ft_fill_struct_starrs(&stock, ap, str));
	stock.arg = va_arg(ap, int);
	ft_fill_struct_pt1(&stock);
	if (*(str - 1) == '.' && *str == '0' && stock.prec > 1)
		stock.prec += 1;
	//printf("%d\t%d\t%d\t%d\t%d\n", stock.prec, stock.width, stock.zero, stock.minus, stock.flags);
	if ((stock.width >= 0 && stock.prec >= stock.width && stock.flags == 1 && stock.arg < 0)
		|| (stock.width < 0 && stock.prec > stock.width && stock.flags && stock.arg < 0))
		stock.prec--;
	else if (stock.arg > 0 && stock.width <= 0 && stock.minus < 0 && stock.flags)
		stock.prec--;
	/*
	condition en desous a peaufiner
	*/
	if (stock.width >= stock.zero && stock.flags && (stock.width += 1))
		stock.zero = 0;
	return (stock);
}
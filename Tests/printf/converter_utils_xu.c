/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils_xu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:14:50 by lnoirot           #+#    #+#             */
/*   Updated: 2020/01/14 21:29:37 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
t_flag	ft_fill_struct_stars_xu(t_flag stock, va_list ap, char *str, int c)
{
	int b;

	if ((b = 0) && *(str - 1) == '-')
		stock.min = abs(va_arg(ap, int));
	else if (!(stock.flag))
		stock.pre = va_arg(ap, int);
	if (stock.flag && (b = 1))
		stock.width = va_arg(ap, int);
	while (!(ft_is_converter(*str)))
		if (*(++str) == '.' && (stock.flag = 1))
		{
			b = 1;
			stock.width = (*(str + 1) == '*') ? va_arg(ap, int)
				: ft_atoi(++str);
			(*str <= '9' && *str >= '0') ? b = 2 : 0;
		}
	stock.arg = va_arg(ap, int);
	(b == 1) ? stock.width -= (count_xu(stock.arg, c - 1)) : 0;
	if (b == 2)
	{
		stock = ft_fill_struct_star_xu_pt1(stock, c);
		return (stock);
	}
	ft_fill_struct_star_xu_pt2(&stock, c);
	return (stock);
}

void	ft_fill_struct_xu_pt3(t_flag *stock, int c)
{
	if (stock->zero > stock->width && stock->flag != 0)
	{
		if (!(stock->width))
			stock->width = abs(stock->pre) - count_xu(stock->arg, c);
		stock->pre = stock->zero - stock->width;
		stock->zero = 0;
	}
	if ((stock->width >= 0 && stock->pre >= stock->width && stock->flag == 1
		&& stock->arg < 0) || (stock->width < 0 && stock->pre > stock->width
			&& stock->flag && stock->arg < 0 && stock->min >= 0))
		stock->pre--;
	if (stock->width >= stock->zero && stock->width
		&& stock->flag && (stock->width += 1))
		stock->zero = 0;
}

void	ft_fill_struct_xu_pt2(t_flag *stock, int c)
{
	int b;

	b = 0;
	(stock->width == stock->min) ? stock->min = 0 : 0;
	if (stock->width && stock->min && (b = 1))
		stock->min -= stock->width;
	if (stock->arg == 0 && stock->pre == 1
		&& stock->flag == 0 && (stock->pre--))
		return ;
	if (stock->arg == 0 && (stock->pre != 0 || stock->min != 0)
		&& stock->width == 0 && stock->flag != 0)
		return ;
	stock->width -= (stock->arg && stock->width > 0)
		? count_xu(stock->arg, c) : 0;
	stock->zero -= count_xu(stock->arg, c);
	stock->min -= (b == 0) ? count_xu(stock->arg, c) : 0;
	if (!(stock->arg) && (stock->min == 1 || stock->pre == 1) && !(stock->flag))
		return ;
	stock->pre -= (stock->width > 0) ? stock->width + count_xu(stock->arg, c)
		: count_xu(stock->arg, c);
	stock->pre += (stock->arg == 0 && stock->flag != 0
		&& stock->pre != 0) ? 1 : 0;
	(stock->min > 0) ? stock->zero = 0 : 0;
}

t_flag	ft_fill_struct_xu(char *str, va_list ap, int c)
{
	t_flag	stock;

	str = ft_fill_struct_pt1(&stock, str);
	if (!(stock.pre) && stock.zero && stock.flag && (stock.pre = stock.zero))
		stock.zero = 0;
	if (*str == '*')
		return (ft_fill_struct_stars_xu(stock, ap, str, c));
	stock.arg = va_arg(ap, int);
	if (stock.arg < 0 && stock.zero && stock.width &&
	stock.width > count_xu(stock.arg, c) + 1 && stock.width != stock.zero
	&& (stock.zero = 0) && (stock.width -= count_xu(stock.arg, c) - 2)
	&& (stock.pre = stock.zero - stock.width))
		return (stock);
	if (stock.width == count_xu(stock.arg, c) && (stock.pre || stock.zero))
	{
		(stock.zero) ? (stock.pre = stock.zero - count_xu(stock.arg, c) - 1)
			: (stock.pre -= stock.width - 1 + count_xu(stock.arg, c));
		stock.zero = 0;
		stock.width = 0;
		return (stock);
	}
	ft_fill_struct_xu_pt2(&stock, c);
	ft_fill_struct_xu_pt3(&stock, c);
	return (stock);
}

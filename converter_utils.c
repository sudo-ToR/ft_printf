/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:40:14 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/27 21:26:27 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
t_flag	ft_fill_struct_stars(t_flag stock, va_list ap, char *str)
{
	int b;

	b = 0;
	if (*(str - 1) == '-')
		stock.min = abs(va_arg(ap, int));
	else  if (!(stock.flag))
		stock.pre = va_arg(ap, int);
	if (stock.flag && (b = 1))
		stock.width = va_arg(ap, int);
	//printf("%d\t%d\t%d\t%d\n", stock.arg, stock.flag, stock.pre, stock.width);
	while (!(ft_is_converter(*str)))
		if (*(++str) == '.')
		{
			stock.width = (*(str + 1) == '*') ? va_arg(ap, int) : ft_atoi(++str);
			if (*str <= '9' && *str >= '0')
				b = 2;
			stock.flag = 1;
		}
	//printf("%d\t%d\t%d\t%d\n", stock.arg, stock.flag, stock.pre, stock.width);
	stock.arg = va_arg(ap, int);
	if (b == 1)
		stock.width -= (ft_count_d(stock.arg) - 1);
	if (b == 2)
	{
		stock.width -= (ft_count_d(stock.arg) - 1);
		stock.width += (stock.arg < 0) ? 1 : 0;
		if (stock.pre > 0)
			stock.pre -= stock.width + ft_count_d(stock.arg) - 1;
		if (stock.pre < 0 && (stock.min = -stock.pre))
			stock.pre = 0;
		if (stock.min)
			stock.min -= stock.width + ft_count_d(stock.arg) - 1;
		return (stock);
	}
	if (stock.width < 0 && (stock.star = 1))
		stock.pre -= (stock.pre > 0) ? 1 : 0;
	//printf("%d\t%d\t%d\t%d\n", stock.arg, stock.flag, stock.pre, stock.width);
	if (stock.pre < 0 && (stock.min = abs(stock.pre)))
		stock.pre = 0;
	//printf("%d\t%d\t%d\t%d\n", stock.arg, stock.flag, stock.pre, stock.width);
	if (!(stock.arg) && stock.flag && stock.width > 0 && (stock.star = 1))
		stock.pre -= 1;
	//printf("%d\t%d\t%d\t%d\n", stock.width, stock.flag, stock.pre, stock.width);
	if (stock.arg < 0)
		stock.width -= 1;
	//printf("%d\t%d\t%d\t%d\n", stock.width, stock.flag, stock.pre, stock.width);
	if (stock.width > 0)
		stock.pre -= stock.width;
	//printf("%d\t%d\t%d\t%d\n", stock.width, stock.flag, stock.pre, stock.width);
	if (((stock.arg ) || (!(stock.arg) && ((stock.pre && !(stock.flag))|| !(stock.flag)))) && (stock.star = 1))
		stock.pre -= ft_count_d(stock.arg);
	if (stock.flag && stock.pre >= 0 && stock.width < 0)
		stock.pre--;
	if (stock.star == 0)
		stock.star = -1;
	stock.min -= (!(stock.arg) && stock.flag && !(stock.pre)) ? 0 : ft_count_d(stock.arg);
	//printf("%d\t%d\t%d\t%d\n", stock.min, stock.flag, stock.pre, stock.width);
	if (!(stock.arg) && stock.pre >= 0 && stock.flag && stock.width < 0)
		stock.pre--;
	if (stock.flag && stock.width > stock.min && stock.width > 0)
		stock.min -= 1;
	return (stock);
}

void	ft_fill_struct_pt2(char *str, t_flag *stock)
{
	if (*(str - 1) == '.' && *str == '0' && stock->pre > 1)
		stock->pre += 1;
	if ((stock->width >= 0 && stock->pre >= stock->width && stock->flag == 1
		&& stock->arg < 0) || (stock->width < 0 && stock->pre > stock->width
			&& stock->flag && stock->arg < 0 && stock->min >= 0))
		stock->pre--;
	else if (stock->arg > 0 && stock->width <= 0
		&& stock->min < 0 && stock->flag)
		stock->pre--;
	if (stock->width >= stock->zero && stock->flag && (stock->width += 1))
		stock->zero = 0;
	if (stock->arg < 0 && stock->width == 1
		&& stock->zero == 0 && stock->min <= -2
			&& stock->flag && stock->pre < 0)
		stock->width--;
	if (stock->arg < 0 && stock->pre >= 0 && stock->width == 1
		&& stock->zero == 0 && stock->flag && stock->min == -4
			&& stock->pre > ft_count_d(stock->arg))
		stock->width--;
}

void	ft_fill_struct_pt1(t_flag *stock)
{
	(stock->width == stock->min) ? stock->min = 0 : 0;
	if (stock->arg == 0 && stock->pre == 1
		&& stock->flag == 0 && (stock->pre--))
		return ;
	if (stock->arg == 0 && (stock->pre != 0 || stock->min != 0)
		&& stock->width == 0 && stock->flag != 0)
		return ;
	stock->width -= (stock->arg != 0 && stock->width > 0) ?
		ft_count_d(stock->arg) : 0;
	stock->zero -= ft_count_d(stock->arg);
	stock->min -= ft_count_d(stock->arg);
	if (!(stock->arg) && (stock->min == 1 || stock->pre == 1) && !(stock->flag))
		return ;
	stock->pre -= (stock->width > 0) ? stock->width : ft_count_d(stock->arg);
	stock->pre += (stock->arg == 0 && stock->flag != 0
		&& stock->pre != 0) ? 1 : 0;
	(stock->min > 0) ? stock->zero = 0 : 0;
	if (stock->zero > stock->width && stock->flag != 0)
	{
		stock->pre = (stock->width > 0) ? stock->zero - stock->width
			: stock->zero;
		stock->zero = 0;
	}
	else if (stock->pre > stock->width && stock->flag && stock->width > 0)
		stock->pre -= ft_count_d(stock->arg);
}

t_flag	ft_fill_struct(char *str, va_list ap)
{
	t_flag	stock;

	ft_init(&stock);
	if (*str == '-')
		stock.min = ft_atoi(++str);
	if (*str == '*')
		return (ft_fill_struct_stars(stock, ap, str));
	if (*str == '0' && stock.min == 0)
		stock.zero = ft_atoi(str++);
	else if (ft_isdigit(*str) && *str != 0 && stock.min == 0)
		stock.pre = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str == '.' && (stock.flag = 1))
		stock.width = ft_atoi(++str);
	if (*str == '*')
		return (ft_fill_struct_stars(stock, ap, str));
	stock.arg = va_arg(ap, int);
	ft_fill_struct_pt1(&stock);
	ft_fill_struct_pt2(str, &stock);
	return (stock);
}

void	ft_converter_d_pt1(t_flag *stock)
{
	if (stock->pre < 0 && stock->min < 0 && stock->zero == 0
		&& stock->flag && stock->arg > 0)
		stock->width--;
	if (stock->pre < 0 && stock->flag && stock->min >= 0)
		stock->width--;
	if (stock->arg == 0 && stock->flag && stock->pre <= -1 && stock->min <= -1)
		stock->width--;
}

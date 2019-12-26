/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:40:14 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/26 20:57:03 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
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

t_flag	ft_fill_struct_stars(t_flag stock, va_list ap, char *str)
{
	int star_1;

	star_1= va_arg(ap,int);
	stock.star = 1;
	stock.min = (*(str - 1) == '-') ? star_1: 0;
	stock.min += (star_1 < 0 && stock.min == 0) ? -star_1 : 0;
	stock.pre += (*(str - 1) == '%') ? abs(star_1) : 0;
	while (!(ft_is_converter(*(str++))))
		if (*str == '.' && (stock.flag = 1))
			stock.pre = (*(++str) == '*') ? va_arg(ap, int) : ft_atoi(str);
	stock.arg = va_arg(ap, int);
	//printf("%d\t%d\t%d\n", star_1, stock.flag, stock.arg);
	if (star_1 == 0 && stock.flag && stock.arg == 0 && (stock.pre--))
		stock.star = -1;
	stock.pre -= (stock.arg != 0) ? ft_count_d(stock.arg) : 0;
	stock.min -= ft_count_d(stock.arg);
	stock.pre *= (!(stock.flag) && star_1 < 0) ? -1 : 1;
	stock.pre -= (!(stock.arg) && !(stock.flag)) ? 1 : 0;
	if (stock.min && stock.flag && star_1 < 0)
	{
		stock.pre = 0;
		stock.min += (stock.arg == 0) ? 1 : 0;
	}
	return (stock);
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

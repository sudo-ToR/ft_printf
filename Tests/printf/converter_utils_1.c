/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:32:18 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/28 18:44:22 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_flag *stock)
{
	stock->pre = 0;
	stock->width = 0;
	stock->min = 0;
	stock->zero = 0;
	stock->flag = 0;
	stock->star = 0;
}

void	ft_converter_d_pt1(t_flag *stock, int b, int *ret)
{
	if (stock->arg < 0 && stock->zero <= 0 && b == 0)
		*ret += write(1, "-", 1);
	if (stock->pre < 0 && stock->min < 0 && stock->zero == 0
		&& stock->flag && stock->arg > 0)
		stock->width--;
	if (stock->pre < 0 && stock->flag && stock->min >= 0)
		stock->width--;
	if (stock->arg == 0 && stock->flag && stock->pre <= -1 && stock->min <= -1)
		stock->width--;
}

t_flag	ft_fill_struct_star_pt1(t_flag stock)
{
	stock.width -= (count_d(stock.arg) - 1);
	stock.width += (stock.arg < 0) ? 1 : 0;
	if (stock.pre > 0)
		stock.pre -= stock.width + count_d(stock.arg) - 1;
	if (stock.pre < 0 && (stock.min = -stock.pre))
		stock.pre = 0;
	if (stock.min)
		stock.min -= stock.width + count_d(stock.arg) - 1;
	return (stock);
}

void	ft_fill_struct_star_pt2(t_flag *stock)
{
	if (stock->pre < 0 && (stock->min = abs(stock->pre)))
		stock->pre = 0;
	if (!(stock->arg) && stock->flag && stock->width > 0 && (stock->star = 1))
		stock->pre -= 1;
	if (stock->arg < 0)
		stock->width -= 1;
	if (stock->width > 0 && stock->width > count_d(stock->arg))
		stock->pre -= stock->width;
	if (((stock->arg) || (!(stock->arg) && ((stock->pre && !(stock->flag))
		|| !(stock->flag)))) && (stock->star = 1))
		stock->pre -= count_d(stock->arg);
	if (stock->star == 0)
		stock->star = -1;
	stock->min -= (!(stock->arg) && stock->flag && !(stock->pre)) ? 0
		: count_d(stock->arg);
	if (!(stock->arg) && stock->flag && stock->width < 0 && (stock->star = 1))
		stock->pre--;
	if (stock->flag && stock->width > stock->min && stock->width > 0)
		stock->min -= 1;
	if ((!(stock->arg) && (stock->width < 0) && stock->flag
		&& stock->min && (stock->star = 1)))
		stock->min--;
}

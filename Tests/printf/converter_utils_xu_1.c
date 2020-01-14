/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils_xu_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:41:23 by lnoirot           #+#    #+#             */
/*   Updated: 2020/01/14 23:12:16 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_fill_struct_star_xu_pt1(t_flag stock, int c)
{
	stock.width -= (count_xu(stock.arg, c));
	stock.width += (stock.arg < 0) ? 1 : 0;
	if (stock.pre > 0)
		stock.pre -= stock.width + count_xu(stock.arg, c) - 1;
	if (stock.pre < 0 && (stock.min = -stock.pre))
		stock.pre = 0;
	if (stock.min)
		stock.min -= stock.width + count_xu(stock.arg, c) - 1;
	return (stock);
}

void	ft_fill_struct_star_xu_pt2(t_flag *stock, int c)
{
	if (stock->pre < 0 && (stock->min = abs(stock->pre)))
		stock->pre = 0;
	if (!(stock->arg) && stock->flag && stock->width > 0 && (stock->star = 1))
		stock->pre -= 1;
	if (stock->width > 0)
		stock->pre -= stock->width;
	if (((stock->arg) || (!(stock->arg) && ((stock->pre && !(stock->flag))
		|| !(stock->flag)))) && (stock->star = 1))
		stock->pre -= count_xu(stock->arg, c);
	if (stock->star == 0)
		stock->star = -1;
	stock->min -= (!(stock->arg) && stock->flag && !(stock->pre)) ? 0
		: count_xu(stock->arg, c);
	if (!(stock->arg) && stock->flag && stock->width < 0 && (stock->star = 1))
		stock->pre--;
	if (stock->flag && stock->width > stock->min && stock->width > 0)
		stock->min -= 1;
	if ((!(stock->arg) && (stock->width < 0) && stock->flag
		&& stock->min && (stock->star = 1)))
		stock->min--;
	if (stock->width > 0 && stock->min)
		stock->min -= stock->width;
}

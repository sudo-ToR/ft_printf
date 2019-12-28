/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils_xu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:14:50 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/28 21:18:36 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>
t_flag	ft_fill_struct_xu(char *str, va_list ap, int c)
{
	t_flag	stock;

	c = 0;
	while (!(ft_is_converter(str[c])))
		c++;
	ft_init(&stock);
	(*str == '-') ? stock.min = ft_atoi(++str) : 0;
	if (*str == '*')
		return (ft_fill_struct_stars_xu(stock, ap, str, c));
	if (*str == '0' && stock.min == 0)
		stock.zero = ft_atoi(str++);
	else if (ft_isdigit(*str) && *str != 0 && stock.min == 0)
		stock.pre = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	stock.width += (*str == '.' && (stock.flag = 1)) ? ft_atoi(++str) : 0;
	if (*str == '*')
		return (ft_fill_struct_stars_xu(stock, ap, str, c));
	stock.arg = va_arg(ap, int);
	ft_fill_struct_xu_pt2(&stock, c);
	return (stock);
}

void	ft_fill_struct_xu_pt2(t_flag *stock, int c)
{
	stock->zero -= count_xu(stock->arg, c);
	stock->min -= count_xu(stock->arg, c);
	stock->pre -= (stock->width > 0) ? stock->width : count_xu(stock->arg, c);
	stock->pre += (stock->arg == 0 && stock->flag != 0
		&& stock->pre != 0) ? 1 : 0;
	stock->zero -= stock->width;
	stock->min -= stock->width;
	stock->width -= count_xu(stock->arg, c);
	
}


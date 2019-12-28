/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:40:14 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/28 18:51:38 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_fill_struct_stars(t_flag stock, va_list ap, char *str)
{
	int b;

	b = 0;
	if (*(str - 1) == '-')
		stock.min = abs(va_arg(ap, int));
	else if (!(stock.flag))
		stock.pre = va_arg(ap, int);
	if (stock.flag && (b = 1))
		stock.width = va_arg(ap, int);
	while (!(ft_is_converter(*str)))
		if (*(++str) == '.' && (stock.flag = 1))
		{
			stock.width = (*(str + 1) == '*') ? va_arg(ap, int)
				: ft_atoi(++str);
			(*str <= '9' && *str >= '0') ? b = 2 : 0;
		}
	stock.arg = va_arg(ap, int);
	(b == 1) ? stock.width -= (count_d(stock.arg) - 1) : 0;
	if (b == 2)
	{
		stock = ft_fill_struct_star_pt1(stock);
		return (stock);
	}
	ft_fill_struct_star_pt2(&stock);
	return (stock);
}

void	ft_fill_struct_pt3(char *str, t_flag *stock)
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
	if (stock->width >= stock->zero && stock->width
		&& stock->flag && (stock->width += 1))
		stock->zero = 0;
	if (stock->arg < 0 && stock->width == 1
		&& stock->zero == 0 && stock->min <= -2
			&& stock->flag && stock->pre < 0)
		stock->width--;
	if (stock->arg < 0 && stock->pre >= 0 && stock->width == 1
		&& stock->zero == 0 && stock->flag && stock->min == -4
			&& stock->pre > count_d(stock->arg))
		stock->width--;
}

void	ft_fill_struct_pt2(t_flag *stock)
{
	(stock->width == stock->min) ? stock->min = 0 : 0;
	if (stock->arg == 0 && stock->pre == 1
		&& stock->flag == 0 && (stock->pre--))
		return ;
	if (stock->arg == 0 && (stock->pre != 0 || stock->min != 0)
		&& stock->width == 0 && stock->flag != 0)
		return ;
	stock->width -= (stock->arg && stock->width > 0) ? count_d(stock->arg) : 0;
	stock->zero -= count_d(stock->arg);
	stock->min -= count_d(stock->arg);
	if (!(stock->arg) && (stock->min == 1 || stock->pre == 1) && !(stock->flag))
		return ;
	stock->pre -= (stock->width > 0) ? stock->width : count_d(stock->arg);
	stock->pre += (stock->arg == 0 && stock->flag != 0
		&& stock->pre != 0) ? 1 : 0;
	(stock->min > 0) ? stock->zero = 0 : 0;
	if (stock->zero > stock->width && stock->flag != 0)
	{
		if (!(stock->width))
			stock->width = abs(stock->pre) - count_d(stock->arg);
		stock->pre = stock->zero - stock->width;
		stock->zero = 0;
	}
	else if (stock->pre > stock->width && stock->flag && stock->width > 0)
		stock->pre -= count_d(stock->arg);
}

char	*ft_fill_struct_pt1(t_flag *stock, char *str)
{
	ft_init(stock);
	(*str == '-') ? stock->min = ft_atoi(++str) : 0;
	if (*str == '*')
		return (str);
	if (*str == '0' && stock->min == 0)
		stock->zero = ft_atoi(str++);
	else if (ft_isdigit(*str) && *str != 0 && stock->min == 0)
		stock->pre = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	stock->width += (*str == '.' && (stock->flag = 1)) ? ft_atoi(++str) : 0;
	if (*str == '*')
		return (str);
	return (str);
}

t_flag	ft_fill_struct(char *str, va_list ap)
{
	t_flag	stock;

	str = ft_fill_struct_pt1(&stock, str);
	if (*str == '*')
		return (ft_fill_struct_stars(stock, ap, str));
	stock.arg = va_arg(ap, int);
	if (stock.arg < 0 && stock.zero && stock.width &&
	stock.width > count_d(stock.arg) + 1 && stock.width != stock.zero
	&& (stock.zero = 0) && (stock.width -= count_d(stock.arg) - 2)
	&& (stock.pre = stock.zero - stock.width))
		return (stock);
	if (stock.arg < 0 && stock.width == count_d(stock.arg)
		&& (stock.pre || stock.zero) && (stock.width = 2))
	{
		(stock.zero) ? (stock.pre = stock.zero - count_d(stock.arg) - 1)
			: (stock.pre -= stock.width - 1 + count_d(stock.arg));
		stock.zero = 0;
		return (stock);
	}
	ft_fill_struct_pt2(&stock);
	ft_fill_struct_pt3(str, &stock);
	return (stock);
}

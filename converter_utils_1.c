/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:32:18 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/26 20:33:51 by lnoirot          ###   ########.fr       */
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

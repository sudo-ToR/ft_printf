/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:32:19 by lnoirot           #+#    #+#             */
/*   Updated: 2019/11/26 18:52:08 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_d(int arg)
{
	unsigned int	nbr;
	int				ret;

	if (arg < 0)
		nbr = - arg;
	else
		nbr = arg;
	while (nbr > 0)
	{
		ret++;
		nbr /= 10;
	}
	return (ret);
}

void	ft_count_int(int *length, char *str, int arg)
{
	if (*str == 'd' ||  *str == 'i')
		*length = ft_count_d(arg);
	if (*str == 'x')
		*length += ft_putnbr_base(arg, "0123456789abcdef");
	if (*str == 'X')
		*length += ft_putnbr_base(arg, "0123456789ABCDEF");
	if (*str == 'u')
		*length += ft_putnbr_base(arg, "0123456789");
	if (*str == 'c')
	{
		ft_putchar(arg);
		*length += 1;
	}
}


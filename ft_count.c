/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:32:19 by lnoirot           #+#    #+#             */
/*   Updated: 2019/11/20 20:15:53 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_base_d_count(int arg)
{
	char			*base;
	unsigned int	nbr;
	int				ret;

	base = "0123456789";
	if (arg < 0)
		nbr = -arg;
	else
		nbr = arg;
	if (nbr < 10)
		return (1);
	else
	{
		ret += ft_putnbr_base_d_count(nbr / 10);
		ret += ft_putnbr_base_d_count(nbr % 10);
	}
}

void	ft_count_int(int *length, char *str, int arg)
{
	if (*str == 'd' ||  *str == 'i')
		*length = ft_putnbr_base_d_count(arg);
	if (*str == 'x')
		i += ft_putnbr_base(arg, "0123456789abcdef");
	if (*str == 'X')
		i += ft_putnbr_base(arg, "0123456789ABCDEF");
	if (*str == 'u')
		i += ft_putnbr_base(arg, "0123456789");
	if (*str == 'c')
	{
		ft_putchar(arg);
		i++;
	}
}


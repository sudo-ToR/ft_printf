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

int		ft_count_xXu(int arg)
{
	int		ret;

	ret = 0;
	while ((unsigned int)arg > 0)
	{
		ret++;
		arg /= 10;
	}
	return (ret);
}

int		ft_count_d(int arg)
{
	unsigned int	nbr;
	int				ret;

	ret = 0;
	if (arg < 0)
		nbr = -arg;
	else
		nbr = arg;
	while (nbr > 0)
	{
		ret++;
		nbr /= 10; 
	}
		return (ret);
}

int		ft_count_int(char *str, int arg)
{
	int		length;

	length = 0;
	if (*str == 'd' ||  *str == 'i')
		length = ft_count_d(arg);
	if (*str == 'x')
		length = ft_putnbr_base(arg, "0123456789abcdef");
	if (*str == 'X')
		length = ft_putnbr_base(arg, "0123456789ABCDEF");
	if (*str == 'u')
		length = ft_putnbr_base(arg, "0123456789");
	return (length);
}


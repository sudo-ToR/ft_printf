/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:00:02 by lnoirot           #+#    #+#             */
/*   Updated: 2019/11/16 19:21:51 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr_m(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		ft_putnbr_base(int n, char *base)
{
	unsigned int	length;
	int				l;

	length = 0;
	l = 0;
	while (base[length])
		length++;
	if ((unsigned)n < length)
	{
		ft_putchar(base[(unsigned)n]);
		return (1);
	}
	else
	{
		l += ft_putnbr_base((unsigned)n / length, base);
		l += ft_putnbr_base((unsigned)n % length, base);
	}
	return (l);
}

int		ft_putnbr_base_d(int n, char *base)
{
	unsigned int	length;
	unsigned int	nbr;
	int				l;

	length = 0;
	l = 0;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	else
		nbr = n;
	while (base[length])
		length++;
	if (nbr < length)
	{
		ft_putchar(base[nbr]);
		return (1);
	}
	else
	{
		l += ft_putnbr_base(nbr / length, base);
		l += ft_putnbr_base(nbr % length, base);
	}
	return (l);
}
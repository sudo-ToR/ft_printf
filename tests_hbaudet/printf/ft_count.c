/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:32:19 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/07 14:49:40 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int len;
	
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_count_d(int arg)
{
	unsigned int	nbr;
	int				ret;

	ret = 0;
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

int		ft_count_xXu(int n, char *base)
{
	unsigned int	length;
	int				l;

	length = 0;
	l = 0;
	while (base[length])
		length++;
	if ((unsigned)n < length)
		return (1);
	else
	{
		l += ft_putnbr_base((unsigned)n / length, base);
		l += ft_putnbr_base((unsigned)n % length, base);
	}
	return (l);
}

int		ft_count_p(void  *n)
{

	int				l;
	long long int	nb;

	nb = (long long int)n;
	l = 2;
	if (n == NULL)
		return (3);
	while (nb > 0)
	{
		nb /= 16;
		l++;
	}
	return (l);
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


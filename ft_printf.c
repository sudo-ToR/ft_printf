/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:15:35 by lnoirot           #+#    #+#             */
/*   Updated: 2019/11/26 19:17:09 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		flag_int(char *str, int arg)
{
	int i;

	i = 0;
	if (*str == 'd' ||  *(str) == 'i')
		i += ft_putnbr_base_d(arg, "0123456789");
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
	return (i);
}

int		flag_minus(char *str)
{
	int i;
	int j;

	if (*str == '0')
		str++;
	i = ft_atoi(str);
	j = -1;
	while (++j < i - 1)
		ft_putchar(' '); 
	return (i);
}

char	*ft_flag_zero(char *str, va_list ap, int *i)
{
	int		nb;
	int		length;

	if (*str == '-')
		return (str);
	if(*str == '.')
		str++;
	nb = ft_atoi(str);
	while (ft_isdigit(*str)== 1)
		str++;
	if (*str == 'd' ||  *(str) == 'i' || *str == 'x' 
		|| *str == 'X' || *str == 'u' || *str == 'c')
		ft_count_int(&length, str, va_arg(ap, int));
	if (*str == 'p' && str++)
		length = ;
	*i += ((length - nb > 0)? length - nb : 0);
	while (length - nb > 0)
		ft_putchar('0');
	return (str);
}

char	*ft_flag_selector(int *i, char *str, va_list ap)
{
	char *minus;

	minus = NULL;
	if (*str == '%' && str++)
		{
			if (*str == '0' && str++)
				str = ft_flag_zero(str, ap, i);
			if (*str == '-' && str++ && (minus = (char *)str))
				while (ft_isdigit(*str) != 0)
					str++;	
			else if (*str == '%' && str++)
				ft_putchar('%');
			else if (*str == 'd' ||  *(str) == 'i' || *str == 'x' 
				|| *str == 'X' || *str == 'u' || *str == 'c')
				*i += flag_int((char *)str++, va_arg(ap, int));
			else if (*str == 'p' && str++)
				*i += ft_putstr_m("0x") + ft_putnbr_p(va_arg(ap, void *));
			if (minus != NULL)
				*i+= flag_minus((char *)minus);
		}
		return (str);
}

int 	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, str);
	while (*str)
	{
		str += ft_putstr_m((char *)str);
		str = ft_flag_selector(&i, (char *)str, ap);
	}
	va_end(ap);
	return (i);
}

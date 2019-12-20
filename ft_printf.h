/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:07:11 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/20 20:34:24 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr_base(int n, char *base);
int		ft_putnbr_base_d(int n, char *base);
void	ft_putchar(char c);
int		ft_putstr_m(char *str, int *i);
int		ft_putnbr_p(void *n);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	ft_count_int(int * length, char *str, int arg);
int		ft_count_d(int arg);
int		ft_count_xXu(int n, char *base);
int		ft_count_p(void  *n);
int		ft_is_converter(char c);
int		ft_converter_c(char *str, va_list ap);
int		ft_converter_p(char *str, va_list ap);
int		ft_converter_d(char *str, va_list ap);
int		ft_star(va_list ap, char *str, int *number, int *nb, int minus);
int		ft_aff_d(va_list ap, int prec, int len, int zero, int minus);
int		ABS(int *x);

#endif

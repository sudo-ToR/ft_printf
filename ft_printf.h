/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:07:11 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/22 13:45:27 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int zero;
	int minus;
	int width;
	int prec;
	int arg;
	int flags;
}				t_flag;

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
t_flag	ft_fill_struct(char *str, va_list ap);


#endif

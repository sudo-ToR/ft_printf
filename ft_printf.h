/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:07:11 by lnoirot           #+#    #+#             */
/*   Updated: 2020/01/14 23:12:35 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flag
{
	int			zero;
	int			min;
	int			width;
	int			pre;
	int			arg;
	int			flag;
	long int	star;
}				t_flag;

int				ft_printf(const char *str, ...);
int				ft_strlen(char *str);
int				ft_putnbr_base(int n, char c);
int				ft_putnbr_base_d(int n, char *base);
void			ft_putchar(char c);
int				ft_putstr_m(char *str, int *i);
int				ft_putnbr_p(void *n);
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
int				abs(int x);
int				count_d(int arg);
int				count_xu(int n, int c);
int				ft_count_p(void *n);
int				ft_is_converter(char c);
int				ft_converter_c(char *str, va_list ap, int i);
int				ft_converter_p(char *str, va_list ap);
int				ft_converter_d(char *str, va_list ap);
t_flag			ft_fill_struct(char *str, va_list ap);
char			*ft_fill_struct_pt1(t_flag *stock, char *str);
void			ft_converter_d_pt1(t_flag *stock, int b, int *ret);
t_flag			ft_fill_struct_star_pt1(t_flag stock);
void			ft_fill_struct_star_pt2(t_flag *stock);
void			ft_init(t_flag *stock);
int				ft_converter_xu(char *str, va_list ap, char c);
t_flag			ft_fill_struct_stars_xu(t_flag stock, va_list ap,
					char *str, int c);
char			*ft_fill_struct_xu_pt1(t_flag *stock, char *str, int c);
void			ft_fill_struct_xu_pt2(t_flag *stock, int c);
t_flag			ft_fill_struct_xu(char *str, va_list ap, int c);
t_flag			ft_fill_struct_star_xu_pt1(t_flag stock, int c);
void			ft_fill_struct_star_xu_pt2(t_flag *stock, int c);
void			ft_converter_s_pt1(char **tmp, va_list ap, t_flag *stock);
int				ft_converter_s(char *str, va_list ap);

#endif

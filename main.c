/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:14:02 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/22 21:18:39 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	char *str;
	str = NULL;
	int	a = -3;
		printf("real = |%010.11d|\n", -42);
		ft_printf("mine = |%010.11d|\n", -42);
}

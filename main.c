/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:14:02 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/27 21:23:54 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	char *str;
	str = NULL;
	printf("real = |%*.*d|\n", 2, 1, 4);
	ft_printf("mine = |%*.*d|\n", 2, 1, 4);
}

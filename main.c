/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:14:02 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/26 20:44:52 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	char *str;
	str = NULL;
	printf("real = |%*.*d|\n",0,1, 0);
	ft_printf("mine = |%*.*d|\n",0, 1, 0);
}

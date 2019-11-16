/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:38:50 by lnoirot           #+#    #+#             */
/*   Updated: 2019/11/16 19:30:24 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main()
{
	//tests sans flags
	printf("real = Bonjour\n");
	ft_printf("mine = Bonjour\n");

	//test avec %d
	printf("real = %i\n", -15);
	ft_printf("mine = %i\n", -15);
	printf("real = %i\n", -2147483648);
	ft_printf("mine = %i\n", -2147483648);
	printf("real = %i\n", 2147483647);
	ft_printf("mine = %i\n", 2147483647);
	printf("real = %d avec une tres longe ligne derriere\n", 123456);
	ft_printf("mine = %d avec une tres longe ligne derriere\n", 123456);
}

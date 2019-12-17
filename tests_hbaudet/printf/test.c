/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:38:50 by lnoirot           #+#    #+#             */
/*   Updated: 2019/12/06 17:28:56 by lnoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main()
{
	//tests sans flags
	printf("tests sans flags\n");
	printf("real = Bonjour\n");
	ft_printf("mine = Bonjour\n");
	printf("\n");

	//test avec %%
	printf("test avec %%\n");
	printf("real = %%\n");
	ft_printf("real = %%\n");
	printf("\n");

	//test avec %d && %i
	printf("test avec d && i\n");
	printf("real = %i\n", -15);
	ft_printf("mine = %i\n", -15);
	printf("real = %i\n", -2147483648);
	ft_printf("mine = %i\n", -2147483648);
	printf("real = %i\n", 2147483647);
	ft_printf("mine = %i\n", 2147483647);
	printf("real = %d avec une tres longe ligne derriere\n", 123456);
	ft_printf("mine = %d avec une tres longe ligne derriere\n", 123456);
	printf("\n");

	//test avec %x
	printf("test avec x\n");
	printf("real = %x\n", -15);
	ft_printf("mine = %x\n", -15);
	printf("real = %x\n", -2147483648);
	ft_printf("mine = %x\n", -2147483648);
	printf("real = %x\n", 2147483647);
	ft_printf("mine = %x\n", 2147483647);
	printf("real = %x avec une tres longe ligne derriere\n", 123456);
	ft_printf("mine = %x avec une tres longe ligne derriere\n", 123456);
	printf("\n");

		
	//test avec %X
	printf("test avec X\n");
	printf("real = %X\n", -15);
	ft_printf("mine = %X\n", -15);
	printf("real = %X\n", -2147483648);
	ft_printf("mine = %X\n", -2147483648);
	printf("real = %X\n", 2147483647);
	ft_printf("mine = %X\n", 2147483647);
	printf("real = %X avec une tres longe ligne derriere\n", 123456);
	ft_printf("mine = %X avec une tres longe ligne derriere\n", 123456);
	printf("\n");
	
	//test avec %u
	printf("test avec u\n");
	printf("real = %u\n", -15);
	ft_printf("mine = %u\n", -15);
	printf("real = %u\n", -2147483648);
	ft_printf("mine = %u\n", -2147483648);
	printf("real = %u\n", 2147483647);
	ft_printf("mine = %u\n", 2147483647);
	printf("real = %u avec une tres longe ligne derriere\n", 123456);
	ft_printf("mine = %u avec une tres longe ligne derriere\n", 123456);
	printf("\n");

	//test avec %c
	printf("tests avec c\n");
	printf("real = %c\n", 'z');
	ft_printf("mine = %c\n", 'z');
	printf("real = %c123445\n", 'z');
	ft_printf("mine = %c123445\n", 'z');
	printf("real = %c\n", 132);
	ft_printf("mine = %c\n", 132);
	printf("\n");

	//tests avec plusieurs flags
	printf("real = %d\t%c\tbonjour les gens\n", 21234, 'z');
	ft_printf("mine = %d\t%c\tbonjour les gens\n", 21234, 'z');
	printf("real = \t\tc[i] = ptr(\"%%d\\t%%%%%ds\\t\\t\\t: |%%%ds|\\n\", i, \"Hello World!\"); i++;\n", -16, -16);
	ft_printf("mine = \t\tc[i] = ptr(\"%%d\\t%%%%%ds\\t\\t\\t: |%%%ds|\\n\", i, \"Hello World!\"); i++;\n", -16, -16);
	printf("\n");

	char *adress_test = NULL;

	//test avec p
	printf("tests avec p\n");
	printf("real = %p\n", adress_test);
	ft_printf("mine = %p\n", adress_test);
	printf("\n");

	//tests avec -
	printf("tests avec '-'\n");
	printf("real = %-20c ceci est un test\n", 42);
	ft_printf("mine = %-20c ceci est un test\n", 42);
	printf("\n");

	//test avec 0
	printf("real = %045d", 42);
}

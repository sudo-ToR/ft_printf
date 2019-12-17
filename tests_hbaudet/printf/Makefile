# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/16 12:12:45 by lnoirot           #+#    #+#              #
#    Updated: 2019/12/09 14:37:01 by lnoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= basic_functions.c ft_printf.c basics_functions_1.c ft_count.c converter_functions.c converter_utils.c  

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -Ift_printf.h

NAME	= libftprintf.a

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

all :		$(NAME)

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re : fclean all	

o : re
	${MAKE} clean

.PHONY:		all clean fclean re

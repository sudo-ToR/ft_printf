# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/16 12:12:45 by lnoirot           #+#    #+#              #
#    Updated: 2019/11/16 16:58:01 by lnoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= basic_functions.c ft_printf.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -Iincludes

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

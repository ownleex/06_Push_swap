# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 18:12:20 by ayarmaya          #+#    #+#              #
#    Updated: 2024/03/04 01:53:34 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
PATH_SRC	=	src/
SRC			=	ft_fonction.c \
				ft_main.c
SRCS		=	$(addprefix $(PATH_SRC), $(SRC))
OBJS		=	$(SRCS:.c=.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
HEADERS		=	-I./include
LIBFT		=	libft/libft.a
RM			= 	rm -f

all:		$(NAME)

$(NAME): 	$(OBJS)
			make -C libft
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(HEADERS)
			make clean

%.o: 		%.c
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
			$(RM) $(OBJS)
			make -C libft clean

fclean:		clean
			$(RM) $(NAME)
			make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re

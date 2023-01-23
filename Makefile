# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 16:59:04 by kgezgin           #+#    #+#              #
#    Updated: 2023/01/17 10:46:26 by kgezgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= ./srcs
SRCS		=	map.c \
				get_next_line.c \
				init_window.c \
				so_long.c \
				pathfinding.c \
				moves.c \
				so_long_utils.c
			
OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))
NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3
RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	cd mlx_linux && make && cd ../libft && make && cd ../ft_printf && make 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a mlx_linux/libmlx_Linux.a ft_printf/libftprintf.a -lXext -lX11 -I ./minilibx_linux/

all:		${NAME}
				rm -f

clean:	
	cd mlx_linux && make clean && cd ../libft && make fclean && cd ../ft_printf && make fclean
	${RM} ${OBJS}

fclean:		clean			
		${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 16:59:04 by kgezgin           #+#    #+#              #
#    Updated: 2023/01/02 18:02:48 by kgezgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= ./srcs
BONUS_DIR	= ./bonus
BONUS_SRCS	=
SRCS		=	map.c \
				get_next_line.c \
				init_window.c \
				main.c \
				pathfinding.c
			
OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))
OBJSBONUS		= 	$(addprefix $(BONUS_DIR)/, ${BONUS_SRCS:%.c=%.o})
NAME			=	so_long
BONUS 			=	so_long_bonus
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3
RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	cd mlx_linux && make && cd ../libft && make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a mlx_linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/

$(BONUS): $(OBJSBONUS)
	cd mlx_linux && make
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJSBONUS) mlx_linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/

all:		${NAME}
				rm -f $(BONUS)

bonus :		$(BONUS)	
				rm -f $(NAME)

clean:	
	cd mlx_linux && make clean && cd ../libft && make clean
	${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean			
		${RM} ${NAME} $(BONUS)

re:			fclean all

.PHONY: 	all clean fclean re
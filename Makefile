# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valarcon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 12:52:43 by valarcon          #+#    #+#              #
#    Updated: 2023/04/11 11:30:44 by valarcon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.c src/process/ft_data.c src/get_next_line/get_next_line.c src/process/ft_process_range.c src/process/ft_process_range2.c src/process/ft_process_utils.c	src/process/ft_process.c src/process/ft_process_objet.c src/process/ft_process_camera.c src/utils.c src/process/ft_process4.c \
		src/point/ft_point.c src/impact/ft_impact.c src/vectors/ft_vector_figures.c src/img/ft_make_img.c src/img/ft_make_img2.c src/process/ft_process_objet2.c src/parser/ft_parser.c src/parser/ft_parser2.c src/process/ft_process2.c src/process/ft_process3.c src/process/ft_process_utils2.c \
		src/closet/ft_closet.c src/figures/ft_cylinder.c src/figures/ft_sphere.c src/figures/ft_plane.c src/figures/ft_cylinder2.c src/figures/ft_cylinder3.c src/figures/ft_cylinder4.c src/light/ft_light.c src/point/cylinder/ft_p_cylinder.c src/point/plane/ft_p_plane.c src/point/sphere/ft_p_sphere.c \
		src/point/cylinder/ft_p_cylinder2.c src/point/cylinder/ft_p_cylinder3.c src/point/plane/ft_p_plane2.c src/point/sphere/ft_p_sphere2.c src/light/cylinder/ft_l_cylinder.c src/light/sphere/ft_l_sphere.c src/light/plane/ft_l_plane.c \
		src/all_black.c src/parser/ft_parser3.c

OBJS = ${SRCS:.c=.o}

NAME = miniRT

CC = gcc 

FLAGS = -Wall -Wextra -Werror

SL = -framework OpenGL -framework AppKit

CI = -I sl_inc/

RM = rm -f

LIBMLX = lib/mlx/libmlx.a

LIBFT = lib/libft/libft.a

${NAME}: ${SRCS} ${LIBMLX} ${LIBFT}
	${CC} ${FLAGS} ${CF} ${CI} ${SL} ${SRCS} ${LIBMLX}  ${LIBFT} -o ${NAME}

${LIBMLX}:
	make -C lib/mlx/

${LIBFT}:
	make bonus -C lib/libft/

all: ${NAME}

clean: 
		${RM} ${OBJS}

fclean: clean 
		${RM} ${NAME}
		make clean -C lib/mlx/
		make fclean -C lib/libft/

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 16:51:08 by mapfenni          #+#    #+#              #
#    Updated: 2024/03/21 17:17:01 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES=srcs/main.c \
		srcs/gnl/get_next_line.c \
		srcs/gnl/get_next_line_utils.c \
		srcs/engine/setup_mlx.c \
		srcs/engine/mlx_functions.c \
		srcs/engine/mlx_key.c \
		srcs/engine/player_movement.c \
		srcs/engine/init_ceiling_floor_texture.c \
		srcs/engine/new_frame.c \
		srcs/engine/raycasting.c \
		srcs/engine/raycasting2.c \
		srcs/engine/set_textures.c \
		srcs/engine/sprite_to_win.c \
		srcs/engine/display_texture.c \
		srcs/parsing/get_data.c \
		srcs/parsing/get_map.c \
		srcs/parsing/get_tex_utile.c \
		srcs/parsing/get_tex.c  \
		srcs/parsing/pars_map_utile1.c \
		srcs/parsing/pars_map_utile2.c \
		srcs/parsing/pars_map.c \
		srcs/parsing/utile1.c \
		srcs/parsing/utile2.c \
		srcs/utils/utils.c \
		srcs/utils/init_struct.c \
		srcs/utils/init_struct2.c \
		srcs/utils/clean_exit.c
		
OBJECTS  = ${SOURCES:.c=.o}
NAME = cub3d

MLX_PATH = mlx/mlx_linux
LIB_PATH = libft
MLX      = $(MLX_PATH)/libmlx.a
CFLAGS     = -Wall -Wextra -Werror -gdwarf-4
LDFLAGS    = -L ${MLX_PATH} -lm -lbsd -lX11 -lXext -lmlx

.c.o:
	clang $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): ${MLX} ${OBJECTS}
	clang $(CFLAGS) ${OBJECTS} $(LDFLAGS) libft/libft.a -o $(NAME) mlx/mlx_linux/libmlx.a

all: $(NAME)

$(MLX):
	make -C $(LIB_PATH) all
	make -C $(MLX_PATH) all

bonus:
	cd bonus1 ; make

clean:
	make -C $(LIB_PATH) clean
	make -C ./bonus1 clean
	make -C $(MLX_PATH) clean
	rm -f ${OBJECTS}

fclean: clean
	make -C $(LIB_PATH) fclean
	make -C ./bonus1 fclean
	rm -f $(NAME)

re: fclean all
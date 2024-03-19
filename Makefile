# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 16:51:08 by mapfenni          #+#    #+#              #
#    Updated: 2024/03/19 11:24:07 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	cub3d
SOURCES=srcs/main.c \
		srcs/gnl/get_next_line.c \
		srcs/gnl/get_next_line_utils.c \
		srcs/engine/setup_mlx.c \
		srcs/engine/mlx_functions.c \
		srcs/engine/minimap.c \
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

NAME     = cub3d
OBJECTS  = ${SOURCES:.c=.o}
MLX_PATH = mlx/mlx_linux
LIB_PATH = libft
MLX      = $(MLX_PATH)/libmlx.a
CFLAGS     = -Wall -Wextra -Werror -g
LDFLAGS    = -L ${MLX_PATH} -lm -lbsd -lX11 -lXext -lmlx

.c.o:
	clang $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): ${MLX} ${OBJECTS}
	clang $(CFLAGS) ${OBJECTS} $(LDFLAGS) libft/libft.a -o $(NAME) mlx/mlx_linux/libmlx.a

all: $(NAME)

$(MLX):
	make -C $(MLX_PATH) all

clean:
	make -C $(LIB_PATH) clean
	make -C $(MLX_PATH) clean
	rm -f ${OBJECTS}

fclean: clean
	rm -f $(NAME)

re: fclean all
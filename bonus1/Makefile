# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 16:51:08 by mapfenni          #+#    #+#              #
#    Updated: 2024/03/19 12:13:20 by edfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	$(addprefix ../, cub3d_bonus)
SOURCES=srcs_bonus/main_bonus.c \
		srcs_bonus/gnl/get_next_line_bonus.c \
		srcs_bonus/gnl/get_next_line_utils_bonus.c \
		srcs_bonus/engine/setup_mlx_bonus.c \
		srcs_bonus/engine/mlx_functions_bonus.c \
		srcs_bonus/engine/minimap_bonus.c \
		srcs_bonus/engine/mlx_key_bonus.c \
		srcs_bonus/engine/player_movement_bonus.c \
		srcs_bonus/engine/init_ceiling_floor_texture_bonus.c \
		srcs_bonus/engine/new_frame_bonus.c \
		srcs_bonus/engine/raycasting_bonus.c \
		srcs_bonus/engine/raycasting2_bonus.c \
		srcs_bonus/engine/set_textures_bonus.c \
		srcs_bonus/engine/sprite_to_win_bonus.c \
		srcs_bonus/engine/display_texture_bonus.c \
		srcs_bonus/parsing/get_data_bonus.c \
		srcs_bonus/parsing/get_map_bonus.c \
		srcs_bonus/parsing/get_tex_utile_bonus.c \
		srcs_bonus/parsing/get_tex_bonus.c  \
		srcs_bonus/parsing/pars_map_utile1_bonus.c \
		srcs_bonus/parsing/pars_map_utile2_bonus.c \
		srcs_bonus/parsing/pars_map_bonus.c \
		srcs_bonus/parsing/utile1_bonus.c \
		srcs_bonus/parsing/utile2_bonus.c \
		srcs_bonus/utils/utils_bonus.c \
		srcs_bonus/utils/init_struct_bonus.c \
		srcs_bonus/utils/init_struct2_bonus.c \
		srcs_bonus/utils/clean_exit_bonus.c

OBJECTS  = ${SOURCES:.c=.o}
MLX_PATH = mlx_bonus/mlx_linux
LIB_PATH = libft_bonus
MLX      = $(MLX_PATH)/libmlx.a
CFLAGS     = -Wall -Wextra -Werror -g
LDFLAGS    = -L ${MLX_PATH} -lm -lbsd -lX11 -lXext -lmlx

.c.o:
	clang $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): ${MLX} ${OBJECTS}
	clang $(CFLAGS) ${OBJECTS} $(LDFLAGS) libft_bonus/libft.a -o $(NAME) mlx_bonus/mlx_linux/libmlx.a

all: $(NAME)

$(MLX):
	make -C $(LIB_PATH) all
	make -C $(MLX_PATH) all

clean:
	make -C $(LIB_PATH) clean
	make -C $(MLX_PATH) clean
	rm -f ${OBJECTS}

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(addprefix ../, cub3d_bonus)

re: fclean all
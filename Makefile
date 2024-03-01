# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 16:51:08 by mapfenni          #+#    #+#              #
#    Updated: 2024/03/01 17:42:47 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= cub3d

SRCS=	main.c \
		engine/setup_mlx.c \
		engine/mlx_functions.c \
		engine/minimap.c \
		engine/mlx_key.c \
		engine/player_movement.c \
		engine/init_ceiling_floor_texture.c \
		engine/new_frame.c \
		parsing/parsing.c \
		parsing/errors.c \
		utils/utils.c \
		utils/init_struct.c \
		utils/clean_exit.c

SRCS_DIR=$(addprefix ./srcs/, ${SRCS})
DEST=${SRCS_DIR:.c=.o}
NO_OF_FILES:=$(words $(SRCS))

START=0
LAST_PERCENT=0

RED=$(shell tput setaf 1)
GREEN=$(shell tput setaf 2)
YELLOW=$(shell tput setaf 3)
BLUE=$(shell tput setaf 4)
MAGENTA=$(shell tput setaf 5)
CYAN=$(shell tput setaf 6)
WHITE=$(shell tput setaf 7)
RESET=$(shell tput sgr0)

HIDE_CURSOR=$(shell tput civis)
SHOW_CURSOR=$(shell tput cnorm)
CURSOR_UP=$(shell tput cuu1)
CURSOR_DOWN=$(shell tput cud1)
BEG_LINE=$(shell tput hpa 0)
BOLD=$(shell tput bold)

define change_bar_color
	if [ $1 -lt 12 ]; then \
		printf "${RED}"; \
	elif [ $1 -lt 24 ]; then \
		printf "${YELLOW}"; \
	elif [ $1 -lt 36 ]; then \
		printf "${GREEN}"; \
	else \
		printf "${CYAN}"; \
	fi
endef

define move_progress_bar
	@if [ ${START} -eq 0 ]; then \
		printf "${MAGENTA}"; \
		echo "COMPILING CUB3D"; \
		printf "${RESET}"; \
		tput cud1; \
		$(eval START = 1) \
	fi
	@tput civis; tput cuu1; tput hpa 0
	@$(eval COUNT := $(shell bash -c 'echo $$(($(COUNT) + 1))'))
	@$(eval PERCENT := $(shell bash -c 'echo $$(($(COUNT) * 100 / $(NO_OF_FILES)))'))
	@$(eval current := 1)
	@$(eval MAX := $(shell bash -c 'echo $$(($(PERCENT) / 2))'))
	@printf "["
	@tput hpa 0
	@tput cuf ${LAST_PERCENT}
	@for i in $$(seq ${LAST_PERCENT} ${MAX}); do\
		$(call change_bar_color, $$i); \
		printf "#"; \
	done
	@tput hpa 0; tput cuf 51
	@printf "${RESET}"
	@printf "] "
	@if [ "${PERCENT}" -lt 100 ]; then \
		printf "${WHITE}"; \
	else \
		printf "${CYAN}${BOLD}"; \
	fi
	@echo "${PERCENT}% | ${COUNT} / ${NO_OF_FILES}"
	@$(eval LAST_PERCENT = ${MAX})
endef

define max_count
	@$(eval COUNT := $(shell bash -c 'echo $$(($(NO_OF_FILES) - 1))'))
endef

MLX_PATH=./mlx/
MLX_MAKEFILE=${MLX_PATH}
MLX=$(addsuffix libmlx.a, ${MLX_PATH})

LIBFT_PATH=./libft/
LIBFT=$(addsuffix libft.a, ${LIBFT_PATH})

GNL_PATH=./gnl/
GNL=$(addsuffix gnl.a, ${GNL_PATH})

RM=rm -f

GCC=gcc
CFLAGS=-Wall -Wextra -Werror

ADDITIONAL_DEFINES='-D OS=unknown'

# UNAME_S = Darwin for Mac
UNAME_S:=$(shell uname -s)
ifeq (${UNAME_S},Darwin)
	MLX_MAKEFILE="${MLX_PATH}/mlx_macos/"
	ADDITIONAL_FRAMEWORKS=-framework OpenGL -framework Appkit
	ADDITIONAL_DEFINES='-D OS="Darwin"'
	LINKERS=-L ${MLX_PATH} -lmlx -lm
else
	MLX_MAKEFILE="${MLX_PATH}/mlx_linux/"
	ADDITIONAL_DEFINES='-D OS="Linux"'
	LINKERS=-L ${MLX_PATH} -lmlx -lX11 -lXext -lm
endif

INCLUDES=-I ./includes/ -I ${MLX_MAKEFILE} -I ${LIBFT_PATH} -I ${GNL_PATH}

COUNT=0

all: ${NAME}

bonus: ${NAME}

.c.o:
	@${GCC} ${CFLAGS} ${INCLUDES} ${ADDITIONAL_DEFINES} -c $< -o ${<:.c=.o}
	$(call move_progress_bar, COUNT)

${LIBFT}:
	@echo "${RED}Compiling LIBFT..."
	@make -s -C ${LIBFT_PATH}
	@printf "${RESET}"

${GNL}:
	@echo "${RED}Compiling GNL..."
	@make -s -C ${GNL_PATH}
	@printf "${RESET}"

${MLX}:
	@echo "${CYAN}Compiling MLX..."
	@make -s -C ${MLX_MAKEFILE}
	@mv ${MLX_MAKEFILE}/libmlx.a ${MLX}
	@printf "${RESET}"

${NAME}: ${LIBFT} ${GNL} ${MLX} ${DEST}
	@$(call max_count)
	@$(call move_progress_bar, COUNT)
	@${GCC} ${CFLAGS} ${DEST} -o ${NAME} ${ADDITIONAL_DEFINES} ${ADDITIONAL_FRAMEWORKS} ${INCLUDES} -L${LIBFT_PATH} -lft ${LINKERS} ${LIBFT}
	@printf "${GREEN}${BOLD}"
	@echo "CUB3D COMPILED"
	@printf "${RESET}"
	@printf ${SHOW_CURSOR}

clean_libft:
	@make -s clean -C ${LIBFT_PATH}

clean_gnl:
	@make -s clean -C ${GNL_PATH}

clean_mlx:
	@make -s clean -C ${MLX_MAKEFILE}
	@rm ${MLX}

clean: clean_libft clean_mlx clean_gnl
	@echo "${GREEN}Cleaning CUB3D..."
	@${RM} ${DEST}
	@printf "${RESET}"
	@echo "~~~~"

fclean: clean
	@${RM} ${LIBFT}
	@${RM} ${GNL}
	@${RM} ${NAME}

re: fclean all

.PHONY:all .c.o clean fclean clean_libft

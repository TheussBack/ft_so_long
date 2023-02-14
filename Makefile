# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 15:36:51 by hrobin            #+#    #+#              #
#    Updated: 2023/02/14 13:14:39 by hrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := so_long
SRC_DIR        := src
BUILD_DIR:= .build
SRCS        :=     \
			display/generate_map.c \
		   display/main_map.c \
		   manage_map/check_map.c \
		   manage_map/get_map.c \
		   manage_map/flood_fill.c \
		   manage_map/manage_err.c \
		   display/init.c \
		   display/exit.c \
		   display/mouv.c



PATH_MLX = minilibx-linux

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)

CC            := gcc -g3
CFLAGS        := -Wall -Wextra -Werror
CPPFLAGS    := -MMD -MP -I include
RM            := rm -f
MAKEFLAGS    += --no-print-directory
DIR_DUP        = mkdir -p $(@D)
LIBRARIES    := -LLibft -lft
INCLUDES    := -ILibft/include
MLX_LIBS    := -L$(PATH_MLX) -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	make -C minilibx-linux
	make -C Libft
	$(CC) $(OBJS) $(LIBRARIES) $(MLX_LIBS) -o $(NAME)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)
	make -C Libft clean

fclean: clean
	$(RM) $(NAME)
	make -C Libft fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
.SILENT:

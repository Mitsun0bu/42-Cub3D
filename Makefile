# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 17:19:42 by llethuil          #+#    #+#              #
#    Updated: 2022/06/22 10:41:23 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                              ~~~ COLOR CODES ~~~                             #
#                                                                              #
# **************************************************************************** #

GREEN	:=	\033[32m
BLUE	:=	\033[34m
PINK	:=	\033[35m
END		:=	\033[0m

# **************************************************************************** #
#                                                                              #
#                              ~~~ VARIABLES ~~~                               #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror -I mlx -O3

RM			:=	rm -f

LIBFT_DIR	:=	libft

MLX_DIR		:=	mlx

INCS_DIR	:=	incs

SRCS_DIR	:=	srcs

OBJS_DIR	:=	.objs

INCS_LST	:=	config_parser.h								\
				header.h									\
				init_img.h									\
				init_player.h								\
				init_ray.h									\
				key_press.h									\
				main.h										\
				render_manager.h							\
				utils.h										\
				window_manager.h							\

SRCS_LST	:=	config_parser/check_map.c					\
				config_parser/check_texture_paths.c			\
				config_parser/close_file.c					\
				config_parser/convert_rgb_codes_to_hex.c	\
				config_parser/exit_with_error_message.c		\
				config_parser/get_map.c						\
				config_parser/get_rgb_code_int_tabs.c		\
				config_parser/get_config_lines.c			\
				config_parser/open_file.c					\
				config_parser/parse_config_lines.c			\
				config_parser/config_parser.c				\
				config_parser/replace_spaces_in_map.c		\
				config_parser/replace_spaces_in_str.c		\
				init_img/init_img.c							\
				init_player/init_player.c					\
				init_ray/init_ray.c							\
				key_press/key_press.c						\
				key_press/movement.c						\
				key_press/rotation.c						\
				main/main.c									\
				render_manager/dda_algorithm_utils.c		\
				render_manager/dda_algorithm.c				\
				render_manager/h_probe_manager.c			\
				render_manager/ray_casting.c				\
				render_manager/render_game.c				\
				render_manager/render_manager.c				\
				render_manager/render_mini_map.c			\
				render_manager/render_utils.c				\
				render_manager/texture_utils.c				\
				render_manager/v_probe_manager.c			\
				utils/calculate_distance.c					\
				utils/check_collision.c						\
				utils/normalize_angle.c						\
				utils/pixel_put.c							\
				window_manager/window_manager.c				\

SUBDIRS_LST	:=	config_parser								\
				init_img									\
				init_player									\
				init_ray									\
				key_press									\
				main										\
				render_manager								\
				utils										\
				window_manager								\

OBJS_LST	:=	$(SRCS_LST:.c=.o)

LIBFT_AR	:=	$(LIBFT_DIR)/libft.a

MLX_AR		:=	$(MLX_DIR)/mlx.a

LIBFT_AR	:=	./libft/libft.a

MLX_AR		:=	./mlx/libmlx.a

INCS		:=	$(addprefix $(INCS_DIR)/, $(INCS_LST))

SRCS		:=	$(addprefix $(SRCS_DIR)/, $(SRCS_LST))

OBJS		:=	$(addprefix $(OBJS_DIR)/, $(OBJS_LST))

# ************************************************************************** #
#                                                                            #
#                              ~~~ RULES & COMMANDS ~~~                      #
#                                                                            #
# ************************************************************************** #

.SILENT:

all: libft mlx $(NAME)

libft:
	make -C $(LIBFT_DIR)

mlx:
	make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT_AR) ${MLX_AR}
	test -z '$(filter %.o,$?)' || printf "$(GREEN)> All the .c files from $(NAME) have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	$(CC) $(OBJS) $(LIBFT_AR) $(MLX_AR) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"

$(OBJS_DIR):
	mkdir -p $(addprefix $(OBJS_DIR)/, $(SUBDIRS_LST))

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS) Makefile | $(OBJS_DIR)
	printf "$(BLUE)> Compiling :$(END) $<\n"
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	printf "$(PINK)> Removing $(NAME) .o files ...$(END)\n"
	$(RM) $(OBJS)
	printf "$(PINK)> Removing .objs directory ...$(END)\n"
	rm -rf $(OBJS_DIR)
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	printf "$(PINK)> Removing libft archive file ...$(END)\n"
	$(RM) $(LIBFT_AR)
	printf "$(PINK)> Removing mlx archive file ...$(END)\n"
	$(RM) $(MLX_AR)
	printf "$(PINK)> Removing $(NAME) executable file ...$(END)\n"
	$(RM) $(NAME)
	printf "$(GREEN)> Libft archive and $(NAME) executable files have been removed successfully !$(END)\n"

re: fclean all

.PHONY: all libft mlx clean fclean re

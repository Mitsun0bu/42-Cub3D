# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 17:31:49 by llethuil          #+#    #+#              #
#    Updated: 2022/05/30 17:32:21 by llethuil         ###   ########lyon.fr    #
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

NAME	:= libft.a

CC		:= gcc

CFLAGS	:= -Wall -Wextra -Werror

RM = rm -f

INCS = libft.h

SRCS = ft_atoi.c			\
	   ft_bzero.c			\
	   ft_calloc.c			\
	   ft_free_char_tab.c	\
	   ft_get_next_line.c	\
	   ft_isalnum.c			\
	   ft_isalpha.c			\
	   ft_isascii.c			\
	   ft_isdigit.c			\
	   ft_isprint.c			\
	   ft_itoa.c			\
	   ft_lstadd_back.c		\
	   ft_lstadd_front.c	\
	   ft_lstclear.c		\
	   ft_lstdelone.c		\
	   ft_lstiter.c			\
	   ft_lstlast.c			\
	   ft_lstmap.c			\
	   ft_lstnew.c			\
	   ft_lstsize.c			\
	   ft_memchr.c			\
	   ft_memcmp.c			\
	   ft_memcpy.c			\
	   ft_memmove.c			\
	   ft_memset.c			\
	   ft_putchar_fd.c		\
	   ft_putendl_fd.c		\
	   ft_putnbr_fd.c		\
	   ft_putstr_fd.c		\
	   ft_split.c			\
	   ft_strchr.c			\
	   ft_strcmp.c			\
	   ft_strdup.c			\
	   ft_striteri.c		\
	   ft_strjoin.c			\
	   ft_strlcat.c			\
	   ft_strlcpy.c			\
	   ft_strlen.c			\
	   ft_strmapi.c			\
	   ft_strncmp.c			\
	   ft_strnstr.c			\
	   ft_strrchr.c			\
	   ft_strtrim.c			\
	   ft_substr.c			\
	   ft_tolower.c			\
	   ft_toupper.c			\

OBJS = ${SRCS:.c=.o}

# ************************************************************************** #
#                                                                            #
#                              ~~~ RULES & COMMANDS ~~~                      #
#                                                                            #
# ************************************************************************** #

.SILENT:

all: ${NAME}

%.o: %.c libft.h Makefile
	${CC} ${CFLAGS} -I $(INCS) -c $< -o $@
	printf "$(BLUE)> Compiling :$(END) libft/$<\n"

${NAME}: ${OBJS}
	printf "$(GREEN)> All the libft .c files have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the libft archive file :$(END) $@\n"
	ar rcs $@ ${OBJS}
	printf "$(GREEN)> libft archive has been compiled successfully !$(END)\n"

bonus: all

clean:
	${RM} ${OBJS}
	printf "$(PINK)> Removing libft .o files ...$(END)\n"

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re

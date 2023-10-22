# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 15:17:00 by skorte            #+#    #+#              #
#    Updated: 2021/08/21 16:04:36 by skorte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FTS	=	ft_memset		\
		ft_bzero		\
		ft_memcpy		\
		ft_memmove		\
		ft_memchr		\
		ft_memcmp		\
		ft_memcpy		\
		ft_strchr		\
		ft_strdup		\
		ft_strlcat		\
		ft_strlcpy		\
		ft_strlen		\
		ft_strmapi		\
		ft_strncmp		\
		ft_strrchr		\
		ft_isalpha 		\
		ft_isalnum		\
		ft_isascii		\
		ft_isdigit		\
		ft_isprint		\
		ft_toupper		\
		ft_tolower		\
		ft_atoi			\
		ft_itoa			\
		ft_calloc		\
		ft_putchar_fd	\
		ft_putendl_fd	\
		ft_putnbr_fd	\
		ft_putstr_fd	\
		ft_striteri		\
		ft_strnstr		\
		ft_substr		\
		ft_strjoin 		\
		ft_strtrim		\
		ft_split		\
		ft_strmapi		\

NAME = libft.a

SRCS = $(addsuffix .c, $(FTS))
OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs/
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "Libft Done !"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

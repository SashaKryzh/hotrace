# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlytvyne <vlytvyne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 16:06:58 by okryzhan          #+#    #+#              #
#    Updated: 2019/01/21 20:31:14 by vlytvyne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

FLAGS = -Wall -Wextra -Werror
CC = gcc $(FLAGS)

SRCS =	main.c \
		hash.c \
		utils.c \
		parser.c \
		put_funcs.c \
		ft_strdup.c \
		ft_strcmp.c \

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) -O3 -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c *.h
	$(CC) -O3 -o $@ -c $<

$(OBJS_DIR):
	@mkdir objs

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

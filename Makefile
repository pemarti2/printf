# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pemarti2 <pemarti2student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 12:50:40 by pemarti2          #+#    #+#              #
#    Updated: 2024/01/29 10:38:42 by pemarti2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
CFLAGS := -Wall -Werror -Wextra
CC := gcc
LIBFT_DIR := ./Libft
LIBFT_NAME := libft.a
LIBFT := $(LIBFT_DIR)/$(LIBFT_NAME)

SRCS := \
	ft_extra1.c ft_extra2.c ft_printf.c

OBJECTS := $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	make -C $(LIBFT_DIR)
	cp $(LIBFT) .
	mv $(LIBFT_NAME) $(NAME)

$(NAME): makelibft $(OBJECTS)
	ar -r $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	cd $(LIBFT_DIR) && make clean
	
fclean: clean
	rm -f $(NAME)
	cd $(LIBFT_DIR) && make fclean
	
re: fclean all
.PHONY: all clean re

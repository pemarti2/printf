# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 12:50:40 by pemarti2          #+#    #+#              #
#    Updated: 2024/01/29 10:38:42 by pemarti2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
CFLAGS := -Wall -Werror -Wextra
CC := gcc

# Agregar archivos de libft
LIBFT_DIR := ./Libft
LIBFT := $(LIBFT_DIR)/libft.a

SRCS := \
	ft_extra1.c ft_extra2.c ft_printf.c

OBJECTS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o : %.c Makefile ft_printf.h
	$(CC) -c $(CFLAGS) -I$(LIBFT_DIR) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

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
SRCS := \
	ft_printf.c ft_extra1.c ft_extra2.c ft_extra3.c

OBJECTS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o : %.c Makefile ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY:
	all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 20:30:01 by qjosmyn           #+#    #+#              #
#    Updated: 2019/11/10 20:31:17 by qjosmyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SECONDARY: $(OBJ)

.PHONY: all clean fclean re

override CC = gcc

override CFLAGS = -Wall -Wextra -Werror -I filit.h

override ARFLAGS = rc

NAME = filit.a

all: $(NAME)

SRC = 

OBJ = $(SRC:.c=.o)

$(NAME): $(NAME)($(OBJ))

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
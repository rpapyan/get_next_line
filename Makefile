# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapyan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 16:33:30 by rpapyan           #+#    #+#              #
#    Updated: 2022/07/31 17:08:29 by rpapyan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
 
CFLAGS = -Wall -Wextra -Werror

CC = cc

test:
	$(CC) $(CFLAGS) *.c
	./a.out
	rm -rf a.out

all: $(NAME)

$(NAME):

clean:

fclean:

re:

.SILENT:

.PHONY: all clean fclean re

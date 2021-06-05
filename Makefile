# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paim <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/04 14:12:25 by paim              #+#    #+#              #
#    Updated: 2016/11/01 16:32:38 by paim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3D

SRC = main.c\
	  error.c\
	  raycasting.c\
	  init_wolf.c\
	  map.c\
	  moove.c\
	  piximg.c

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re libft minilibx

all: $(NAME)

$(NAME) : libft minilibx
	@gcc $(SRC) -o $(NAME) -L./libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "Easy compil ma poule"

minilibx:
	@make -C minilibx_macos

libft:
	@make -C libft

clean:
	@make -C minilibx_macos/ clean
	@make -C libft/ clean
	@rm -f $(OBJ)
	@echo "T'inquiete pas ca delete juste les .o :)"

fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "La tu peux stresser parcque je delete touuuuuuuuuuuut"

re: fclean all

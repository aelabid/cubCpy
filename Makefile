# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 07:22:21 by aelabid           #+#    #+#              #
#    Updated: 2023/01/13 01:19:12 by aelabid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = execution/check_wall.c execution/color_background.c execution/cub3d.c\
		execution/dda.c execution/get_texture_image.c execution/handle_key.c\
		execution/init_player.c execution/init.c execution/my_mlx_put.c\
		execution/open_windows.c execution/rays.c execution/render_image.c\
		execution/render_recs.c execution/sizes.c\
		pars/main.c pars/get_next_line.c pars/get_next_line_utils.c pars/parsing.c pars/parsing_utils.c \
		pars/check_map.c pars/convert_color.c


OBJ = $(SRC:.c=.o)

NAME = cub3D

# CFLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT = pars/libft/libft.a

all : $(LIBFT) $(NAME)


%.o: %.c pars/cub.h pars/libft/libft.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C pars/libft

clean :
	rm -f $(OBJ) 
	make clean -C pars/libft

fclean : clean
	rm -f $(NAME) 
	make fclean -C pars/libft

re : fclean all 

# OBJ = $(SRC:.c=.o)

# # CC_FLAGS = -Wall -Wextra -Werror
# CC = cc

# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
# MATH_FLAGS = -lm

# NAME = cub3d
# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ) -o $@
	
# %.o: %.c 
# 	$(CC) $(CC_FLAGS) -c $< -o $@

# clean:
# 	rm -rf $(OBJ)
		
# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 07:22:21 by aelabid           #+#    #+#              #
#    Updated: 2023/01/18 18:43:07 by aelabid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = execution/check_wall.c execution/color_background.c execution/cub3d.c\
		execution/dda.c execution/get_texture_image.c execution/handle_key.c\
		execution/init_player.c execution/init.c execution/my_mlx_put.c\
		execution/open_windows.c execution/rays.c execution/render_image.c\
		execution/render_recs.c execution/sizes.c execution/rays_util.c \
		execution/rays_util2.c\
		pars/get_next_line.c pars/get_next_line_utils.c pars/parsing.c pars/parsing_utils.c \
		pars/check_map.c pars/convert_color.c pars/utils_functions.c pars/check_map_utils.c\
		pars/parsing_utls.c pars/parsing_uts.c pars/final_pars.c


OBJ = $(SRC:.c=.o)

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT = pars/libft/libft.a

all : $(LIBFT) $(NAME)


%.o: %.c pars/cub.h pars/libft/libft.h includes/cub3d.h
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 07:22:21 by aelabid           #+#    #+#              #
#    Updated: 2023/01/14 22:30:50 by mabdelba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRC = execution/check_wall.c execution/color_background.c execution/cub3d.c\
# 		execution/dda.c execution/get_texture_image.c execution/handle_key.c\
# 		execution/init_player.c execution/init.c execution/my_mlx_put.c\
# 		execution/open_windows.c execution/rays.c execution/render_image.c\
# 		execution/render_recs.c execution/sizes.c\
# 		pars/get_next_line.c pars/get_next_line_utils.c pars/parsing.c pars/parsing_utils.c \
# 		pars/check_map.c pars/convert_color.c pars/utils_functions.c pars/check_map_utils.c\
# 		pars/parsing_utls.c pars/parsing_uts.c



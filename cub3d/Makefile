# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkham <dkham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 18:57:41 by chanwoki          #+#    #+#              #
#    Updated: 2023/09/11 19:28:57 by dkham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=cub3D

CFLAGS=-Wall -Wextra -Werror

LIBFT=libft
LIBFT_NAME=libft.a

AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES=main.c \
./game/main_loop.c ./game/raycast.c \
./init/init_1.c ./init/init_2.c ./init/set_dir_plane.c ./init/set_info.c \
./parse/parse.c ./parse/check_args.c ./parse/check_colors.c ./parse/check_info.c ./parse/check_maps.c ./parse/check_walls.c ./parse/parse_args.c ./parse/parse_utils.c \
./utils/free.c ./utils/keys.c ./utils/load.c ./utils/utils.c

OBJECTS = $(SRC_FILES:.c=.o)

FT = ft

MLX = mlx

MLXF = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(CFLAGS) -L $(LIBFT) -I . -l $(FT) -L $(MLX) -l $(MLX) $(MLXF) $(SRC_FILES) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean :
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	$(RM) $(OBJECTS) libmlx.dylib

fclean : clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME) $(LIBFT_NAME)

re : fclean all

libft :
	make all -C $(LIBFT)/

.PHONY : all clean fclean re libft

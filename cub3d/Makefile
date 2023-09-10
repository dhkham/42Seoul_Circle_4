# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkham <dkham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 18:57:41 by chanwoki          #+#    #+#              #
#    Updated: 2023/09/10 15:04:19 by dkham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=cub3D

CFLAGS=-Wall -Wextra -Werror

LIBFT=libft
LIBFT_NAME=libft.a

AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES=main.c ./check/check_args.c ./utils/utils.c ./parse/parse.c ./parse/parse_utils.c ./check/check_walls.c ./check/check_info.c \
./parse/parse_args.c ./check/check_colors.c ./check/check_maps.c ./utils/init.c ./utils/keys.c free.c

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

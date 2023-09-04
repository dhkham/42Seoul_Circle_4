/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:52:27 by dkham             #+#    #+#             */
/*   Updated: 2023/09/04 20:10:45 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include <math.h>

#define width 640
#define height 480
#define TEXTURE_WIDTH  64
#define TEXTURE_HEIGHT 64

typedef struct s_config
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3]; // RGB
	int		ceiling_color[3]; // RGB
	char	**map;
	int		map_width;
	int		map_height;
	char	*direction;
}	t_config;

typedef struct	s_img
{
	void	*img;		// 이미지 식별자
	int		*data;		// 픽셀 데이터
	int		size_l; 	// 한 줄의 픽셀 수
	int		bpp;		// 픽셀당 비트 수
	int		endian;		// 엔디안
	int		img_width;	// 이미지 가로 길이
	int		img_height; // 이미지 세로 길이
}	t_img;				// 이미지 정보

typedef struct	s_info
{
	double 		posX;
	double 		posY;
	double 		dirX;
	double 		dirY;
	double 		planeX;
	double 		planeY;
	void		*mlx;
	void		*win;
	t_img		img;
	t_config	config;
	int			buf[height][width];
	int			**texture;
	double		moveSpeed;
	double		rotSpeed;
}	t_info;	// 게임/플레이어 정보


int	check_args(int args, char **argv);
int	ft_strcmp(char *s1, char *s2);
int	ft_isalpha_isdigit(char c);

t_config	*parse_config(const char *filename);
static void	parse_textures(t_config *s_config, char *line);
static void	parse_colors(t_config *s_config, char *line);
static void	parse_map_dimensions(t_config *s_config, char *line);
static void	parse_map_data(t_config *s_config, const char *filename);

static void	handle_error(int fd);
static t_config	*init_config(int fd);
static int	init_map_memory(t_config *s_config);
static void	parse_actual_map_data(t_config *s_config, int fd);





#endif

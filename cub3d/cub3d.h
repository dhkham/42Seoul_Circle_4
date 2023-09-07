/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:33:47 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/07 19:07:12 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIDTH 640 // norm check
# define HEIGHT 480
# define TEXTURE_WIDTH  64
# define TEXTURE_HEIGHT 64

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include <math.h>


typedef struct s_config
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];		// RGB
	int		ceiling_color[3];	// RGB
	char	**map;
	int		map_width;
	int		map_height;
	char	*direction;
	int		error;
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
	int			buf[HEIGHT][WIDTH];
	int			**texture;
	double		moveSpeed;
	double		rotSpeed;
}	t_info;	// 게임/플레이어 정보


int			check_args(int args, char **argv);
int			ft_strcmp(char *s1, char *s2);
int			ft_isalpha_isdigit(char c);
t_config	*parse_config(const char *filename);
void		handle_error(int fd);
t_config	*init_config(int fd);
int			init_map_memory(t_config *config);
void		check_walls(t_config *config);


#endif

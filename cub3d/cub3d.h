/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:33:47 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/09 20:21:33 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 640
# define HEIGHT 480
# define TEXTURE_WIDTH  64
# define TEXTURE_HEIGHT 64
# define X_EVENT_KEY_PRESS 2

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include <unistd.h>		// 불필요한 헤더 있는지 체크
# include <fcntl.h>
# include "mlx/mlx.h"
# include <math.h>

typedef struct s_config
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	char	**map;
	int		map_width;
	int		map_height;
	char	*direction;
	int		error;
}	t_config;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	t_img		img;
	t_config	config;
	int			buf[HEIGHT][WIDTH];
	int			**texture;
	double		move_speed;
	double		rot_speed;
	double		camera_x;
	double 		raydir_x;
	double 		raydir_y;
	double 		sidedist_x;									// 레이가 x, y면에 부딪히기까지의 거리
	double 		sidedist_y;
	int 		map_x;
	int 		map_y;
	double 		deltadist_x;
	double 		deltadist_y;
	double 		perpwalldist;									//플레이어 위치부터 레이가 벽과 충돌한 지점까지의 직교 거리
	int 		step_x;												//x, y 방향으로 얼마나 가야하는지 (만약 info->rayDirX/Y가 음수면 -1, 아니면 1) : info->map_x/Y를 업데이트 위해 사용
	int 		step_y;
	int 		hit;
	int 		side;
}	t_info;

int			check_args(int args, char **argv);
int			ft_strcmp(char *s1, char *s2);
int			ft_isalpha_isdigit(char c);
t_config	*parse_config(const char *filename);
void		handle_error(int fd);
t_config	*init_config(int fd);
int			init_map_memory(t_config *config);
void		check_walls(t_config *config);
void		parse_info(t_config *config, char **content);
void		parse_textures(t_config *config, char **lines);
void		parse_colors(t_config *config, char **lines);
void		check_colors(int *colors, t_config *config, char *color);
int			check_color_info(char **color_info, t_config *config);
int			check_maps(t_config *config, int idx, char **content);
void		duplicate_map(t_config *config, int idx, char **content);

#endif

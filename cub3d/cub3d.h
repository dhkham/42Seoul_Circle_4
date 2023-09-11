/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:25:38 by dkham             #+#    #+#             */
/*   Updated: 2023/09/11 20:49:15 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WID 640
# define HEI 480
# define TEX_WID 64
# define TEX_HEI 64
# define X_EVENT_KEY_PRESS 2
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_ESC 53

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
	int		floor_color[3];
	int		ceil_color[3];
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
	int			buf[HEI][WID];
	int			**texture;
	double		move_speed;
	double		rot_speed;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	int			map_x;
	int			map_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		wall_x;
	int			tex_num;
	int			line_hei;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
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
int			validate_arguments(int argc, char **argv, t_config **s_config);
int			color_error(int flag, int len, char **color_info, t_config *config);
int			check_comma(char *line, char **color_info, t_config *config);
void		initialize_info(t_info *info);
void		initialize_info_img(t_info *info, t_config *config);
void		initialize_buffer(t_info *info);
void		allocate_texture_memory(t_info *info, t_config *config);
void		initialize_texture_values(t_info *info);
void		free_config(t_config *config);
void		free_resources(t_info *info);
void		move_forward(t_info *info);
void		move_backward(t_info *info);
void		rotate_left(t_info *info);
void		rotate_right(t_info *info);
int			handle_keys(int keycode, t_info *info);
void		exit_game(t_info *info);
void		free_resources(t_info *info);
void		free_config(t_config *config);
void		set_start_position_and_direction(t_info *info, t_config *config);
void		find_start_position(t_info *info, t_config *config, int *i, int *j);
void		set_dir_and_plane(t_info *info, t_config *config, int i, int j);
void		set_direction_north(t_info *info, t_config *config, int i, int j);
void		set_direction_south(t_info *info, t_config *config, int i, int j);
void		set_direction_west(t_info *info, t_config *config, int i, int j);
void		set_direction_east(t_info *info, t_config *config, int i, int j);
void		raycasting(t_info *info);
void		drawing(t_info *info);
int			game_loop(t_info *info);
void		setup_hooks_and_loop(t_info *s_info);
void		initialize_s_info(t_info *info, t_config *config);
void		initialize_info(t_info *info);
int			initialize_window(t_info *s_info, t_config *s_config);
void		setup_hooks_and_loop(t_info *s_info);
void		init_ray_map_deltadist(t_info *info, int x);
void		init_step_and_sidedist(t_info *info);
void		perform_DDA(t_info *info);
void		calc_variables_for_drawing(t_info *info);
void		determine_tex_num_and_wall_x(t_info *info);
void		draw_texture_column(t_info *info, int x);
void		paint_floor_and_ceiling(t_info *info);
int			rgb_to_int(int r, int g, int b);
void		initialize_texture(t_info *info, t_config *config);
void		initialize_buffer(t_info *info);
int			load_texture_from_config(t_info *info, t_config *config);
char		**get_info(int fd);
int			check_config(t_config *config);
char		**get_type_and_value(char *line);
void		check_type(t_config *config, char **lines);
int			check_maps(t_config *config, int idx, char **content);
void		parse_map_data(t_config *config, int i, char **content);

#endif

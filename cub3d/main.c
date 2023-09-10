/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:23:55 by dkham             #+#    #+#             */
/*   Updated: 2023/09/10 15:03:07 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 텍스처 바꾸기???

#include "cub3d.h"
#include "key_macos.h"

void	find_start_position(t_info *info, t_config *config, int *i, int *j)
{
	*i = 0;
	while (*i < config->map_height)
	{
		*j = 0;
		while (*j < config->map_width)
		{
			if (config->map[*i][*j] == 'N' || config->map[*i][*j] == 'S' || \
			config->map[*i][*j] == 'W' || config->map[*i][*j] == 'E')
			{
				info->pos_x = *i + 0.5;
				info->pos_y = *j + 0.5;
				return ;
			}
			(*j)++;
		}
		(*i)++;
	}
}

void	set_direction_north(t_info *info, t_config *config, int i, int j)
{
	info->dir_x = -1.0;
	info->dir_y = 0.0;
	info->plane_x = 0.0;
	info->plane_y = 0.66;
	config->map[i][j] = '0';
}

void	set_direction_south(t_info *info, t_config *config, int i, int j)
{
	info->dir_x = 1.0;
	info->dir_y = 0.0;
	info->plane_x = 0.0;
	info->plane_y = -0.66;
	config->map[i][j] = '0';
}

void	set_direction_west(t_info *info, t_config *config, int i, int j)
{
	info->dir_x = 0.0;
	info->dir_y = -1.0;
	info->plane_x = -0.66;
	info->plane_y = 0.0;
	config->map[i][j] = '0';
}

void	set_direction_east(t_info *info, t_config *config, int i, int j)
{
	info->dir_x = 0.0;
	info->dir_y = 1.0;
	info->plane_x = 0.66;
	info->plane_y = 0.0;
	config->map[i][j] = '0';
}

void	set_direction_and_plane(t_info *info, t_config *config, int i, int j)
{
	if (config->map[i][j] == 'N')
		set_direction_north(info, config, i, j);
	else if (config->map[i][j] == 'S')
		set_direction_south(info, config, i, j);
	else if (config->map[i][j] == 'W')
		set_direction_west(info, config, i, j);
	else if (config->map[i][j] == 'E')
		set_direction_east(info, config, i, j);
}

void	set_start_position_and_direction(t_info *info, t_config *config)
{
	int	i;
	int	j;

	find_start_position(info, config, &i, &j);
	set_direction_and_plane(info, config, i, j);
	info->move_speed = 0.1;
	info->rot_speed = 0.1;
}



void	initialize_texture(t_info *info, t_config *config)
{
	allocate_texture_memory(info, config);
	initialize_texture_values(info);
}

void	initialize_s_info(t_info *info, t_config *config)
{
	set_start_position_and_direction(info, config);
	initialize_info(info);
	initialize_info_img(info, config);
	initialize_buffer(info);
	initialize_texture(info, config);
}

int	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, \
	&img->img_height);
	if (!img->img)
	{
		perror("Error loading texture");
		return (0);
	}
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, \
	&img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
	return (1);
}

int	load_texture_from_config(t_info *info, t_config *config)
{
	t_img	img;

	if (!load_image(info, info->texture[0], config->north_texture, &img))
		return (0);
	if (!load_image(info, info->texture[1], config->south_texture, &img))
		return (0);
	if (!load_image(info, info->texture[2], config->west_texture, &img))
		return (0);
	if (!load_image(info, info->texture[3], config->east_texture, &img))
		return (0);
	return (1);
}

int	rgb_to_int(int r, int g, int b)
{
	return (r << 16) | (g << 8) | b;
}

void	paint_floor_and_ceiling(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEI)
	{
		x = 0;
		while (x < WID)
		{
			info->buf[y][x] = rgb_to_int(info->config.floor_color[0], \
			info->config.floor_color[1], info->config.floor_color[2]);
			info->buf[HEI - y - 1][x] = rgb_to_int(info->config.ceil_color[0], \
			info->config.ceil_color[1], info->config.ceil_color[2]);
			x++;
		}
		y++;
	}
}

void	init_step_and_sideDist(t_info *info)
{
	if (info->raydir_x < 0)
	{
		info->step_x = -1;
		info->sidedist_x = (info->pos_x - info->map_x) * info->deltadist_x;
	}
	else
	{
		info->step_x = 1;
		info->sidedist_x = (info->map_x + 1.0 - info->pos_x) * \
		info->deltadist_x;
	}
	if (info->raydir_y < 0)
	{
		info->step_y = -1;
		info->sidedist_y = (info->pos_y - info->map_y) * info->deltadist_y;
	}
	else
	{
		info->step_y = 1;
		info->sidedist_y = (info->map_y + 1.0 - info->pos_y) * \
		info->deltadist_y;
	}
}

void	init_ray_map_deltaDist(t_info *info, int x)
{
	info->camera_x = 2 * x / (double)WID - 1;
	info->raydir_x = info->dir_x + info->plane_x * info->camera_x;
	info->raydir_y = info->dir_y + info->plane_y * info->camera_x;
	info->map_x = (int)info->pos_x;
	info->map_y = (int)info->pos_y;
	info->deltadist_x = fabs(1 / info->raydir_x);
	info->deltadist_y = fabs(1 / info->raydir_y);
}

void	perform_DDA(t_info *info)
{
	info->hit = 0;
	while (info->hit == 0)
	{
		if (info->sidedist_x < info->sidedist_y)
		{
			info->sidedist_x += info->deltadist_x;
			info->map_x += info->step_x;
			info->side = 0;
		}
		else
		{
			info->sidedist_y += info->deltadist_y;
			info->map_y += info->step_y;
			info->side = 1;
		}
		if (info->config.map[info->map_x][info->map_y] != '0')
			info->hit = 1;
	}
}

void	calc_variables_for_drawing(t_info *info)
{
	if (info->side == 0)
		info->perpwalldist = (info->map_x - info->pos_x + \
		(1 - info->step_x) / 2) / info->raydir_x;
	else
		info->perpwalldist = (info->map_y - info->pos_y + \
		(1 - info->step_y) / 2) / info->raydir_y;
	info->line_hei = (int)(HEI / info->perpwalldist);
	info->draw_start = -info->line_hei / 2 + HEI / 2;
	if (info->draw_start < 0)
		info->draw_start = 0;
	info->draw_end = info->line_hei / 2 + HEI / 2;
	if (info->draw_end >= HEI)
		info->draw_end = HEI - 1;
}

void	determine_tex_num_and_wall_x(t_info *info)
{
	if (info->side == 0)
	{
		if (info->raydir_x > 0)
			info->tex_num = 1;
		else
			info->tex_num = 0;
	}
	else
	{
		if (info->raydir_y > 0)
			info->tex_num = 3;
		else
			info->tex_num = 2;
	}
	if (info->side == 0)
		info->wall_x = info->pos_y + info->perpwalldist * info->raydir_y;
	else
		info->wall_x = info->pos_x + info->perpwalldist * info->raydir_x;
		info->wall_x -= floor(info->wall_x);
}

void	draw_texture_column(t_info *info, int x)
{
	int	y;
	int	color;

	info->tex_x = (int)(info->wall_x * (double)TEX_WID);
	if ((info->side == 0 && info->raydir_x > 0) || \
	(info->side == 1 && info->raydir_y < 0))
		info->tex_x = TEX_WID - info->tex_x - 1;
	info->step = 1.0 * TEX_HEI / info->line_hei;
	info->tex_pos = (info->draw_start - HEI / 2 + info->line_hei / 2) \
	* info->step;
	y = info->draw_start;
	while (y < info->draw_end)
	{
		info->tex_y = (int)info->tex_pos & (TEX_HEI - 1);
		info->tex_pos += info->step;
		color = info->texture[info->tex_num][TEX_HEI * info->tex_y + \
		info->tex_x];
		if (info->side == 1)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
		y++;
	}
}

void	raycasting(t_info *info)
{
	int	x;

	paint_floor_and_ceiling(info);
	x = 0;
	while (x < WID)
	{
		init_ray_map_deltaDist(info, x);
		init_step_and_sideDist(info);
		perform_DDA(info);
		calc_variables_for_drawing(info);
		determine_tex_num_and_wall_x(info);
		draw_texture_column(info, x);
		x++;
	}
}

void	drawing(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEI)
	{
		x = 0;
		while (x < WID)
		{
			info->img.data[y * WID + x] = info->buf[y][x];	
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int	game_loop(t_info *info)
{
	raycasting(info);
	drawing(info);
	return (0);
}

void	exit_game(t_info *info)
{
	free_config(&info->config);
	free_resources(info);
	exit(0);
}

int	initialize_window(t_info *s_info, t_config *s_config)
{
	s_info->mlx = mlx_init();
	if (!load_texture_from_config(s_info, s_config))
	{
		perror("Error: Failed to load textures");
		free_resources(s_info);
		free_config(s_config);
		free(s_config);
		return (0);
	}
	s_info->win = mlx_new_window(s_info->mlx, WID, HEI, "cub3D");
	if (!s_info->win)
	{
		perror("Error: Failed to create window");
		free_resources(s_info);
		free_config(s_config);
		free(s_config);
		return (0);
	}
	s_info->img.img = mlx_new_image(s_info->mlx, WID, HEI);
	s_info->img.data = (int *)mlx_get_data_addr(s_info->img.img, \
	&s_info->img.bpp, &s_info->img.size_l, &s_info->img.endian);
	return (1);
}

void	setup_hooks_and_loop(t_info *s_info)
{
	mlx_loop_hook(s_info->mlx, &game_loop, s_info);
	mlx_hook(s_info->win, X_EVENT_KEY_PRESS, 0, &handle_keys, s_info);
	mlx_loop(s_info->mlx);
}

int	main(int argc, char **argv)
{
	t_config	*s_config;
	t_info		s_info;

	if (!validate_arguments(argc, argv, &s_config))
		return (0);
	initialize_s_info(&s_info, s_config);
	if (!initialize_window(&s_info, s_config))
		return (0);
	setup_hooks_and_loop(&s_info);
	free_config(s_config);
	free_resources(&s_info);
	free(s_config);
	return (0);
}

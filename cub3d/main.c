/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:23:55 by dkham             #+#    #+#             */
/*   Updated: 2023/09/10 13:40:43 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_macos.h"

void	check_leaks(void)
{
	system("leaks cub3D");
}

void	free_config(t_config *config)
{
	int	i;

	if (config->north_texture)
		free(config->north_texture);
	if (config->south_texture)
		free(config->south_texture);
	if (config->west_texture)
		free(config->west_texture);
	if (config->east_texture)
		free(config->east_texture);
	if (config->map)
	{
		i = 0;
		while (i < config->map_height)
		{
			free(config->map[i]);
			i++;
		}
		free(config->map);
	}
}

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

void	initialize_info(t_info *info)
{
	info->mlx = NULL;
	info->win = NULL;
	info->camera_x = 0;
	info->raydir_x = 0;
	info->raydir_y = 0;
	info->sidedist_x = 0;
	info->sidedist_y = 0;
	info->map_x = 0;
	info->map_y = 0;
	info->deltadist_x = 0;
	info->deltadist_y = 0;
	info->perpwalldist = 0;
	info->step_x = 0;
	info->step_y = 0;
	info->hit = 0;
	info->side = 0;
	info->wallX = 0;
	info->texNum = 0;
	info->lineHEI = 0;
	info->drawStart = 0;
	info->drawEnd = 0;
	info->texX = 0;
	info->texY = 0;
	info->step = 0;
	info->texPos = 0;
}

void	initialize_info_img(t_info *info, t_config *config)
{
	info->img.img = NULL;
	info->img.data = NULL;
	info->img.size_l = 0;
	info->img.bpp = 0;
	info->img.endian = 0;
	info->img.img_width = 0;
	info->img.img_height = 0;
	info->config = *config;
}

void	initialize_buffer(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEI)
	{
		x = 0;
		while (x < WID)
		{
			info->buf[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	free_resources(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(info->texture[i]);
		i++;
	}
	free(info->texture);
	if (info->img.img)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
}

void	allocate_texture_memory(t_info *info, t_config *config)
{
	int	i;

	if (!(info->texture = (int **)malloc(sizeof(int *) * 4)))
	{
		perror("Error allocating memory for texture");
		free_resources(info);
		free_config(config);
		exit(1);
	}
	i = 0;
	while (i < 4)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * \
		(TEX_WID * TEX_HEI))))
		{
			perror("Error allocating memory for texture row");
			free_resources(info);
			free_config(config);
			exit(1);
		}
		i++;
	}
}

void	initialize_texture_values(t_info *info)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (i < 4)
	{
		y = 0;
		while (y < TEX_HEI)
		{
			x = 0;
			while (x < TEX_WID)
			{
				info->texture[i][TEX_WID * y + x] = 0;
				x++;
			}
			y++;
		}
		i++;
	}
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
	info->lineHEI = (int)(HEI / info->perpwalldist);
	info->drawStart = -info->lineHEI / 2 + HEI / 2;
	if (info->drawStart < 0)
		info->drawStart = 0;
	info->drawEnd = info->lineHEI / 2 + HEI / 2;
	if (info->drawEnd >= HEI)
		info->drawEnd = HEI - 1;
}

void	determine_texNum_and_wallX(t_info *info)
{
	if (info->side == 0)
	{
		if (info->raydir_x > 0)
			info->texNum = 1;
		else
			info->texNum = 0;
	}
	else
	{
		if (info->raydir_y > 0)
			info->texNum = 3;
		else
			info->texNum = 2;
	}
	if (info->side == 0)
		info->wallX = info->pos_y + info->perpwalldist * info->raydir_y;
	else
		info->wallX = info->pos_x + info->perpwalldist * info->raydir_x;
		info->wallX -= floor(info->wallX);
}

void	draw_texture_column(t_info *info, int x)
{
	int	y;
	int	color;

	info->texX = (int)(info->wallX * (double)TEX_WID);
	if ((info->side == 0 && info->raydir_x > 0) || \
	(info->side == 1 && info->raydir_y < 0))
		info->texX = TEX_WID - info->texX - 1;
	info->step = 1.0 * TEX_HEI / info->lineHEI;
	info->texPos = (info->drawStart - HEI / 2 + info->lineHEI / 2) * info->step;
	y = info->drawStart;
	while (y < info->drawEnd)
	{
		info->texY = (int)info->texPos & (TEX_HEI - 1);
		info->texPos += info->step;
		color = info->texture[info->texNum][TEX_HEI * info->texY + info->texX];
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
		determine_texNum_and_wallX(info);
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

void	move_forward(t_info *info)
{
	if (info->config.map[(int)(info->pos_x + info->dir_x * info->move_speed)] \
	[(int)info->pos_y] == '0')
		info->pos_x += info->dir_x * info->move_speed;
	if (info->config.map[(int)info->pos_x][(int)(info->pos_y + info->dir_y * \
	info->move_speed)] == '0')
		info->pos_y += info->dir_y * info->move_speed;
}

void	move_backward(t_info *info)
{
	if (info->config.map[(int)(info->pos_x - info->dir_x * info->move_speed)] \
	[(int)info->pos_y] == '0')
		info->pos_x -= info->dir_x * info->move_speed;
	if (info->config.map[(int)info->pos_x][(int)(info->pos_y - info->dir_y * \
	info->move_speed)] == '0')
		info->pos_y -= info->dir_y * info->move_speed;
}

void	rotate_left(t_info *info)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(info->rot_speed) - info->dir_y * \
	sin(info->rot_speed);
	info->dir_y = olddir_x * sin(info->rot_speed) + info->dir_y * \
	cos(info->rot_speed);
	oldplane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y * \
	sin(info->rot_speed);
	info->plane_y = oldplane_x * sin(info->rot_speed) + info->plane_y * \
	cos(info->rot_speed);
}

void	rotate_right(t_info *info)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(-info->rot_speed) - info->dir_y * \
	sin(-info->rot_speed);
	info->dir_y = olddir_x * sin(-info->rot_speed) + info->dir_y * \
	cos(-info->rot_speed);
	oldplane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y * \
	sin(-info->rot_speed);
	info->plane_y = oldplane_x * sin(-info->rot_speed) + info->plane_y * \
	cos(-info->rot_speed);
}

int	handle_keys(int keycode, t_info *info)
{
	if (keycode == K_ESC)
		exit_game(info);
	if (keycode == K_W)
		move_forward(info);
	if (keycode == K_S)
		move_backward(info);
	if (keycode == K_A)
		rotate_left(info);
	if (keycode == K_D)
		rotate_right(info);
	return (0);
}

int	main(int argc, char **argv)
{
	t_config	*s_config;
	t_info		s_info;

	atexit(check_leaks);
	if (check_args(argc, argv) == 0)
		return (0);
	s_config = parse_config(argv[1]);
	if (s_config->error == 1)
	{
		ft_putstr("map Error\n", 2);
		free_config(s_config);
		free(s_config);
		return (1);
	}
	initialize_s_info(&s_info, s_config);
	s_info.mlx = mlx_init();
	if (!load_texture_from_config(&s_info, s_config))
	{
		perror("Error: Failed to load textures");
		free_resources(&s_info);
		free_config(s_config);
		free(s_config);
		exit (1);
	}
	s_info.win = mlx_new_window(s_info.mlx, WID, HEI, "cub3D");
	if (!s_info.win)
	{
		perror("Error: Failed to create window");
		free_resources(&s_info);
		free_config(s_config);
		free(s_config);
		exit (1);
	}
	s_info.img.img = mlx_new_image(s_info.mlx, WID, HEI);
	s_info.img.data = (int *)mlx_get_data_addr(s_info.img.img, \
	&s_info.img.bpp, &s_info.img.size_l, &s_info.img.endian);
	mlx_loop_hook(s_info.mlx, &game_loop, &s_info);
	mlx_hook(s_info.win, X_EVENT_KEY_PRESS, 0, &handle_keys, &s_info);
	mlx_loop(s_info.mlx);
	free_config(s_config);
	free_resources(&s_info);
	free(s_config);
	return (0);
}

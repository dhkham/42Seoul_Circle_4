/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:36:34 by dkham             #+#    #+#             */
/*   Updated: 2023/09/12 18:46:04 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	initialize_window(t_info *s_info, t_config *s_config)
{
	s_info->mlx = mlx_init();
	if (!load_texture_from_config(s_info, s_config))
	{
		ft_putstr("Error\n:Failed to load textures\n", 2);
		free_resources(s_info);
		free_config(s_config);
		free(s_config);
		return (0);
	}
	s_info->win = mlx_new_window(s_info->mlx, WID, HEI, "cub3D");
	if (!s_info->win)
	{
		ft_putstr("Error\n:Failed to create window\n", 2);
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

void	init_step_and_sidedist(t_info *info)
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

void	init_ray_map_deltadist(t_info *info, int x)
{
	info->camera_x = 2 * x / (double)WID - 1;
	info->raydir_x = info->dir_x + info->plane_x * info->camera_x;
	info->raydir_y = info->dir_y + info->plane_y * info->camera_x;
	info->map_x = (int)info->pos_x;
	info->map_y = (int)info->pos_y;
	info->deltadist_x = fabs(1 / info->raydir_x);
	info->deltadist_y = fabs(1 / info->raydir_y);
}

void	allocate_texture_memory(t_info *info, t_config *config)
{
	int	i;

	info->texture = (int **)malloc(sizeof(int *) * 4);
	if (!info->texture)
	{
		ft_putstr("Error\n:Failed to allocate memory for textures\n", 2);
		free_resources(info);
		free_config(config);
		exit(1);
	}
	i = 0;
	while (i < 4)
	{
		info->texture[i] = (int *)malloc(sizeof(int) * (TEX_WID * TEX_HEI));
		if (!info->texture[i])
		{
			ft_putstr("Error\n:Failed to allocate memory for texture row\n", 2);
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

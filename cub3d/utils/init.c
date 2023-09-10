/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:36:34 by dkham             #+#    #+#             */
/*   Updated: 2023/09/10 14:40:07 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	info->wall_x = 0;
	info->tex_num = 0;
	info->line_hei = 0;
	info->draw_start = 0;
	info->draw_end = 0;
	info->tex_x = 0;
	info->tex_y = 0;
	info->step = 0;
	info->tex_pos = 0;
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

void	allocate_texture_memory(t_info *info, t_config *config)
{
	int	i;

	info->texture = (int **)malloc(sizeof(int *) * 4);
	if (!info->texture)
	{
		perror("Error allocating memory for texture");
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

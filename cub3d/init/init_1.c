/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:43:35 by dkham             #+#    #+#             */
/*   Updated: 2023/09/12 20:21:36 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialize_s_info(t_info *info, t_config *config)
{
	set_start_position_and_direction(info, config);
	initialize_info(info);
	initialize_info_img(info, config);
	initialize_buffer(info);
	initialize_texture(info, config);
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

void	initialize_texture(t_info *info, t_config *config)
{
	allocate_texture_memory(info, config);
	initialize_texture_values(info);
}

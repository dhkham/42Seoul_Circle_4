/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:58:41 by dkham             #+#    #+#             */
/*   Updated: 2023/09/11 18:59:06 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:37:05 by dkham             #+#    #+#             */
/*   Updated: 2023/09/13 20:59:47 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_hooks_and_loop(t_info *s_info)
{
	mlx_loop_hook(s_info->mlx, &game_loop, s_info);
	mlx_hook(s_info->win, PRESS_RED_BUTTON, 0, &ft_close, &s_info);
	mlx_hook(s_info->win, X_EVENT_KEY_PRESS, 0, &handle_keys, s_info);
	mlx_loop(s_info->mlx);
}

int	game_loop(t_info *info)
{
	raycasting(info);
	drawing(info);
	return (0);
}

void	raycasting(t_info *info)
{
	int	x;

	paint_floor_and_ceiling(info);
	x = 0;
	while (x < WID)
	{
		init_ray_map_deltadist(info, x);
		init_step_and_sidedist(info);
		perform_dda(info);
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

int	ft_close(void)
{
	exit(0);
	return (0);
}

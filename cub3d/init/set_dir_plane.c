/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dir_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:16:04 by dkham             #+#    #+#             */
/*   Updated: 2023/09/11 18:16:41 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:12:37 by dkham             #+#    #+#             */
/*   Updated: 2023/09/11 18:27:58 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_start_position_and_direction(t_info *info, t_config *config)
{
	int	i;
	int	j;

	find_start_position(info, config, &i, &j);
	set_dir_and_plane(info, config, i, j);
	info->move_speed = 0.1;
	info->rot_speed = 0.1;
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

void	set_dir_and_plane(t_info *info, t_config *config, int i, int j)
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

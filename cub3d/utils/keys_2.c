/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:32:52 by dkham             #+#    #+#             */
/*   Updated: 2023/09/13 20:33:14 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

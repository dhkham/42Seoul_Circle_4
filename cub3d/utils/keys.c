/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:58:01 by dkham             #+#    #+#             */
/*   Updated: 2023/09/13 20:29:49 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	move_left(t_info *info)
{
	if (info->config.map[(int)(info->pos_x - info->dir_y * info->move_speed)] \
	[(int)info->pos_y] == '0')
		info->pos_x -= info->dir_y * info->move_speed;
	if (info->config.map[(int)info->pos_x][(int)(info->pos_y + info->dir_x * \
	info->move_speed)] == '0')
		info->pos_y += info->dir_x * info->move_speed;
}

void	move_right(t_info *info)
{
	if (info->config.map[(int)(info->pos_x + info->dir_y * info->move_speed)] \
	[(int)info->pos_y] == '0')
		info->pos_x += info->dir_y * info->move_speed;
	if (info->config.map[(int)info->pos_x][(int)(info->pos_y - info->dir_x * \
	info->move_speed)] == '0')
		info->pos_y -= info->dir_x * info->move_speed;
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
		move_left(info);
	if (keycode == K_D)
		move_right(info);
	if (keycode == LEFT_KEY)
		rotate_left(info);
	if (keycode == RIGHT_KEY)
		rotate_right(info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:55:40 by dkham             #+#    #+#             */
/*   Updated: 2023/09/11 18:56:02 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

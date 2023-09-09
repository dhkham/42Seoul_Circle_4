/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:14:07 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/09 16:37:44 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_textures(t_config *config, char **lines)
{
	char	*line;

	line = lines[0];
	if (ft_strcmp(line, "NO") == 0)
	{
		if (config->north_texture != NULL)
		{
			config->error = 1;
			return ;
		}
		config->north_texture = ft_strdup(lines[1]);
	}
	else if (ft_strcmp(line, "SO") == 0)
	{
		if (config->south_texture != NULL)
		{
			config->error = 1;
			return ;
		}
		config->south_texture = ft_strdup(lines[1]);
	}
	else if (ft_strcmp(line, "WE") == 0)
	{
		if (config->west_texture != NULL)
		{
			config->error = 1;
			return ;
		}
		config->west_texture = ft_strdup(lines[1]);
	}
	else if (ft_strcmp(line, "EA") == 0)
	{
		if (config->east_texture != NULL)
		{
			config->error = 1;
			return ;
		}
		config->east_texture = ft_strdup(lines[1]);
	}
}

void	parse_colors(t_config *config, char **lines)
{
	int		colors[3];
	int		len;
	char	*color;
	char	**color_info;

	len = 0;
	color = lines[0];
	color_info = ft_split(lines[1], ',');
	if (check_color_info(color_info, config))
		return ;
	colors[0] = ft_atoi(color_info[0]);
	colors[1] = ft_atoi(color_info[1]);
	colors[2] = ft_atoi(color_info[2]);
	check_colors(colors, config, color);
	len = 0;
	while (color_info[len])
	{
		free(color_info[len]);
		len++;
	}
	free(color_info);
}

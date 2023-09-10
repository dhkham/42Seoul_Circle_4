/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:14:07 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/10 14:30:51 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_duplicate(char *texture, t_config *config)
{
	if (texture != NULL)
	{
		config->error = 1;
		return (1);
	}
	return (0);
}

static void	set_north_south(char **lines, t_config *config)
{
	char	*line;

	line = lines[0];
	if (ft_strcmp(line, "NO") == 0)
	{
		if (check_duplicate(config->north_texture, config))
			return ;
		config->north_texture = ft_strdup(lines[1]);
	}
	else if (ft_strcmp(line, "SO") == 0)
	{
		if (check_duplicate(config->south_texture, config))
			return ;
		config->south_texture = ft_strdup(lines[1]);
	}
}

static void	set_east_west(char **lines, t_config *config)
{
	char	*line;

	line = lines[0];
	if (ft_strcmp(line, "WE") == 0)
	{
		if (check_duplicate(config->west_texture, config))
			return ;
		config->west_texture = ft_strdup(lines[1]);
	}
	else if (ft_strcmp(line, "EA") == 0)
	{
		if (check_duplicate(config->east_texture, config))
			return ;
		config->east_texture = ft_strdup(lines[1]);
	}
}

void	parse_textures(t_config *config, char **lines)
{
	set_north_south(lines, config);
	set_east_west(lines, config);
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
	if (check_comma(lines[1], color_info, config) || \
	check_color_info(color_info, config))
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

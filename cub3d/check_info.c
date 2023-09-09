/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:10:02 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/09 16:12:46 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_config(t_config *config)
{
	if (config->north_texture == NULL)
		return (0);
	else if (config->south_texture == NULL)
		return (0);
	else if (config->west_texture == NULL)
		return (0);
	else if (config->east_texture == NULL)
		return (0);
	else if (config->floor_color[0] == -1)
		return (0);
	else if (config->ceiling_color[0] == -1)
		return (0);
	else
		return (1);
}

static void	check_type(t_config *config, char **lines)
{
	char	*line;

	line = lines[0];
	if (ft_strncmp(line, "NO", 3) == 0)
		parse_textures(config, lines);
	else if (ft_strncmp(line, "SO", 3) == 0)
		parse_textures(config, lines);
	else if (ft_strncmp(line, "WE", 3) == 0)
		parse_textures(config, lines);
	else if (ft_strncmp(line, "EA", 3) == 0)
		parse_textures(config, lines);
	else if (ft_strncmp(line, "F", 2) == 0)
		parse_colors(config, lines);
	else if (ft_strncmp(line, "C", 2) == 0)
		parse_colors(config, lines);
	else
		config->error = 1;
	return ;
}

static int	check_type_info(char **line, t_config *config)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i != 2)
	{
		i = 0;
		while (line[i])
		{
			free(line[i]);
			i++;
		}
		free(line);
		config->error = 1;
		return (1);
	}
	return (0);
}

static void	parse_map_data(t_config *config, int i, char **content)
{
	if (check_maps(config, i, content))
		return ;
	if (init_map_memory(config))
		return ;
	duplicate_map(config, i, content);
	check_walls(config);
}

void	parse_info(t_config *config, char **content)
{
	int		i;
	char	**temp;

	i = 0;
	while (content[i])
	{
		if (check_config(config))
			break ;
		temp = ft_split(content[i], ' ');
		if (check_type_info(temp, config))
			break ;
		check_type(config, temp);
		free(temp[0]);
		free(temp[1]);
		free(temp);
		if (config->error == 1)
			break ;
		i++;
	}
	if (config->error == 1)
		return ;
	parse_map_data(config, i, content);
}

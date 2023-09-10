/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:10:02 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/10 13:22:41 by dkham            ###   ########.fr       */
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
	else if (config->ceil_color[0] == -1)
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
	free(lines[0]);
	free(lines[1]);
	free(lines);
	return ;
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

char	**get_type_and_value(char *line)
{
	int		i;
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * 3);
	if (!temp)
		return (NULL);
	temp[2] = NULL;
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	temp[0] = ft_substr(line, 0, i);
	if (!temp[0])
	{
		free(temp);
		return (NULL);
	}
	temp[1] = ft_substr(line, i, ft_strlen(line) - i);
	if (!temp[1])
	{
		free(temp[0]);
		free(temp);
		return (NULL);
	}
	temp[1] = ft_strtrim(temp[1], " ");
	return (temp);
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
		temp = get_type_and_value(content[i]);
		if (!temp)
		{
			config->error = 1;
			break ;
		}
		check_type(config, temp);
		if (config->error == 1)
			break ;
		i++;
	}
	if (config->error == 1)
		return ;
	parse_map_data(config, i, content);
}

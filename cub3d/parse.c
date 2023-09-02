/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:38:01 by dkham             #+#    #+#             */
/*   Updated: 2023/09/02 17:12:21 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_textures(t_config *config, char **lines)
{
	char	*line;

	line = lines[0];
	if (ft_strcmp(line, "NO") == 0) {
		if (config->north_texture != NULL)
		{
			config->error = 1;
			return ;
		}
		config->north_texture = ft_strdup(lines[1]);
	}
	else if (ft_strcmp(line, "SO") == 0) {
		if (config->south_texture != NULL)
		{
			config->error = 1;
			return ;
		}
		config->south_texture = ft_strdup(lines[1]);
	}
	else if (ft_strcmp(line, "WE") == 0) {
		if (config->west_texture != NULL)
		{
			config->error = 1;
			return ;
		}
		config->west_texture = ft_strdup(lines[1]);
	}
	else if (ft_strcmp(line, "EA") == 0) {
		if (config->east_texture != NULL)
		{
			config->error = 1;
			return ;
		}
		config->east_texture = ft_strdup(lines[1]);
	}
}

static void	check_colors(int *colors, t_config *config, char *color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (colors[i] < 0 || colors[i] > 255)
			return ;
		i++;
	}
	if (ft_strncmp("F", color, 2) == 0) {
		if (config->floor_color[0] != -1)
		{
			config->error = 1;
			return ;
		}
		ft_memcpy(config->floor_color, colors, sizeof(int) * 3);
	}
	else if (ft_strncmp("C", color, 2) == 0) {
		if (config->ceiling_color[0] != -1)
		{
			config->error = 1;
			return ;
		}
		ft_memcpy(config->ceiling_color, colors, sizeof(int) * 3);
	}
	else
		return ;
}

int	check_color_info(char **color_info, t_config *config)
{
	int	i;
	int	j;
	int	len;
	int	flag;

	len = 0;
	while (color_info[len])
		len++;
	i = 0;
	flag = 0;
	while (color_info[i])
	{
		j = 0;
		while (color_info[i][j])
		{
			if (!ft_isdigit(color_info[i][j]))
				flag = 1;
			j++;
		}
		i++;
	}
	if (flag == 1 || len != 3)
	{
		config->error = 1;
		len = 0;
		while (color_info[len])
		{
			free(color_info[len]);
			len++;
		}
		free(color_info);
		return (1);
	}
	return (0);
}

static void	parse_colors(t_config *config, char **lines)
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


// static void	parse_map_dimensions(t_config *config, char *line)
// {
// 	config->map_height++;
// 	if (ft_strlen(line) > config->map_width)
// 		config->map_width = ft_strlen(line);
// }

static int	check_maps(t_config *config, int idx, char **content)
{
	int	i;
	int	j;
	int	width;
	int	flag;

	i = idx;
	width = 0;
	flag = 0;
	while(content[i])
	{
		j = 0;
		while (content[i][j])
		{
			if (ft_strchr("01NSEW ", content[i][j]) == NULL)
			{
				config->error = 1;
				return (1);
			}
			else if (ft_strchr("NSEW", content[i][j]) != NULL)
			{
				if (flag == 1)
				{
					config->error = 1;
					return (1);
				}
				flag = 1;
			}
			j++;
		}
		if (width < j)
			width = j;
		i++;
	}
	config->map_height = i - idx;
	config->map_width = width;
	return (0);
}

static void	duplicate_map(t_config *config, int idx, char **content)
{
	int	i;
	int	j;

	i = idx;
	while (content[i])
	{
		j = 0;
		while (content[i][j])
		{
			config->map[i - idx][j] = content[i][j];
			j++;
		}
		while (j < config->map_width)
		{
			config->map[i - idx][j] = ' ';
			j++;
		}
		i++;
	}
}

static void	parse_map_data(t_config *config, int i, char **content)
{
	if (check_maps(config, i, content))
		return ;
	if (init_map_memory(config))
		return ;
	duplicate_map(config, i, content);
}

char	**get_info(int fd)
{
	char	*line;
	char	*temp;
	char	**ll;

	line = get_next_line(fd);
	temp = NULL;
	while (line)
	{
		temp = ft_strjoin(temp, line);

		free(line);
		line = get_next_line(fd);
	}
	ll = ft_split(temp, '\n');
	free(temp);
	return (ll);
}
int	check_config(t_config *config)
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

void	parse_info(t_config *config, char **content)
{
	int		i;
	char	**temp;

	i = 0;
	while(content[i])
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

t_config	*parse_config(const char *filename)
{
	int			fd;
	t_config	*config;
	char		**content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		handle_error(fd);
		return (NULL);
	}
	config = init_config(fd);
	content = get_info(fd);
	close(fd);
	parse_info(config, content);
	int i = 0;
	while (content[i])
	{
		free(content[i]);
		i++;
	}
	free(content);
	return (config);
}

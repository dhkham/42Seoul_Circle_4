/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:38:01 by dkham             #+#    #+#             */
/*   Updated: 2023/09/02 14:21:07 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_textures(t_config *s_config, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		s_config->north_texture = \
		ft_strdup(ft_strnstr(line, " ", ft_strlen(line)) + 1);
	else if (ft_strncmp(line, "SO", 2) == 0)
		s_config->south_texture = \
		ft_strdup(ft_strnstr(line, " ", ft_strlen(line)) + 1);
	else if (ft_strncmp(line, "WE", 2) == 0)
		s_config->west_texture = \
		ft_strdup(ft_strnstr(line, " ", ft_strlen(line)) + 1);
	else if (ft_strncmp(line, "EA", 2) == 0)
		s_config->east_texture = \
		ft_strdup(ft_strnstr(line, " ", ft_strlen(line)) + 1);
}

static void	parse_colors(t_config *s_config, char *line)
{
	int		colors[3];
	char	*next_comma;
	int		index;

	index = 0;
	line += 2; // RGB값 가리키도록 'F' 또는 'C' 다음의 공백을 건너뛴다. (map.cub에 F 220,100,0로 표시되어 있음)
	while (index < 3)
	{
		colors[index] = ft_atoi(line);			// 색상 값을 가져온다.
		next_comma = ft_strchr(line, ',');		// 다음 쉼표를 찾는다.
		if (!next_comma)						// 쉼표가 없으면 루프를 중단한다.
			break ;
		line = next_comma + 1;					// 다음 색상 값의 시작 위치로 line을 업데이트
		index++;
	}
	if (*(line - 2) == 'F')
		ft_memcpy(s_config->floor_color, colors, sizeof(colors));
	else
		ft_memcpy(s_config->ceiling_color, colors, sizeof(colors));
}


static void	parse_map_dimensions(t_config *s_config, char *line)
{
	s_config->map_height++;
	if (ft_strlen(line) > s_config->map_width)
		s_config->map_width = ft_strlen(line);
}

static void	parse_map_data(t_config *s_config, const char *filename)
{
	int	fd;

	if (!init_map_memory(s_config))
		return ;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		free(s_config->map);
		return ;
	}
	parse_actual_map_data(s_config, fd);
	close(fd);
}

t_config	*parse_config(const char *filename)
{
	int			fd;
	t_config	*s_config;
	char		*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		handle_error(fd);
		return (NULL);
	}
	s_config = init_config(fd);
	line = get_next_line(fd);
	while (line)
	{
		parse_textures(s_config, line);
		parse_colors(s_config, line);
		parse_map_dimensions(s_config, line);
		free(line);
		line = get_next_line(fd);
	}
	parse_map_data(s_config, fd);
	close(fd);
	return (s_config);
}

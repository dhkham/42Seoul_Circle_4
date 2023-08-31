/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:38:01 by dkham             #+#    #+#             */
/*   Updated: 2023/08/31 20:59:15 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	parse_textures(t_config *config, char *line)
// {
// 	if (ft_strcmp(line, "NO") == 0)
// 		config->north_texture = \
// 		ft_strdup(ft_strnstr(line, " ", ft_strlen(line)) + 1);
// 	else if (ft_strcmp(line, "SO") == 0)
// 		config->south_texture = \
// 		ft_strdup(ft_strnstr(line, " ", ft_strlen(line)) + 1);
// 	else if (ft_strcmp(line, "WE") == 0)
// 		config->west_texture = \
// 		ft_strdup(ft_strnstr(line, " ", ft_strlen(line)) + 1);
// 	else if (ft_strcmp(line, "EA") == 0)
// 		config->east_texture = \
// 		ft_strdup(ft_strnstr(line, " ", ft_strlen(line)) + 1);
// }

// static void	parse_colors(t_config *config, char *line)
// {
// 	int		colors[3];
// 	char	*next_comma;
// 	int		index;

// 	index = 0;
// 	line += 2; // RGB값 가리키도록 'F' 또는 'C' 다음의 공백을 건너뛴다. (map.cub에 F 220,100,0로 표시되어 있음)
// 	while (index < 3)
// 	{
// 		colors[index] = ft_atoi(line);			// 색상 값을 가져온다.
// 		next_comma = ft_strchr(line, ',');		// 다음 쉼표를 찾는다.
// 		if (!next_comma)						// 쉼표가 없으면 루프를 중단한다.
// 			break ;
// 		line = next_comma + 1;					// 다음 색상 값의 시작 위치로 line을 업데이트
// 		index++;
// 	}
// 	if (*(line - 2) == 'F')
// 		ft_memcpy(config->floor_color, colors, sizeof(colors));
// 	else
// 		ft_memcpy(config->ceiling_color, colors, sizeof(colors));
// }


// static void	parse_map_dimensions(t_config *config, char *line)
// {
// 	config->map_height++;
// 	if (ft_strlen(line) > config->map_width)
// 		config->map_width = ft_strlen(line);
// }

// static void	parse_map_data(t_config *config, const char *filename)
// {
// 	int	fd;

// 	if (!init_map_memory(config))
// 		return ;
// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		free(config->map);
// 		return ;
// 	}
// 	parse_actual_map_data(config, fd);
// 	close(fd);
// }

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

int	check_type(char *line)
{
	int		flag;

	flag = 0;
	if (ft_strncmp(line, "NO", 3) == 0)
		flag = 1;
	else if (ft_strncmp(line, "SO", 3) == 0)
		flag = 1;
	else if (ft_strncmp(line, "WE", 3) == 0)
		flag = 1;
	else if (ft_strncmp(line, "EA", 3) == 0)
		flag = 1;
	else if (ft_strncmp(line, "F", 2) == 0)
		flag = 2;
	else if (ft_strncmp(line, "C", 2) == 0)
		flag = 2;
	else
		return (0);
	printf("flag: %d\n", flag);
	return (flag);
}

void	parse_info(t_config *config, char **content)
{
	int		i;
	int		re;
	char	**temp;

	i = 0;
	while(content[i])
	{
		if (check_config(config))
			break ;
		temp = ft_split(content[i], ' ');
		re = check_type(temp[0]);
		free(temp[0]);
		free(temp[1]);
		free(temp);
		if (re == 0)
			break ;
		i++;
	}
	if (re == 0)
		return ;

	// parse_textures(config, line);
	// parse_colors(config, line);
	//parse_map_data(config, filename);
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

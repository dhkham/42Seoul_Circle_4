/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:38:01 by dkham             #+#    #+#             */
/*   Updated: 2023/09/09 16:42:36 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	duplicate_map(t_config *config, int idx, char **content)
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

t_config	*parse_config(const char *filename)
{
	int			fd;
	t_config	*config;
	char		**content;
	int			i;

	i = 0;
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
	while (content[i])
	{
		free(content[i]);
		i++;
	}
	free(content);
	return (config);
}

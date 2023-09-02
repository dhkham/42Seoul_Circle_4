/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:10:10 by dkham             #+#    #+#             */
/*   Updated: 2023/09/02 14:21:07 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_error(int fd)
{
	perror("Error opening file");
	close(fd);
}

static t_config	*init_config(int fd)
{
	t_config	*s_config;

	s_config = malloc(sizeof(t_config));
	if (!s_config)
	{
		perror("Error allocating memory");
		close(fd);
	}
	ft_memset(s_config, 0, sizeof(t_config));
	return (s_config);
}

static int	init_map_memory(t_config *s_config)
{
	s_config->map = malloc(sizeof(char *) * s_config->map_height);
	if (!s_config->map)
	{
		perror("Error allocating memory for map");
		free(s_config);
		return (0);  // Indicate failure
	}
	return (1); // Indicate success
}

static void	parse_actual_map_data(t_config *s_config, int fd)
{
	char	*line;
	int		row;

	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '1' || line[0] == '0' || ft_strchr("NSEW", line[0]))
		{
			s_config->map[row] = ft_strdup(line);
			row++;
		}
		free(line);
		line = get_next_line(fd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:10:10 by dkham             #+#    #+#             */
/*   Updated: 2023/08/27 16:54:05 by dkham            ###   ########.fr       */
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
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
	{
		perror("Error allocating memory");
		close(fd);
	}
	ft_memset(config, 0, sizeof(t_config));
	return (config);
}

static int	init_map_memory(t_config *config)
{
	config->map = malloc(sizeof(char *) * config->map_height);
	if (!config->map)
	{
		perror("Error allocating memory for map");
		free(config);
		return (0);  // Indicate failure
	}
	return (1); // Indicate success
}

static void	parse_actual_map_data(t_config *config, int fd)
{
	char	*line;
	int		row;

	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '1' || line[0] == '0' || ft_strchr("NSEW", line[0]))
		{
			config->map[row] = ft_strdup(line);
			row++;
		}
		free(line);
		line = get_next_line(fd);
	}
}

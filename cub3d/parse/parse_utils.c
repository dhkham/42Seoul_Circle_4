/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:10:10 by dkham             #+#    #+#             */
/*   Updated: 2023/09/11 19:13:20 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	handle_error(int fd)
{
	perror("Error opening file");
	close(fd);
}

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

int	init_map_memory(t_config *config)
{
	int	i;

	config->map = (char **)malloc(sizeof(char *) * config->map_height + 1);
	if (!config->map)
	{
		perror("Error allocating memory for map");
		config->error = 1;
		return (1);
	}
	config->map[config->map_height - 1] = NULL;
	i = 0;
	while (i < config->map_height)
	{
		config->map[i] = malloc(sizeof(char) * config->map_width + 1);
		if (!config->map[i])
		{
			perror("Error allocating memory for map");
			config->error = 1;
			return (1);
		}
		config->map[i][config->map_width] = '\0';
		i++;
	}
	return (0);
}

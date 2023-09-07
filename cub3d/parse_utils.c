/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:10:10 by dkham             #+#    #+#             */
/*   Updated: 2023/09/07 18:39:43 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_error(int fd)
{
	perror("Error opening file");
	close(fd);
}

t_config	*init_config(int fd)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
	{
		perror("Error allocating memory");
		close(fd);
	}
	ft_memset(config, 0, sizeof(t_config));
	config->floor_color[0] = -1;
	config->ceiling_color[0] = -1;
	return (config);
}

int	init_map_memory(t_config *config)
{
	int	i;
	config->map = (char **)malloc(sizeof(char *) * config->map_height + 1);
	if (!config->map)
	{
		perror("Error allocating memory for map");
		config->error = 1;
		return (1);  // Indicate failure
	}
	config->map[config->map_height] = NULL;
	i = 0;
	while (i < config->map_height)
	{
		config->map[i] = malloc(sizeof(char) * config->map_width + 1);
		if (!config->map[i])
		{
			perror("Error allocating memory for map");
			config->error = 1;
			return (1); // Indicate failure
		}
		config->map[i][config->map_width] = '\0';
		i++;
	}
	return (0); // Indicate success
}

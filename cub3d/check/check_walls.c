/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:08:21 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/10 14:27:42 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	**init_maps(t_config *config)
{
	int	**visited;
	int	i;

	visited = (int **)malloc(sizeof(int *) * config->map_height);
	if (!visited)
	{
		config->error = 1;
		return (NULL);
	}
	i = 0;
	while (i < config->map_height)
	{
		visited[i] = (int *)malloc(sizeof(int) * config->map_width);
		if (!visited[i])
		{
			while (i >= 0)
				free(visited[i--]);
			config->error = 1;
			free(visited);
			return (NULL);
		}
		ft_memset(visited[i], 0, sizeof(int) * config->map_width);
		i++;
	}
	return (visited);
}

void	dfs(t_config *config, int **visited, int i, int j)
{
	if (i < 0 || i >= config->map_height || j < 0 || j >= config->map_width)
		return ;
	if (config->map[i][j] == '1' || visited[i][j] == 1)
		return ;
	visited[i][j] = 1;
	if (config->map[i][j] == ' ' || i == 0 || i == config->map_height - 1 \
		|| j == 0 || j == config->map_width - 1)
	{
		config->error = 1;
		return ;
	}
	dfs(config, visited, i + 1, j);
	dfs(config, visited, i - 1, j);
	dfs(config, visited, i, j + 1);
	dfs(config, visited, i, j - 1);
}

void	check_walls(t_config *config)
{
	int	**visited;
	int	i;
	int	j;

	visited = init_maps(config);
	if (!visited)
		return ;
	i = 0;
	while (i < config->map_height)
	{
		j = 0;
		while (j < config->map_width)
		{
			if (config->map[i][j] == '0' || config->map[i][j] == 'N' \
				|| config->map[i][j] == 'S' || config->map[i][j] == 'E' \
				|| config->map[i][j] == 'W')
				dfs(config, visited, i, j);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < config->map_height)
		free(visited[i++]);
	free(visited);
}

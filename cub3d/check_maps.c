/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:30:27 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/09 16:34:23 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_direction(char c, t_config *config)
{
	if (c == 'N')
		config->direction = "N";
	else if (c == 'S')
		config->direction = "S";
	else if (c == 'E')
		config->direction = "E";
	else if (c == 'W')
		config->direction = "W";
}

int	check_maps(t_config *config, int idx, char **content)
{
	int	i;
	int	j;
	int	width;
	int	flag;

	i = idx;
	width = 0;
	flag = 0;
	while (content[i])
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
				set_direction(content[i][j], config);
			}
			j++;
		}
		if (width < j)
			width = j;
		i++;
	}
	if (flag == 0)
	{
		config->error = 1;
		return (1);
	}
	config->map_height = i - idx;
	config->map_width = width;
	return (0);
}

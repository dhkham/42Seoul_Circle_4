/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:24:07 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/09 16:33:55 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_colors(int *colors, t_config *config, char *color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (colors[i] < 0 || colors[i] > 255)
			return ;
		i++;
	}
	if (ft_strncmp("F", color, 2) == 0)
	{
		if (config->floor_color[0] != -1)
		{
			config->error = 1;
			return ;
		}
		ft_memcpy(config->floor_color, colors, sizeof(int) * 3);
	}
	else if (ft_strncmp("C", color, 2) == 0)
	{
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

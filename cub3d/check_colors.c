/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:24:07 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/10 13:22:41 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_colors(int *colors, t_config *config, char *color)
{
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
		if (config->ceil_color[0] != -1)
		{
			config->error = 1;
			return ;
		}
		ft_memcpy(config->ceil_color, colors, sizeof(int) * 3);
	}
	else
		return ;
}

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
	set_colors(colors, config, color);
	return ;
}

int	color_error(int flag, int len, char **color_info, t_config *config)
{
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

static int	check_digit(char **color_info)
{
	int	i;
	int	j;

	i = 0;
	while (color_info[i])
	{
		j = 0;
		while (color_info[i][j])
		{
			if (!ft_isdigit(color_info[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_color_info(char **color_info, t_config *config)
{
	int	i;
	int	len;
	int	flag;

	len = 0;
	while (color_info[len])
		len++;
	i = 0;
	while (color_info[i])
	{
		color_info[i] = ft_strtrim(color_info[i], " ");
		i++;
	}
	flag = check_digit(color_info);
	if (color_error(flag, len, color_info, config))
		return (1);
	return (0);
}

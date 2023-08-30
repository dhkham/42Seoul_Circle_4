/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:52:27 by dkham             #+#    #+#             */
/*   Updated: 2023/08/30 19:52:46 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "utils/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct config
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3]; // RGB
	int		ceiling_color[3]; // RGB
	char	**map;
	int		map_width;
	int		map_height;
}	t_config;

int	check_args(int args, char **argv);
int	ft_strcmp(char *s1, char *s2);
int	ft_isalpha_isdigit(char c);

#endif

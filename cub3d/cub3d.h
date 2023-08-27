/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:52:27 by dkham             #+#    #+#             */
/*   Updated: 2023/08/27 17:22:00 by dkham            ###   ########.fr       */
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

#endif
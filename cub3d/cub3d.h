/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:52:27 by dkham             #+#    #+#             */
/*   Updated: 2023/08/31 18:36:22 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
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
	char	*direction;
}	t_config;

int			check_args(int args, char **argv);
int			ft_strcmp(char *s1, char *s2);
int			ft_isalpha_isdigit(char c);
t_config	*parse_config(const char *filename);
void		handle_error(int fd);
t_config	*init_config(int fd);
int			init_map_memory(t_config *config);
void		parse_actual_map_data(t_config *config, int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:38:01 by dkham             #+#    #+#             */
/*   Updated: 2023/09/12 18:54:11 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validate_arguments(int argc, char **argv, t_config **s_config)
{
	if (check_args(argc, argv) == 0)
		return (0);
	*s_config = parse_config(argv[1]);
	if ((*s_config)->error == 1)
	{
		ft_putstr("Error\n:arg error\n", 2);
		free_config(*s_config);
		free(*s_config);
		exit(1);
	}
	return (1);
}

t_config	*parse_config(const char *filename)
{
	int			fd;
	t_config	*config;
	char		**content;
	int			i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		handle_error(fd);
		return (NULL);
	}
	config = init_config(fd);
	content = get_info(fd);
	close(fd);
	parse_info(config, content);
	while (content[i])
	{
		free(content[i]);
		i++;
	}
	free(content);
	return (config);
}

t_config	*init_config(int fd)
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config));
	if (!config)
	{
		ft_putstr("Error\n:error allocating memory\n", 2);
		close(fd);
	}
	ft_memset(config, 0, sizeof(t_config));
	config->floor_color[0] = -1;
	config->ceil_color[0] = -1;
	return (config);
}

char	**get_info(int fd)
{
	char	*line;
	char	*temp;
	char	**ll;

	line = get_next_line(fd);
	temp = NULL;
	while (line)
	{
		temp = ft_strjoin(temp, line);
		free(line);
		line = get_next_line(fd);
	}
	ll = ft_split(temp, '\n');
	free(temp);
	return (ll);
}

void	parse_info(t_config *config, char **content)
{
	int		i;
	char	**temp;

	i = 0;
	while (content[i])
	{
		if (check_config(config))
			break ;
		temp = get_type_and_value(content[i]);
		if (!temp)
		{
			config->error = 1;
			break ;
		}
		check_type(config, temp);
		if (config->error == 1)
			break ;
		i++;
	}
	if (config->error == 1)
		return ;
	parse_map_data(config, i, content);
}

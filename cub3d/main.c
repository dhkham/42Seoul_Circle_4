/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:23:55 by dkham             #+#    #+#             */
/*   Updated: 2023/09/12 18:57:17 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// leak check
void leak_check(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_config	*s_config;
	t_info		s_info;

	atexit(leak_check);
	if (!validate_arguments(argc, argv, &s_config))
		return (0);
	initialize_s_info(&s_info, s_config);
	if (!initialize_window(&s_info, s_config))
		return (0);
	setup_hooks_and_loop(&s_info);
	free_config(s_config);
	free_resources(&s_info);
	free(s_config);
	return (0);
}

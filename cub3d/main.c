/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:02:59 by dkham             #+#    #+#             */
/*   Updated: 2023/09/02 16:50:43 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_config(t_config *config)
{
	printf("North texture: %s\n", config->north_texture);
	printf("South texture: %s\n", config->south_texture);
	printf("West texture: %s\n", config->west_texture);
	printf("East texture: %s\n", config->east_texture);
	printf("Floor color: %d, %d, %d\n", config->floor_color[0], config->floor_color[1], config->floor_color[2]);
	printf("Ceiling color: %d, %d, %d\n", config->ceiling_color[0], config->ceiling_color[1], config->ceiling_color[2]);
	printf("Map width: %d\n", config->map_width);
	printf("Map height: %d\n", config->map_height);
	printf("Map:\n");
	for (int i = 0; i < config->map_height; i++)
		printf("%s\n", config->map[i]);
}

void	check_leaks(void)
{
	system("leaks cub3D | grep leaked");
}

void	free_config(t_config *config)
{
	if (config->north_texture)
		free(config->north_texture);
	if (config->south_texture)
		free(config->south_texture);
	if (config->west_texture)
		free(config->west_texture);
	if (config->east_texture)
		free(config->east_texture);
	if (config->map)
	{
		for (int i = 0; i < config->map_height; i++)
			free(config->map[i]);
		free(config->map);
	}
	free(config);
}

int	main(int argc, char **argv)
{
	t_config	*config;

	atexit(check_leaks);
	if (check_args(argc, argv) == 0)
		return (0);
	config = parse_config(argv[1]);
	if (config->error == 1)
	{
		ft_putstr("Error\n", 2);
		free_config(config);
		return (1);
	}
	print_config(config);
	free_config(config);
	// if (!config)
	// {
	// 	ft_putstr("Error: Failed to parse the configuration.\n", 2);
	// 	return (1);
	// }
    // if (!init_graphics())	// Initialize window and graphics rendering context
	// {
	// 	ft_putstr("Error: Failed to initialize graphics.\n", 2);
	// 	free_config(config);
	// 	return (1);
	// }
    // if (!load_textures(config))    // Load Textures
	// {
	// 	ft_putstr("Error: Failed to load textures.\n", 2);
	// 	free_graphics();  // hypothetical cleanup function for the graphics library used
	// 	free_config(config);
	// 	return (1);
	// }
    // game = init_game_state(config);    // Initialize game state
    // if (!game)
	// {
	// 	ft_putstr("Error: Failed to initialize game state.\n", 2);
	// 	free_textures();  // hypothetical cleanup function for loaded textures
	// 	free_graphics();
	// 	free_config(config);
	// 	return (1);
	// }

	// // Main game loop
	// while (game_is_running)
	// {
	// 	// Capture user input
	// 	// Update game state
	// 	// Render game
	// }
	// // Cleanup and free resources


	// return (0);
}

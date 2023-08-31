/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:02:59 by dkham             #+#    #+#             */
/*   Updated: 2023/08/31 18:28:46 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_config	*config;

	if (check_args(argc, argv) == 0)
		return (0);
	config = parse_config(argv[1]);
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
	// free_config(config);

	// return (0);
}

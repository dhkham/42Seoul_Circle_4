/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:02:59 by dkham             #+#    #+#             */
/*   Updated: 2023/09/02 16:24:50 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_macos.h"

int load_texture_from_config(t_info *info, t_config *config)
{
    t_img img;

    if (!load_image(info, info->texture[0], config->north_texture, &img)) return 0;
    if (!load_image(info, info->texture[1], config->south_texture, &img)) return 0;
    if (!load_image(info, info->texture[2], config->west_texture, &img)) return 0;
    if (!load_image(info, info->texture[3], config->east_texture, &img)) return 0;

    return 1; // All textures loaded successfully
}

int load_image(t_info *info, int *texture, char *path, t_img *img)
{
    img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
    if (!img->img)  // Check if image loading was successful
    {
        perror("Error loading texture");
        return 0; // Return 0 to indicate failure
    }
    img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
    for (int y = 0; y < img->img_height; y++)
    {
        for (int x = 0; x < img->img_width; x++)
        {
            texture[img->img_width * y + x] = img->data[img->img_width * y + x];
        }
    }
    mlx_destroy_image(info->mlx, img->img);
    
    return 1; // Return 1 to indicate success
}

void initialize_s_info(t_info *info)
{
    // Initialize position, direction, and plane
    info->posX = 0.0;
    info->posY = 0.0;
    info->dirX = 0.0;
    info->dirY = 0.0;
    info->planeX = 0.0;
    info->planeY = 0.0;

    // Initialize mlx and win pointers
    info->mlx = NULL;
    info->win = NULL;

    // Initialize image
    info->img.img = NULL;
    info->img.data = NULL;
    info->img.size_l = 0;
    info->img.bpp = 0;
    info->img.endian = 0;
    info->img.img_width = 0;
    info->img.img_height = 0;

    // Initialize buffer - considering height and width are constants
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            info->buf[y][x] = 0;
        }
    }

    // Initialize texture - Assuming a total of 4 textures based on previous info
    info->texture = (int **)malloc(sizeof(int *) * 4);
    for (int i = 0; i < 4; i++)
    {
        info->texture[i] = (int *)malloc(sizeof(int) * (TEXTURE_WIDTH * TEXTURE_HEIGHT)); 
    }
    info->moveSpeed = 0.0;  // Set to a default value if you have one.
    info->rotSpeed = 0.0;   // Set to a default value if you have one.
}

void cleanup_s_info(t_info *info)
{
    for (int i = 0; i < 4; i++)
    {
        free(info->texture[i]);
    }
    free(info->texture);
    // Add other cleanup logic if required
}

int game_loop(t_info *info)
{
    // Clearing the screen buffer
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            info->buf[y][x] = 0; // Or use a background color
        }
    }
    
    // Implement your raycasting logic here
    // This might involve calculations to figure out walls, textures, etc.
    // ...

    // Draw the results from the buffer to the screen
    // Note: You may need to adjust this part depending on how you've set up drawing with MLX.
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Assuming you have a function to put pixel in an image
            put_pixel_to_img(info->img, x, y, info->buf[y][x]);
        }
    }
    mlx_put_image_to_window(info->mlx, info->win, info->img->img, 0, 0);

    return (0);
}

int handle_keys(int keycode, t_info *info)
{
    if (keycode == K_ESC) // Assuming you have defined KEY_ESC for the escape key
    {
        free_resources(info, NULL); // Assuming the function also handles null config
        exit(0);
    }
    // Handle other keys, e.g., movement
    if (keycode == K_W) // Move forward
    {
        // Update player position forward
        info->posX += info->dirX * info->moveSpeed;
        info->posY += info->dirY * info->moveSpeed;
    }
    // Similarly, handle KEY_S, KEY_A, KEY_D, etc. for other movements
	if (keycode == K_S) // Move backward
	{
		// Update player position backward
		info->posX -= info->dirX * info->moveSpeed;
		info->posY -= info->dirY * info->moveSpeed;
	}
	if (keycode == K_A) // Move left
	{
		// Update player position left
		info->posX -= info->planeX * info->moveSpeed;
		info->posY -= info->planeY * info->moveSpeed;
	}
	if (keycode == K_D) // Move right
	{
		// Update player position right
		info->posX += info->planeX * info->moveSpeed;
		info->posY += info->planeY * info->moveSpeed;
	}
    return (0);
}

int	main(int argc, char **argv)
{
	t_config	*s_config;
	t_info		s_info;
	t_img		s_img;
	
	if (check_args(argc, argv) == 0)
		return (0);
	s_config = parse_config(argv[1]);
	if (!s_config)
	{
		perror("Error: Failed to parse config file");
		exit(1);
	}
	s_info.mlx = mlx_init();
	if (!load_texture_from_config(&s_info, s_config))
	{
		perror("Error: Failed to load textures");
		// Cleanup and free resources.
		// Assuming you have a function named free_resources or similar.
		free_resources(&s_info, s_config);
		return (0);
	}

	// Assuming the window size is defined by the constants width and height.
	s_info.win = mlx_new_window(s_info.mlx, width, height, "Your Game Title Here");
	if (!s_info.win)
	{
		perror("Error: Failed to create window");
		// Cleanup and free resources.
		free_resources(&s_info, s_config);
		return (0);
	}
	
    // Set game logic to be continuously called
    mlx_loop_hook(s_info.mlx, game_loop, &s_info);

    // Set key input function
    mlx_key_hook(s_info.win, handle_keys, &s_info);
	
	// Start the event loop. This will keep your game running.
	mlx_loop(s_info.mlx);

	// If your program somehow gets here, cleanup and end.
	// However, usually mlx_loop only ends when the program closes.
	free_resources(&s_info, s_config);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:41:21 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/09 20:22:12 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_macos.h"

void	print_config(t_config *config)
{
	printf("North texture: %s\n", config->north_texture);
	printf("South texture: %s\n", config->south_texture);
	printf("West texture: %s\n", config->west_texture);
	printf("East texture: %s\n", config->east_texture);
	printf("direction %s\n", config->direction);
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
	system("leaks cub3D");
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
		{
			free(config->map[i]);
		}
		free(config->map);
	}
}

void find_start_position(t_info *info, t_config *config, int *i, int *j)
{
    *i = 0;
    while (*i < config->map_height)
    {
        *j = 0;
        while (*j < config->map_width)
        {
            if (config->map[*i][*j] == 'N' || config->map[*i][*j] == 'S' || config->map[*i][*j] == 'W' || config->map[*i][*j] == 'E')
            {
                info->pos_x = *i + 0.5;
                info->pos_y = *j + 0.5;
                return;
            }
            (*j)++;
        }
        (*i)++;
    }
}

void set_direction_north(t_info *info, t_config *config, int i, int j)
{
    info->dir_x = -1.0;
    info->dir_y = 0.0;
    info->plane_x = 0.0;
    info->plane_y = 0.66;
    config->map[i][j] = '0';
}

void set_direction_south(t_info *info, t_config *config, int i, int j)
{
    info->dir_x = 1.0;
    info->dir_y = 0.0;
    info->plane_x = 0.0;
    info->plane_y = -0.66;
    config->map[i][j] = '0';
}

void set_direction_west(t_info *info, t_config *config, int i, int j)
{
    info->dir_x = 0.0;
    info->dir_y = -1.0;
    info->plane_x = -0.66;
    info->plane_y = 0.0;
    config->map[i][j] = '0';
}

void set_direction_east(t_info *info, t_config *config, int i, int j)
{
    info->dir_x = 0.0;
    info->dir_y = 1.0;
    info->plane_x = 0.66;
    info->plane_y = 0.0;
    config->map[i][j] = '0';
}

void set_direction_and_plane(t_info *info, t_config *config, int i, int j)
{
    if (config->map[i][j] == 'N')
        set_direction_north(info, config, i, j);
    else if (config->map[i][j] == 'S')
        set_direction_south(info, config, i, j);
    else if (config->map[i][j] == 'W')
        set_direction_west(info, config, i, j);
    else if (config->map[i][j] == 'E')
        set_direction_east(info, config, i, j);
}

void set_start_position_and_direction(t_info *info, t_config *config)
{
    int i, j;
    find_start_position(info, config, &i, &j);
    set_direction_and_plane(info, config, i, j);
	info->move_speed = 0.1;
    info->rot_speed = 0.1;
}

void initialize_basic_fields(t_info *info, t_config *config)
{
    info->mlx = NULL;
    info->win = NULL;
    info->img.img = NULL;
    info->img.data = NULL;
    info->img.size_l = 0;
    info->img.bpp = 0;
    info->img.endian = 0;
    info->img.img_width = 0;
    info->img.img_height = 0;
	info->config = *config;
	info->camera_x = 0;
	info->raydir_x = 0;
	info->raydir_y = 0;
	info->sidedist_x = 0;
	info->sidedist_y = 0;
	info->map_x = 0;
	info->map_y = 0;
	info->deltadist_x = 0;
	info->deltadist_y = 0;
	info->perpwalldist = 0;
	info->step_x = 0;
	info->step_y = 0;
	info->hit = 0;
	info->side = 0;
}

void initialize_buffer(t_info *info)
{
    int x;
	int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            info->buf[y][x] = 0;
            x++;
        }
        y++;
    }
}

void initialize_texture(t_info *info)
{
    int x;
	int y;
	int i;

    if (!(info->texture = (int **)malloc(sizeof(int *) * 4)))
    {
        perror("Error allocating memory for texture");
		// free_resources(info); // 확인
 		// free_config(config);
        exit(1);  // You might want to replace this with proper error handling
    }
    i = 0;
    while (i < 4)    // Memory allocation for each row of the texture
    {
        if (!(info->texture[i] = (int *)malloc(sizeof(int) * (TEXTURE_WIDTH * TEXTURE_HEIGHT))))
        {
            perror("Error allocating memory for texture row");
			// free_resources(info);
			// free_config(config);
            exit(1);  // You might want to replace this with proper error handling
        }
        i++;
    }
    i = 0;
    while (i < 4)    // Initialize the texture
    {
        y = 0;
        while (y < TEXTURE_HEIGHT)
        {
            x = 0;
            while (x < TEXTURE_WIDTH)
            {
                info->texture[i][TEXTURE_WIDTH * y + x] = 0;
                x++;
            }
            y++;
        }
        i++;
    }
}


void initialize_s_info(t_info *info, t_config *config)
{
	set_start_position_and_direction(info, config);
	initialize_basic_fields(info, config);
	initialize_buffer(info);
	initialize_texture(info);
}

void free_resources(t_info *info)
{
	for (int i = 0; i < 4; i++)
	{
		free(info->texture[i]);
	}
	free(info->texture);
	if (info->img.img)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
}

int load_image(t_info *info, int *texture, char *path, t_img *img)
{
    img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	if (!img->img)  // Check if image loading was successful
    {
        perror("Error loading texture");
        return (0); // Return 0 to indicate failure
    }
    img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);

	int y = 0;
	while (y < img->img_height)
	{
		int x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
    mlx_destroy_image(info->mlx, img->img);
    return (1);
}

int load_texture_from_config(t_info *info, t_config *config)
{
    t_img img;

    if (!load_image(info, info->texture[0], config->north_texture, &img))
		return (0);
	if (!load_image(info, info->texture[1], config->south_texture, &img))
		return (0);
    if (!load_image(info, info->texture[2], config->west_texture, &img))
		return (0);
    if (!load_image(info, info->texture[3], config->east_texture, &img))
		return (0);
	printf("info->texture[0]: %d\n", info->texture[0][0]);
    return (1);
}

int rgb_to_int(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}

void paint_floor_and_ceiling(t_info *info)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->buf[y][x] = rgb_to_int(info->config.floor_color[0], info->config.floor_color[1], info->config.floor_color[2]);
			info->buf[HEIGHT - y - 1][x] = rgb_to_int(info->config.ceiling_color[0], info->config.ceiling_color[1], info->config.ceiling_color[2]);
			x++;
		}
		y++;
	}
}

void init_step_and_sideDist(t_info *info)
{
	if (info->raydir_x < 0) //만약 레이가 -x 방향으로 향하고 있다면,
	{
		info->step_x = -1;	//info->map_x는 현재 위치보다 1 작은 값이 됨
		info->sidedist_x = (info->pos_x - info->map_x) * info->deltadist_x;		//info->map_x+1-pos_x : 1 = sidedist_x : info->deltadist_x
	}
	else			//만약 레이가 -x 방향으로 향하고 있다면,
	{
		info->step_x = 1;	//info->map_x는 현재 위치보다 1 큰 값이 됨
		info->sidedist_x = (info->map_x + 1.0 - info->pos_x) * info->deltadist_x;	//pos_x-info->map_x : 1 = sidedist_x : info->deltadist_x
	}
	if (info->raydir_y < 0)
	{
		info->step_y = -1;
		info->sidedist_y = (info->pos_y - info->map_y) * info->deltadist_y;
	}
	else
	{
		info->step_y = 1;
		info->sidedist_y = (info->map_y + 1.0 - info->pos_y) * info->deltadist_y;
	}
}

void init_ray_map_deltaDist(t_info *info, int x)
{
	info->camera_x = 2 * x / (double)WIDTH - 1;
	info->raydir_x = info->dir_x + info->plane_x * info->camera_x;
	info->raydir_y = info->dir_y + info->plane_y * info->camera_x;
	info->map_x = (int)info->pos_x;								//레이의 위치 (여기선 일단 시작 지점 맵상의 x,y좌표)
	info->map_y = (int)info->pos_y;
	info->deltadist_x = fabs(1 / info->raydir_x);						// 레이가 x, y면에 부딪히기까지의 거리
	info->deltadist_y = fabs(1 / info->raydir_y);
}

void perform_DDA(t_info *info)
{
	info->hit = 0; // 벽에 부딪히지 않았다면 hit = 0
	while (info->hit == 0) //DDA 알고리즘 : 광선이 부딪힐 때까지 계속 광선을 한 칸씩 이동
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (info->sidedist_x < info->sidedist_y) // 만약 x면에 부딪히는 거리가 y면에 부딪히는 거리보다 짧다면, x면으로 이동
		{
			info->sidedist_x += info->deltadist_x; // 광선이 X 경계와 부딪혔으므로, 다음 X 경계까지의 거리를 계산하기 위해 info->deltadist_x를 더해줍니다.
			info->map_x += info->step_x;	// info->map_x(광선의 현재 위치)는 step_x(1 혹은 -1)만큼 증가
			info->side = 0;	// x면에 부딪힘
		}
		else						// 만약 y면에 부딪히는 거리가 x면에 부딪히는 거리보다 짧다면, y면으로 이동
		{
			info->sidedist_y += info->deltadist_y;
			info->map_y += info->step_y;
			info->side = 1;	// y면에 부딪힘
		}
		if (info->config.map[info->map_x][info->map_y] != '0') 			//광선이 벽에 부딪혔는지 확인 (에러 지점: seg fault)
			info->hit = 1; // 벽에 부딪혔다면 hit = 1
	}
}

void calc_variables_for_drawing(t_info *info, int *lineHeight, int *drawStart, int *drawEnd)
{
	if (info->side == 0)
		info->perpwalldist = (info->map_x - info->pos_x + (1 - info->step_x) / 2) / info->raydir_x;
	else
		info->perpwalldist = (info->map_y - info->pos_y + (1 - info->step_y) / 2) / info->raydir_y;

	*lineHeight = (int)(HEIGHT / info->perpwalldist); // use dereference
	*drawStart = -*lineHeight / 2 + HEIGHT / 2;  // use dereference
	if (*drawStart < 0)  // use dereference
		*drawStart = 0; // use dereference
	*drawEnd = *lineHeight / 2 + HEIGHT / 2;  // use dereference
	if (*drawEnd >= HEIGHT) // use dereference
		*drawEnd = HEIGHT - 1;  // use dereference
}

void determine_texNum_and_wallX(t_info *info, double *wallX, int *texNum)
{
	if (info->side == 0)
		{
			if (info->raydir_x > 0)
				*texNum = 1;	// S
			else
				*texNum = 0; // N
		}
		else
		{
			if (info->raydir_y > 0)
				*texNum = 3;	// E
			else
				*texNum = 2; // W
		}
		if (info->side == 0)										//만약 광선이 X면에 부딪혔다면
			*wallX = info->pos_y + info->perpwalldist * info->raydir_y;	//wallX는 광선이 시작된 Y 좌표와 광선의 Y 방향에 벽까지의 직교 거리를 곱한 값을 더해서 계산
		else												//Y면에 부딪혔다면
			*wallX = info->pos_x + info->perpwalldist * info->raydir_x;	//X 좌표와 광선의 X 방향에 벽까지의 직교 거리를 곱한 값을 더해서 계산
		*wallX -= floor(*wallX);								//그 후, wallX에서 floor(wallX)를 뺌으로써 wallX를 [0,1) 범위 안에 있게 만듭니다. 이렇게 하면 텍스처의 어느 부분이 화면에 그려져야 하는지 결정할 수 있음
}

void raycasting(t_info *info)
{
	double	wallX; // wallX 계산: 벽에 부딪힌 위치 계산 (텍스처 매핑을 위해)
	int		texNum;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;

	paint_floor_and_ceiling(info);
	for (int x = 0; x < WIDTH; x++)
	{
		init_ray_map_deltaDist(info, x);
		init_step_and_sideDist(info);
		perform_DDA(info);
		calc_variables_for_drawing(info, &lineHeight, &drawStart, &drawEnd);
		determine_texNum_and_wallX(info, &wallX, &texNum);
		int texX = (int)(wallX * (double)TEXTURE_WIDTH);		// 텍스처의 x 좌표 계산 (wallX 값을 텍스처의 너비로 스케일링해서 얻음)
		if ((info->side == 0 && info->raydir_x > 0) || (info->side == 1 && info->raydir_y < 0)) //광선 방향에 따라서 텍스처를 뒤집을 필요 확인. 이유는 벽의 다른 쪽면에 있는 텍스처가 화면에 반대로 나타나지 않게 하기 위함
			texX = TEXTURE_WIDTH - texX - 1;
		double step = 1.0 * TEXTURE_HEIGHT / lineHeight; //step은 화면의 각 픽셀에 대해서 텍스처의 어떤 Y 좌표를 사용해야 하는지 결정하는 값의 증가량. 벽의 높이와 텍스처의 높이의 비율을 사용해 계산
		double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;	//texPos는 텍스처에서의 시작 Y 좌표를 나타냅니다.
		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (TEXTURE_HEIGHT - 1);	//texY는 사용될 텍스처의 Y 좌표
			texPos += step;									//step을 더해서 다음 픽셀의 텍스처 Y 좌표를 계산

			int color = info->texture[texNum][TEXTURE_HEIGHT * texY + texX]; //텍스처에서 해당 좌표의 색상 값을 가져

			if (info->side == 1)
				color = (color >> 1) & 8355711;  // 만약 광선이 Y면에 부딪혔다면, 색상 값을 약간 어둡게 (시각효과, 필요한지 모르겠음)

			info->buf[y][x] = color;	//그 후, 해당 화면의 X, Y 좌표에 해당하는 버퍼에 색상 값을 저장
		}
	}
}

void drawing(t_info *info)
{
	for (int y = 0; y < HEIGHT; y++) // row (height) 훑기
		{
			for (int x = 0; x < WIDTH; x++)	// column (width) 훑기
			{
				// 화면의 2D 포인트 (x,y)를 'data' 배열의 1D 포인트로 매핑
				// 5x5 크기의 2D 배열의 경우, 첫 번째 행(즉, y=0)은 1D 인덱스 0부터 4까지 매핑. 두 번째 행(y=1)은 1D 인덱스 5부터 9까지 매핑
				// y * width로 계산된 시작 인덱스에 x를 더하면, 우리는 그 행에서 정확한 열의 원소의 1D 인덱스에 도달. 예: 5x5 배열에서 y=2, x=3의 2D 좌표는 2 * 5 + 3 = 13으로 1D 인덱스 13에 매핑
				info->img.data[y * WIDTH + x] = info->buf[y][x];
			}
		}
		mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0); // 이미지를 윈도우에 표시
}

int game_loop(t_info *info)
{
	raycasting(info);
	drawing(info);
	return (0);
}

int handle_keys(int keycode, t_info *info)
{
    if (keycode == K_ESC) // Assuming you have defined KEY_ESC for the escape key
    {
		free_config(&info->config);
        free_resources(info);
        exit(0);
    }
    if (keycode == K_W) // Move forward
    {
        if (info->config.map[(int)(info->pos_x + info->dir_x * info->move_speed)][(int)info->pos_y] == '0')
			info->pos_x += info->dir_x * info->move_speed;
		if (info->config.map[(int)info->pos_x][(int)(info->pos_y + info->dir_y * info->move_speed)] == '0')
			info->pos_y += info->dir_y * info->move_speed;
	}
	if (keycode == K_S) // Move backward
	{
		if (info->config.map[(int)(info->pos_x - info->dir_x * info->move_speed)][(int)info->pos_y] == '0')
			info->pos_x -= info->dir_x * info->move_speed;
		if (info->config.map[(int)info->pos_x][(int)(info->pos_y - info->dir_y * info->move_speed)] == '0')
			info->pos_y -= info->dir_y * info->move_speed;
	}
	if (keycode == K_A) // Move left
	{
		double oldDirX = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rot_speed) - info->dir_y * sin(info->rot_speed);
		info->dir_y = oldDirX * sin(info->rot_speed) + info->dir_y * cos(info->rot_speed);
		double oldPlaneX = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y * sin(info->rot_speed);
		info->plane_y = oldPlaneX * sin(info->rot_speed) + info->plane_y * cos(info->rot_speed);
	}
	if (keycode == K_D) // Move right
	{
		double oldDirX = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed) - info->dir_y * sin(-info->rot_speed);
		info->dir_y = oldDirX * sin(-info->rot_speed) + info->dir_y * cos(-info->rot_speed);
		double oldPlaneX = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y * sin(-info->rot_speed);
		info->plane_y = oldPlaneX * sin(-info->rot_speed) + info->plane_y * cos(-info->rot_speed);
	}
    return (0);
}

int	main(int argc, char **argv)
{
	t_config	*s_config;
	t_info		s_info;

	atexit(check_leaks);
	if (check_args(argc, argv) == 0)
		return (0);
	s_config = parse_config(argv[1]);
	if (s_config->error == 1)
	{
		ft_putstr("Error\n", 2);
		free_config(s_config);
		free(s_config);
		return (1);
	}
	print_config(s_config);
	initialize_s_info(&s_info, s_config); // 구조체 초기화 (게임 정보)
	s_info.mlx = mlx_init();	//mlx_init: void * 타입의 포인터 연결 식별자로 반환
	if (!load_texture_from_config(&s_info, s_config))
	{
		perror("Error: Failed to load textures");
		// Cleanup and free resources.
		// Assuming you have a function named free_resources or similar.
		free_resources(&s_info);
		free_config(s_config);
		free(s_config);
		exit (1);
	}

	// Assuming the window size is defined by the constants width and height.
	s_info.win = mlx_new_window(s_info.mlx, WIDTH, HEIGHT, "cub3D");
	if (!s_info.win)
	{
		perror("Error: Failed to create window");
		// Cleanup and free resources.
		free_resources(&s_info);
		free_config(s_config);
		free(s_config);
		exit (1);
	}

	s_info.img.img = mlx_new_image(s_info.mlx, WIDTH, HEIGHT); // 이미지 식별자 생성

	s_info.img.data = (int *)mlx_get_data_addr(s_info.img.img, &s_info.img.bpp, &s_info.img.size_l, &s_info.img.endian);

	mlx_loop_hook(s_info.mlx, &game_loop, &s_info); 	//메인 루프에서 반복적으로 호출되는 함수 설정

    // Set key input function
	//mlx_key_hook(s_info.win, handle_keys, &s_info);
	mlx_hook(s_info.win, X_EVENT_KEY_PRESS, 0, &handle_keys, &s_info);

	//Start the event loop. This will keep your game running.
	mlx_loop(s_info.mlx);

	// // If your program somehow gets here, cleanup and end.
	// // However, usually mlx_loop only ends when the program closes.

	free_config(s_config);
	free_resources(&s_info);
	free(s_config);
	return (0);
}
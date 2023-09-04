/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:02:59 by dkham             #+#    #+#             */
/*   Updated: 2023/09/04 21:37:19 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_macos.h"

void initialize_s_info(t_info *info, t_config *config)
{
    // Initialize position, direction, and plane
    info->posX = 22.0;
    info->posY = 11.5;
    info->dirX = -1.0;
    info->dirY = 0.0;
    info->planeX = 0.0;
    info->planeY = 0.66;

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

	// Initialize config
	info->config = *config;

    // Initialize buffer - considering height and width are constants
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            info->buf[y][x] = 0;
        }
    }

    // Initialize texture - Assuming a total of 4 textures based on previous info
    if (!(info->texture = (int **)malloc(sizeof(int *) * 4)))
	{
		perror("Error allocating memory for texture");
		exit(1);
	}
	for (int i = 0; i < 4; i++)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * (TEXTURE_WIDTH * TEXTURE_HEIGHT))))
		{
			perror("Error allocating memory for texture");
			exit(1);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int y = 0; y < TEXTURE_HEIGHT; y++)
		{
			for (int x = 0; x < TEXTURE_WIDTH; x++)
			{
				info->texture[i][TEXTURE_WIDTH * y + x] = 0;
			}
		}
	}
    info->moveSpeed = 0.05;  // Set to a default value if you have one.
    info->rotSpeed = 0.05;   // Set to a default value if you have one.
}

void free_resources(t_info *info, t_config *config)
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
	if (config->north_texture)
		free(config->north_texture);
	if (config->south_texture)
		free(config->south_texture);
	if (config->west_texture)
		free(config->west_texture);
	if (config->east_texture)
		free(config->east_texture);
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
    for (int y = 0; y < img->img_height; y++)
    {
        for (int x = 0; x < img->img_width; x++)
        {
            texture[img->img_width * y + x] = img->data[img->img_width * y + x];
        }
    }
    mlx_destroy_image(info->mlx, img->img);
    return (1); // Return 1 to indicate success
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
    return (1);
}

int rgb_to_int(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}

int game_loop(t_info *info)//, t_config *config)
{
	for (int y = 0; y < height; y++)     // 버퍼 초기화
    {
        for (int x = 0; x < width; x++)
        {
            info->buf[y][x] = 0;
        }
    }
	// 천장과 바닥은 int floor_color[3];, int ceiling_color[3]으로 저장된 RGB값을 이용하여 색칠한다.
	// 동서남북 벽의 경우 텍스쳐를 이용하여 색칠한다. info->texture[0] = N / [1] = S / [2] = W / [3] = E
	for (int x = 0; x < width; x++)
	{
		double cameraX = 2 * x / (double)width - 1;
		double rayDirX = info->dirX + info->planeX * cameraX;
		double rayDirY = info->dirY + info->planeY * cameraX;

		int mapX = (int)info->posX;								//레이의 위치 (여기선 일단 시작 지점 맵상의 x,y좌표)
		int mapY = (int)info->posY;

		double sideDistX;										// 레이가 x, y면에 부딪히기까지의 거리
		double sideDistY;

		double deltaDistX = fabs(1 / rayDirX);					// 레이가 x, y면에 부딪히기까지의 거리
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;									//플레이어 위치부터 레이가 벽과 충돌한 지점까지의 직교 거리

		int stepX;												//x, y 방향으로 얼마나 가야하는지 (만약 rayDirX/Y가 음수면 -1, 아니면 1) : mapX/Y를 업데이트 위해 사용
		int stepY;
		
		int hit = 0; 											//was there a wall hit?
		int side; 												//was a NS or a EW wall hit?

		if (rayDirX < 0) //만약 레이가 -x 방향으로 향하고 있다면,
		{
			stepX = -1;	//mapX는 현재 위치보다 1 작은 값이 됨
			sideDistX = (info->posX - mapX) * deltaDistX;		//mapX+1-posX : 1 = sideDistX : deltaDistX
		}
		else			//만약 레이가 -x 방향으로 향하고 있다면,
		{
			stepX = 1;	//mapX는 현재 위치보다 1 큰 값이 됨
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;	//posx-mapx : 1 = sideDistX : deltaDistX
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}
		while (hit == 0) //DDA 알고리즘 : 광선이 부딪힐 때까지 계속 광선을 한 칸씩 이동
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY) // 만약 x면에 부딪히는 거리가 y면에 부딪히는 거리보다 짧다면, x면으로 이동
			{
				sideDistX += deltaDistX; // 광선이 X 경계와 부딪혔으므로, 다음 X 경계까지의 거리를 계산하기 위해 deltaDistX를 더해줍니다.
				mapX += stepX;	// mapX(광선의 현재 위치)는 stepX(1 혹은 -1)만큼 증가
				side = 0;	// x면에 부딪힘
			}
			else						// 만약 y면에 부딪히는 거리가 x면에 부딪히는 거리보다 짧다면, y면으로 이동
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;	// y면에 부딪힘
			}
			if (info->config.map[mapX][mapY] == 1) 			//광선이 벽에 부딪혔는지 확인
				hit = 1; // 벽에 부딪혔다면 hit = 1
		}
		if (side == 0)	// 만약 x면에 부딪혔다면,
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
			// 
		else			// 만약 y면에 부딪혔다면,
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(height / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + height / 2; //drawStart의 역할: 
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if(drawEnd >= height)
			drawEnd = height - 1;
		

		// 천장과 바닥 색칠
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				if (y < height / 2)	// 천장
					info->buf[y][x] = rgb_to_int(info->config.ceiling_color[0], info->config.ceiling_color[1], info->config.ceiling_color[2]);
				else	// 바닥
					info->buf[y][x] = rgb_to_int(info->config.floor_color[0], info->config.floor_color[1], info->config.floor_color[2]);
			}
		}

		// 광선이 부딪힌 벽의 방향에 따라 사용할 텍스처를 결정합니다.
		int texNum;
		if (side == 0)   // x면에 부딪혔다면
		{
			if (rayDirX > 0)
				texNum = 2;  // West
			else
				texNum = 3;  // East
		}
		else  			// y면에 부딪혔다면
		{
			if (rayDirY > 0)
				texNum = 0;  // North
			else
				texNum = 1;  // South
		}
		double wallX; // wallX 계산: 벽에 부딪힌 위치 계산 (텍스처 매핑을 위해)
		if (side == 0)										//만약 광선이 X면에 부딪혔다면
			wallX = info->posY + perpWallDist * rayDirY;	//wallX는 광선이 시작된 Y 좌표와 광선의 Y 방향에 벽까지의 직교 거리를 곱한 값을 더해서 계산
		else												//Y면에 부딪혔다면
			wallX = info->posX + perpWallDist * rayDirX;	//X 좌표와 광선의 X 방향에 벽까지의 직교 거리를 곱한 값을 더해서 계산
		wallX -= floor(wallX);								//그 후, wallX에서 floor(wallX)를 뺌으로써 wallX를 [0,1) 범위 안에 있게 만듭니다. 이렇게 하면 텍스처의 어느 부분이 화면에 그려져야 하는지 결정할 수 있음

		int texX = (int)(wallX * (double)TEXTURE_WIDTH);		// 텍스처의 x 좌표 계산 (wallX 값을 텍스처의 너비로 스케일링해서 얻음)
		if ((side == 0 && rayDirX > 0) || (side == 1 && rayDirY < 0)) //광선 방향에 따라서 텍스처를 뒤집을 필요 확인. 이유는 벽의 다른 쪽면에 있는 텍스처가 화면에 반대로 나타나지 않게 하기 위함
			texX = TEXTURE_WIDTH - texX - 1;

		// 화면의 각 픽셀에 대한 텍스처의 Y 좌표를 계산하기 위한 step 및 texPos 값 설정
		double step = 1.0 * TEXTURE_HEIGHT / lineHeight; //step은 화면의 각 픽셀에 대해서 텍스처의 어떤 Y 좌표를 사용해야 하는지 결정하는 값의 증가량. 벽의 높이와 텍스처의 높이의 비율을 사용해 계산
		double texPos = (drawStart - height / 2 + lineHeight / 2) * step;	//texPos는 텍스처에서의 시작 Y 좌표를 나타냅니다.

		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (TEXTURE_HEIGHT - 1);	//texY는 사용될 텍스처의 Y 좌표
			texPos += step;									//step을 더해서 다음 픽셀의 텍스처 Y 좌표를 계산

			int color = info->texture[texNum][TEXTURE_HEIGHT * texY + texX]; //텍스처에서 해당 좌표의 색상 값을 가져

			if (side == 1)
				color = (color >> 1) & 8355711;  // 만약 광선이 Y면에 부딪혔다면, 색상 값을 약간 어둡게 (시각효과, 필요한지 모르겠음)

			info->buf[y][x] = color;	//그 후, 해당 화면의 X, Y 좌표에 해당하는 버퍼에 색상 값을 저장
		}
		
		for (int y = 0; y < height; y++) // row (height) 훑기
		{
			for (int x = 0; x < width; x++)	// column (width) 훑기
			{
				// 화면의 2D 포인트 (x,y)를 'data' 배열의 1D 포인트로 매핑
				// 5x5 크기의 2D 배열의 경우, 첫 번째 행(즉, y=0)은 1D 인덱스 0부터 4까지 매핑. 두 번째 행(y=1)은 1D 인덱스 5부터 9까지 매핑
				// y * width로 계산된 시작 인덱스에 x를 더하면, 우리는 그 행에서 정확한 열의 원소의 1D 인덱스에 도달. 예: 5x5 배열에서 y=2, x=3의 2D 좌표는 2 * 5 + 3 = 13으로 1D 인덱스 13에 매핑
				info->img.data[y * width + x] = info->buf[y][x];
			}
		}
		mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0); // 이미지를 윈도우에 표시
	}
	return (0);
}

int handle_keys(int keycode, t_info *info)
{
    if (keycode == K_ESC) // Assuming you have defined KEY_ESC for the escape key
    {
        free_resources(info, &info->config);
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
	//t_img		s_img;
	
	if (check_args(argc, argv) == 0)
		return (0);
	s_config = parse_config(argv[1]); // 파싱 부분 (chanwoki)
	if (!s_config)
	{
		perror("Error: Failed to parse config file");
		exit(1);
	}
	initialize_s_info(&s_info, s_config); // 구조체 초기화 (게임 정보)
	s_info.mlx = mlx_init();	//mlx_init: void * 타입의 포인터 연결 식별자로 반환
	if (!load_texture_from_config(&s_info, s_config))
	{
		perror("Error: Failed to load textures");
		// Cleanup and free resources.
		// Assuming you have a function named free_resources or similar.
		free_resources(&s_info, s_config);
		return (0);
	}
	// Assuming the window size is defined by the constants width and height.
	s_info.win = mlx_new_window(s_info.mlx, width, height, "cub3D");
	if (!s_info.win)
	{
		perror("Error: Failed to create window");
		// Cleanup and free resources.
		free_resources(&s_info, s_config);
		return (0);
	}
	s_info.img.img = mlx_new_image(s_info.mlx, width, height); // 이미지 식별자 생성

	s_info.img.data = (int *)mlx_get_data_addr(s_info.img.img, &s_info.img.bpp, &s_info.img.size_l, &s_info.img.endian);

	mlx_loop_hook(s_info.mlx, &game_loop, &s_info); 	//메인 루프에서 반복적으로 호출되는 함수 설정

    // Set key input function
	mlx_key_hook(s_info.win, handle_keys, &s_info);
	
	//Start the event loop. This will keep your game running.
	mlx_loop(s_info.mlx);

	// // If your program somehow gets here, cleanup and end.
	// // However, usually mlx_loop only ends when the program closes.
	free_resources(&s_info, s_config);
	return (0);
}

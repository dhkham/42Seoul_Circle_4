/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:53:20 by yohlee            #+#    #+#             */
/*   Updated: 2023/09/03 18:19:30 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc temp.c -Lmlx -lmlx -framework OpenGL -framework Appkit

#include "mlx/mlx.h"
#include "key_macos.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define width 640
#define height 480

typedef struct	s_img	
{
	void	*img;	// 이미지 식별자
	int		*data;	// 픽셀 데이터

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;	// 이미지 정보 (mlx 위해 필요)

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[height][width];
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;	// 게임/플레이어 정보

int	worldMap[mapWidth][mapHeight] =	// 맵 정보 (숫자는 다른 텍스쳐 뜻함)
									{
										{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
										{8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
										{8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
										{7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
										{7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
										{2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
										{2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
										{2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
										{1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
										{2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
										{2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
									};

void	draw(t_info *info)
{
	for (int y = 0; y < height; y++) // row (height) 훑기
	{
		for (int x = 0; x < width; x++)	// column (width) 훑기
		{
			// 화면의 2D 포인트 (x,y)를 'data' 배열의 1D 포인트로 매핑
            // 'data' 배열은 픽셀 데이터를 선형 방식으로 보유하고 있습니다.
            // 5x5 크기의 2D 배열을 생각해보세요. 첫 번째 행(즉, y=0)은 1D 인덱스 0부터 4까지 매핑됩니다. 두 번째 행(y=1)은 1D 인덱스 5부터 9까지 매핑
			// y * width로 계산된 시작 인덱스에 x를 더하면, 우리는 그 행에서 정확한 열의 원소의 1D 인덱스에 도달
			// 예를 들어, 위의 5x5 배열에서 y=2, x=3의 2D 좌표는 2 * 5 + 3 = 13으로 1D 인덱스 13에 매핑
			info->img.data[y * width + x] = info->buf[y][x];
			//copies the content of the buffer (which holds the pixel data to be shown on screen) to an image and then displays the image in the window.
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0); // 이미지를 윈도우에 표시
}

void	calc(t_info *info)
{
	//FLOOR CASTING
	for (int y = 0; y < height; y++)
	{
		// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		float rayDirX0 = info->dirX - info->planeX;
		float rayDirY0 = info->dirY - info->planeY;
		float rayDirX1 = info->dirX + info->planeX;
		float rayDirY1 = info->dirY + info->planeY;

		// Current y position compared to the center of the screen (the horizon)
		int p = y - height / 2;

		// Vertical position of the camera.
		float posZ = 0.5 * height;

		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float rowDistance = posZ / p;

		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / width;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / width;

		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		float floorX = info->posX + rowDistance * rayDirX0;
		float floorY = info->posY + rowDistance * rayDirY0;

		for (int x = 0; x < width; ++x)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);

			// get the texture coordinate from the fractional part
			int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
			int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			// choose texture and draw the pixel
			int floorTexture = 3;
			int ceilingTexture = 6;

			int color;

			// floor
			color = info->texture[floorTexture][texWidth * ty + tx];
			color = (color >> 1) & 8355711; // make a bit darker

			info->buf[y][x] = color;

			//ceiling (symmetrical, at screenHeight - y - 1 instead of y)
			color = info->texture[ceilingTexture][texWidth * ty + tx];
			color = (color >> 1) & 8355711; // make a bit darker

			info->buf[height - y - 1][x] = color;
		}
	}
	//WALL CASTING
	for (int x = 0; x < width; x++) // x좌표, 즉 세로선을 훑기
	{
		double cameraX = 2 * x / (double)width - 1; 			//x-coordinate in camera space (화면 왼쪽 끝이 -1, 오른쪽 끝이 1)
																//화면의 x 좌표(x)를 width로 나누어주면 x는 0부터 1 사이의 값이 됨.
																//화면의 왼쪽 끝에서는 x = 0, 화면의 오른쪽 끝에서는 x = width 이므로, 왼쪽 끝에서는 0, 오른쪽 끝에서는 1이 됨
																//이 값을 2배로 곱하면 값의 범위는 0에서 2가 됩니다. 이전 단계의 결과에서 1을 뺍니다. 이를 통해 값의 범위는 -1부터 1 사이로 변경
																//따라서, 화면의 왼쪽 끝에서는 cameraX 값이 -1이 되고, 오른쪽 끝에서는 cameraX 값이 1이 됨
																//화면의 중앙에서는 cameraX 값이 0이 됨
																//이렇게 변환된 cameraX 값은 시야의 중심에서의 레이 방향을 얼마나 이탈할 것인지를 나타냅니다. 
																//이 cameraX 값은 실제 레이의 방향을 계산하는 데 사용되며, 이를 통해 화면에 어떤 부분이 표시될 것인지 결정하게 됩니다.
		double rayDirX = info->dirX + info->planeX * cameraX;	//레이의 방향벡터: x방향
		double rayDirY = info->dirY + info->planeY * cameraX;	//레이의 방향벡터: y방향
		
		int mapX = (int)info->posX;								//레이의 위치 (여기선 일단 시작 지점 맵상의 x,y좌표)
		int mapY = (int)info->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;										// 레이가 x, y면에 부딪히기까지의 거리
		double sideDistY;										
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		/*
		원래 식: deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
		이는 deltaDistX = abs(|v| / rayDirX) 와 같다. |v|는 rayDir 벡터의 길이이다.
		여기서 실제 길이는 중요하지 않고, rayDirX와 rayDirY의 비율만 중요하다.
		(deltaDist 값을 이용해 나중에 계산하는 sideDist 역시 비율만 중요하다. 둘 중 더 작은 값을 선택해 그 방향으로 광선을 한 칸씩 이동시키기 때문)
		고로 최적화를 위해 abs(1/rayDirX)로 바꿀 수 있다. 1 / rayDirX는 레이가 x 그리드를 건너는 데 얼마나 멀리 이동해야 하는지를 나타내는 값이다.
		*/
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;					//플레이어 위치부터 레이가 벽과 충돌한 지점까지의 직교 거리
		
		int stepX;								//x, y 방향으로 얼마나 가야하는지 (만약 rayDirX/Y가 음수면 -1, 아니면 1) : mapX/Y를 업데이트 위해 사용
		int stepY;
		
		int hit = 0; 	//was there a wall hit?
		int side; 		//was a NS or a EW wall hit?

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
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) hit = 1; // 만약 광선의 위치가 벽이라면, hit = 1
		}
		/*
		레이캐스팅의 주된 목적 중 하나는 광선이 어디에서 벽에 부딪히는지 정확한 위치를 파악하는 것입니다. 
		맵은 2D 그리드로 이루어져 있고, 각 그리드 셀은 벽 또는 빈 공간일 수 있습니다. 
		레이가 플레이어의 위치에서 발사되어 벽에 처음 부딪힐 때까지의 최단 거리를 계산해야 합니다.

		이제 stepX 값을 고려해봅시다. 광선이 왼쪽으로 발사되면 stepX는 -1이 됩니다. 그리고 광선이 왼쪽으로 진행함에 따라 x 좌표는 줄어들게 됩니다. 
		이러한 상황에서 광선이 x 좌표에 부딪힌다면, 그 광선은 해당 그리드 셀의 오른쪽 경계에 부딪힌 것입니다.

		예를 들어, 플레이어가 2.7의 x 좌표에 있고 광선이 왼쪽으로 발사된다면, 광선은 x=2의 위치, 즉 그리드 셀의 오른쪽 경계에 처음 부딪히게 됩니다.

		그런데 실제 계산에서는 그리드의 정확한 경계 위치, 즉 정수 좌표를 사용하여 mapX 값을 결정하게 됩니다. 
		이 때문에, 실제 플레이어의 위치와 mapX 사이의 거리를 계산할 때, 해당 그리드 셀의 중앙을 기준으로 보정 값을 더하거나 빼야 합니다.

		이러한 보정은 (1 - stepX) / 2 식을 통해 이루어집니다.
		stepX가 -1일 때 (즉, 광선이 왼쪽을 향할 때), 이 식은 1이 됩니다.
		(보정 이유:광선이 왼쪽으로 이동하면서 그리드의 경계에 도달했을 때, mapX의 값은 1 감소하게 됩니다.
		이 때 광선이 부딪힌 그리드 경계는 현재 mapX의 오른쪽 경계입니다. 따라서 부딪힌 위치는 mapX의 좌표에서 얼마나 떨어져 있는지를 계산하기 위해 보정값 1을 더해줍니다.)
		이 값은 광선이 해당 그리드 셀의 오른쪽 경계에 부딪힌 것을 반영합니다.
		만약 stepX가 1이라면 (광선이 오른쪽을 향할 때), 식의 결과는 0이 되며, 
		이는 광선이 해당 그리드 셀의 왼쪽 경계에 부딪히게 되는 것을 반영합니다.
		*/
		if (side == 0)	// 만약 x면에 부딪혔다면,
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
			// 
		else			// 만약 y면에 부딪혔다면,
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(height / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if(drawEnd >= height)
			drawEnd = height - 1;

		// texturing calculations
		int texNum = worldMap[mapX][mapY] - 1;

		// calculate value of wallX
		double wallX;
		if (side == 0)
			wallX = info->posY + perpWallDist * rayDirY;
		else
			wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		// x coordinate on the texture
		int texX = (int)(wallX * (double)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;

		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHeight / lineHeight;

		// Starting texture coordinate
		double texPos = (drawStart - height / 2 + lineHeight / 2) * step;

		for (int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;

			int color = info->texture[texNum][texHeight * texY + texX];

			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (side == 1)
				color = (color >> 1) & 8355711;

			info->buf[y][x] = color;
		}

		//FLOOR CASTING (vertical version, directly after drawing the vertical wall stripe for the current x)
		double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall

		//4 different wall directions possible
		if(side == 0 && rayDirX > 0)
		{
			floorXWall = mapX;
			floorYWall = mapY + wallX;
		}
		else if(side == 0 && rayDirX < 0)
		{
			floorXWall = mapX + 1.0;
			floorYWall = mapY + wallX;
		}
		else if(side == 1 && rayDirY > 0)
		{
			floorXWall = mapX + wallX;
			floorYWall = mapY;
		}
		else
		{
			floorXWall = mapX + wallX;
			floorYWall = mapY + 1.0;
		}

		double distWall, distPlayer, currentDist;

		distWall = perpWallDist;
		distPlayer = 0.0;

		if (drawEnd < 0) drawEnd = height; //becomes < 0 when the integer overflows

		//draw the floor from drawEnd to the bottom of the screen
		for(int y = drawEnd + 1; y < height; y++)
		{
			currentDist = height / (2.0 * y - height); //you could make a small lookup table for this instead

			double weight = (currentDist - distPlayer) / (distWall - distPlayer);

			double currentFloorX = weight * floorXWall + (1.0 - weight) * info->posX;
			double currentFloorY = weight * floorYWall + (1.0 - weight) * info->posY;

			int floorTexX, floorTexY;
			floorTexX = (int)(currentFloorX * texWidth) % texWidth;
			floorTexY = (int)(currentFloorY * texHeight) % texHeight;

			int checkerBoardPattern = ((int)(currentFloorX) + (int)(currentFloorY)) % 2;
			int floorTexture;
			if(checkerBoardPattern == 0) floorTexture = 3;
			else floorTexture = 4;

			//floor
			info->buf[y][x] = (info->texture[floorTexture][texWidth * floorTexY + floorTexX] >> 1) & 8355711;
			//ceiling (symmetrical!)
			info->buf[height - y][x] = info->texture[6][texWidth * floorTexY + floorTexX];
		}
	}
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == K_W)
	{
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
	load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
	load_image(info, info->texture[3], "textures/greystone.xpm", &img);
	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
	load_image(info, info->texture[6], "textures/wood.xpm", &img);
	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
}

int	main(void)
{
	t_info info;
	
	/*
	mlx_init();
	mlx_new_window(mlx, 600, 400, "miniRT");
	mlx_new_image(mlx, 600, 400);
	mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	*/
	info.mlx = mlx_init(); // mlx_init() : connection identifier를 반환

	info.posX = 22.0; //기본값
	info.posY = 11.5;
	info.dirX = -1.0;
	info.dirY = 0.0;
	info.planeX = 0.0;
	info.planeY = 0.66;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			info.buf[i][j] = 0;
		}
	}

	if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	for (int i = 0; i < 8; i++)
	{
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			info.texture[i][j] = 0;
		}
	}

	load_texture(&info);

	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;
	
	info.win = mlx_new_window(info.mlx, width, height, "mlx");

	info.img.img = mlx_new_image(info.mlx, width, height);

	
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	// 여기까지 완료

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

	mlx_loop(info.mlx);
}

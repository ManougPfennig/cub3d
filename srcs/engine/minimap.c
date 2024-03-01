/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:35:05 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/01 17:44:31 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	big_pixel_put(t_img *img, int x, int y, int color)
{
	int	px;
	int	py;

	py = MAPSIZE;
	while (py >= 0)
	{
		px = MAPSIZE;
		while (px >= 0)
		{
			pixel_put(img, (x * MAPSIZE) + px, (y * MAPSIZE) + py, color);
			px--;	
		}
		py--;
	}
}

void	make_minimap(t_cub *cub, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '1')
				big_pixel_put(img, x, y, 0x00000FFF);
			if (cub->map[y][x] == '0')
				big_pixel_put(img, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
	return ;
}

void	display_player(t_cub *cub)
{
	t_img	*img;

	img = init_img();
	setup_img(cub, img, MAPSIZE, MAPSIZE);
	color_img(img, 0x00FF0000, MAPSIZE, MAPSIZE);
	mlx_put_image_to_window(cub->mlx, cub->win, img, ((int)cub->pos[0] * MAPSIZE), ((int)cub->pos[1] * MAPSIZE));
}

void	display_minimap(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img_map, 0, 0);
	display_player(cub);
	return ;
}
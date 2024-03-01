/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:35:05 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/01 02:32:11 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	big_pixel_put(t_img *img, int x, int y, int color)
{
	int	px;
	int	py;

	py = MINIMAPSIZE;
	while (py >= 0)
	{
		px = MINIMAPSIZE;
		while (px >= 0)
		{
			pixel_put(img, (x * MINIMAPSIZE) + px, (y * MINIMAPSIZE) + py, color);
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

void	display_minimap(t_cub *cub, t_img *img)
{
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img_map, 0, 0);
	big_pixel_put(img, (int)cub->pos[0], (int)cub->pos[1], 0xFFFF0000);
	return ;
}
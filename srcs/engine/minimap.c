/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:35:05 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/02 21:06:53 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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

void	display_minimap(t_cub *cub, t_img *frame)
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
				big_pixel_put(frame, x, y, BLUE);
			else if (cub->map[y][x] == '0')
				big_pixel_put(frame, x, y, WHITE);
			x++;
		}
		y++;
	}
	big_pixel_put(frame, (int)cub->pos[0], (int)cub->pos[1], RED);
	return ;
}
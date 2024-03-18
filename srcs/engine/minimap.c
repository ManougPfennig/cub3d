/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:35:05 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/18 14:19:16 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	toggle_map_display(t_cub *cub)
{
	if (cub->toggle_map == 1)
		cub->toggle_map = 0;
	else if (cub->toggle_map == 0)
		cub->toggle_map = 1;
	return ;
}

void	big_pixel_put(t_img *img, int x, int y, int color)
{
	int	px;
	int	py;

	py = MAPSIZE;
	while (py > 0)
	{
		px = MAPSIZE;
		while (px > 0)
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

	x = 0;
	while (cub->map[x])
	{
		y = 0;
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == '1')
				big_pixel_put(frame, x, y, BLUE);
			else if (cub->map[x][y] == '0')
				big_pixel_put(frame, x, y, WHITE);
			y++;
		}
		x++;
	}
	big_pixel_put(frame, (int)cub->pos[0], (int)cub->pos[1], RED);
	return ;
}

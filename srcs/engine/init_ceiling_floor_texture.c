/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ceiling_floor_texture.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:34 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/01 17:33:58 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	rgb_to_hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	color_img(t_img *img, int color, int length, int height)
{
	int		x;
	int		y;

	y = height;
	while (y >= 0)
	{
		x = length;
		while (x >= 0)
		{
			pixel_put(img, x, y, color);
			x--;
		}
		y--;
	}
}

void	init_ceiling_floor_texture(t_cub *cub)
{
	int	color;

	cub->ceiling = init_img();
	cub->floor = init_img();
	setup_img(cub, cub->ceiling, (WIN_LENGTH), (WIN_HEIGHT / 2));
	setup_img(cub, cub->floor, (WIN_LENGTH), (WIN_HEIGHT / 2));
	color = rgb_to_hex(cub->c->r, cub->c->g, cub->c->b);
	color_img(cub->ceiling, color, (WIN_LENGTH), (WIN_HEIGHT / 2));
	color = rgb_to_hex(cub->f->r, cub->f->g, cub->f->b);
	color_img(cub->floor, color, (WIN_LENGTH), (WIN_HEIGHT / 2));
}

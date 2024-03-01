/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ceiling_floor_texture.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:34 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/01 17:21:03 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	rgb_to_hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	color_img(t_img *img, t_color *rgb, int length, int height)
{
	int		color;
	int		x;
	int		y;

	color = rgb_to_hex(rgb->r, rgb->g, rgb->b);
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
	cub->ceiling = init_img();
	cub->floor = init_img();
	setup_img(cub, cub->ceiling, (WIN_LENGTH), (WIN_HEIGHT / 2));
	setup_img(cub, cub->floor, (WIN_LENGTH), (WIN_HEIGHT / 2));
	color_img(cub->ceiling, cub->c, (WIN_LENGTH), (WIN_HEIGHT / 2));
	color_img(cub->floor, cub->f, (WIN_LENGTH), (WIN_HEIGHT / 2));
}
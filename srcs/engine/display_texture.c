/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:24:58 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/19 10:54:06 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

t_img	*which_texture(t_cub *cub, int texture)
{
	if (texture == N_WALL)
		return (cub->txtr->no);
	if (texture == S_WALL)
		return (cub->txtr->so);
	if (texture == E_WALL)
		return (cub->txtr->ea);
	if (texture == W_WALL)
		return (cub->txtr->we);
	return (NULL);
}

void	init_wall_size(t_draw *draw, double distance)
{
	draw->height = (int)(WIN_HEIGHT / distance);
	draw->start_y = (-(draw->height) / 2) + (WIN_HEIGHT / 2);
	draw->end_y = ((draw->height) / 2) + (WIN_HEIGHT / 2);
}

void	drawn(t_draw *draw, t_img *img, int col, t_cub *cub)
{
	int		y;
	double	step;
	double	y_texture;
	t_img	*tx;
	t_ray	*ray;

	ray = cub->ray;
	y_texture = 0;
	tx = which_texture(cub, ray->type);
	step = (double)((double)tx->height / \
	(double)(draw->end_y - draw->start_y));
	if (draw->start_y < 0)
	{
		y_texture = step * draw->start_y * -1;
		draw->start_y = 0;
	}
	y = draw->start_y;
	while (y <= draw->end_y)
	{
		if (y >= WIN_HEIGHT - 1)
			break ;
		pixel_put(img, col, y, gc(tx, (int)(ray->line * tx->width), y_texture));
		y++;
		y_texture += step;
	}
}

void	display_texture(t_cub *cub, t_img *img, t_ray *ray, int col)
{
	t_draw	draw;

	init_wall_size(&draw, ray->distance);
	drawn(&draw, img, col, cub);
}

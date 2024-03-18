/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:24:58 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/18 21:17:40 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	init_wall_size(t_draw *draw, double distance)
{
	draw->height = (int)(WIN_HEIGHT / distance);
	draw->start_y = (-(draw->height) / 2) + (WIN_HEIGHT / 2);
	if (draw->start_y < 0)
		draw->start_y = 0;
	draw->end_y = ((draw->height) / 2) + (WIN_HEIGHT / 2);
	if (draw->end_y >= WIN_HEIGHT)
		draw->end_y = WIN_HEIGHT - 1;
}

void	draw_on_column(t_draw *draw, t_ray *ray, t_img *frame, int column)
{
	int	i;

	i = draw->start_y;
	while (i <= draw->end_y)
	{
		if (ray->type == N_WALL)
			pixel_put(frame, column, i, BLUE * ray->line);
		else if (ray->type == S_WALL)
			pixel_put(frame, column, i, BLUE * ray->line);
		else if (ray->type == E_WALL)
			pixel_put(frame, column, i, BLUE * ray->line);
		else if (ray->type == W_WALL)
			pixel_put(frame, column, i, BLUE * ray->line);
		i++;
	}
}

void	display_texture(t_cub *cub, t_img *frame, t_ray *ray, int column)
{
	t_draw	draw;

	(void)cub;
	init_wall_size(&draw, ray->distance);
	draw_on_column(&draw, ray, frame, column);
}
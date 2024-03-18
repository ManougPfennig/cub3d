/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:24:58 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/18 21:44:03 by mapfenni         ###   ########.fr       */
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

void    draw_on_column(t_draw *draw, t_ray *ray, t_img *frame, int column, t_cub *cub)
{
	int		y;
    double	step;
    double	y_texture;
	t_img	*texture;
    
    y_texture = 0;
	texture = which_texture(cub, ray->type);
    step = (double)((double)texture->height / (double)(draw->end_y - draw->start_y));
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
        pixel_put(frame, column, y, get_color(texture, (int)(ray->line * texture->width), y_texture));
        y++;
        y_texture += step;
    }
}

void	display_texture(t_cub *cub, t_img *frame, t_ray *ray, int column)
{
	t_draw	draw;

	init_wall_size(&draw, ray->distance);
	draw_on_column(&draw, ray, frame, column, cub);
}
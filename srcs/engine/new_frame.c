/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 02:42:31 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/02 21:07:01 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

t_img	*img_to_fill(t_cub *cub)
{
	if (cub->current_img == 0)
	{
		cub->current_img = 1;
		return (cub->img1);
	}
	else
	{
		cub->current_img = 0;
		return (cub->img1);
	}
}

void	fill_background(t_cub *cub, t_img *frame)
{
	int	x;
	int	y;

	x = WIN_LENGTH;
	while (x >= 0)
	{
		y = (WIN_HEIGHT / 2);
		while (y >= 0)
		{
			pixel_put(frame, x, y, cub->ceiling_clr);
			pixel_put(frame, x, y + (WIN_HEIGHT / 2), cub->floor_clr);
			y--;
		}
		x--;
	}
	return ;
}

void	new_frame(t_cub *cub)
{
	t_img	*frame;

	frame = img_to_fill(cub);
	fill_background(cub, frame);
	display_minimap(cub, frame);
	
	mlx_put_image_to_window(cub->mlx, cub->win, frame->img, 0, 0);
}
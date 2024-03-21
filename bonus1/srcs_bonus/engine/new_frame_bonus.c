/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 02:42:31 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/21 15:57:35 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

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
		return (cub->img0);
	}
}

void	fill_background(t_cub *cub, t_img *frame)
{
	int	x;
	int	y;

	x = WIN_LEN;
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
	cub->frame = frame;
	fill_background(cub, frame);
	raycasting(cub, frame);
	if (cub->toggle_map)
		display_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, frame->img, 0, 0);
}

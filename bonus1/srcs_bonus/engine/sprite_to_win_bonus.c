/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_win_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:46:43 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/19 12:05:31 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

void	put_img_to_frame(t_img *img, t_img *frame, int x, int y)
{
	int	px;
	int	py;
	int	color;

	px = 0;
	py = 0;
	color = 1;
	while (color)
	{
		color = gc(img, px, py);
		pixel_put(frame, (x + px), (y + py), color);
		if (px >= img->line_length / 4)
		{
			py++;
			px = 0;
		}
		px++;
	}
	return ;
}

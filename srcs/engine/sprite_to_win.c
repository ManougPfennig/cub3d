/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:46:43 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/09 21:58:01 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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
		color = get_color(img, px, py);
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

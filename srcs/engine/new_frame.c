/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 02:42:31 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/01 17:44:13 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

void	fill_background(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->win, cub->ceiling, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->floor, 0, (WIN_HEIGHT / 2));
}

void	new_frame(t_cub *cub)
{
	fill_background(cub);
	display_minimap(cub);
}
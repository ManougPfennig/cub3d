/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 02:42:31 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/01 17:22:35 by mapfenni         ###   ########.fr       */
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

void	new_frame(t_cub *cub)
{
	fill_background(cub);
}
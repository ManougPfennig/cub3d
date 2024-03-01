/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:46:43 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/01 17:21:44 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	sprite_to_win(t_data *data, char sign, int x, int y)
{
	if (sign == 'N')
		mlx_put_image_to_window(data->mlx, data->win, data->img_1, \
		(x * 64), (y * 64));
	else if (sign == 'S')
		mlx_put_image_to_window(data->mlx, data->win, data->img_0, \
		(x * 64), (y * 64));
	else if (sign == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img_e, \
		(x * 64), (y * 64));
	else if (sign == 'W')
		mlx_put_image_to_window(data->mlx, data->win, data->img_c, \
		(x * 64), (y * 64));
}

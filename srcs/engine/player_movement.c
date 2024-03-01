/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:56:56 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/01 17:45:03 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_player(t_cub *cub, float x, float y)
{
	cub->pos[0] += x;
	cub->pos[1] += y;
	new_frame(cub);
}

void	rotate_player(t_cub *cub, int dir)
{
	if (dir == LEFT_TURN)
		cub->dir += -1;
	else if (dir == RIGHT_TURN)
		cub->dir += +1;
	if (cub->dir >= 360)
		cub->dir += -360;
	else if (cub->dir < 0)
		cub->dir += 360;
}

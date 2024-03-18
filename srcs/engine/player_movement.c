/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:56:56 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/18 15:39:33 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	move_player(t_cub *cub, double x, double y)
{
	double	new_x;
	double	new_y;

	new_x = cub->pos[0] + (cub->dir[0] * x);
	new_y = cub->pos[1] + (cub->dir[1] * y);
	if (new_x < 0.0 || new_y < 0.0)
		return ;
	if (!cub->map[(int)new_x])
		return ;
	if (new_y >= ft_strlen(cub->map[(int)new_x]))
		return ;
	cub->pos[0] = new_x;
	cub->pos[1] = new_y;
}

void	rotate_player(t_cub *cub, int dir)
{
	double	oldDirX;
	double	oldPlaneX;

	if (dir == RIGHT_TURN)
    {
      oldDirX = cub->dir[0];
      cub->dir[0] = cub->dir[0] * cos(-(ROT_SPEED)) - cub->dir[1] * sin(-(ROT_SPEED));
      cub->dir[1] = oldDirX * sin(-(ROT_SPEED)) + cub->dir[1] * cos(-(ROT_SPEED));
      oldPlaneX = cub->plane[0];
      cub->plane[0] = cub->plane[0] * cos(-(ROT_SPEED)) - cub->plane[1] * sin(-(ROT_SPEED));
      cub->plane[1] = oldPlaneX * sin(-(ROT_SPEED)) + cub->plane[1] * cos(-(ROT_SPEED));
    }
    if (dir == LEFT_TURN)
    {
      oldDirX = cub->dir[0];
      cub->dir[0] = cub->dir[0] * cos(ROT_SPEED) - cub->dir[1] * sin(ROT_SPEED);
      cub->dir[1] = oldDirX * sin(ROT_SPEED) + cub->dir[1] * cos(ROT_SPEED);
      oldPlaneX = cub->plane[0];
      cub->plane[0] = cub->plane[0] * cos(ROT_SPEED) - cub->plane[1] * sin(ROT_SPEED);
      cub->plane[1] = oldPlaneX * sin(ROT_SPEED) + cub->plane[1] * cos(ROT_SPEED);
    }
}

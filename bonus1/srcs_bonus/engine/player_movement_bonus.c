/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:56:56 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/19 12:05:11 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

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
	if (cub->map[(int)new_x][(int)new_y] == '1')
		return ;
	cub->pos[0] = new_x;
	cub->pos[1] = new_y;
}

void	move_player_side(t_cub *cub, int key)
{
	if (key == A_KEY)
	{
		rotate_player(cub, LEFT_TURN, (M_PI / 2));
		move_player(cub, STEP_SIZE, STEP_SIZE);
		rotate_player(cub, RIGHT_TURN, (M_PI / 2));
	}
	else if (key == D_KEY)
	{
		rotate_player(cub, RIGHT_TURN, (M_PI / 2));
		move_player(cub, STEP_SIZE, STEP_SIZE);
		rotate_player(cub, LEFT_TURN, (M_PI / 2));
	}
}

void	rotate_player(t_cub *cub, int dir, double rot)
{
	double	old_dirx;
	double	old_planex;

	if (dir == RIGHT_TURN)
	{
		old_dirx = cub->dir[0];
		cub->dir[0] = cub->dir[0] * cos(-(rot)) - cub->dir[1] * sin(-(rot));
		cub->dir[1] = old_dirx * sin(-(rot)) + cub->dir[1] * cos(-(rot));
		old_planex = cub->plane[0];
		cub->plane[0] = \
		cub->plane[0] * cos(-(rot)) - cub->plane[1] * sin(-(rot));
		cub->plane[1] = old_planex * sin(-(rot)) + cub->plane[1] * cos(-(rot));
	}
	if (dir == LEFT_TURN)
	{
		old_dirx = cub->dir[0];
		cub->dir[0] = cub->dir[0] * cos(rot) - cub->dir[1] * sin(rot);
		cub->dir[1] = old_dirx * sin(rot) + cub->dir[1] * cos(rot);
		old_planex = cub->plane[0];
		cub->plane[0] = cub->plane[0] * cos(rot) - cub->plane[1] * sin(rot);
		cub->plane[1] = old_planex * sin(rot) + cub->plane[1] * cos(rot);
	}
}

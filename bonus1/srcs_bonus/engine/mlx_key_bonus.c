/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:56:15 by mapfenni          #+#    #+#             */
/*   Updated: 2024/04/08 15:35:11 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

int	key_release(int key, t_cub *cub)
{
	if (key == W_KEY)
		cub->keys[0] = 0;
	else if (key == A_KEY)
		cub->keys[1] = 0;
	else if (key == S_KEY)
		cub->keys[2] = 0;
	else if (key == D_KEY)
		cub->keys[3] = 0;
	else if (key == LEFT_KEY)
		cub->keys[4] = 0;
	else if (key == RIGHT_KEY)
		cub->keys[5] = 0;
	return (0);
}

int	key_pressed(int key, t_cub *cub)
{
	if (key == W_KEY)
		cub->keys[0] = 1;
	else if (key == A_KEY)
		cub->keys[1] = 1;
	else if (key == S_KEY)
		cub->keys[2] = 1;
	else if (key == D_KEY)
		cub->keys[3] = 1;
	else if (key == LEFT_KEY)
		cub->keys[4] = 1;
	else if (key == RIGHT_KEY)
		cub->keys[5] = 1;
	else if (key == ESCAPE_KEY)
		exit_game(cub);
	else if (key == MAP_KEY)
		toggle_map_display(cub);
	return (0);
}

void	mouse_movement(t_cub *cub)
{
	int	x;
	int	y;
	int	dif_x;

	mlx_mouse_get_pos(cub->mlx, cub->win, &x, &y);
	if (x < (WIN_LEN / 2))
	{
		dif_x = (WIN_LEN / 2) - x;
		rotate_player(cub, LEFT_TURN, ROT_SPEED * ((double)dif_x) / 3);
	}
	else if (x > (WIN_LEN / 2))
	{
		dif_x = x - (WIN_LEN / 2);
		rotate_player(cub, RIGHT_TURN, ROT_SPEED * ((double)dif_x) / 3);
	}
	mlx_mouse_move(cub->mlx, cub->win, (WIN_LEN / 2), (WIN_HEIGHT / 2));
}

int	loop_hook(t_cub *cub)
{
	mouse_movement(cub);
	if (cub->keys[0])
		move_player(cub, STEP_SIZE, STEP_SIZE);
	if (cub->keys[1])
		move_player_side(cub, A_KEY);
	if (cub->keys[2])
		move_player(cub, -STEP_SIZE, -STEP_SIZE);
	if (cub->keys[3])
		move_player_side(cub, D_KEY);
	if (cub->keys[4])
		rotate_player(cub, LEFT_TURN, ROT_SPEED);
	if (cub->keys[5])
		rotate_player(cub, RIGHT_TURN, ROT_SPEED);
	mouse_movement(cub);
	new_frame(cub);
	return (0);
}

void	setup_mlx_event(t_cub *cub)
{
	mlx_mouse_move(cub->mlx, cub->win, (WIN_LEN / 2), (WIN_HEIGHT / 2));
	mlx_hook(cub->win, 17, 1L << 21, exit_window, cub);
	mlx_hook(cub->win, 2, 1L << 0, key_pressed, cub);
	mlx_hook(cub->win, 3, 1L << 1, key_release, cub);
	mlx_mouse_hide(cub->mlx, cub->win);
	mlx_loop_hook(cub->mlx, loop_hook, cub);
}

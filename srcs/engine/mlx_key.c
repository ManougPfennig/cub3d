/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:56:15 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/18 15:38:35 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	key_pressed(int key, t_cub *cub)
{
//	else if (key == A_KEY)
//		move_player(cub, -(STEP_SIZE), 0);
//	else if (key == D_KEY)
//		move_player(cub, (STEP_SIZE), 0);
	if (key == W_KEY)
		move_player(cub, 0, -(STEP_SIZE));
	else if (key == S_KEY)
		move_player(cub, 0, (STEP_SIZE));
	else if (key == LEFT_KEY)
		rotate_player(cub, LEFT_TURN);
	else if (key == RIGHT_KEY)
		rotate_player(cub, RIGHT_TURN);
	else if (key == MAP_KEY)
		toggle_map_display(cub);
	else if (key == ESCAPE_KEY)
		exit_game(cub);
	printf("key: %i\n", key);
	return (0);
}

int	mouse_moved(int x, int y, t_cub *cub)
{
	(void)cub;
	printf("x: -%i-      y: -%i-\n", x, y);
	if (y < 0)
		rotate_player(cub, LEFT_TURN);
	else if (y > 0)
		rotate_player(cub, RIGHT_TURN);
	return (0);
}

int	loop_hook(t_cub *cub)
{
/*	int	x;
	int	y;

	mlx_mouse_get_pos(cub->mlx, cub->win, &x, &y);
	if (x > (WIN_LEN / 2))
		rotate_player(cub, RIGHT_TURN);
	else if (x < (WIN_LEN / 2))
		rotate_player(cub, LEFT_TURN);
	mlx_mouse_move(cub->mlx, cub->win, (WIN_LEN / 2), (WIN_HEIGHT / 2));*/
	new_frame(cub);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_cub *cub)
{
	(void)key;
	(void)x;
	(void)y;
	(void)cub;
	return (0);
}

void	setup_mlx_event(t_cub *cub)
{
	mlx_hook(cub->win, 2, 1L << 0, key_pressed, cub);
	mlx_hook(cub->win, 6, 1L << 0, mouse_moved, cub);
	mlx_mouse_hook(cub->win, mouse_hook, cub);
//	mlx_mouse_hide(cub->mlx, cub->win);
	mlx_loop_hook(cub->mlx, loop_hook, cub);
}

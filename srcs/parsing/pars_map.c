/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:06:34 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/18 18:01:43 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	check_around(t_cub *data, int i, int j)
{
	if (!data->map[i + 1][j] || !data->map[i - 1][j]
		|| !data->map[i][j + 1] || !data->map[i][j - 1])
		error_mes(6, data);
	if (!is_out(data->map[i + 1][j]) || !is_out(data->map[i - 1][j])
		|| !is_out(data->map[i][j + 1]) || !is_out(data->map[i][j - 1]))
		error_mes(6, data);
}

void	check_close_map(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (n_player(data->map[i][j]) || data->map[i][j] == '0')
			{
				if (i == 0 || i == tab_len(data->map) - 1)
					error_mes(6, data);
				check_around(data, i, j);
			}
			j++;
		}
		i++;
	}
}

void	init_player_dir(t_cub *data, char c)
{
	data->dir[0] = -1.0;
	data->dir[1] = 0.0;
	data->plane[0] = 0;
	data->plane[1] = (double)FOV / 100.0;
	if (c == 'N')
		return;
	else if (c == 'S')
		rotate_player(data, LEFT_TURN, M_PI);
	else if (c == 'E')
		rotate_player(data, RIGHT_TURN, (M_PI / 2));
	else if (c == 'W')
		rotate_player(data, LEFT_TURN, (M_PI / 2));
}

void	init_player(t_cub *data)
{
	int	i;
	int	y;

	i = 0;
	while (data->map[i])
	{
		y = 0;
		while (data->map[i][y])
		{
			if (data->map[i][y] == 'S' || data->map[i][y] == 'N' \
			|| data->map[i][y] == 'E' || data->map[i][y] == 'W')
			{
				init_player_dir(data, data->map[i][y]);
				data->pos[0] = ((double)i) + 0.5;
				data->pos[1] = ((double)y) + 0.5;
				data->map[i][y] = '0';
				return ;
			}
			y++;
		}
		i++;
	}
}

void	pars_map(t_cub *data)
{
	check_bad_char(data);
	check_n_player(data);
	check_close_map(data);
	get_fl(data);
	get_ce(data);
	init_player(data);
}

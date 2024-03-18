/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:06:34 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/16 18:37:46 by edfirmin         ###   ########.fr       */
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

void	pars_map(t_cub *data)
{
	check_bad_char(data);
	check_n_player(data);
	check_close_map(data);
	get_fl(data);
	get_ce(data);
}

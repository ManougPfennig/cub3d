/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utile1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:09:09 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/19 12:05:54 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

int	map_char(char c)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	n_player(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

void	check_bad_char(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!map_char(data->map[i][j]))
				error_mes(2, data);
			j++;
		}
		i++;
	}
}

void	check_n_player(t_cub *data)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (n_player(data->map[i][j]))
				n++;
			j++;
		}
		i++;
	}
	if (n != 1)
		error_mes(5, data);
}

int	is_out(char c)
{
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:57:09 by edfirmin          #+#    #+#             */
/*   Updated: 2024/04/08 15:24:22 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

void	skip_n(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	i--;
	while (tab[i] && tab[i][0] == '\n')
	{
		free(tab[i]);
		i--;
	}
	tab[i + 1] = NULL;
}

void	get_data(t_cub *data, char **map, char *buff)
{
	int	n;

	get_texture(data, map, buff);
	ft_free_tab(map);
	n = get_map_size(data, buff);
	data->map = get_map(n, buff);
	if (data->map && data->map[0])
		skip_n(data->map);
}

void	set_tex(t_texture *tex)
{
	tex->ceiling = NULL;
	tex->ea_path = NULL;
	tex->floor = NULL;
	tex->no_path = NULL;
	tex->so_path = NULL;
	tex->we_path = NULL;
}
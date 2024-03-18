/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:57:09 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/16 18:39:25 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	get_data(t_cub *data, char **map, char *buff)
{
	int	n;

	get_texture(data, map, buff);
	ft_free_tab(map);
	n = get_map_size(data, buff);
	data->map = get_map(n, buff);
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

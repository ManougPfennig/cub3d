/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utile2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:57:07 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/16 18:10:02 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	check_val(t_color *col)
{
	if (col->r < 0 || col->r > 255)
		return (0);
	if (col->g < 0 || col->g > 255)
		return (0);
	if (col->b < 0 || col->b > 255)
		return (0);
	return (1);
}

int	check_col(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		if (str[i] != ',' && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (j != 2)
		return (0);
	return (1);
	
}

void	get_fl(t_cub *data)
{
	char	**tab;

	if (!check_col(data->txtr->floor))
		error_mes(3, data);
	tab = ft_split(data->txtr->floor, ',');
	if (tab_len(tab) != 3)
		error_mes(7, data);
	data->f->r = ft_atoi(tab[0]);
	data->f->g = ft_atoi(tab[1]);
	data->f->b = ft_atoi(tab[2]);
    ft_free_tab(tab);
	if (!check_val(data->f))
		error_mes(7, data);
}

void	get_ce(t_cub *data)
{
	char	**tab;

	if (!check_col(data->txtr->ceiling))
		error_mes(3, data);
	tab = ft_split(data->txtr->ceiling, ',');
	if (tab_len(tab) != 3)
		error_mes(7, data);
	data->c->r = ft_atoi(tab[0]);
	data->c->g = ft_atoi(tab[1]);
	data->c->b = ft_atoi(tab[2]);
    ft_free_tab(tab);
	if (!check_val(data->c))
		error_mes(7, data);
}

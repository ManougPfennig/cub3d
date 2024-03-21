/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_utile_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:52:07 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/19 12:05:50 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

int	check_full(t_texture *tex)
{
	if (tex->ea_path && tex->no_path && tex->so_path
		&& tex->we_path && tex->ceiling && tex->floor)
		return (1);
	return (0);
}

int	lil_tex(char *str)
{
	if (ft_strstr(str, "N"))
		return (1);
	if (ft_strstr(str, "S"))
		return (2);
	if (ft_strstr(str, "E"))
		return (3);
	if (ft_strstr(str, "W"))
		return (4);
	if (ft_strstr(str, "F"))
		return (5);
	if (ft_strstr(str, "C"))
		return (6);
	return (0);
}

int	big_tex(char *str)
{
	if (ft_strstr(str, "NO"))
		return (1);
	if (ft_strstr(str, "SO"))
		return (2);
	if (ft_strstr(str, "EA"))
		return (3);
	if (ft_strstr(str, "WE"))
		return (4);
	return (0);
}

int	what_tex(char *str)
{
	if (ft_strlen(str) == 1)
		return (lil_tex(str));
	else
		return (big_tex(str));
}

void	free_d_tex(t_texture *tex, int n)
{
	if (n == 1 && tex->no_path)
		free(tex->no_path);
	if (n == 2 && tex->so_path)
		free(tex->so_path);
	if (n == 3 && tex->ea_path)
		free(tex->ea_path);
	if (n == 4 && tex->we_path)
		free(tex->we_path);
	if (n == 5 && tex->floor)
		free(tex->floor);
	if (n == 6 && tex->ceiling)
		free(tex->ceiling);
}

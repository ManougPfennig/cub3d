/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:08:48 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/02 21:07:23 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	free_str(char *str)
{
	if (str)
		free(str);
	return ;
}

void	free_color(t_color *c)
{
	if (c)
		free(c);
	return ;
}

void	free_texture(t_texture *t)
{
	free_str(t->no_path);
	free_str(t->so_path);
	free_str(t->we_path);
	free_str(t->ea_path);
	return ;
}

void	clean_exit(t_cub *cub, int sig)
{
	free_texture(cub->txtr);
	free_color(cub->f);
	free_color(cub->c);
	ft_free_tab(cub->map);
	free(cub);
	exit(sig);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:08:48 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/19 10:54:29 by mapfenni         ###   ########.fr       */
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
	if (!t)
		return ;
	free_str(t->no_path);
	free_str(t->so_path);
	free_str(t->we_path);
	free_str(t->ea_path);
	free_str(t->floor);
	free_str(t->ceiling);
	free(t);
	return ;
}

int	exit_window(t_cub *cub)
{
	printf("Exiting...\n");
	free_all(cub);
	exit(0);
	return (0);
}

void	free_img(t_cub *cub, t_img *img)
{
	if (!img)
		return ;
	if (img->img)
		mlx_destroy_image(cub->mlx, img->img);
	free(img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:08:48 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/19 12:06:22 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

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

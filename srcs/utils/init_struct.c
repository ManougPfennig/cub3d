/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:44:07 by mapfenni          #+#    #+#             */
/*   Updated: 2024/02/28 02:10:14 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_texture	*init_texture(void)
{
	t_texture	*t;

	t = malloc(sizeof(t_texture));
	t->no_path = NULL;
	t->so_path = NULL;
	t->we_path = NULL;
	t->ea_path = NULL;
	t->no = NULL;
	t->so = NULL;
	t->we = NULL;
	t->ea = NULL;
	return (t);
}

t_color	*init_color(void)
{
	t_color	*c;

	c = malloc(sizeof(t_color));
	c->r = 0;
	c->g = 0;
	c->b = 0;
	return (c)
}

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub->txtr = init_texture();
	cub->f = init_color();
	cub->c = init_color();
	cub->pos[0] = 0;
	cub->pos[1] = 0;
	cub->dir = 0;
	cub->map = NULL;
	cub->mlx = NULL;
	cub->win = NULL;
	cub->error = 0;
	return (cub);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:44:07 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/01 16:33:59 by mapfenni         ###   ########.fr       */
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
	return (c);
}

t_img	*init_img(void)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	return (img);
}

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	cub->txtr = init_texture();
	cub->f = init_color();
	cub->c = init_color();
	cub->pos[0] = 0;
	cub->pos[1] = 0;
	cub->dir = 0;
	cub->map = NULL;
	cub->mlx = NULL;
	cub->win = NULL;
	cub->ceiling = NULL;
	cub->floor = NULL;
	cub->img_map = init_img();
	cub->img0 = init_img();
	cub->img1 = init_img();
	cub->img_x = WIN_LENGTH;
	cub->img_y = WIN_HEIGHT;
	cub->error = 0;
	cub->current_img = 0;
	return (cub);
}
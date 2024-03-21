/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ceiling_floor_texture_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:34 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/19 12:04:56 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	init_ceiling_floor_texture(t_cub *cub)
{
	cub->floor_clr = rgb_to_hex(cub->f->r, cub->f->g, cub->f->b);
	cub->ceiling_clr = rgb_to_hex(cub->c->r, cub->c->g, cub->c->b);
	return ;
}

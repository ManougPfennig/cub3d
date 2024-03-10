/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ceiling_floor_texture.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:34 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/08 18:26:05 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:39:27 by mapfenni          #+#    #+#             */
/*   Updated: 2024/04/08 15:24:00 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

t_img	*setup_texture(t_cub *cub, char *path)
{
	t_img	*texture;

	texture = init_img();
	texture->img = ft_xpm_to_img(cub, texture, path);
	texture->addr = mlx_get_data_addr(texture->img, \
	&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	return (texture);
}

void	set_textures(t_cub *cub)
{
	cub->txtr->no = setup_texture(cub, cub->txtr->we_path);
	cub->txtr->so = setup_texture(cub, cub->txtr->so_path);
	cub->txtr->we = setup_texture(cub, cub->txtr->no_path);
	cub->txtr->ea = setup_texture(cub, cub->txtr->ea_path);
}

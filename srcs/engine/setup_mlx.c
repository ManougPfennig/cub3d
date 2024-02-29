/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:55:57 by mapfenni          #+#    #+#             */
/*   Updated: 2024/02/28 21:09:17 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_imgs(t_cub *cub)
{
	cub->txtr->no = ft_xpm_to_img(cub, cub->txtr->no_path);
	cub->txtr->so = ft_xpm_to_img(cub, cub->txtr->so_path);
	cub->txtr->we = ft_xpm_to_img(cub, cub->txtr->we_path);
	cub->txtr->ea = ft_xpm_to_img(cub, cub->txtr->ea_path);
}

void	create_window(t_cub *cub, char *name)
{
	cub->win = mlx_new_window(cub->mlx, cub->img_x, cub->img_y, name);
	if (cub->win == NULL)
	{
		ft_printf("Error: Program interrupted : mlx_new_window failed\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	start_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
	{
		ft_printf("Error: Program interrupted : mlx_init failed\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	create_image(t_cub *cub)
{
	cub->img0->img = mlx_new_image(cub->mlx, cub->img_x, cub->img_y);
	cub->img1->img = mlx_new_image(cub->mlx, cub->img_x, cub->img_y);
	if (cub->img0->img == NULL || cub->img1->img == NULL)
	{
		ft_printf("Error: Program interrupted : mlx_new_image failed\n");
		exit(EXIT_FAILURE);
	}
	cub->img0->addr = mlx_get_data_addr(cub->img0->img, &cub->img0->bits_per_pixel, \
	&cub->img0->line_length, &cub->img0->endian);
	cub->img1->addr = mlx_get_data_addr(cub->img1->img, &cub->img1->bits_per_pixel, \
	&cub->img1->line_length, &cub->img1->endian);
	return ;
}

void	setup_mlx(t_cub *cub)
{
	start_mlx(cub);
	create_window(cub, "cub3d");
	create_image(cub);
//	set_imgs(cub);
}

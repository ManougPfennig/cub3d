/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:55:57 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/09 22:44:07 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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

void	setup_img(t_cub *cub, t_img *img, int length, int height)
{
	img->img = mlx_new_image(cub->mlx, length, height);
	if (img->img == NULL)
	{
		ft_printf("Error: Program interrupted : mlx_new_image failed\n");
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	return ;
}

void	setup_mlx(t_cub *cub)
{
	start_mlx(cub);
	create_window(cub, "cub3d");
	cub->img0 = init_img();
	cub->img1 = init_img();
	setup_img(cub, cub->img0, WIN_LEN, WIN_HEIGHT);
	setup_img(cub, cub->img1, WIN_LEN, WIN_HEIGHT);
	set_textures(cub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:55:57 by mapfenni          #+#    #+#             */
/*   Updated: 2024/02/28 16:47:12 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_imgs(t_cub *cub)
{
	cub->txtr->no = ft_xpm_to_img(cub, cub->txtr->no_path);
	cub->txtr->so = ft_xpm_to_img(cub, cub->txtr->so_path);
	cub->txtr->we = ft_xpm_to_img(cub, cub->txtr->we_path);
	cub->txtr->ea = ft_xpm_to_img(cub, cub->txtr->ea_path);
}

void	create_window(t_cub *cub, char *name)
{
	cub->img_x = 960;
	cub->img_y = 704;
	cub->win = mlx_new_window(cub->mlx, cub->img_x, cub->img_y, name);
	if (cub->win == NULL)
	{
		ft_printf("Error: Program interrupted : mlx_new_window failed\n");
		ft_free_tab(cub->map, cub->copy_map);
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
	if (cub->img == NULL)
		cub->img = mlx_new_image(cub->mlx, 960, 704);
	if (cub->img == NULL)
	{
		ft_printf("Error: Program interrupted : mlx_new_image failed\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	setup_mlx(t_cub *cub)
{
	start_mlx(cub);
	create_window(cub, "cub3d");
	create_image(cub);
	set_imgs(cub);
}

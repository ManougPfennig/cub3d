/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:55:57 by mapfenni          #+#    #+#             */
/*   Updated: 2024/02/28 16:23:56 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_imgs(t_data *data)
{
	data->img_0 = ft_xpm_to_img(data, "./img/floor.xpm");
	data->img_1 = ft_xpm_to_img(data, "./img/wall.xpm");
	data->img_b = ft_xpm_to_img(data, "./img/broken.xpm");
	data->img_c = ft_xpm_to_img(data, "./img/house.xpm");
	data->img_e = ft_xpm_to_img(data, "./img/exit.xpm");
	data->img_p = ft_xpm_to_img(data, "./img/player.xpm");
	data->img_end = ft_xpm_to_img(data, "./img/end.xpm");
}

void	create_window(t_data *data, char *name)
{
	if (ft_strlen(data->map[0]) < 15 && ft_tablen(data->map) < 11)
	{
		data->img_x = ft_strlen(data->map[0]) * 64;
		data->img_y = ft_tablen(data->map) * 64;
	}
	else
	{
		data->img_x = 15 * 64;
		data->img_y = 11 * 64;
	}
	data->win = mlx_new_window(data->mlx, data->img_x, data->img_y, name);
	if (data->win == NULL)
	{
		ft_printf("Error:\nCould not mlx_new_window -> Program interrupted\n");
		ft_free_tab(data->map, data->copy_map);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	start_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
	{
		ft_printf("Error:\nCould not mlx_init -> Program interrupted\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	setup_mlx(t_cub *cub)
{
	start_mlx(cub);
	create_window(cub, "cub3d");
	create_image(cub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:49:21 by gfabre            #+#    #+#             */
/*   Updated: 2024/02/28 17:18:53 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		ft_exit(1);
	cub = init_cub();
	parsing(cub, argv);
/*	setup_mlx(cub);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	set_imgs(&data);
	put_map(&data);
	mlx_hook(data.win, 2, 1L << 0, key_pressed, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, deal_key, &data);
	mlx_hook(data.win, 17, 0, ft_destroy_windows, &data);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_loop(data.mlx); */
	return (0);
}

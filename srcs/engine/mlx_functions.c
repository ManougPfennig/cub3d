/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:16:19 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/31 10:16:19 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	*ft_xpm_to_img(t_cub *cub, char *path)
{
	void	*ptr;
	int		width;
	int		height;

	width = cub->img_x / 4;
	height = cub->img_y / 4;
	ptr = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	if (!ptr)
	{
		printf("Error : Sprite not found : mlx_xpm_to_image failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void	exit_game(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	ft_free_tab(cub->map);
	printf("Exiting...\n");
	exit(0);
	return ;
}

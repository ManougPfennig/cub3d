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

void	*ft_xpm_to_img(t_cub *cub, t_img *txtr, char *path)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(cub->mlx, path, &txtr->width, &txtr->height);
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
	*(unsigned int *)dst = color;
}

int	gc(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	exit_game(t_cub *cub)
{
	printf("Exiting...\n");
	free_all(cub);
	exit(0);
	return ;
}

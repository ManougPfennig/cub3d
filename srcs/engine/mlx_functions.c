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

#include "../cub3d.h"

void	*ft_xpm_to_img(t_cub *cub, char *path)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(cub->mlx, path, &cub->width, &cub->height);
	if (!ptr)
	{
		print_error("Error : Sprite not found : mlx_xpm_to_image failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

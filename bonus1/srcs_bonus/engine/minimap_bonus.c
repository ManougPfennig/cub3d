/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:35:05 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/21 17:18:08 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

void	toggle_map_display(t_cub *cub)
{
	if (cub->toggle_map == 1)
		cub->toggle_map = 0;
	else if (cub->toggle_map == 0)
		cub->toggle_map = 1;
	return ;
}

void	big_pixel_put(t_img *img, int x, int y, int color)
{
	int	px;
	int	py;

	py = MAPSIZE;
	while (py > 0)
	{
		px = MAPSIZE;
		while (px > 0)
		{
			pixel_put(img, (x * MAPSIZE) + px, (y * MAPSIZE) + py, color);
			px--;
		}
		py--;
	}
}

void	mini_map_2(t_cub *cub, int p[2], int x, int y)
{
	while (y < 15)
	{
		if (!cub->map[p[0]][p[1]])
			break ;
		if (p[0] == (int)cub->pos[0] && p[1] == (int)cub->pos[1])
			big_pixel_put(cub->frame, y, x, RED);
		else if (cub->map[p[0]][p[1]] && cub->map[p[0]][p[1]] != '1')
			big_pixel_put(cub->frame, y, x, WHITE);
		else if (cub->map[p[0]][p[1]] && cub->map[p[0]][p[1]] == '1')
			big_pixel_put(cub->frame, y, x, BLUE);
		y++;
		p[1]++;
	}
}

void	display_minimap(t_cub *cub)
{
	int	x;
	int	y;
	int	p[2];

	x = 0;
	p[0] = (int)cub->pos[0] - 7;
	if (tab_len(cub->map) - 15 < p[0])
		p[0] = tab_len(cub->map) - 15;
	if (p[0] < 0)
		p[0] = 0;
	while (x < 15)
	{
		if (!cub->map[p[0]])
			break ;
		p[1] = (int)cub->pos[1] - 7;
		if (ft_strlen(cub->map[p[0]]) - 15 < p[1])
			p[1] = ft_strlen(cub->map[p[0]]) - 15;
		y = 0;
		if (p[1] < 0)
			p[1] = 0;
		mini_map_2(cub, p, x, y);
		x++;
		p[0]++;
	}
}

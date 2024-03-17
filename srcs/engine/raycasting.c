/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:32:27 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/12 17:42:27 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	send_ray(t_cub *cub, t_ray *r)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->sideDist[0] < r->sideDist[1])
		{
			r->sideDist[0] += r->deltaDist[0];
			r->map[0] += r->step[0];
			r->side = 0;
		}
		else
		{
			r->sideDist[1] += r->deltaDist[1];
			r->map[1] += r->step[1];
			r->side = 1;
		}
		if (cub->map[r->map[0]][r->map[1]] == '1')
			hit = 1;
	}
}

void	get_ray_len(t_ray *r)
{
	if (r->side == 0)
		r->distance = (r->sideDist[0] - r->deltaDist[0]);
	else
		r->distance = (r->sideDist[1] - r->deltaDist[1]);
}

void	get_dir(t_cub *cub, t_ray *r, int i)
{
	r->cameraX = (2 * i) / (double)WIN_LEN - 1.0;
	r->map[0] = (int)cub->pos[0];
	r->map[1] = (int)cub->pos[1];
	r->rayDir[0] = cub->dir[0] + r->plane[0] * r->cameraX;
	r->rayDir[1] = cub->dir[1] + r->plane[1] * r->cameraX;
	r->deltaDist[0] = fabs(1 / r->rayDir[0]);
	r->deltaDist[1] = fabs(1 / r->rayDir[1]);
}

void	get_steps(t_cub *cub, t_ray *r)
{
	if (r->rayDir[0] < 0)
	{
		r->step[0] = -1.0;
		r->sideDist[0] = (cub->pos[0] - r->map[0]) * r->deltaDist[0];
	}
	else
	{
		r->step[0] = 1.0;
		r->sideDist[0] = (r->map[0] + 1.0 - cub->pos[0]) * r->deltaDist[0];
	}
	if (r->rayDir[1] < 0)
	{
		r->step[1] = -1.0;
		r->sideDist[1] = (cub->pos[1] - r->map[1]) * r->deltaDist[1];
	}
	else
	{
		r->step[1] = 1.0;
		r->sideDist[1] = (r->map[1] + 1.0 - cub->pos[1]) * r->deltaDist[1];
	}
}

void	raycasting(t_cub *cub, t_img *frame)
{
	t_ray	*ray;
	int		i;

	i = 0;
	ray = cub->ray;
	ray->plane[0] = 0;
	ray->plane[1] = (double)FOV / 100.0;
	while (i < WIN_LEN)
	{
		get_dir(cub, ray, i);
		get_steps(cub, ray);
		send_ray(cub, ray);
		get_ray_len(ray);
//		display_texture(frame, ray, column);
		i++;
	}
	free(ray);
	(void)frame;
}

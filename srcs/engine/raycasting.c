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

/*void	init_steps(double coef, t_ray *ray)
{
	if ()
}

void	send_ray(t_cub *cub, t_ray *ray, double coef)
{
	double	rayY;
	double	rayX;

	rayY = cub->pos[1];
	rayX = cub->pos[0];
	while (ray->hit == 0)
	{
        //jump to next map square, either in x-direction, or in y-direction
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
        //Check if ray has hit a wall
		if (worldMap[rayX][rayY] > 0)
			ray->hit = 1;
	} 
}*/

void	get_dir(t_cub *cub, t_ray *r, int column)
{
	(void)column;
	r->rayDir[0] = cub->dir[0];
	r->rayDir[1] = cub->dir[1];
	r->deltaDist[0] = sqrt(1 + (r->rayDir[1] * r->rayDir[1]) / (r->rayDir[0] * r->rayDir[0]));
	r->deltaDist[1] = sqrt(1 + (r->rayDir[0] * r->rayDir[0]) / (r->rayDir[1] * r->rayDir[1]));
	r->map[0] = (int)cub->pos[0];
	r->map[1] = (int)cub->pos[1];
}

void	get_steps(t_cub *cub, t_ray *r)
{
	if (r->rayDir[0] < 0)
	{
		r->step[0] = -1;
		r->sideDist[0] = (cub->pos[0] - (double)r->map[0]) * r->deltaDist[0];
	}
	else
	{
		r->step[0] = 1;
		r->sideDist[0] = ((double)r->map[0] + 1.0 - cub->pos[0]) * r->deltaDist[0];
	}
	if (r->rayDir[1] < 0)
	{
		r->step[1] = -1;
		r->sideDist[1] = (cub->pos[1] - (double)r->map[1]) * r->deltaDist[1];
	}
	else
	{
		r->step[1] = 1;
		r->sideDist[1] = ((double)r->map[1] + 1.0 - cub->pos[1]) * r->deltaDist[1];
	}
}

void	raycasting(t_cub *cub, t_img *frame)
{
	double	column;
	t_ray	ray;

	column = (double)WIN_LEN;
	while (column > 0)
	{
		ray.distance = 0;
		ray.type = 0;
		get_steps(cub, &ray);
//		send_ray(cub, &ray, get_lead_coef(column, cub->dir));
//		display_texture(frame, ray, column);
		column--;
	}
	(void)ray;
	(void)frame;
}

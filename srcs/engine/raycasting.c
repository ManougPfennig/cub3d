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

void	send_ray(t_cub *cub, t_ray *ray, double coef)
{
	double	ry;
	double	rx;

	ry = cub->pos[1];
	rx = cub->pos[0];
	while(ry >= 0 && tab[(int)ry] && rx >= 0 && tab[(int)ry][(int)rx])
	{
		if ()
	}
}

double	get_lead_coef(double column, double dir)
{
	double	ray_angle;
	double	fov;
	double	len;

	fov = (double)FOV;
	len = (double)WIN_LEN;
	ray_angle = dir + (((fov / 2) / (len / 2)) * column) - (fov / 2);
	if (ray_angle >= 360)
		ray_angle -= 360;
	else if (ray_angle < 0)
		ray_angle += 360;
	printf("angle: '%f'   --    ", ray_angle);
	return (tan(ray_angle * (M_PI / 180)));
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
//		send_ray(cub, &ray, get_lead_coef(column, cub->dir));
		printf("coef: '%f'\n", get_lead_coef(column, cub->dir));
		column--;
	}
	(void)ray;
	(void)frame;
}

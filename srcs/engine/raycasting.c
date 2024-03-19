/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:32:27 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/19 11:04:53 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	send_ray(t_cub *cub, t_ray *r)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->sidedist[0] < r->sidedist[1])
		{
			r->sidedist[0] += r->deltadist[0];
			r->map[0] += r->step[0];
			r->side = 0;
		}
		else
		{
			r->sidedist[1] += r->deltadist[1];
			r->map[1] += r->step[1];
			r->side = 1;
		}
		if (out_of_border(cub, r) == TRUE)
			return (0);
		if (cub->map[r->map[0]][r->map[1]] == '1')
			hit = 1;
	}
	get_texture_val(r);
	get_texture_line(cub, r);
	return (HIT_WALL);
}

void	get_ray_len(t_ray *r)
{
	if (r->side == 0)
		r->distance = (r->sidedist[0] - r->deltadist[0]);
	else
		r->distance = (r->sidedist[1] - r->deltadist[1]);
}

void	get_dir(t_cub *cub, t_ray *r, int i)
{
	r->camx = (2 * i) / (double)WIN_LEN - 1.0;
	r->map[0] = (int)cub->pos[0];
	r->map[1] = (int)cub->pos[1];
	r->raydir[0] = cub->dir[0] + cub->plane[0] * r->camx;
	r->raydir[1] = cub->dir[1] + cub->plane[1] * r->camx;
	r->deltadist[0] = fabs(1 / r->raydir[0]);
	r->deltadist[1] = fabs(1 / r->raydir[1]);
}

void	get_steps(t_cub *cub, t_ray *r)
{
	if (r->raydir[0] < 0)
	{
		r->step[0] = -1.0;
		r->sidedist[0] = (cub->pos[0] - r->map[0]) * r->deltadist[0];
	}
	else
	{
		r->step[0] = 1.0;
		r->sidedist[0] = (r->map[0] + 1.0 - cub->pos[0]) * r->deltadist[0];
	}
	if (r->raydir[1] < 0)
	{
		r->step[1] = -1.0;
		r->sidedist[1] = (cub->pos[1] - r->map[1]) * r->deltadist[1];
	}
	else
	{
		r->step[1] = 1.0;
		r->sidedist[1] = (r->map[1] + 1.0 - cub->pos[1]) * r->deltadist[1];
	}
}

void	raycasting(t_cub *cub, t_img *frame)
{
	t_ray	*ray;
	int		i;

	i = 0;
	ray = cub->ray;
	while (i < WIN_LEN)
	{
		get_dir(cub, ray, i);
		get_steps(cub, ray);
		if (send_ray(cub, ray) == HIT_WALL)
		{
			get_ray_len(ray);
			display_texture(cub, frame, ray, i);
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:56:18 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/19 12:06:26 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->side = 0;
	ray->type = 0;
	ray->line = 0;
	ray->distance = 0;
	ray->camx = 0;
	ray->map[0] = 0;
	ray->sidedist[0] = 0;
	ray->step[0] = 0;
	ray->raydir[0] = 0;
	ray->deltadist[0] = 0;
	ray->map[1] = 0;
	ray->sidedist[1] = 0;
	ray->step[1] = 0;
	ray->raydir[1] = 0;
	ray->deltadist[1] = 0;
	return (ray);
}

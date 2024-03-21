/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:43:58 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/21 15:03:38 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

void	get_texture_val(t_ray *r)
{
	if (r->raydir[0] < 0 && r->raydir[1] < 0 && r->side == 0)
		r->type = W_WALL;
	else if (r->raydir[0] < 0 && r->raydir[1] < 0)
		r->type = N_WALL;
	else if (r->raydir[0] < 0 && r->raydir[1] >= 0 && r->side == 0)
		r->type = W_WALL;
	else if (r->raydir[0] < 0 && r->raydir[1] >= 0)
		r->type = E_WALL;
	else if (r->raydir[0] >= 0 && r->raydir[1] >= 0 && r->side == 0)
		r->type = S_WALL;
	else if (r->raydir[0] >= 0 && r->raydir[1] >= 0)
		r->type = E_WALL;
	else if (r->raydir[0] >= 0 && r->raydir[1] < 0 && r->side == 0)
		r->type = S_WALL;
	else if (r->raydir[0] >= 0 && r->raydir[1] < 0)
		r->type = N_WALL;
}

void	get_texture_line(t_cub *cub, t_ray *r)
{
	int	temp;

	if (r->side == 0)
		r->line = cub->pos[1] + r->distance * r->raydir[1];
	else
		r->line = cub->pos[0] + r->distance * r->raydir[0];
	temp = (int)r->line;
	r->line = r->line - (double)temp;
	if (r->line < 0.0)
		r->line = 0.0;
	else if (r->line > 1.0)
		r->line = 1;
}

int	out_of_border(t_cub *cub, t_ray *r)
{
	if (r->map[0] < 0.0 || r->map[0] < 0.0)
		return (TRUE);
	else if (!cub->map[r->map[0]])
		return (TRUE);
	else if (cub->map[r->map[0]][r->map[1]] == '\0')
		return (TRUE);
	else if (r->map[1] > ft_strlen(cub->map[r->map[0]]))
		return (TRUE);
	return (FALSE);
}

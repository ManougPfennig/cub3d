/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:49:21 by gfabre            #+#    #+#             */
/*   Updated: 2024/03/18 15:49:29 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

char	*skip(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == '\n')
		i++;
	return (&str[i]);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;
	char 	*buff;
	char	**tab;

	buff = NULL;
	cub = init_cub();
	if (argc != 2)
		error_mes(0, cub);
	check_name(argv[1], cub);
	buff = line(buff, open(argv[1], O_RDONLY), cub);
	if (!buff)
		error_mes(2, cub);
	tab = ft_split(buff, '\n');
	buff = skip(buff);
	get_data(cub, tab, buff);
	pars_map(cub);
	cub = init_cub();
	setup_mlx(cub);
	init_ceiling_floor_texture(cub);
	setup_mlx_event(cub);
	mlx_loop(cub->mlx);
	return (0);
}

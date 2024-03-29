/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:49:21 by gfabre            #+#    #+#             */
/*   Updated: 2024/03/19 12:06:37 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl_bonus/cub3d_bonus.h"

char	*skip(char *str)
{
	int		i;
	char	*s2;

	i = 0;
	while (str[i] && str[i] == '\n')
		i++;
	s2 = ft_strdup(&str[i]);
	free(str);
	return (s2);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;
	char	*buff;
	char	**tab;

	cub = init_cub();
	if (argc != 2)
		error_mes(0, cub);
	check_name(argv[1], cub);
	buff = line(NULL, open(argv[1], O_RDONLY), cub);
	if (!buff)
		error_mes(2, cub);
	tab = ft_split(buff, '\n');
	buff = skip(buff);
	get_data(cub, tab, buff);
	pars_map(cub);
	setup_mlx(cub);
	init_ceiling_floor_texture(cub);
	setup_mlx_event(cub);
	mlx_loop(cub->mlx);
	return (0);
}

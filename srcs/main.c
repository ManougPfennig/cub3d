/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:49:21 by gfabre            #+#    #+#             */
/*   Updated: 2024/03/01 17:13:03 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return ;
}

char	**read_map(char *file)
{
	int		fd;
	int		ret;
	char	*buffer;
	char	*str;

	fd = open(file, O_RDONLY);
	ret = 1;
	str = NULL;
	buffer = ft_calloc(2, sizeof(char));
	while (ret > 0)
	{
		if (!buffer)
			return (NULL);
		ret = read(fd, buffer, 1);
		str = ft_strjoin(str, buffer);
	}
	return (ft_split(str, '\n'));
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		ft_exit(1);
	cub = init_cub();
	cub->map = read_map(argv[1]);
	make_minimap(cub, cub->img_map);
	init_ceiling_floor_texture(cub);
//	parsing(cub, argv);
	setup_mlx(cub);
	setup_mlx_event(cub);
	mlx_loop(cub->mlx);
	return (0);
}

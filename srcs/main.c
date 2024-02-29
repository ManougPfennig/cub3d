/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:49:21 by gfabre            #+#    #+#             */
/*   Updated: 2024/02/29 01:50:38 by mapfenni         ###   ########.fr       */
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
	parsing(cub, argv);
	setup_mlx(cub);
	cub->map = read_map(argv[1]);
	display_minimap(cub, cub->img0);
/*	mlx_hook(data.win, 2, 1L << 0, key_pressed, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, deal_key, &data);
	mlx_hook(data.win, 17, 0, ft_destroy_windows, &data);
	mlx_key_hook(data.win, deal_key, &data);*/
	mlx_loop(cub->mlx);
	return (0);
}

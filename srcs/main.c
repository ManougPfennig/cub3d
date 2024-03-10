/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:49:21 by gfabre            #+#    #+#             */
/*   Updated: 2024/03/10 15:09:42 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

// to delete

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

// to delete

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

// to delete

void	set_rgb(t_color *f, t_color *c)
{
	c->r = 10;
	c->g = 10;
	c->b = 10;
	f->r = 100;
	f->g = 100;
	f->b = 100;
}

// to delete

void	set_textures_path(t_cub *cub)
{
	cub->txtr->no_path = "textures/wall_n.xpm";
	cub->txtr->so_path = "textures/wall_s.xpm";
	cub->txtr->we_path = "textures/wall_w.xpm";
	cub->txtr->ea_path = "textures/wall_e.xpm";
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		ft_exit(1);
	cub = init_cub();
//	parsing(cub, argv);
	set_textures_path(cub); // to delete
	set_rgb(cub->f, cub->c); // to delete
	setup_mlx(cub);
	cub->map = read_map(argv[1]); // to_delete
	init_ceiling_floor_texture(cub);
	cub->dir = 0;
	raycasting(cub, NULL);
	setup_mlx_event(cub);
	mlx_loop(cub->mlx);
	return (0);
}

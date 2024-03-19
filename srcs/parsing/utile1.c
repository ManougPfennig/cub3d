/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:44:01 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/19 10:28:20 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	free_all(t_cub *data)
{
	if (data->map)
		ft_free_tab(data->map);
	free_color(data->c);
	free_color(data->f);
	if (data->ray)
		free(data->ray);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	free_img(data, data->img0);
	free_img(data, data->img1);
	free_img(data, data->txtr->no);
	free_img(data, data->txtr->so);
	free_img(data, data->txtr->ea);
	free_img(data, data->txtr->we);
	free_texture(data->txtr);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}

int	ft_free2(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (1);
}

void	error_mes(int n, t_cub	*data)
{
	write(2, "Error\n", 7);
	if (n == 0)
		write(2, "cub3D need 2 arguments !\n", 26);
	if (n == 1)
		write(2, "Wrong file name !\n", 19);
	if (n == 2)
		write(2, "Invalide map !\n", 16);
	if (n == 3)
		write(2, "Bad elements in the map file !\n", 32);
	if (n == 4)
		write(2, "The file does not exist !\n", 27);
	if (n == 5)
		write(2, "The map have wrong numbers of player !\n", 40);
	if (n == 6)
		write(2, "The map is open or the player is out of the map !\n", 51);
	if (n == 7)
		write(2, "Bad color def.\n", 16);
	free_all(data);
	exit(1);
}

char	*line(char *buffer, int fd, t_cub *data)
{
	char	*str;
	int		i;

	if (fd == -1)
		error_mes(4, data);
	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (ft_free(str, NULL));
	i = 1;
	while (i == 1)
	{
		ft_bzero(str, 1);
		i = read(fd, str, 1);
		if (i == 0)
			break ;
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	close(fd);
	if (!buffer[0] && ft_free2(buffer, NULL))
		error_mes(2, data);
	return (buffer);
}

void	check_name(char *str, t_cub *data)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
		error_mes(1, data);
	if (ft_strlen(&str[i]) != 4)
		error_mes(1, data);
	if (!ft_strstr(&str[i], ".cub"))
		error_mes(1, data);
}

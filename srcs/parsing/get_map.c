/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:14:31 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/18 15:55:16 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

char	**get_map(int n, char *buff)
{
	int		j;
	char	**map;

	j = c_back_n(&buff[n]);
	map = malloc ((j + 1) * sizeof(char *));
	j = 0;
	while (buff[n])
	{
		map[j] = put_line(&buff[n]);
		while (buff[n] && buff[n] != '\n')
			n++;
		if (buff[n] && buff[n] == '\n')
			n++;
		j++;
	}
	map[j] = NULL;
//	free(buff);
	return (map);
}

int	get_map_size(t_cub *data, char *buff)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (n < 6 && buff[++i])
	{
		while (buff[i] && buff[i] != '\n')
			i++;
		while (buff[i] && buff[n] == '\n' && buff[i + 1] && buff[i + 1] == '\n')
			i++;
		if (buff[i] == '\n' && buff[i + 1] != '\n')
		{
			n++;
			i++;
		}
		if (!buff[i] && n != 6)
		{
			free(buff);
			error_mes(2, data);
		}
	}
	while (buff[i] && buff[i] == '\n')
		i++;
	return (i);
}

char	*put_line(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!src)
		return (NULL);
	if (src[0] == '\n')
		return (ft_strdup("\n"));
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		str = malloc ((i + 2) * sizeof(char));
	else
		str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (i > j)
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	c_back_n(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

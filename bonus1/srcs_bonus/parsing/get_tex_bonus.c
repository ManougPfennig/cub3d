/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:48:37 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/19 12:05:48 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

int	alloc_space(char *str)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= ' ')
			n++;
		else if (str[i] < ' ' && str[i + 1] >= ' ')
			n++;
		i++;
	}
	return (n);
}

char	*set_space(char *str)
{
	char	*s1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s1 = ft_calloc(alloc_space(str) + 1, sizeof(char));
	while (str[i])
	{
		if (str[i] >= ' ')
		{
			s1[j] = str[i];
			j++;
		}
		else if (str[i] < ' ' && str[i + 1] && str[i + 1] > ' ')
		{
			s1[j] = ' ';
			j++;
		}
		i++;
	}
	free(str);
	return (s1);
}

void	get_texture(t_cub *data, char **tab, char *buff)
{
	int		i;
	char	**ttab;

	i = -1;
	set_tex(data->txtr);
	while (tab[++i])
	{
		if (check_full(data->txtr))
			return ;
		tab[i] = set_space(tab[i]);
		ttab = ft_split(tab[i], ' ');
		if ((ttab[2] || !ttab[1]))
			go_free(ttab, tab, buff, data);
		get_texture2(data, ttab, tab);
		ft_free_tab(ttab);
	}
	if (!check_full(data->txtr))
	{
		ft_free_tab(tab);
		error_mes(3, data);
	}
}

void	get_texture2(t_cub *data, char **tab, char **g_free)
{
	int	n;

	n = 0;
	if (ft_strlen(tab[0]) > 2)
	{
		ft_free_tab(tab);
		ft_free_tab(g_free);
		error_mes(3, data);
	}
	n = what_tex(tab[0]);
	if (n == 0)
	{
		ft_free_tab(tab);
		ft_free_tab(g_free);
		error_mes(3, data);
	}
	get_texture3(tab[1], data->txtr, n);
}

void	get_texture3(char *str, t_texture *tex, int n)
{
	free_d_tex(tex, n);
	if (n == 1)
		tex->no_path = ft_strdup(str);
	if (n == 2)
		tex->so_path = ft_strdup(str);
	if (n == 3)
		tex->ea_path = ft_strdup(str);
	if (n == 4)
		tex->we_path = ft_strdup(str);
	if (n == 5)
		tex->floor = ft_strdup(str);
	if (n == 6)
		tex->ceiling = ft_strdup(str);
}

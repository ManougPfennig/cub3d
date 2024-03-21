/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:35:44 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/19 12:06:16 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	go_free(char **ttab, char **tab, char *buff, t_cub *data)
{
	ft_free_tab(ttab);
	ft_free_tab(tab);
	free (buff);
	error_mes(3, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:39:58 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/19 12:05:38 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

void	ft_freestr(char **ptr)
{
	if ((*ptr) != NULL)
	{
		free((*ptr));
		(*ptr) = NULL;
	}
	return ;
}

char	*ft_clean_up(char **ptr, char **ptr2)
{
	ft_freestr(ptr);
	ft_freestr(ptr2);
	return (NULL);
}

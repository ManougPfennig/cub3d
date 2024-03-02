/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:39:58 by mapfenni          #+#    #+#             */
/*   Updated: 2024/03/02 21:17:44 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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

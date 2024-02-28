/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:39:58 by mapfenni          #+#    #+#             */
/*   Updated: 2024/02/28 17:17:02 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (s);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

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

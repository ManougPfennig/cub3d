/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:39:55 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/05 18:15:55 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*keep_first_nl(char *str)
{
	char	*new_str;
	int		i;

	if (str == NULL)
		return (str);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	new_str = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_str[i] = str[i];
	return (new_str);
}

int	check_no_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*del_first_nl(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = NULL;
	while (str && str[i] && str[i] != '\n')
		i++;
	while (str && str[i++])
		j++;
	if (j == 0)
		return (ft_clean_up(&str, &new_str));
	new_str = ft_calloc(j, sizeof(char));
	new_str[j - 1] = '\0';
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i])
		new_str[j++] = str[i++];
	ft_freestr(&str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line = NULL;
	char		*ret_str;
	ssize_t		ret;
	static int	end;

	ret_str = NULL;
	if (fd < 0 || fd >= 256 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = end + 1;
	while (ret > 0 && check_no_nl(line) == 1)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (ft_clean_up(&buffer, &line));
		line = ft_strjoin(line, buffer);
	}
	if (ret == 0)
		end--;
	ret_str = keep_first_nl(line);
	line = del_first_nl(line);
	if (ret_str != NULL && (*ret_str))
		return (ret_str);
	return (NULL);
}

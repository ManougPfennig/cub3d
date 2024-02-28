/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:39:05 by mapfenni          #+#    #+#             */
/*   Updated: 2024/02/28 17:13:55 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
void	*ft_bzero(void *s, size_t n);
char	*ft_calloc(size_t count, size_t size);
char	*keep_first_nl(char *str);
int		check_no_nl(char *str);
char	*del_first_nl(char *str);
void	ft_freestr(char **ptr);
char	*ft_clean_up(char **ptr, char **ptr2);

#endif

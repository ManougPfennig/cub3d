/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:50:26 by gfabre            #+#    #+#             */
/*   Updated: 2024/03/19 12:06:29 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl_bonus/cub3d_bonus.h"

void	ft_exit(int code)
{
	if (code == 1)
	{
		printf("Wrong numbers of arguments\n");
		exit(code);
	}
}

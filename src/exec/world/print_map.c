/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 02:01:06 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/22 02:29:18 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int print_map(t_cub	cub)
{
    int i;
    int j;
    
    i = 0;
	while (i < cub.map.map_length_y)
	{
		j = 0;
		while (j < cub.map.map_length_x)
		{
			printf("%c", cub.map.map[i][j]);
			j++;
		}
		printf("\n"); // Move to the next line after printing each row
		i++;
	}
    return (0);
}
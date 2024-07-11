/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:18:11 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/10 04:25:28 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/commons.h"

void	print_map(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	while (i < map->rows)
	{
		if (map->grid[i])
		{
			len = get_str_length(map->grid[i]);
			write(1, map->grid[i], len);
			write(1, "\n", 1);
		}
		else
		{
			print_error("Error: Null pointer at row\n");
		}
		i++;
	}
}

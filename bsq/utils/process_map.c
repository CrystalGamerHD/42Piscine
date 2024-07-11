/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:14:24 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/10 14:58:00 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/commons.h"

void	process_map(const char *filename)
{
	t_map	*map;
	t_box	max_box;

	map = read_map(filename);
	if (!map || !check_map(map))
	{
		print_error("map error\n");
		return ;
	}
	max_box = tl_algo(map);
	if (max_box.size > 0)
	{
		mark_largest_square(map, max_box);
		print_map(map);
	}
	else
		print_error("No valid square found.\n");
	free_map(map);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (!(check_char(map, map->grid[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_char(t_map *map, char c)
{
	if (c == map->empty || c == map->obstacle)
	{
		return (1);
	}
	return (0);
}

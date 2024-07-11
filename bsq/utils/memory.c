/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:18:31 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/10 04:25:15 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/commons.h"

char	**allocate_grid(int rows)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * rows);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		grid[i] = NULL;
		i++;
	}
	return (grid);
}

void	free_grid(char **grid, int rows)
{
	int	i;

	if (grid)
	{
		i = 0;
		while (i < rows)
		{
			if (grid[i])
				free(grid[i]);
			i++;
		}
		free(grid);
	}
}

void	free_map(t_map *map)
{
	if (map)
	{
		free_grid(map->grid, map->rows);
		free(map);
	}
}

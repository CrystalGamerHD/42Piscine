/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:18:54 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/10 14:57:04 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/commons.h"

void	update_aux(int **aux, int i, int j)
{
	if (i == 0 || j == 0)
		aux[i][j] = 1;
	else
	{
		aux[i][j] = aux[i][j - 1];
		if (aux[i - 1][j] < aux[i][j])
			aux[i][j] = aux[i - 1][j];
		if (aux[i - 1][j - 1] < aux[i][j])
			aux[i][j] = aux[i - 1][j - 1];
		aux[i][j]++;
	}
}

void	update_max_box_if_needed(t_box *max_box, int size, int i, int j)
{
	if (size > max_box->size)
	{
		max_box->size = size;
		max_box->row = i;
		max_box->col = j;
	}
}

void	process_aux_cell(t_map *map, int **aux, int i, int j)
{
	if (map->grid[i][j] == map->empty)
		update_aux(aux, i, j);
	else
		aux[i][j] = 0;
}

t_box	tl_algo(t_map *map)
{
	t_box	max_box;
	int		**aux;
	int		i;
	int		j;

	max_box.size = 0;
	aux = allocate_aux(map);
	if (!aux)
		return (max_box);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			process_aux_cell(map, aux, i, j);
			update_max_box_if_needed(&max_box, aux[i][j], i, j);
			j++;
		}
		i++;
	}
	free_aux(aux, map->rows);
	return (max_box);
}

void	mark_largest_square(t_map *map, t_box max_box)
{
	int	i;
	int	j;

	i = max_box.row - max_box.size + 1;
	while (i <= max_box.row)
	{
		j = max_box.col - max_box.size + 1;
		while (j <= max_box.col)
		{
			map->grid[i][j] = map->full;
			j++;
		}
		i++;
	}
}

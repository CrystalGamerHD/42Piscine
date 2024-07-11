/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:43:07 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/30 22:51:29 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	find_empty(int grid[N][N], int *row, int *col)
{
	*row = 0;
	while (*row < N)
	{
		*col = 0;
		while (*col < N)
		{
			if (grid[*row][*col] == 0)
				return (1);
			(*col)++;
		}
		(*row)++;
	}
	return (0);
}

int	is_valid(int grid[N][N], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve_grid(int grid[N][N], int clues[16])
{
	int	row;
	int	col;
	int	num;

	num = 1;
	if (!find_empty(grid, &row, &col))
		return (check_clues(grid, clues));
	while (num <= N)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_grid(grid, clues))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

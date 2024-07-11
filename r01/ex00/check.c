/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:58:36 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/30 22:47:00 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

//refer to the three D Sudoku (max height and visible num)
int	count_visible_boxes(int *line, int size)
{
	int	max_height;
	int	visible_count;
	int	i;

	max_height = 0;
	visible_count = 0;
	i = 0;
	while (i < size)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

//check all the rows views
int	validate_row_clues(int grid[N][N], int clues[N*4], int row)
{
	int	left_view;
	int	right_view;
	int	reversed_row[N];
	int	i;

	left_view = clues[(N * 2) + row];
	right_view = clues[(N * 3) + row];
	if (count_visible_boxes(grid[row], N) != left_view)
		return (0);
	i = 0;
	while (i < N)
	{
		reversed_row[i] = grid[row][(N - 1) - i];
		i++;
	}
	if (count_visible_boxes(reversed_row, N) != right_view)
		return (0);
	return (1);
}

//check all the cols views
int	validate_col_clues(int grid[N][N], int clues[N*4], int col)
{
	int	up_view;
	int	down_view;
	int	column[N];
	int	reversed_column[N];
	int	i;

	up_view = clues[col];
	down_view = clues[N + col];
	i = 0;
	while (i < N)
	{
		column[i] = grid[i][col];
		reversed_column[i] = grid[(N - 1) - i][col];
		i++;
	}
	if (count_visible_boxes(column, N) != up_view)
		return (0);
	if (count_visible_boxes(reversed_column, N) != down_view)
		return (0);
	return (1);
}

//check if row and col clues are writtable 
int	check_clues(int grid[N][N], int clues[N*4])
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (!validate_row_clues(grid, clues, i)
			|| !validate_col_clues(grid, clues, i))
			return (0);
		i++;
	}
	return (1);
}

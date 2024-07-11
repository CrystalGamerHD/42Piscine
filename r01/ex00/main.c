/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:09:36 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/30 22:50:26 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	grid[N][N];
	int	clues[4 * N];
	int	row;
	int	col;

	row = 0;
	while (row < N)
	{
		col = 0;
		while (col < N)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	if (argc != 2 || !parse_input(argv[1], clues) || !ft_verify(argv[1]))
		display_error();
	else if (solve_grid(grid, clues))
		paint_grid(grid);
	else
		display_error();
	return (0);
}
//grid = N x N grid from sudoku
//clues = what's outide the grid

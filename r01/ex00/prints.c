/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:42:49 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/30 22:51:16 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	paint_grid(int grid[N][N])
{
	int		i;
	int		j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < (N - 1))
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

//take every value from the grid itoa
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

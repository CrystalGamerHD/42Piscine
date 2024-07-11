/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:10:34 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/30 22:50:01 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	display_error(void)
{
	write(1, "Error\n", 6);
}

int	parse_input(char *str, int clues[N*4])
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (str[row])
	{
		if (str[row] >= '1' && str[row] <= (N + 60))
		{
			if (col < (4 * N))
				clues[col++] = str[row] - '0';
			else
				return (0);
		}
		else if (str[row] != ' ')
			return (0);
		row++;
	}
	return (col == (4 * N));
}
//display = error case of main
//parse_input = alow segmentation of input, between one and four
//else if = means to allow space only in this case
// we love u, good grade pls <3333
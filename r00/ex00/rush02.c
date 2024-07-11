/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:56:53 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/23 12:16:01 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_char(char x, char y, char z, int len_x)
{
	int	i;

	i = 0;
	while (i < len_x)
	{
		if (i == 0)
		{
			ft_putchar(x);
		}
		else if (i > 0 && i < (len_x - 1))
		{
			ft_putchar(y);
		}
		else if (i == (len_x - 1))
		{
			ft_putchar(z);
		}
	i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	while (i < y)
	{
		if (i == 0)
		{
			print_char('A', 'B', 'A', x);
		}
		else if (i > 0 && i < (y - 1))
		{
			print_char('B', ' ', 'B', x);
		}
		else if (i == (y - 1))
		{
			print_char('C', 'B', 'C', x);
		}		
	i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:01:02 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/20 12:53:42 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int idx;
	int	temp;
	
	idx = 0;
	temp = 0;
	while (idx < (size / 2))
	{
		temp = tab[idx];
		tab[idx] = tab[size - 1 - idx];
		tab[size - 1 - idx] = temp;
		idx++;
	}
}

/*
void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;

	temp = 0;
	
	while (size > 1)
	{
		temp += (*tab % 10) * (10 ^ (--size));
		*tab /= 10;
	}
	temp += *tab;
	*tab = temp;
}
*/

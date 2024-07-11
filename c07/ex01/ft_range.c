/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:57:28 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/27 17:33:18 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*rtrn;
	int	i;

	if (min >= max)
		return (NULL);
	rtrn = (int *)malloc(sizeof(int) * (max - min + 1));
	i = 0;
	while (min <= max)
	{
		rtrn[i] = min;
		min++;
		i++;
	}
	return (rtrn);
}

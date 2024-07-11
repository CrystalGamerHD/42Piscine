/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:30:17 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/30 20:49:55 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_verify(char *values)
{
	int	i;

	i = 0;
	if (str_len(values) > (((N * 4) * 2) - 1))
	{
		return (0);
	}
	while (values[i])
	{
		if ((values[i] != ' ' && values[i] <= '1' && values[i] >= (N + 60)))
		{
			return (0);
		}
		else if ((i % 2 != 0) && values[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
//allow str only to work with spaces between num

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:06:55 by cbopp             #+#    #+#             */
/*   Updated: 2024/07/09 14:12:52 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*temp;
	int			i;

	temp = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!temp)
		return (0);
	i = 0;
	while (i < ac)
	{
		temp[i].size = ft_strlen(av[i]);
		temp[i].str = malloc(temp[i].size + 1);
		temp[i].copy = malloc(temp[i].size + 1);
		ft_strcpy(temp[i].str, av[i]);
		ft_strcpy(temp[i].copy, av[i]);
		i++;
	}
	temp[i].str = 0;
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:17:04 by cbopp             #+#    #+#             */
/*   Updated: 2024/07/10 15:02:00 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/commons.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}

int	min(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

int	**allocate_aux(t_map *map)
{
	int	**aux;
	int	i;

	aux = (int **)malloc(sizeof(int *) * map->rows);
	if (!aux)
		return (NULL);
	i = 0;
	while (i < map->rows)
	{
		aux[i] = (int *)malloc(sizeof(int) * map->cols);
		if (!aux[i])
		{
			while (--i >= 0)
				free(aux[i]);
			free(aux);
			return (NULL);
		}
		i++;
	}
	return (aux);
}

void	free_aux(int **aux, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(aux[i]);
		i++;
	}
	free(aux);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:17:57 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/10 14:09:17 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/commons.h"

t_map	*initialize_map(char *buffer, int *line_start)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		print_error("Failed to allocate memory for map structure\n");
		return (NULL);
	}
	*line_start = read_first_line(map, buffer);
	if (*line_start == -1)
	{
		free(map);
		return (NULL);
	}
	map->grid = allocate_grid(map->rows);
	if (!map->grid)
	{
		print_error("Failed to allocate memory for grid\n");
		free(map);
		return (NULL);
	}
	return (map);
}

int	process_grid_line(t_map *map, char *buffer, int *line_start, int row)
{
	int	line_length;

	line_length = *line_start;
	while (buffer[line_length] != '\n' && buffer[line_length] != '\0')
		line_length++;
	line_length -= *line_start;
	if (row == 0)
		map->cols = line_length;
	if (line_length != map->cols)
	{
		print_error("Inconsistent line length at row\n");
		return (-1);
	}
	map->grid[row] = malloc(line_length + 1);
	if (!map->grid[row])
	{
		print_error("Failed to allocate memory for grid row\n");
		return (-1);
	}
	ft_memcpy(map->grid[row], buffer + *line_start, line_length);
	map->grid[row][line_length] = '\0';
	*line_start += line_length + 1;
	return (0);
}

int	fill_grid(t_map *map, char *buffer, int line_start)
{
	int	row;
	int	i;

	row = 0;
	i = line_start;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			if (process_grid_line(map, buffer, &line_start, row) == -1)
				return (-1);
			row++;
		}
		i++;
	}
	if (row != map->rows)
	{
		print_error("Mismatch between expected rows and actual rows\n");
		return (-1);
	}
	return (0);
}

t_map	*parse_map(char *buffer)
{
	int		line_start;
	t_map	*map;

	map = initialize_map(buffer, &line_start);
	if (!map)
		return (NULL);
	if (fill_grid(map, buffer, line_start) == -1)
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

t_map	*read_map(const char *filename)
{
	char	*buffer;
	t_map	*map;

	buffer = read_large_file(filename);
	if (!buffer)
		return (NULL);
	map = parse_map(buffer);
	free(buffer);
	return (map);
}

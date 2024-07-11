/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:09:09 by cbopp             #+#    #+#             */
/*   Updated: 2024/07/10 14:57:28 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/commons.h"

int	read_first_line(t_map *map, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0' || i < 4)
	{
		print_error("Failed to read first line\n");
		return (-1);
	}
	buffer[i] = '\0';
	map->rows = ft_atoi(buffer);
	if (map->rows <= 0)
	{
		print_error("Invalid number of rows\n");
		return (-1);
	}
	map->empty = buffer[i - 3];
	map->obstacle = buffer[i - 2];
	map->full = buffer[i - 1];
	return (i + 1);
}

char	*reallocate_buffer(char *buffer, int *buffer_size)
{
	char	*temp_buffer;

	temp_buffer = malloc(*buffer_size + BUF_SIZE);
	if (!temp_buffer)
	{
		print_error("Failed to allocate temporary buffer\n");
		free(buffer);
		return (NULL);
	}
	ft_memcpy(temp_buffer, buffer, *buffer_size);
	free(buffer);
	*buffer_size += BUF_SIZE;
	return (temp_buffer);
}

char	*allocate_buffer(int buffer_size)
{
	char	*buffer;

	buffer = malloc(buffer_size);
	if (!buffer)
		print_error("Failed to allocate buffer\n");
	return (buffer);
}

int	open_file(const char *filename)
{
	int	fd;

	if (filename)
		fd = open(filename, O_RDONLY);
	else
		fd = STDIN_FILENO;
	if (fd < 0)
		print_error("Failed to open file\n");
	return (fd);
}

void	print_error(const char *message)
{
	int	len;

	len = 0;
	while (message[len] != '\0')
		len++;
	write(2, message, len);
}

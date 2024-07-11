/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:19:26 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/10 14:56:25 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/commons.h"

char	*handle_read_error(char *buffer, int fd)
{
	print_error("Failed to read file\n");
	free(buffer);
	close(fd);
	return (NULL);
}

char	*finalize_read(char *buffer, int total_read)
{
	buffer[total_read] = '\0';
	return (buffer);
}

char	*read_file_data(int fd, char *buffer, int buffer_size)
{
	int	total_read;
	int	ret;

	total_read = 0;
	ret = read(fd, buffer + total_read, BUF_SIZE);
	while (ret > 0)
	{
		total_read += ret;
		if (total_read + BUF_SIZE > buffer_size)
		{
			buffer = reallocate_buffer(buffer, &buffer_size);
			if (!buffer)
			{
				close(fd);
				return (NULL);
			}
		}
		ret = read(fd, buffer + total_read, BUF_SIZE);
	}
	if (ret < 0)
		return (handle_read_error(buffer, fd));
	return (finalize_read(buffer, total_read));
}

char	*read_large_file(const char *filename)
{
	int		fd;
	char	*buffer;

	fd = open_file(filename);
	if (fd < 0)
		return (NULL);
	buffer = allocate_buffer(BUF_SIZE);
	if (!buffer)
	{
		if (filename)
			close(fd);
		return (NULL);
	}
	buffer = read_file_data(fd, buffer, BUF_SIZE);
	if (filename)
		close(fd);
	return (buffer);
}

int	get_str_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

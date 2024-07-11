/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:16:27 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/10 15:13:39 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUF_SIZE 1024

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_box
{
	int	row;
	int	col;
	int	size;
}	t_box;

// Prototypes

//		process_map.c
void	process_map(const char *filename);
int		check_map(t_map *map);
int		check_char(t_map *map, char c);

//		read_map.c
t_map	*initialize_map(char *buffer, int *line_start);
int		process_grid_line(t_map *map, char *buffer, int *line_start, int row);
int		fill_grid(t_map *map, char *buffer, int line_start);
t_map	*parse_map(char *buffer);
t_map	*read_map(const char *filename);

//		utils.c
int		get_str_length(char *str);
char	*read_large_file(const char *filename);
char	*read_file_data(int fd, char *buffer, int buffer_size);
char	*finalize_read(char *buffer, int total_read);
char	*handle_read_error(char *buffer, int fd);

//		utils2.c
int		read_first_line(t_map *map, char *buffer);
char	*reallocate_buffer(char *buffer, int *buffer_size);
char	*allocate_buffer(int buffer_size);
int		open_file(const char *filename);
void	print_error(const char *message);

//		utils3.c
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		min(int num1, int num2);
int		**allocate_aux(t_map *map);
void	free_aux(int **aux, int rows);

//		memory.c
char	**allocate_grid(int rows);
void	free_grid(char **grid, int rows);
void	free_map(t_map *map);

//		print_map.c
void	print_map(t_map *map);

//		algo_dp.c
void	update_aux(int **aux, int i, int j);
void	update_max_box_if_needed(t_box *max_box, int size, int i, int j);
void	process_aux_cell(t_map *map, int **aux, int i, int j);
t_box	tl_algo(t_map *map);
void	mark_largest_square(t_map *map, t_box max_box);

#endif
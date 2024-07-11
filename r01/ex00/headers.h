/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:44:19 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/30 22:55:59 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implementation library
#ifndef HEADERS_H
# define HEADERS_H
# define N 4
# include <unistd.h>
# include <stdlib.h>

int		ft_verify(char *values);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	paint_grid(int grid[N][N]);
int		parse_input(char *str, int clues[N*4]);
void	display_error(void);
int		solve_grid(int grid[N][N], int clues[N*4]);
int		is_valid(int grid[N][N], int row, int col, int num);
int		find_empty(int grid[N][N], int *row, int *cold);
int		check_clues(int grid[N][N], int clues[N*4]);

#endif

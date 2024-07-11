/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:12:06 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/10 03:34:12 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/commons.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		process_map(NULL);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (i > 1)
				write(1, "\n", 1);
			process_map(argv[i]);
			i++;
		}
	}
	return (0);
}

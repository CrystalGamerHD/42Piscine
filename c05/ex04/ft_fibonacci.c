/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:21:50 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/25 15:18:13 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	a;
	int	b;
	int	c;
	int	i;

	a = 0;
	b = 1;
	i = 2;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (a);
	while (i <= index)
	{
		c = a + b;
		a = b;
		b = c;
		i++;
	}
	return (b);
}

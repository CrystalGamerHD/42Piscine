/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:17:46 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/25 15:19:14 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	temp;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	temp = nb;
	while (power > 1)
	{
		temp *= nb;
		power--;
	}
	return (temp);
}

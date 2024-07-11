/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:52:11 by cbopp             #+#    #+#             */
/*   Updated: 2024/06/25 12:17:20 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	temp;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	temp = 1;
	while (nb)
		temp *= (nb--);
	return (temp);
}

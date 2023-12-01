/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:45:03 by kreys             #+#    #+#             */
/*   Updated: 2023/07/17 20:15:23 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	powered(int nb, int power)
{
	int	multiplay;

	multiplay = 1;
	while (power-- >= 1)
	{
		multiplay *= nb;
	}
	return (multiplay);
}

int	ft_iterative_power(int nb, int power)
{
	int	number;

	number = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 1)
		return (1);
	if (power == 1)
		return (nb);
	number = nb * powered(nb, power - 1);
	return (number);
}

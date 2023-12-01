/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:45:03 by kreys             #+#    #+#             */
/*   Updated: 2023/07/30 13:05:28 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	found_sqrt(long nb, long m, int change, int try)
{
	long	c;

	if (change == 0)
		change = 1;
	if (try >= m)
		return (0);
	c = m * m;
	if (c == nb)
		return (m);
	if (c < nb)
		return (found_sqrt(nb, m + change, change / 2, m));
	else
		return (found_sqrt(nb, m - change, change / 2, try));
}

int	ft_sqrt(int nb)
{
	long		nb1;
	int			x;

	if (nb < 0)
		return (0);
	nb1 = nb;
	x = 1;
	if (nb1 == 1)
		return (1);
	return (found_sqrt(nb1, nb1 / 2, nb1 / 4, 0));
}

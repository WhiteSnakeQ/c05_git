/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:16:41 by kreys             #+#    #+#             */
/*   Updated: 2023/07/17 19:43:05 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	b;
	int	c;

	c = 0;
	if (nb < 0)
		return (0);
	b = 1;
	while (nb > 0)
	{
		b *= c + 1;
		nb--;
		c++;
	}
	return (b);
}

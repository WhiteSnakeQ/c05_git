/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:16:41 by kreys             #+#    #+#             */
/*   Updated: 2023/07/18 15:25:51 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	factorial_q(int nb, int iteration)
{
	int	fact;

	fact = 1;
	if (iteration > 1)
		fact = factorial_q(nb + 1, iteration - 1);
	return (nb * fact);
}

int	ft_recursive_factorial(int nb)
{
	int	b;

	if (nb < 0)
		return (0);
	b = 1;
	if (nb > 1)
		return (factorial_q(b, nb));
	else
		return (1);
}

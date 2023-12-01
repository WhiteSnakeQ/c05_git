/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:45:03 by kreys             #+#    #+#             */
/*   Updated: 2023/07/31 08:32:54 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	fibbonaci(int nb, int last, int index)
{
	int	c;

	c = nb + last;
	if (index > 1)
		return (fibbonaci(c, nb, index - 1));
	return (c);
}

int	ft_fibonacci(int index)
{
	int	c;

	c = 1;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index == 2)
		return (1);
	c = fibbonaci(c, 1, index - 2);
	return (c);
}

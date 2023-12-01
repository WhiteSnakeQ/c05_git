/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:57:59 by kreys             #+#    #+#             */
/*   Updated: 2023/07/31 07:11:52 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

typedef struct s_my_str
{
	int		start_i;
	int		start_b;
	int		count_win;
	char	arr[11][11];
}			t_quins;

void	fill_arr(char arr[11][11], int i, int b)
{
	i = 0;
	while (i < 10)
	{
		b = 0;
		while (b < 10)
			arr[i][b++] = '-';
		i++;
	}
}

int	print_arr(t_quins quin, int *c_w)
{
	int	i;
	int	d;
	int	to_print;

	i = 0;
	while (i < 10)
	{
		d = 0;
		while (d < 10)
		{
			if (quin.arr[d++][i] == 'Q')
			{
				to_print = d + 47;
				write(1, &to_print, 1);
			}
		}
		i++;
	}
	write(1, "\n", 1);
	*c_w += 1;
	return (-1);
}

int	fill_field(char arr[11][11], int row, int coll)
{
	int	i;
	int	d;

	i = 0;
	if (row > 9 || coll > 9)
		return (-1);
	while (i < 10)
	{
		if (arr[row][i] == 'Q')
			return (-1);
		if ((arr[i++][coll]) == 'Q')
			return (-1);
	}
	i = row;
	d = coll;
	while (i < 10 && i >= 0 && d < 10 && d >= 0)
		if (arr[i--][d--] == 'Q')
			return (-1);
	i = row;
	d = coll;
	while (i < 10 && i >= 0 && d < 10 && d >= 0)
		if (arr[i++][d--] == 'Q')
			return (-1);
	arr[row][coll] = 'Q';
	return (0);
}

int	build_all(t_quins quin, int cc, int *count_win)
{
	int		start_ii;
	int		start_bb;

	cc = fill_field(quin.arr, quin.start_i, quin.start_b++);
	if (cc == -1)
		return (-1);
	start_ii = quin.start_i;
	start_bb = quin.start_b - 1;
	if (quin.start_b == 10)
	{
		cc = print_arr(quin, count_win);
		quin.arr[start_ii][start_bb] = '-';
		return (cc);
	}
	quin.start_i = -1;
	while (cc != 1 && start_ii > ++quin.start_i)
		cc = build_all(quin, 0, count_win);
	quin.start_i = start_ii;
	while (cc != 1 && ++quin.start_i <= 9)
		cc = build_all(quin, 0, count_win);
	if (cc == -1)
		quin.arr[start_ii][start_bb] = '-';
	return (cc);
}

int	ft_ten_queens_puzzle(void)
{
	t_quins		quin;

	quin.count_win = 0;
	quin.start_b = 0;
	quin.start_i = -1;
	fill_arr(quin.arr, 0, 0);
	while (++quin.start_i < 10)
		build_all(quin, 0, &quin.count_win);
	return (quin.count_win);
}

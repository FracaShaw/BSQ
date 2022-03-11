/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squares.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:38:40 by nprimo            #+#    #+#             */
/*   Updated: 2021/07/20 11:30:04 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h" 
#include <stdio.h>

int	ft_min_cells(int **matrix_n, int r, int c)
{
	int	min;

	min = matrix_n[r - 1][c];
	if (matrix_n[r - 1][c] < min)
		min = matrix_n[r - 1][c - 1];
	if (matrix_n[r - 1][c - 1] < min)
		min = matrix_n[r - 1][c - 1];
	if (matrix_n[r][c - 1] < min)
		min = matrix_n[r][c - 1];
	return (min);
}

int	**get_squares(int **matrix_n, t_rules rules)
{
	int	**square_sizes;
	int	r;
	int	c;

	square_sizes = malloc(sizeof(*square_sizes) * rules.r_count);
	if (square_sizes == 0)
		return (0);
	r = 0;
	while (r < rules.r_count)
	{
		c = 0;
		square_sizes[r] = malloc(sizeof(**square_sizes) * rules.c_count);
		if (square_sizes[r] == 0)
			return (0);
		while (c < rules.c_count)
		{
			if (r != 0 && c != 0 && matrix_n[r][c] != 0)
				square_sizes[r][c] = ft_min_cells(square_sizes, r, c) + 1;
			else
				square_sizes[r][c] = matrix_n[r][c];
			c++;
		}
		r++;
	}
	return (square_sizes);
}

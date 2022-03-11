/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:22:37 by nprimo            #+#    #+#             */
/*   Updated: 2021/07/20 13:58:28 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

t_point	get_max_sq(int **matrix_n, t_rules rules)
{
	int		max;
	t_point	idx;
	t_point	max_sq;

	max = 0;
	idx.r = 0;
	max_sq.r = -1;
	max_sq.c = -1;
	while (idx.r < rules.r_count)
	{
		idx.c = 0;
		while (idx.c < rules.c_count)
		{
			if (matrix_n[idx.r][idx.c] > max)
			{
				max = matrix_n[idx.r][idx.c];
				max_sq.r = idx.r;
				max_sq.c = idx.c;
			}
			idx.c++;
		}
		idx.r++;
	}
	return (max_sq);
}

int	draw_solution(char **matrix_or, t_rules rules, t_point max_sq,
			int size_sq)
{
	t_point	shift;

	shift.r = 0;
	while (shift.r < size_sq)
	{
		shift.c = 0;
		while (shift.c < size_sq)
		{
			matrix_or[max_sq.r - shift.r][max_sq.c - shift.c] = rules.full;
			shift.c++;
		}
		shift.r++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_01matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:27:38 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/07/20 15:03:22 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	**malloc_matrix_int(t_rules rules)
{
	int	r;
	int	**matrix;

	matrix = malloc(sizeof(*matrix) * (rules.r_count + 1));
	if (matrix == NULL)
		return (0);
	r = 0;
	while (r < rules.r_count)
	{
		matrix[r] = malloc(sizeof(**matrix) * (rules.c_count));
		if (matrix[r] == NULL)
			return (0);
		r++;
	}
	matrix[r] = NULL;
	return (matrix);
}

int	**gen_matrix_n(char **og_matrix, t_rules rules)
{
	int	**matrix_n;
	int	r;
	int	c;

	matrix_n = malloc_matrix_int(rules);
	if (matrix_n == NULL)
		return (NULL);
	r = 0;
	while (r < rules.r_count)
	{
		c = 0;
		while (c < rules.c_count)
		{
			if (og_matrix[r][c] == rules.empty)
				matrix_n[r][c] = 1;
			if (og_matrix[r][c] == rules.obs)
				matrix_n[r][c] = 0;
			c++;
		}
		r++;
	}
	matrix_n[r] = NULL;
	return (matrix_n);
}

void	print_matrix_int(int **matrix, t_rules rules)
{
	int	r;
	int	c;

	r = 0;
	while (r < rules.r_count)
	{
		c = 0;
		while (c < rules.c_count)
		{
			ft_putnbr(matrix[r][c]);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

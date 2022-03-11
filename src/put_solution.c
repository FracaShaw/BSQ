/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:20:18 by nprimo            #+#    #+#             */
/*   Updated: 2021/07/20 15:55:00 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	put_solution(char *fname)
{
	char	**og_matrix;
	int		**squares;
	t_rules	rules;
	t_point	max_sq;

	rules = get_rules(fname);
	if (rules.r_count == 0 || !check_matrix(fname, rules))
		return (0);
	og_matrix = get_og_matrix(fname, rules, count_char_line(fname) + 1);
	if (og_matrix == 0)
		return (0);
	squares = get_squares(gen_matrix_n(og_matrix, rules), rules);
	max_sq = get_max_sq(squares, rules);
	if (max_sq.r != -1)
		draw_solution(og_matrix, rules, max_sq, squares[max_sq.r][max_sq.c]);
	print_matrix(og_matrix);
	free(og_matrix);
	free(squares);
	return (1);
}

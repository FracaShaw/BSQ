/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:29:35 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/07/19 19:32:16 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**malloc_matrix(int r_count, int c_count)
{
	int		r;
	char	**matrix;

	matrix = malloc(sizeof(*matrix) * (r_count + 1));
	if (matrix == NULL)
		return (0);
	r = 0;
	while (r < r_count)
	{
		matrix[r] = malloc(sizeof(**matrix) * (c_count + 1));
		matrix[r][c_count] = '\0';
		if (matrix[r] == NULL)
			return (0);
		r++;
	}
	matrix[r] = NULL;
	return (matrix);
}

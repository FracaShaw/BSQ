/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:08:54 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/07/20 10:51:17 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUF_SIZE 5

char	**get_og_matrix(char *fname, t_rules rules, int line0_size)
{
	int		fd;
	int		ret;
	char	**og_matrix;
	char	*buf;
	int		r;

	og_matrix = malloc_matrix(rules.r_count, rules.c_count);
	buf = malloc(sizeof(*buf) * line0_size);
	fd = open(fname, O_RDONLY);
	if (buf == NULL || og_matrix == NULL || fd == -1)
		return (NULL);
	ret = read(fd, buf, line0_size);
	r = 0;
	while (r < rules.r_count)
	{
		ret = read(fd, og_matrix[r], rules.c_count);
		ret = read(fd, buf, 1);
		r++;
	}
	free(buf);
	if (close(fd) == -1)
		return (NULL);
	return (og_matrix);
}
/*			
int main(void)
{
	char fname[] = "example\0";
	int line0_size = 5;
	int line_size = 27;
	int size = 9;
	char **og_matrix;

	og_matrix = get_og_matrix(fname, size, line0_size, line_size);
	print_matrix(og_matrix);
}
*/
